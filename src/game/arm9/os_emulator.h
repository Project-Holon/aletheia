#ifndef GAME_ARM9_OS_EMULATOR_H
#define GAME_ARM9_OS_EMULATOR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_emulator.c, prototypes copied from their definitions. */

#include "../types.h"

u32 OS_GetConsoleType(void);
int OS_IsRunOnEmulator(void);
int OS_IsRunOnTwl(void);
int OSi_IsRunOnTwl(void);
/* END mkheaders: generated region */

#endif
