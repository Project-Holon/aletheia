#ifndef GAME_ARM9_NNS_G2D_LOAD_H
#define GAME_ARM9_NNS_G2D_LOAD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_g2d_load.c, prototypes copied from their definitions. */

struct NNSG2dBinaryFileHeader;
struct Tbl;
struct NodeRec;

#include "../types.h"
#include "../arm9/nns_g2d_anim_types.h"

BOOL NNS_G2dGetUnpackedScreenData(void *file, void **out);
void *NNS_G2dFindBinaryBlock(struct NNSG2dBinaryFileHeader *pHeader, u32 signature);
void NNSi_G2dFixupOffsets(struct Tbl *t);
void NNSi_G2dCellAnimationEdgeHandler(AnimCtrl *s);
int NNSi_G2dSetCellAnimationFrame(void *p, u32 i);
struct NodeRec *NNSi_G2dGetCellAnimationCurrentSequence(AnimCtrl *anim);
BOOL NNS_G2dTickAnimCtrl(AnimCtrl *p, fx32 frames);
int NNSi_G2dSetCellAnimationCurrentFrame(void *s, u32 i);
u16 NNSi_G2dGetCellAnimFrameIdx(const AnimCtrl *n);
int NNS_G2dInitAnimCtrl(AnimCtrl *pAnimCtrl);
void NNSi_G2dResetCellAnimationState(AnimCallBack *callBack);
/* END mkheaders: generated region */

#endif
