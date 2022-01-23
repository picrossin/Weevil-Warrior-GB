#include "Banks/SetAutoBank.h"
#include "SpriteManager.h"

const UINT8 bubble_anim[] = {4, 0, 1, 2, 3};

UINT8 frames;

void START() {
    frames = 0;
    SetSpriteAnim(THIS, bubble_anim, 20);
}

void UPDATE() {
    frames++;
    if (frames >= 16) {
        SpriteManagerRemoveSprite(THIS);
    }
}

void DESTROY() {
}