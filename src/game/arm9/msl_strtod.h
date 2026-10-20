#ifndef GAME_ARM9_MSL_STRTOD_H
#define GAME_ARM9_MSL_STRTOD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of msl_strtod.c, prototypes copied from their definitions. */

#include "../types.h"

double __strtold(int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg, int *chars_scanned, int *overflow);
double strtod(const char *s, char **endptr);
double atof(const char *s);
u32 __strtoul(int base, int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg, int *chars_scanned, int *negative, int *overflow);
u32 strtoul(const char *s, char **endptr, int base);
int strtol(const char *s, char **endptr, int base);
u64 __strtoull(int base, int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg, int *chars_scanned, int *negative, int *overflow);
s64 strtoll(const char *s, char **endptr, int base);
int atoi(const char *s);
long long atoll(const char *s);
/* END mkheaders: generated region */

#endif
