#ifndef GAME_ARM9_NNS_G2D_CELL_ANIMATION_H
#define GAME_ARM9_NNS_G2D_CELL_ANIMATION_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_g2d_cell_animation.c, prototypes copied from their definitions. */

#include "../arm9/nns_g2d_anim_types.h"
#include "../types.h"

void NNS_G2dResetCellAnimation(AnimCtrl *pAnimCtrl);
void NNS_G2dSetCellAnimationBank(CellAnim *anim, void *bank);
void NNS_G2dSetCellAnimationParam(CellAnim *anim, int type, int param, int func);
void NNS_G2dSetCellAnimationParamTagged(CellAnim *anim, u32 param, u32 func, u16 frameIdx);
s32 NNS_G2dIsCellAnimationBoundingBox(CellAnim *anim);
/* END mkheaders: generated region */

#endif
