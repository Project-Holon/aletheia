#ifndef GAME_ARM9_NNS_G3D_UTIL_H
#define GAME_ARM9_NNS_G3D_UTIL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_g3d_util.c, prototypes copied from their definitions. */

#include "../sdk_fx.h"

int NNS_G3dWorldPosToScrPos(const VecFx32 *pWorld, int *px, int *py);
int NNS_G3dScrPosToWorldLine(int px, int py, VecFx32 *pNear, VecFx32 *pFar);
/* END mkheaders: generated region */

#endif
