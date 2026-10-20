#ifndef GAME_ARM9_INFOWIN_H
#define GAME_ARM9_INFOWIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of infowin.c, prototypes copied from their definitions. */

#include "../types.h"

void INFOWIN_Init(u8 bgFrame, u8 palette, void *gameData, u16 heap);
void INFOWIN_Update(void);
int INFOWIN_Exit(void);
void INFOWIN_DrawTask(void);
void INFOWIN_WriteScreen(u32 base, u32 blk, u8 x, u8 y, u8 w, u8 h);
int INFOWIN_LoadCharacters(int tile, const void *src, int count);
void INFOWIN_LoadGraphics(u32 a, u32 b, u32 c);
void INFOWIN_UpdateClock(void);
/* END mkheaders: generated region */

#endif
