#include "Banks/SetAutoBank.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "ZGBMain.h"

const UINT8 anim_idle[] = {1, 0};
const UINT8 anim_walk[] = {2, 1, 2};

void START() {
}

void UPDATE() {
    UINT8 i;
    Sprite* spr;
    
    if (KEY_PRESSED(J_UP)) {
        TranslateSprite(THIS, 0, -1);
        SetSpriteAnim(THIS, anim_walk, 15);
    }

    if (KEY_PRESSED(J_DOWN)) {
        TranslateSprite(THIS, 0, 1);
        SetSpriteAnim(THIS, anim_walk, 15);
    }

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

    SPRITEMANAGER_ITERATE(i, spr) {
        if (spr->type == SpriteEnemy) {
            if (CheckCollision(THIS, spr)) {
                SetState(StateGame);
            }
        }
    }
}

void DESTROY() {
}