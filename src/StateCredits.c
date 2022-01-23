#include "Banks/SetAutoBank.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "Keys.h"

IMPORT_MAP(credits);

static UINT8 frames;

void START() {
	frames = 0;
	InitScroll(BANK(credits), &credits, 0, 0);
}

extern UINT8 current_level;
void NextLevel();
void UPDATE() {
	frames++;
	if (frames >= 60 || keys) {
		current_level = 0;

		current_level--;
		SetState(StateTitle);
	}
}