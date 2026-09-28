/*
 * function: func_0207D55C
 * address:  0x0207D55C
 * packet:   pkt_0207D55C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GXx_GetMasterBrightness_ (libgx.TWL.HYB.a gx.o)
 *
 * symbols:
 *   (none)
 */

typedef unsigned short u16;
typedef volatile u16 vu16;

int func_0207D55C(vu16 *reg)
{
    u16 mode = (u16)(*reg & 0xC000);

    if (mode == 0)
    {
        return 0;
    }
    else if (mode == 0x4000)
    {
        return *reg & 0x1F;
    }
    else if (mode == 0x8000)
    {
        return -(*reg & 0x1F);
    }
    return 0;
}
