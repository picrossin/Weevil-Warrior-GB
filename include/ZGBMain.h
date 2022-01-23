#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#define STATES \
_STATE(StateGame)\
STATE_DEF_END

#define SPRITES \
_SPRITE_DMG(SpritePlayer, player)\
_SPRITE_DMG(SpriteEnemy, enemy)\
_SPRITE_DMG(SpriteSpikeUp, spikes)\
_SPRITE_DMG(SpriteSpikeDown, spikesDown)\
_SPRITE_DMG(SpriteSpikeLeft, spikesLeft)\
_SPRITE_DMG(SpriteSpikeRight, spikesRight)\
_SPRITE_DMG(SpriteGrain, grainWave)\
SPRITE_DEF_END

#include "ZGBMain_Init.h"

#endif