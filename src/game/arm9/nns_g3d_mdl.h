#ifndef GAME_ARM9_NNS_G3D_MDL_H
#define GAME_ARM9_NNS_G3D_MDL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_g3d_mdl.c, prototypes copied from their definitions. */

struct NNSFndAllocator;

#include "../arm9/nns_g3d_anm_types.h"
#include "../arm9/nns_g3d_anm_types.h"
#include "../arm9/nns_g3d_anm_calc_types.h"

void *NNS_G3dAllocRenderObj(struct NNSFndAllocator *pAllocator);
void NNS_G3dFreeRenderObj(struct NNSFndAllocator *pAllocator, void *pRenderObj);
NNSG3dAnmObj *NNS_G3dAllocAnmObj(struct NNSFndAllocator *pAllocator, const NNSG3dAnmFmtHeader *pAnm, const NNSG3dResMdl *pMdl);
void NNS_G3dFreeAnmObj(struct NNSFndAllocator *pAllocator, void *pAnmObj);
/* END mkheaders: generated region */

#endif
