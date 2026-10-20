#ifndef GAME_ARM9_FX_VEC_H
#define GAME_ARM9_FX_VEC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fx_vec.c, prototypes copied from their definitions. */

#include "../sdk_fx.h"
#include "../sdk_fx.h"
#include "../sdk_fx.h"
#include "../types.h"

void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
void VEC_Subtract(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
void VEC_Fx16Add(const VecFx16 *a, const VecFx16 *b, VecFx16 *ab);
fx32 VEC_DotProduct(const VecFx32 *a, const VecFx32 *b);
fx32 VEC_Fx16DotProduct(const VecFx16 *a, const VecFx16 *b);
void VEC_CrossProduct(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb);
void VEC_Fx16CrossProduct(const VecFx16 *a, const VecFx16 *b, VecFx16 *axb);
fx32 VEC_Mag(const VecFx32 *pSrc);
fx32 VEC_Fx16Mag(const VecFx16 *pSrc);
void VEC_Normalize(const VecFx32 *pSrc, VecFx32 *pDst);
void VEC_Fx16Normalize(const VecFx16 *pSrc, VecFx16 *pDst);
void VEC_MultAdd(fx32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);
fx32 VEC_Distance(const VecFx32 *v1, const VecFx32 *v2);
/* END mkheaders: generated region */

#endif
