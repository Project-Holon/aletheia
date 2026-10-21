#ifndef GAME_ARM9_OS_TICK_H
#define GAME_ARM9_OS_TICK_H

#include "../sdk_os.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_tick.c, prototypes copied from their definitions. */

#include "../types.h"

void OS_InitTick(void);
BOOL OS_IsTickAvailable(void);
void OSi_CountUpTick(void);
OSTick OS_GetTick(void);
unsigned short OS_GetTickLo(void);
/* END mkheaders: generated region */

#endif
