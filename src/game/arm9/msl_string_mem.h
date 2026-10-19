#ifndef GAME_ARM9_MSL_STRING_MEM_H
#define GAME_ARM9_MSL_STRING_MEM_H

/* Public functions of msl_string_mem.c, prototypes copied from their definitions. */

void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *MSL_C_LIB_MemsetPtr(void *dest, int c, u32 n);
u8 *memchr(u8 *s, u32 c, u32 n);
int memcmp(const u8 *s1, const u8 *s2, u32 n);
void __fill_mem(u8 *dest, u32 val, u32 count);

#endif
