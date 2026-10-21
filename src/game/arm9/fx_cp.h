#ifndef GAME_ARM9_FX_CP_H
#define GAME_ARM9_FX_CP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fx_cp.c, prototypes copied from their definitions. */

#include "../types.h"

fx32 FX_Div(fx32 numer, fx32 denom);
fx32 FX_Inv(fx32 denom);
fx64 FX_InvFx64c(fx32 denom);
fx32 FX_Sqrt(fx32 x);
fx32 FX_InvSqrt(fx32 x);
u64 FX_GetDivResultFx64c(void);
s32 FX_GetDivResult(void);
void FX_InvAsync(fx32 denom);
void FX_SqrtAsync(fx32 x);
fx32 FX_GetSqrtResult(void);
void FX_DivAsync(s32 numer, s32 denom);
s32 FX_DivS32(s32 numer, s32 denom);
fx32 FX_ModS32(fx32 a, fx32 b);
/* END mkheaders: generated region */

#endif
