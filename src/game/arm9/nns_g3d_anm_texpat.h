#ifndef GAME_ARM9_NNS_G3D_ANM_TEXPAT_H
#define GAME_ARM9_NNS_G3D_ANM_TEXPAT_H

typedef struct NNSG3dResTexPatAnmTrack NNSG3dResTexPatAnmTrack;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_g3d_anm_texpat.c, prototypes copied from their definitions. */

struct NNSG3dResTexPatAnmTrack;
typedef struct NNSG3dResTexPatAnmTrack NNSG3dResTexPatAnmTrack;

#include "../arm9/nns_g3d_anm_calc_types.h"
#include "../arm9/nns_g3d_anm_calc_types.h"
#include "../types.h"

const NNSG3dResName *NNSi_G3dGetTexPatAnmTexNameByIdx(const NNSG3dResTexPatAnm *pPatAnm, u8 texIdx);
const NNSG3dResName *NNSi_G3dGetTexPatAnmPlttNameByIdx(const NNSG3dResTexPatAnm *pPatAnm, u8 plttIdx);
const NNSG3dResTexPatAnmFV *NNSi_G3dTexPatAnmGetFrameValue(const NNSG3dResTexPatAnm *pPatAnm, u32 dataIdx, u32 frame);
const NNSG3dResTexPatAnmTrack *NNSi_G3dTexPatAnmGetTrackByIdx(const NNSG3dResTexPatAnm *pPatAnm, u32 dataIdx);
/* END mkheaders: generated region */

#endif
