#ifndef GAME_ARM9_MSL_FDLIBM_H
#define GAME_ARM9_MSL_FDLIBM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of msl_fdlibm.c, prototypes copied from their definitions. */

#include "../types.h"

int __kernel_rem_pio2(double *x, double *y, int e0, int nx, int prec, const int *ipio2);
double __kernel_sin(double x, double y, int iy);
double copysign(double x, double y);
double cos(double x);
double fabs(double x);
double floor(double x);
double frexp(double x, int *eptr);
double ldexp(double x, int n);
double sin(double x);
double pow(double x, double y);
int stricmp(const u8 *s1, const u8 *s2);
int strnicmp(const u8 *s1, const u8 *s2, int n);
int strcmp_nocase(const char *s1, const char *s2);
/* END mkheaders: generated region */

#endif
