#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#define STATES \
_STATE(StateTitle)\
_STATE(StateEnd)\
_STATE(StateGame)\
STATE_DEF_END

#define SPRITES \
_SPRITE_DMG(SpritePlayer, player)\
_SPRITE_DMG(SpriteEnemy, weevil)\
_SPRITE_DMG(SpriteSpikeUp, spikes)\
_SPRITE_DMG(SpriteSpikeDown, spikesDown)\
_SPRITE_DMG(SpriteSpikeLeft, spikesLeft)\
_SPRITE_DMG(SpriteSpikeRight, spikesRight)\
_SPRITE_DMG(SpriteLadder, ladder)\
_SPRITE_DMG(SpriteCorn, corn)\
_SPRITE_DMG(SpriteCornPit, cornTop)\
_SPRITE_DMG(SpriteBubble, pop)\
_SPRITE_DMG(SpriteDeath, pop)\
SPRITE_DEF_END

#include "ZGBMain_Init.h"

#endif