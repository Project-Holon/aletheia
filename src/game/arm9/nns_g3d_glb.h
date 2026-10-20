#ifndef GAME_ARM9_NNS_G3D_GLB_H
#define GAME_ARM9_NNS_G3D_GLB_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_g3d_glb.c, prototypes copied from their definitions. */

#include "../sdk_fx.h"
#include "../types.h"

void NNS_G3dGlbInit(void);
void NNS_G3dGlbFlush(void);
void NNS_G3dGlbFlushP(void);
void NNS_G3dGlbFlushWVP(void);
void NNS_G3dGlbBaseTrans(const VecFx32 *pTrans);
void NNS_G3dGlbBaseScale(const VecFx32 *pScale);
void NNS_G3dGlbLightVector(int lightId, s16 x, s16 y, s16 z);
void NNS_G3dGlbLightColor(int lightId, u32 lightColor);
void NNS_G3dGlbMaterialColorDiffAmb(u32 diffuse, u32 ambient, u32 isSetVtxColor);
void NNS_G3dGlbMaterialColorSpecEmi(u32 specular, u32 emission, u32 isShininess);
MtxFx43 *NNS_G3dGlbGetInvCameraMtx(void);
int MTX_Inverse44(const MtxFx44 *pSrc, MtxFx44 *pDst);
MtxFx44 *NNS_G3dGlbGetInvProjectionMtx(void);
void NNSi_G3dGlbUpdateWV(void);
MtxFx43 *NNS_G3dGlbGetWVMtx(void);
MtxFx43 *NNS_G3dGlbGetInvWVMtx(void);
MtxFx44 *NNS_G3dGlbGetInvVPMtx(void);
void NNS_G3dGlbGetViewPort(u32 *x1, u32 *y1, u32 *x2, u32 *y2);
/* END mkheaders: generated region */

#endif
