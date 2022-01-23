#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Music.h"

IMPORT_TILES(font);
UINT8 collision_tiles[] = {1, 0};
IMPORT_MAP(map);
DECLARE_MUSIC(Level_Music);

void START() {
	scroll_target = SpriteManagerAdd(SpritePlayer, 20, 50);
	InitScroll(BANK(map), &map, collision_tiles, 0);
	PlayMusic(Level_Music, 1);
}

void UPDATE() {
}
