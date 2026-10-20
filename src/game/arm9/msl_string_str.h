#ifndef GAME_ARM9_MSL_STRING_STR_H
#define GAME_ARM9_MSL_STRING_STR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of msl_string_str.c, prototypes copied from their definitions. */

#include "../types.h"

int strlen(const u8 *s);
char *strcpy(char *dst, const char *src);
u8 *strncpy(u8 *dest, const u8 *src, u32 n);
u8 *strcat(u8 *dest, const u8 *src);
int strcmp(const char *s1, const char *s2);
int strncmp(const u8 *s1, const u8 *s2, u32 n);
u8 *strchr(const u8 *s, int c);
int strcspn(const u8 *s, const u8 *reject);
u8 *strstr(const u8 *s1, const u8 *s2);
/* END mkheaders: generated region */

#endif
