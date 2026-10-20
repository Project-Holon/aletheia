#ifndef GAME_ARM9_FX_MTX33_H
#define GAME_ARM9_FX_MTX33_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fx_mtx33.c, prototypes copied from their definitions. */

#include "../sdk_fx.h"
#include "../types.h"

void MTX_Identity33_(MtxFx33 *pDst);
void MTX_Copy33To44_(const MtxFx33 *pSrc, MtxFx44 *pDst);
void MTX_Scale33_(MtxFx33 *pDst, fx32 x, fx32 y, fx32 z);
void MTX_ScaleApply33(const MtxFx33 *pSrc, MtxFx33 *pDst, fx32 x, fx32 y, fx32 z);
void MTX_RotX33_(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal);
void MTX_RotY33_(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal);
void MTX_RotZ33_(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal);
void MTX_RotAxis33(MtxFx33 *pDst, const VecFx32 *vec, fx32 sinVal, fx32 cosVal);
int MTX_Inverse33(const MtxFx33 *pSrc, MtxFx33 *pDst);
void MTX_Concat33(const MtxFx33 *a, const MtxFx33 *b, MtxFx33 *ab);
void MTX_MultVec33(const VecFx32 *vec, const MtxFx33 *m, VecFx32 *dst);
/* END mkheaders: generated region */

#endif
