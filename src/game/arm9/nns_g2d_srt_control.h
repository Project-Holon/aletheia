#ifndef GAME_ARM9_NNS_G2D_SRT_CONTROL_H
#define GAME_ARM9_NNS_G2D_SRT_CONTROL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_g2d_srt_control.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../arm9/nns_g2d_anim_types.h"

void NNSi_G2dSrtcInitTable(s32 *tbl);
void NNSi_G2dSrtcSetTable(s32 *tbl, u32 i, u32 v);
s32 NNSi_G2dSrtcGetTable(const s32 *tbl, u32 i);
void NNS_G2dSetSRTTranslate(SRTControl *obj, s16 x, s16 y);
void NNS_G2dSetSRTRotate(SRTControl *obj, u16 rotZ);
void NNS_G2dSetSRTScale(SRTControl *obj, u32 scaleX, u32 scaleY);
void NNSi_G2dSrtcInitControl(SRTControl *pSrtCtrl, u32 mode);
int NNSi_G2dSrtcResetSrtData(SRTControl *pSrtCtrl);
/* END mkheaders: generated region */

#endif
