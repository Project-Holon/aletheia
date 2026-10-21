#ifndef GAME_ARM9_NNS_G3D_RES_H
#define GAME_ARM9_NNS_G3D_RES_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_g3d_res.c, prototypes copied from their definitions. */

#include "../arm9/nns_g3d_anm_calc_types.h"
#include "../arm9/nns_g3d_anm_calc_types.h"
#include "../types.h"

void *NNS_G3dGetResDataByName(const NNSG3dResDict *dict, const NNSG3dResName *name);
s32 NNS_G3dGetResDictIdxByName(const NNSG3dResDict *dict, const NNSG3dResName *name);
NNSG3dResMdlSet *NNS_G3dGetMdlSet(NNSG3dResFileHeader *pFile);
NNSG3dResTex *NNS_G3dGetTex(NNSG3dResFileHeader *pFile);
u8 *NNS_G3dGetAnmByIdx(u8 *pFile, u32 resIdx);
/* END mkheaders: generated region */

#endif
