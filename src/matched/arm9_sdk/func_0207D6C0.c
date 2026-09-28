/*
 * function: func_0207D6C0
 * address:  0x0207D6C0
 * packet:   pkt_0207D6C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      G2x_ChangeBlendBrightness_ (libgx.TWL.HYB.a g2.o)
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

void func_0207D6C0(u32 addr, int brightness)
{
    u16 tmp = *(vu16 *)addr;

    if (brightness < 0) {
        if ((tmp & 0xc0) == 0x80) {
            *(vu16 *)addr = (u16)((tmp & ~0xc0) | 0xc0);
        }
        *(vu16 *)(addr + 4) = (u16)-brightness;
    } else {
        if ((tmp & 0xc0) == 0xc0) {
            *(vu16 *)addr = (u16)((tmp & ~0xc0) | 0x80);
        }
        *(vu16 *)(addr + 4) = (u16)brightness;
    }
}
