#ifndef GAME_ARM9_MSL_STRING_MEM_H
#define GAME_ARM9_MSL_STRING_MEM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of msl_string_mem.c, prototypes copied from their definitions. */

#include "../types.h"

void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *MSL_C_LIB_MemsetPtr(void *dest, int c, u32 n);
u8 *memchr(u8 *s, u32 c, u32 n);
int memcmp(const void *buf1, const void *buf2, size_t n);
void __fill_mem(u8 *dest, u32 val, u32 count);
/* END mkheaders: generated region */

#endif
