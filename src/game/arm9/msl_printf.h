#ifndef GAME_ARM9_MSL_PRINTF_H
#define GAME_ARM9_MSL_PRINTF_H

#include "../sdk_stdarg.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of msl_printf.c, prototypes copied from their definitions. */

#include "../types.h"

u32 MSL_C_LIB_SprintfWriteProc(u8 *sb, const void *src, u32 n);
u32 sprintf(char *dst, char *fmt, ...);
/* END mkheaders: generated region */

#endif
