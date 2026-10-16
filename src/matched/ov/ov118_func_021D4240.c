/*
 * function: POKETRADE_DEMO_COMMON_StepFade
 * address:  0x021D4240
 * packet:   pkt_ov118_021D4240
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   _s32_div_f     0x0209C0A4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);

void POKETRADE_DEMO_COMMON_StepFade(s8 *fade)
{
    s32 value;

    if (fade == 0) {
        return;
    }
    if (fade[0] >= fade[1]) {
        fade[1]++;
        value = ((fade[3] - fade[2]) << 12) / fade[0];
        value = value * fade[1] / 4096;
        G2x_SetBlendBrightness_(0x04000050, 0x1E, value);
        G2x_SetBlendBrightness_(0x04001050, 0x1F, value);
    }
}
