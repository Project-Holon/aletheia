#ifndef GAME_ARM9_NNS_G3D_MDL_H
#define GAME_ARM9_NNS_G3D_MDL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_g3d_mdl.c, prototypes copied from their definitions. */

struct NNSFndAllocator;

void *NNS_G3dAllocRenderObj(struct NNSFndAllocator *pAllocator);
void NNS_G3dFreeRenderObj(struct NNSFndAllocator *pAllocator, void *pRenderObj);
void NNS_G3dFreeAnmObj(struct NNSFndAllocator *pAllocator, void *pAnmObj);
/* END mkheaders: generated region */

#endif
