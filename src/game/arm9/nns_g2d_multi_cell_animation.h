#ifndef GAME_ARM9_NNS_G2D_MULTI_CELL_ANIMATION_H
#define GAME_ARM9_NNS_G2D_MULTI_CELL_ANIMATION_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_g2d_multi_cell_animation.c, prototypes copied from their definitions. */

struct AnimBank;

#include "../arm9/nns_g2d_anim_types.h"
#include "../types.h"

void NNSi_G2dInitMCNode(Node *pNode, u32 type);
void NNSi_G2dRefreshCellAnimation(CellAnim *pCellAnim);
void NNS_G2dInitCellAnimation(CellAnim *pCellAnim, const AnimSequenceData *pAnimSeq, CellDataBank *pCellDataBank);
void NNS_G2dInitCellAnimationVramTransfered(CellAnim *pCellAnim, const AnimSequenceData *pAnimSeq, CellDataBank *pCellDataBank, u32 stateIdx, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
void NNS_G2dSetCellAnimationSequence(CellAnim *pCellAnim, const AnimSequenceData *pAnimSeq);
void NNS_G2dTickCellAnimation(CellAnim *pCellAnim, fx32 frames);
void NNS_G2dSetCellAnimationCurrentFrame(CellAnim *pCellAnim, u32 frameIdx);
void NNS_G2dRestartCellAnimation(CellAnim *pCellAnim);
void NNS_G2dSetCellAnimationSpeed(CellAnim *pCellAnim, fx32 speed);
void NNSi_G2dSetMCDataToMCInstanceImpl(MCInstance *pMCInst, const MultiCellData *pMcData, u16 mcTotalFrame);
u16 NNS_G2dGetMCBankNumCellAnimRequired(MultiCellBank *pBank);
void NNS_G2dSetAnimSequenceToMCAnimation(MultiCellAnim *pMCAnim, const AnimSequenceData *pAnimSeq);
void NNS_G2dInitMCAnimation(MultiCellAnim *pMCAnim, void *pBuf, const struct AnimBank *pAnimBank, CellDataBank *pCellDataBank, MultiCellBank *pBank, int kind);
int NNS_G2dGetMCWorkAreaSize(MultiCellBank *pBank, u32 kind);
u16 NNS_G2dGetMCBankNumNodesRequired(MultiCellBank *pBank);
void NNSi_G2dTickMCInstance(MCInstance *pMCInst, fx32 frames);
void NNS_G2dTickMCAnimation(MultiCellAnim *pMCAnim, fx32 frames);
void NNS_G2dSetMCAnimationCurrentFrame(MultiCellAnim *pMCAnim, u32 frameIdx);
void NNS_G2dSetMCAnimationSpeed(MultiCellAnim *pMCAnim, fx32 speed);
void NNSi_G2dSetMCInstanceCurrentFrameZero(MCInstance *pMCInst);
void NNS_G2dRestartMCAnimation(MultiCellAnim *pMCAnim);
/* END mkheaders: generated region */

#endif
