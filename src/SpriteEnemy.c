#include "Banks/SetAutoBank.h"
#include "SpriteManager.h"

typedef struct {
    INT8 vx;
} CUSTOM_DATA;

const UINT8 weevil_anim[] = {2, 0, 1};

void START() {
    CUSTOM_DATA* data = (CUSTOM_DATA*)THIS->custom_data;
    data->vx = 1;
    SetSpriteAnim(THIS, weevil_anim, 15);
}

void UPDATE() {
    CUSTOM_DATA* data = (CUSTOM_DATA*)THIS->custom_data;
    if (TranslateSprite(THIS, data->vx, 0)) {
        data->vx = -data->vx;
    }
}

void DESTROY() {
}