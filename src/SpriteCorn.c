#include "Banks/SetAutoBank.h"
#include "SpriteManager.h"

const UINT8 anim[] = {4, 0, 1, 2, 3};

void START() {
    SetSpriteAnim(THIS, anim, 15);
}

void UPDATE() {
}

void DESTROY() {
}