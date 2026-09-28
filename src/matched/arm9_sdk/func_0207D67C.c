/*
 * function: func_0207D67C
 * address:  0x0207D67C
 * packet:   pkt_0207D67C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      G2x_SetBlendBrightnessExt_ (libgx.TWL.HYB.a g2.o)
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

void func_0207D67C(u32 addr, int plane1, int plane2, int ev1, int ev2, int brightness)
{
    *(vu16 *)(addr + 2) = (u16)(ev1 | (ev2 << 8));
    if (brightness < 0) {
        *(vu16 *)addr = (u16)(plane1 | 0xc0 | (plane2 << 8));
        *(vu16 *)(addr + 4) = (u16)-brightness;
    } else {
        *(vu16 *)addr = (u16)(plane1 | 0x80 | (plane2 << 8));
        *(vu16 *)(addr + 4) = (u16)brightness;
    }
}
