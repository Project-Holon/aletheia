/*
 * function: func_0207D534
 * address:  0x0207D534
 * packet:   pkt_0207D534
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GXx_SetMasterBrightness_ (libgx.TWL.HYB.a gx.o)
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

void func_0207D534(vu16 *reg, int brightness)
{
    if (brightness == 0) {
        *reg = 0;
    } else if (brightness > 0) {
        *reg = (u16)(0x4000 | brightness);
    } else {
        *reg = (u16)(0x8000 | -brightness);
    }
}
