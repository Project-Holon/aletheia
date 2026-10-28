/*
 * string.h variant that also declares memcmp.
 *
 * mwccarm treats a libc function declared in a header named string.h as
 * writing no memory, so loads of globals and struct fields stay in registers
 * across the call.  The shared libc/string.h does not declare memcmp, and a
 * prototype in the .c file gets no such treatment (ov016 usbap.o scanWait).
 * Copy of ../string.h plus memcmp (mwccarm resolves nested includes against the
 * translation unit, so it cannot include the shared header). Include this file instead of ../string.h where memcmp must behave so.
 */
#ifndef ALETHEIA_LIBC_MEMCMP_STRING_H
#define ALETHEIA_LIBC_MEMCMP_STRING_H
#ifdef __MWERKS__
typedef unsigned long size_t;
#else
#include <stddef.h>
#endif
char *strcpy(char *dst, const char *src);
void *memcpy(void *dst, const void *src, size_t n);
void *memset(void *dst, int c, size_t n);
size_t strlen(const char *s);
int memcmp(const void *a, const void *b, size_t n);
#endif
