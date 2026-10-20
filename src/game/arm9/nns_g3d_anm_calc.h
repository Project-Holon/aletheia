#ifndef GAME_ARM9_NNS_G3D_ANM_CALC_H
#define GAME_ARM9_NNS_G3D_ANM_CALC_H

/* Public functions of nns_g3d_anm_calc.c, prototypes copied from their definitions. */

#include "../arm9/nns_g3d_anm_types.h"
#include "../arm9/nns_g3d_anm_calc_types.h"
#include "../arm9/nns_g3d_anm_calc_types.h"
#include "../types.h"
#include "../sdk_fx.h"

void NNSi_G3dAnmObjInitNsBca(NNSG3dAnmObj *pAnmObj, const NNSG3dResJntAnm *pJntAnm, const NNSG3dResMdl *pMdl);
void NNSi_G3dAnmCalcNsBca(NNSG3dJntAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx);
void NNSi_G3dGetNodeTransFromMdl(NNSG3dJntAnmResult *pResult);
void NNSi_G3dGetNodeScaleFromMdl(NNSG3dJntAnmResult *pResult);
void NNSi_G3dGetNodeRotFromMdl(NNSG3dJntAnmResult *pResult);
void NNSi_G3dAnmCalcJntAnmNode(const NNSG3dResJntAnm *pJntAnm, u32 dataIdx, u32 frame, NNSG3dJntAnmResult *pResult);
void NNSi_G3dAnmGetTransData(int *pVal, int frame, const NNSG3dJntAnmTInfo *pInfo, const NNSG3dResJntAnm *pJntAnm);
void NNSi_G3dAnmGetTransDataEx(int *pVal, int frame, const NNSG3dJntAnmTInfo *pInfo, const NNSG3dResJntAnm *pJntAnm);
void NNSi_G3dAnmGetScaleData(fx32 *pScaleInv, fx32 fxFrame, const NNSG3dJntAnmSInfo *pData, const NNSG3dResJntAnm *pJntAnm);
void NNSi_G3dAnmGetScaleDataEx(fx32 *pScaleInv, int frame, const NNSG3dJntAnmSInfo *pInfo, const NNSG3dResJntAnm *pJntAnm);
int NNSi_G3dAnmDecodeRotKey(fx32 *pRot, const s16 *pArrayRot3, const s16 *pArrayRot9, u32 data);
u16 NNSi_G3dAnmGetMatColorData(const u8 *pRes, u32 info, u32 frameIdx);
u16 NNSi_G3dAnmGetMatAlphaData(const u8 *pRes, u32 info, u32 frameIdx);
void NNSi_G3dAnmObjInitNsBma(NNSG3dAnmObj *pAnmObj, const NNSG3dResMatAnm *pMatAnm, const NNSG3dResMdl *pMdl);
void NNSi_G3dAnmCalcNsBma(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx);
s32 NNSi_G3dAnmGetTexSRTScalarData(const void *pRes, u32 info, u32 offset, u32 frameIdx);
int NNSi_G3dAnmGetTexSRTRotData(const void *pRes, u32 info, u32 offset, u32 frameIdx);
void NNSi_G3dAnmGetTexSRTData(const NNSG3dResTexSRTAnm *pSrtAnm, u32 dataIdx, u32 frame, NNSG3dMatAnmResult *pResult);
void NNSi_G3dAnmObjInitNsBta(NNSG3dAnmObj *pAnmObj, const NNSG3dResTexSRTAnm *pSrtAnm, const NNSG3dResMdl *pMdl);
void NNSi_G3dAnmCalcNsBta(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx);
void NNSi_G3dAnmObjInitNsBtp(NNSG3dAnmObj *pAnmObj, const NNSG3dResTexPatAnm *pPatAnm, const NNSG3dResMdl *pMdl);
void NNSi_G3dAnmSetTexParam(const NNSG3dResTex *pTex, const NNSG3dResName *pName, NNSG3dMatAnmResult *pResult);
void NNSi_G3dAnmSetPlttParam(const NNSG3dResTex *pTex, const NNSG3dResName *pName, NNSG3dMatAnmResult *pResult);
void NNSi_G3dAnmCalcNsBtp(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx);
void NNSi_G3dAnmObjInitNsBva(NNSG3dAnmObj *pAnmObj, const NNSG3dResVisAnm *pVisAnm, const NNSG3dResMdl *pMdl);
void NNSi_G3dAnmCalcNsBva(NNSG3dVisAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx);
void NNSi_G3dSendJointSRTBasic(NNSG3dJntAnmResult *pResult);
void NNSi_G3dGetJointScaleBasic(NNSG3dJntAnmResult *pResult, const fx32 *pScale, const NNSG3dSbcNodeDesc *pCmd, u32 flag);
void NNSi_G3dSendJointSRTMaya(NNSG3dJntAnmResult *pResult);
void NNSi_G3dGetJointScaleMaya(NNSG3dJntAnmResult *pResult, const fx32 *pScale, const NNSG3dSbcNodeDesc *pCmd, u32 flag);
void NNSi_G3dTexMtxScaleRotTrans4x4(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult);
void NNSi_G3dTexMtxRotTrans4x4(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult);
void NNSi_G3dTexMtxScaleTrans(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult);
void NNSi_G3dTexMtxTrans(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult);
void NNSi_G3dTexMtxScaleRot4x4(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult);
void NNSi_G3dTexMtxRot4x4(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult);
void NNSi_G3dTexMtxScale4x4(MtxFx44 *pMtx, const NNSG3dMatAnmResult *pResult);
void NNSi_G3dTexMtxIdentity(MtxFx44 *pMtx);
void NNSi_G3dSendTexMtx4x4(NNSG3dMatAnmResult *pResult);
void NNSi_G3dSendJointSRTSi3d(NNSG3dJntAnmResult *pResult);
void NNSi_G3dGetJointScaleSi3d(NNSG3dJntAnmResult *pResult, const fx32 *pScale, const NNSG3dSbcNodeDesc *pCmd, u32 flag);
void NNSi_G3dSendTexMtx4x3(NNSG3dMatAnmResult *pResult);

#endif
