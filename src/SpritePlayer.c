#include "Banks/SetAutoBank.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "SpritePlayer.h"
#include "ZGBMain.h"

CONTROL_STATE control_state;

const UINT8 anim_idle[] = {2, 0, 1};
const UINT8 anim_walk[] = {2, 2, 3};

INT8 y_accel;
UINT8 gravity_offset;
unsigned char jumped;

void START() {
    y_accel = 0;
    gravity_offset = 0;
    jumped = 0;
}

void UPDATE() {
    UINT8 i;
    Sprite* spr;

    if (KEY_PRESSED(J_LEFT)) {
        TranslateSprite(THIS, -1, 0);
        SetSpriteAnim(THIS, anim_walk, 15);
    }

    if (KEY_PRESSED(J_RIGHT)) {
        TranslateSprite(THIS, 1, 0);
        SetSpriteAnim(THIS, anim_walk, 15);
    }        

    if (keys == 0) {
        SetSpriteAnim(THIS, anim_idle, 15);
    }

    switch (control_state) {
        case GROUNDED:
            // If player presses A, then jump
            if (KEY_TICKED(J_A)) {
                y_accel = JUMP_ACCEL;
                control_state = IN_AIR;
                gravity_offset = 0;
                jumped = 1;
            } else {
                // If the player is not trying to jump, keep them on the ground
                if (TranslateSprite(THIS, 0, 1)) {
                    y_accel = 0;
                    control_state = GROUNDED;
                } else {
                    control_state = IN_AIR;
                }
            }
            break;
        case IN_AIR:
            if (KEY_RELEASED(J_A) && jumped == 1 && y_accel < 0) {
                y_accel = -1;
                jumped = 0;
            }

            if (y_accel <= MAX_JUMP_ACCEL) {
                if (gravity_offset == GRAVITY_WAIT) {
                    y_accel += GRAVITY;
                    gravity_offset = 0;
                } else {
                    gravity_offset++;
                }
            }

            if (TranslateSprite(THIS, 0, y_accel)) {
                if (y_accel < 0) {
                    y_accel = 0;
                    control_state = IN_AIR;
                } else {
                    control_state = GROUNDED;
                }

                y_accel = 0;
            }
            break;
    }
    
    // SPRITEMANAGER_ITERATE(i, spr) {
    //     if (spr->type == SpriteEnemy) {
    //         if (CheckCollision(THIS, spr)) {
    //             SetState(StateGame);
    //         }
    //     }
    // }
}

void DESTROY() {
}