#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "Keys.h"

IMPORT_MAP(titleScreen);

void START() {
	InitScroll(BANK(titleScreen), &titleScreen, 0, 0);

	// PRINT(3, 5, "Shield Bouncer");
	// PRINT(6, 15, "by Zal0");
	// PRINT(4, 16, "2018 zgbjam");
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