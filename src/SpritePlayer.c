#include "Banks/SetAutoBank.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "SpritePlayer.h"
#include "Sound.h"
#include "ZGBMain.h"

CONTROL_STATE control_state;

// Animations for player
const UINT8 anim_idle[] = {2, 0, 1};
const UINT8 anim_walk[] = {2, 2, 3};
const UINT8 anim_jump[] = {1, 4};

// Player settings and variables
INT8 x_accel;
INT8 y_accel;
UINT8 gravity_offset;
UINT8 run_offset;
UINT8 coyote_time;
unsigned char jumped;
unsigned char walked;

void START() {
    // Ensure all variables are initialized
    x_accel = 0;
    y_accel = 0;
    gravity_offset = 0;
    run_offset = 0;
    coyote_time = 0;
    jumped = FALSE;
    walked = FALSE;
}

void UPDATE() {
    UINT8 i;
    Sprite* spr;

    walked = FALSE;

    // Handle left and right walking
    if (KEY_PRESSED(J_LEFT)) {
        walked = TRUE;
        THIS->mirror = V_MIRROR;
        if (x_accel > -MAX_RUN_SPEED) {
            x_accel--;
        }
    }

    if (KEY_PRESSED(J_RIGHT)) {
        walked = TRUE;
        THIS->mirror = NO_MIRROR;
        if (x_accel < MAX_RUN_SPEED) {
            x_accel++;
        }
    }

    // Handle walking negative acceleration
    if (walked == FALSE && x_accel != 0) {
        if (x_accel > 0) {
            x_accel--;
        } else if (x_accel < 0) {
            x_accel++;
        }
    }

    // Move in x direction
    run_offset++;
    if (run_offset >= RUN_WAIT) {
        TranslateSprite(THIS, x_accel, 0);
        run_offset = 0;
    }

    // Level wrapping
    if (THIS->x > 160) {
        THIS->x = 0;
    } else if (THIS->x <= 1) {
        THIS->x = 159;
    }

    // Set idle animation
    if (keys == 0) {
        SetSpriteAnim(THIS, anim_idle, 15);
    }

    // Handle vertical movement states (grounded or in the air)
    switch (control_state) {
        case GROUNDED:
            // If player presses A, then jump
            if (KEY_TICKED(J_A)) {
                Jump();
            } else {
                // If the player is not trying to jump, keep them on the ground
                if (TranslateSprite(THIS, 0, 1)) {
                    y_accel = 0;
                    control_state = GROUNDED;
                    jumped = FALSE;
                    coyote_time = COYOTE_WAIT;
                } else {
                    control_state = IN_AIR;
                }

                // Animate walking
                if (KEY_PRESSED(J_LEFT) || KEY_PRESSED(J_RIGHT)) {
                    SetSpriteAnim(THIS, anim_walk, 15);
                }
            }
            break;
        case IN_AIR:
            // Handle coyote time jumping
            if (coyote_time > 0) { 
                coyote_time--;

                if (KEY_TICKED(J_A) && jumped == FALSE && y_accel > 0) {
                    Jump();
                    coyote_time = 0;
                }
            }

            if (KEY_RELEASED(J_A) && jumped == TRUE && y_accel < 0) {
                y_accel = -1;
            }

            // Set jump sprite
            SetSpriteAnim(THIS, anim_jump, 15);

            // Add gravity
            if (y_accel <= MAX_JUMP_ACCEL) {
                if (gravity_offset == GRAVITY_WAIT) {
                    y_accel += GRAVITY;
                    gravity_offset = 0;
                } else {
                    gravity_offset++;
                }
            }

            // Check if back on ground and transition states
            if (TranslateSprite(THIS, 0, y_accel)) {
                if (y_accel < 0) {
                    y_accel = 0;
                    control_state = IN_AIR;
                } else {
                    control_state = GROUNDED;
                }

                y_accel = 0;
            }

            // Handle wall jumping
            if (KEY_PRESSED(J_RIGHT) && KEY_TICKED(J_A) && TranslateSprite(THIS, 2, 0)) {
                PlayFx(CHANNEL_2, 10, 0x80, 0xA1, 0xD7, 0x86);
                x_accel -= WALL_JUMP_OUT;
                y_accel = WALL_JUMP_UP;
            }
            
            if (KEY_PRESSED(J_LEFT) && KEY_TICKED(J_A) && TranslateSprite(THIS, -2, 0)) {
                PlayFx(CHANNEL_2, 10, 0x80, 0xA1, 0xD7, 0x86);
                x_accel += WALL_JUMP_OUT;
                y_accel = WALL_JUMP_UP;
            }
            break;
    }

    // Handle collisions with other sprites
    SPRITEMANAGER_ITERATE(i, spr) {
        if (spr->type == SpriteLadder) {
            if (CheckCollision(THIS, spr)) {
                NextLevel();
                break;
            }
        } else if (spr->type == SpriteCorn) {
            if (CheckCollision(THIS, spr)) {
                PlayFx(CHANNEL_1, 10, 0x2B, 0x02, 0xF2, 0xD6, 0x86);
                SpriteManagerRemoveSprite(spr);
            	SpriteManagerAdd(SpriteBubble, spr->x, spr->y);
            }
        } else if (spr->type == SpriteSpikeDown || spr->type == SpriteSpikeUp || spr->type == SpriteSpikeLeft || spr->type == SpriteSpikeRight || \
        spr->type == SpriteEnemy || spr->type == SpriteCornPit) {
            if (CheckCollision(THIS, spr)) {
                PlayFx(CHANNEL_1, 10, 0x4f, 0xc7, 0xf3, 0x73, 0x86);
                SpriteManagerRemoveSprite(THIS);
            	SpriteManagerAdd(SpriteDeath, THIS->x, THIS->y);
            }
        }
    }
}

void DESTROY() {
}

void Jump() {
    PlayFx(CHANNEL_2, 10, 0x80, 0xA1, 0xD7, 0x86);
    y_accel = JUMP_ACCEL;
    control_state = IN_AIR;
    gravity_offset = 0;
    jumped = TRUE;
}