/*
 * function: func_0207D3AC
 * address:  0x0207D3AC
 * packet:   pkt_0207D3AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GX_HBlankIntr  0x0207D3AC  arm
 *
 * TwlSDK libgx gx.o. Enables/disables the H-Blank interrupt and returns the
 * previous state.
 */

#define reg_GX_DISPSTAT (*(volatile unsigned short *)0x04000004)

#define REG_GX_DISPSTAT_HBI_MASK 0x0010

int func_0207D3AC(int enable)
{
    int rval = (reg_GX_DISPSTAT & REG_GX_DISPSTAT_HBI_MASK);

    if (enable)
    {
        reg_GX_DISPSTAT |= REG_GX_DISPSTAT_HBI_MASK;
    }
    else
    {
        reg_GX_DISPSTAT &= ~REG_GX_DISPSTAT_HBI_MASK;
    }
    return rval;
}
