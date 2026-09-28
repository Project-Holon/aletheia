/*
 * Minimal C library string declarations for SDK translation units.
 *
 * mwccarm treats strcpy and memcpy as intrinsics only when they are
 * declared in a header whose name is string.h (or cstring or memory.h):
 * strcpy from a string literal is then expanded into an inline block copy
 * of strlen + 1 bytes instead of a call.  A prototype written in the .c
 * file itself always produces the call.
 */
#ifndef ALETHEIA_LIBC_STRING_H
#define ALETHEIA_LIBC_STRING_H

typedef unsigned long size_t;

char *strcpy(char *dst, const char *src);
void *memcpy(void *dst, const void *src, size_t n);

#endif
