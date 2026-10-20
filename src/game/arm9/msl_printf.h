#ifndef GAME_ARM9_MSL_PRINTF_H
#define GAME_ARM9_MSL_PRINTF_H

/* Public functions of msl_printf.c, prototypes copied from their definitions. */

#include "../types.h"

u32 MSL_C_LIB_SprintfWriteProc(u8 *sb, const void *src, u32 n);
u32 vsnprintf(u8 *dst, u32 n, const u8 *format, u8 *ap);
u32 sprintf(char *dst, char *fmt, ...);

#endif
