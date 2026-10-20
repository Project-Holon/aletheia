#ifndef GAME_OV228_SAVE_OUTSIDE_H
#define GAME_OV228_SAVE_OUTSIDE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of save_outside.c, prototypes copied from their definitions. */

#include "../types.h"

void *SAVE_OUTSIDE_Load(u32 heap);
void SAVE_OUTSIDE_Free(void *p);
void SAVE_OUTSIDE_ClearFlash(u32 heap);
/* END mkheaders: generated region */

#endif
