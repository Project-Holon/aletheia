#ifndef GAME_ARM9_MSL_PRINTF_H
#define GAME_ARM9_MSL_PRINTF_H

#include "../sdk_stdarg.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of msl_printf.c, prototypes copied from their definitions. */

#include "../types.h"

void *MSL_C_LIB_SprintfWriteProc(void *sb, const u8 *src, size_t n);
u32 sprintf(char *dst, char *fmt, ...);
/* END mkheaders: generated region */

#endif
