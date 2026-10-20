#ifndef GAME_OV037_GIMMICK_INIT_HELPERS_H
#define GAME_OV037_GIMMICK_INIT_HELPERS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gimmick_init_helpers.c, prototypes copied from their definitions. */

struct GameSystem;

void GIMMICK_INIT_SetCartLanesFlags(void *gameSystem, int setFirst, int setSecond);
void GIMMICK_INIT_SetFlagAnimeFlag(struct GameSystem *gameSystem, int enable);
void GIMMICK_INIT_SetButtonStatesFlags(void *gameSystem, int buttonMask);
void GIMMICK_INIT_RestorePlateDoorsState(void *gameSystem, unsigned short **foundVars);
void GIMMICK_INIT_ResetRotatingRoomPanels(void *gameSystem);
/* END mkheaders: generated region */

#endif
