/*
 * function: VCT_SESSION_SetSendEnabled
 * address: 0x021B0CD8
 * packet: pkt_ov013_021B0CD8
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   gVctSendEnabled 0x021B3C24 data a4
 *   gVctSendState 0x021B3C84 data a4
 *   VCT_DSP_ResetVoiceGate 0x021B3018 arm ov013
 */

#include "../include/G_021B3C84.h"

extern int gVctSendEnabled;
extern struct G_021B3C84 gVctSendState;
extern void VCT_DSP_ResetVoiceGate(void);
void VCT_SESSION_SetSendEnabled(int a)
{
    gVctSendEnabled = a;
    VCT_DSP_ResetVoiceGate();
    if (a == 0) ((int *)&gVctSendState)[2] = 1;
}
