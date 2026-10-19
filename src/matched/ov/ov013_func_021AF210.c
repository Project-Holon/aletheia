/*
 * function: VCT_MAIN_GetVoiceLevel
 * address: 0x021AF210
 * packet: pkt_ov013_021AF210
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gVctWork 0x021B3C80 data ov013 a4
 *   VCT_DSP_GetVoiceGateConfig 0x021B3064 arm ov013
 */

#include "../include/G_Work.h"

extern struct Work *gVctWork;
extern void VCT_DSP_GetVoiceGateConfig(void *);
int VCT_MAIN_GetVoiceLevel(void)
{
    int a[4];
    if (gVctWork != 0) {
        VCT_DSP_GetVoiceGateConfig(a);
        if (a[1] > 2) return a[0];
    }
    return 0;
}
