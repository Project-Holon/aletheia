/*
 * function: G2x_SetBlendBrightness_
 * address:  0x0207D658
 * packet:   pkt_0207D658
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      G2x_SetBlendBrightness_ (libgx.TWL.HYB.a g2.o)
 *
 * symbols:
 *   (none)
 */

typedef long fx32;
typedef long s32;
typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;
typedef volatile u16 vu16;
typedef volatile u32 vu32;

#define reg_GX_DISPSTAT (*(vu16 *)0x04000004)

void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness)
{
    if (brightness < 0) {
        *(vu16 *)addr = (u16)(plane | 0xc0);
        *(vu16 *)(addr + 4) = (u16)-brightness;
    } else {
        *(vu16 *)addr = (u16)(plane | 0x80);
        *(vu16 *)(addr + 4) = (u16)brightness;
    }
}
