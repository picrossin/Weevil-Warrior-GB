#include "Banks/SetAutoBank.h"
#include "SpriteManager.h"

const UINT8 bubble_death_anim[] = {4, 0, 1, 2, 3};

UINT8 death_frames;

void START() {
    death_frames = 0;
    SetSpriteAnim(THIS, bubble_death_anim, 20);
}

void UPDATE() {
    death_frames++;
    if (death_frames >= 16) {
        ReloadLevel();
        SpriteManagerRemoveSprite(THIS);
    }
}

void DESTROY() {
}