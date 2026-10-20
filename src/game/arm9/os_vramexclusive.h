#ifndef GAME_ARM9_OS_VRAMEXCLUSIVE_H
#define GAME_ARM9_OS_VRAMEXCLUSIVE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_vramexclusive.c, prototypes copied from their definitions. */

#include "../types.h"

void OSi_InitVramExclusive(void);
void OSi_UnlockVram(u16 bank, u16 lockId);
/* END mkheaders: generated region */

#endif
