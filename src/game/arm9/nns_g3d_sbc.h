#ifndef GAME_ARM9_NNS_G3D_SBC_H
#define GAME_ARM9_NNS_G3D_SBC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_g3d_sbc.c, prototypes copied from their definitions. */

#include "../arm9/nns_g3d_anm_calc_types.h"
#include "../types.h"
#include "../arm9/nns_g3d_anm_types.h"

void NNSi_G3dSbcRun(NNSG3dRS *pRS);
void NNSi_G3dRenderObjRunSbc(NNSG3dRS *pRS, NNSG3dRenderObj *pRenderObj);
void NNSi_G3dAnmObjMarkExistMap(u32 *pExistMap, NNSG3dAnmObj *pAnmObj);
void NNS_G3dDraw(NNSG3dRenderObj *pRenderObj);
void NNSi_G3dFuncSbc_NOP(NNSG3dRS *pRS, u32 opt);
void NNSi_G3dFuncSbc_RET(NNSG3dRS *pRS, u32 opt);
void NNSi_G3dFuncSbc_NODE(NNSG3dRS *pRS);
void NNSi_G3dFuncSbc_MTX(NNSG3dRS *pRS);
void NNSi_G3dFuncSbc_MAT_InternalDefault(NNSG3dRS *pRS, u32 opt, const NNSG3dResMatData *pMatData, u32 idMat);
void NNSi_G3dFuncSbc_MAT(NNSG3dRS *pRS, u32 opt);
void NNSi_G3dFuncSbc_SHP_InternalDefault(NNSG3dRS *pRS, u32 opt, const NNSG3dResShpData *pShp, u32 idxShp);
void NNSi_G3dFuncSbc_SHP(NNSG3dRS *pRS, u32 opt);
void NNSi_G3dFuncSbc_NODEDESC(NNSG3dRS *pRS, u32 opt);
void NNSi_G3dFuncSbc_BB(NNSG3dRS *pRS, u32 opt);
void NNSi_G3dFuncSbc_BBY(NNSG3dRS *pRS, u32 opt);
void NNSi_G3dFuncSbc_NODEMIX(NNSG3dRS *pRS, u32 opt);
void NNSi_G3dFuncSbc_CALLDL(NNSG3dRS *pRS);
void NNSi_G3dFuncSbc_POSSCALE(NNSG3dRS *pRS, u32 which);
void NNSi_G3dFuncSbc_ENVMAP(NNSG3dRS *pRS, u32 opt);
void NNSi_G3dFuncSbc_PRJMAP(NNSG3dRS *pRS, u32 opt);
/* END mkheaders: generated region */

#endif
