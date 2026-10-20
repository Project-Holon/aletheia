#ifndef GAME_OV013_VCT_DSP_H
#define GAME_OV013_VCT_DSP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of vct_dsp.c, prototypes copied from their definitions. */

#include "../types.h"

void VCT_DSP_ResetVoiceGate(void);
void VCT_DSP_GetVoiceGateConfig(void *config);
u32 VCT_DSP_UpdateVoiceGate(u32 energy, u32 level, u8 *levelOut);
void VCT_DSP_InitVoiceGateDefaults(void);
s32 VCT_DSP_HighPassFilter(s16 *samples, u32 length);
void VCT_DSP_InitEchoState(void);
void VCT_DSP_SetEchoReference(void *frame, u32 byteCount);
void VCT_DSP_SuppressEcho(s16 *mic, s16 *reference, u32 count, u32 threshold);
void VCT_DSP_SuppressEchoWithReference(short *mic, unsigned int byteCount, unsigned int threshold);
void VCT_DSP_MixSaturated(s16 *srcA, s16 *srcB, s16 *dst, u32 byteCount);
/* END mkheaders: generated region */

#endif
