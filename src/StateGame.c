#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Music.h"

IMPORT_TILES(font);
UINT8 collision_tiles[] = {33, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 0};

IMPORT_MAP(level1);
IMPORT_MAP(level2);
IMPORT_MAP(level3);
IMPORT_MAP(level4);
IMPORT_MAP(level5);
IMPORT_MAP(level6);

struct MapInfoBanked {
	UINT8 bank;
	struct MapInfo* map;
};

#define BANKED_MAP(MAP) {BANK(MAP), &MAP}

const struct MapInfoBanked levels[] = {
	BANKED_MAP(level1),
	BANKED_MAP(level2),
	BANKED_MAP(level3),
	BANKED_MAP(level4),
	BANKED_MAP(level5),
	BANKED_MAP(level6),
};

typedef struct {
    UINT16 start_x;
    UINT16 start_y;
} START_POS;

const START_POS start_positions[] = {
	{30, 440},
	{30, 350},
	{30, 640},
	{15, 15},
	{30, 600},
	{120, 450},
};

UINT8 current_level = 0;

DECLARE_MUSIC(Level_Music);

void START() {
	const struct MapInfoBanked* level = &levels[current_level];

	scroll_target = SpriteManagerAdd(SpritePlayer, start_positions[current_level].start_x, start_positions[current_level].start_y);
	InitScroll(level->bank, level->map, collision_tiles, 0);
	PlayMusic(Level_Music, 1);

	NR52_REG = 0x80; // Enables sound, you should always setup this first
	NR51_REG = 0xFF; // Enables all channels (left and right)
	NR50_REG = 0x77; // Max volume
}

void UPDATE() {
}

void NextLevel() {
	if (current_level == 5) {
		SetState(StateEnd);
	} else {
		current_level++;
		SetState(StateGame);
	}
}

void ReloadLevel() {
	SetState(StateGame);
}