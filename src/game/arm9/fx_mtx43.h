#ifndef GAME_ARM9_FX_MTX43_H
#define GAME_ARM9_FX_MTX43_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fx_mtx43.c, prototypes copied from their definitions. */

union MtxFx43;

#include "../sdk_fx.h"
#include "../types.h"

void MTX_Identity43_(MtxFx43 *pDst);
void MTX_Copy43To44_(const MtxFx43 *pSrc, MtxFx44 *pDst);
void MTX_Scale43_(void);
void MTX_ScaleApply43(const MtxFx43 *pSrc, MtxFx43 *pDst, fx32 x, fx32 y, fx32 z);
void MTX_RotY43_(union MtxFx43 *m, fx32 sinVal, fx32 cosVal);
void MTX_RotAxis43(void *m, void *v, fx32 sinVal, fx32 cosVal);
int MTX_Inverse43(const MtxFx43 *pSrc, MtxFx43 *pDst);
void MTX_Concat43(const MtxFx43 *a, const MtxFx43 *b, MtxFx43 *ab);
void MTX_MultVec43(const VecFx32 *vec, const MtxFx43 *m, VecFx32 *dst);
void MTX_LookAt(const VecFx32 *camPos, const VecFx32 *camUp, const VecFx32 *target, MtxFx43 *mtx);
/* END mkheaders: generated region */

#endif
