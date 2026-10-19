/*
 * function: VCT_DSP_GetVoiceGateConfig
 * address:  0x021B3064
 * packet:   pkt_021B3064
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gVoiceGateConfig   0x021B3C50  data  ov013
 *   MI_CpuCopy8  0x02082D44  arm
 */

typedef unsigned char u8;

extern u8   gVoiceGateConfig[];
extern void MI_CpuCopy8(void *dst, void *src, int n);

void VCT_DSP_GetVoiceGateConfig(void *p)
{
    if (!p)
        return;
    MI_CpuCopy8(gVoiceGateConfig, p, 0x10);
}
