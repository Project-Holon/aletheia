#ifndef GAME_ARM9_MSL_STRTOD_H
#define GAME_ARM9_MSL_STRTOD_H

/* Public functions of msl_strtod.c, prototypes copied from their definitions. */

#include "../types.h"

double __strtold(int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg, int *chars_scanned, int *overflow);
u64 strtod(u32 s, u32 *endptr);
int atof(char *s);
u32 __strtoul(int base, int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg, int *chars_scanned, int *negative, int *overflow);
u32 strtoul(u32 s, u32 *endptr, u32 base);
int strtol(u32 s, u32 *endptr, u32 base);
u64 __strtoull(int base, int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg, int *chars_scanned, int *negative, int *overflow);
s64 strtoll(u32 s, u32 *endptr, u32 base);
int atoi(u32 s);
long long atoll(u32 s);

#endif
