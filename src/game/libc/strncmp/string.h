/*
 * string.h variant that also declares strncmp.
 *
 * mwccarm treats a libc function declared in a header named string.h as
 * writing no memory, so loads of struct fields and locals stay in registers
 * across the call.  The shared libc/string.h does not declare strncmp, and a
 * prototype in the .c file gets no such treatment (ov009 gsiXmlUtilParseElement).
 * Copy of ../string.h plus strncmp (mwccarm resolves nested includes against the
 * translation unit, so it cannot include the shared header). Include this file
 * instead of ../string.h where strncmp must behave so.
 */
#ifndef ALETHEIA_LIBC_STRNCMP_STRING_H
#define ALETHEIA_LIBC_STRNCMP_STRING_H
#ifdef __MWERKS__
typedef unsigned long size_t;
#else
#define __need_size_t
#define __need_ptrdiff_t
#include <stddef.h>
#endif
char *strcpy(char *dst, const char *src);
void *memcpy(void *dst, const void *src, size_t n);
void *memset(void *dst, int c, size_t n);
size_t strlen(const char *s);
int strncmp(const char *a, const char *b, size_t n);
#endif
