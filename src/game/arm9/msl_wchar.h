#ifndef GAME_ARM9_MSL_WCHAR_H
#define GAME_ARM9_MSL_WCHAR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of msl_wchar.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../arm9/msl_wchar_shared_types.h"

int fwide(u8 *stream, int orientation);
int wcslen(const u16 *s);
u16 *wcscpy(u16 *d, const u16 *s);
int MSL_C_LIB_ShouldRoundUp(u8 *dec, int idx);
void MSL_C_LIB_IncrementDigits(u8 *dec, int idx);
void MSL_C_LIB_SetPrecision(DB *dec, int precision);
/* END mkheaders: generated region */

#endif
