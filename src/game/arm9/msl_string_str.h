#ifndef GAME_ARM9_MSL_STRING_STR_H
#define GAME_ARM9_MSL_STRING_STR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of msl_string_str.c, prototypes copied from their definitions. */

#include "../types.h"

size_t strlen(const char *str);
char *strcpy(char *dst, const char *src);
char *strncpy(char *destStr, const char *srcStr, size_t n);
u8 *strcat(u8 *dest, const u8 *src);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *str1, const char *str2, size_t n);
char *strchr(const char *str, int c);
int strcspn(const u8 *s, const u8 *reject);
char *strstr(const char *str1, const char *str2);
/* END mkheaders: generated region */

#endif
