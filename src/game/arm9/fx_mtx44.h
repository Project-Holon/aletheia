#ifndef GAME_ARM9_FX_MTX44_H
#define GAME_ARM9_FX_MTX44_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fx_mtx44.c, prototypes copied from their definitions. */

#include "../sdk_fx.h"
#include "../types.h"

void MTX_Identity44_(MtxFx44 *pDst);
void MTX_Copy44To43_(MtxFx44 *pSrc, MtxFx43 *pDst);
void MTX_Concat44(const MtxFx44 *a, const MtxFx44 *b, MtxFx44 *ab);
void MTX_FrustumW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx);
void MTX_PerspectiveW(fx32 fovySin, fx32 fovyCos, fx32 aspect, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx);
void MTX_OrthoW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx);
/* END mkheaders: generated region */

#endif
