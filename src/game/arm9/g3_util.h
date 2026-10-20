#ifndef GAME_ARM9_G3_UTIL_H
#define GAME_ARM9_G3_UTIL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of g3_util.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../sdk_fx.h"

void G3i_PerspectiveW_(fx32 fovySin, fx32 fovyCos, fx32 aspect, fx32 n, fx32 f, fx32 scaleW, BOOL draw, MtxFx44 *mtx);
void G3i_OrthoW_(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, BOOL draw, MtxFx44 *mtx);
void G3i_LookAt_(const VecFx32 *camPos, const VecFx32 *camUp, const VecFx32 *target, BOOL draw, MtxFx43 *mtx);
void G3_RotX(fx32 s, fx32 c);
void G3_RotY(fx32 s, fx32 c);
void G3_RotZ(fx32 s, fx32 c);
/* END mkheaders: generated region */

#endif
