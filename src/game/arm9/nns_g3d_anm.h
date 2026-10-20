#ifndef GAME_ARM9_NNS_G3D_ANM_H
#define GAME_ARM9_NNS_G3D_ANM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_g3d_anm.c, prototypes copied from their definitions. */

#include "../arm9/nns_g3d_anm_types.h"
#include "../types.h"

int NNSi_G3dAnmBlendMat(void *pResult, const NNSG3dAnmObj *pAnmObj, u32 matIdx);
void NNSi_G3dAnmBlendJntVec(volatile s32 *dst, const s32 *src, s32 weight, int isOne);
int NNSi_G3dAnmBlendJnt(NNSG3dJntAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 jntIdx);
int NNSi_G3dAnmBlendVis(u32 *pResult, const NNSG3dAnmObj *pAnmObj, u32 nodeIdx);
/* END mkheaders: generated region */

#endif
