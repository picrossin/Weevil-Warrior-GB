#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Music.h"

IMPORT_TILES(font);
UINT8 collision_tiles[] = {33, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 0};

IMPORT_MAP(map);
IMPORT_MAP(map1);
IMPORT_MAP(level1);

struct MapInfoBanked {
	UINT8 bank;
	struct MapInfo* map;
};

#define BANKED_MAP(MAP) {BANK(MAP), &MAP}

const struct MapInfoBanked levels[] = {
	BANKED_MAP(map),
	BANKED_MAP(map1),
	BANKED_MAP(level1)
};

typedef struct {
    UINT16 start_x;
    UINT16 start_y;
} START_POS;

const START_POS start_positions[] = {
	{20, 440},
	{20, 300},
	{20, 440}
};

extern UINT8 current_level = 0;

DECLARE_MUSIC(Level_Music);

void START() {
	const struct MapInfoBanked* level = &levels[current_level];

	scroll_target = SpriteManagerAdd(SpritePlayer, start_positions[current_level].start_x, start_positions[current_level].start_y);
	InitScroll(level->bank, level->map, collision_tiles, 0);
	PlayMusic(Level_Music, 1);
}

void UPDATE() {
}

void NextLevel() {
	current_level++;
	SetState(StateGame);
}