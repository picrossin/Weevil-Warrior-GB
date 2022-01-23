#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "Keys.h"

IMPORT_MAP(endScreen);

void START() {
	InitScroll(BANK(endScreen), &endScreen, 0, 0);
}

extern UINT8 current_level;
void NextLevel();
void UPDATE() {
	if (keys) {
		current_level = 0;
		SetState(StateTitle);
	}
}