/*
 * function: WORLDTRADE_SetBrightnessOut
 * address:  0x021F5034
 * packet:   pkt_021F5034
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G2x_SetBlendBrightness_  0x0207D658  arm  arm9
 *

 * Pick the 0x04000050 or 0x04001050 hardware register from the flag and write the 0x1b/-7 pair.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);

void WORLDTRADE_SetBrightnessOut(u32 x)
{
    if (x != 0) {
        G2x_SetBlendBrightness_(0x04000050, 0x1b, -7);
    } else {
        G2x_SetBlendBrightness_(0x04001050, 0x1b, -7);
    }
}
