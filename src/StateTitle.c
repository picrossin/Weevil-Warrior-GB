#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "Keys.h"
#include "Music.h"

IMPORT_MAP(titleScreen);
DECLARE_MUSIC(Main_Menu);

void START() {
	InitScroll(BANK(titleScreen), &titleScreen, 0, 0);
	PlayMusic(Main_Menu, 1);
}

extern UINT8 current_level;
void NextLevel();
void UPDATE() {
	if (keys) {
		current_level = 0;

		current_level--;
		NextLevel();
	}
}