/*
 * function: VCT_DSP_InitVoiceGateDefaults
 * address: 0x021B3250
 * packet: pkt_ov013_021B3250
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * lever: enum count cast to short preserves the smulbb; short local folded 15*68.
 * symbols:
 *   gVoiceGateConfig 0x021B3C50 data a4
 *   VCT_DSP_ResetVoiceGate 0x021B3018 arm ov013
 */

#include "../include/G_VadCfg.h"

extern struct VadCfg gVoiceGateConfig;
extern void VCT_DSP_ResetVoiceGate(void);
typedef enum { CountZero } Count;
void VCT_DSP_InitVoiceGateDefaults(void)
{
    Count n=15;
    short stride=68;
    ((int *)&gVoiceGateConfig)[2]=n;
    ((int *)&gVoiceGateConfig)[3]=(short)n*stride;
    VCT_DSP_ResetVoiceGate();
}
