#ifndef GAME_ARM9_MSL_ANSI_FP_H
#define GAME_ARM9_MSL_ANSI_FP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of msl_ansi_fp.c, prototypes copied from their definitions. */

struct MslDecString;

#include "../arm9/msl_strtod_shared_types.h"
#include "../types.h"
#include "../arm9/msl_wchar_shared_types.h"
#include "../arm9/msl_printf_shared_types.h"
#include "../arm9/msl_printf_shared_types.h"

void __ull2dec(decimal2 *result, u64 val);
void __timesdec(decimal2 *result, const decimal2 *x, const decimal2 *y);
void __str2dec(struct MslDecString *dec, const u8 *s, u16 exponent);
void __two_exp(decimal2 *result, long exp);
void __minus_dec(decimal2 *z, const decimal2 *x, const decimal2 *y);
void __num2dec(DB *r, double x);
void __dtoa(const decform *f, double x, decimal *p);
double __dec2num(const decimal2 *d);
/* END mkheaders: generated region */

#endif
