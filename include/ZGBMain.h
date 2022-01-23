#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#define STATES \
_STATE(StateCredits)\
_STATE(StateTitle)\
_STATE(StateGame)\
STATE_DEF_END

#define SPRITES \
_SPRITE_DMG(SpritePlayer, player)\
_SPRITE_DMG(SpriteEnemy, enemy)\
_SPRITE_DMG(SpriteSpikeUp, spikes)\
_SPRITE_DMG(SpriteSpikeDown, spikesDown)\
_SPRITE_DMG(SpriteSpikeLeft, spikesLeft)\
_SPRITE_DMG(SpriteSpikeRight, spikesRight)\
_SPRITE_DMG(SpriteLadder, ladder)\
_SPRITE_DMG(SpriteCorn, corn)\
SPRITE_DEF_END

#include "ZGBMain_Init.h"

#endif