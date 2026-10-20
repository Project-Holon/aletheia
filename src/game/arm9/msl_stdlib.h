#ifndef GAME_ARM9_MSL_STDLIB_H
#define GAME_ARM9_MSL_STDLIB_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of msl_stdlib.c, prototypes copied from their definitions. */

#include "../types.h"

u32 rand(void);
void srand(u32 v);
int MSL_C_LIB_StrReadProc(u32 *state, u32 ch, u32 mode);
void MSL_C_LIB_CallExitHook(u32 a, u32 b, u32 c);
void MSL_C_LIB_DefaultExitHook(void);
/* END mkheaders: generated region */

#endif
