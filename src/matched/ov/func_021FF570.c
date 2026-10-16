/*
 * function: WORLDTRADE_SEARCH_SetBlendEffect
 * address:  0x021FF570
 * packet:   pkt_021FF570
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

 * Program the 0x04000050 display register from the flag, or clear it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);

void WORLDTRADE_SEARCH_SetBlendEffect(u32 v)
{
    if (v != 0) {
        G2x_SetBlendBrightness_(0x04000050, 0xa, v);
    } else {
        *(u16 *)0x04000050 = 0;
    }
}
