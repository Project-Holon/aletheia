#ifndef GAME_ARM9_NNS_G3D_TEX_H
#define GAME_ARM9_NNS_G3D_TEX_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_g3d_tex.c, prototypes copied from their definitions. */

#include "../arm9/nns_g3d_anm_types.h"
#include "../arm9/nns_g3d_anm_types.h"
#include "../arm9/nns_g3d_anm_calc_types.h"
#include "../arm9/nns_g3d_anm_calc_types.h"
#include "../types.h"

void NNS_G3dAnmObjInit(NNSG3dAnmObj *anmObj, NNSG3dAnmFmtHeader *resAnm, const NNSG3dResMdl *resMdl, NNSG3dResTex *resTex);
void NNS_G3dRenderObjInit(NNSG3dRenderObj *rndObj, const NNSG3dResMdl *resMdl);
void NNSi_G3dAnmObjInsertByPriority(NNSG3dAnmObj **head, NNSG3dAnmObj *item);
void NNSi_G3dAnmObjCollectMapDataMask(u32 *mask, NNSG3dAnmObj *anmObj);
void NNS_G3dRenderObjAddAnmObj(NNSG3dRenderObj *rndObj, NNSG3dAnmObj *anmObj);
u32 NNSi_G3dAnmObjUnlink(NNSG3dAnmObj **head, NNSG3dAnmObj *target);
void NNS_G3dRenderObjRemoveAnmObj(NNSG3dRenderObj *rndObj, NNSG3dAnmObj *anmObj);
int NNS_G3dTexGetRequiredSize(void *pTex);
int NNS_G3dTex4x4GetRequiredSize(NNSG3dResTex *pTex);
void NNS_G3dTexSetTexKey(NNSG3dResTex *pTex, int texKey, int tex4x4Key);
void NNS_G3dTexLoad(NNSG3dResTex *pTex, u32 exec);
void NNS_G3dTexReleaseTexKey(NNSG3dResTex *pTex, u32 *pTexKey, u32 *pTex4x4Key);
u32 NNS_G3dPlttGetRequiredSize(NNSG3dResTex *pTex);
void NNS_G3dPlttSetPlttKey(NNSG3dResTex *pTex, u32 plttKey);
void NNS_G3dPlttLoad(NNSG3dResTex *pTex, BOOL exec);
void *NNS_G3dPlttReleasePlttKey(NNSG3dResTex *pTex);
BOOL NNS_G3dBindMdlTex(NNSG3dResMdl *pMdl, const NNSG3dResTex *pTex);
BOOL NNS_G3dBindMdlPltt(NNSG3dResMdl *pMdl, const NNSG3dResTex *pTex);
int NNS_G3dBindMdlPlttEx(NNSG3dResMdl *pMdl, NNSG3dResTex *pTex, u32 plttToMatIdx, u32 plttDataIdx);
void NNS_G3dReleaseMdlPltt(NNSG3dResMdl *pMdl);
/* END mkheaders: generated region */

#endif
