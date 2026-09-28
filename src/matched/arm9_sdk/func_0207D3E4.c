/*
 * function: func_0207D3E4
 * address:  0x0207D3E4
 * packet:   pkt_0207D3E4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GX_VBlankIntr  0x0207D3E4  arm
 *
 * TwlSDK libgx gx.o. Enables/disables the V-Blank interrupt and returns the
 * previous state.
 */

#define reg_GX_DISPSTAT (*(volatile unsigned short *)0x04000004)

#define REG_GX_DISPSTAT_VBI_MASK 0x0008

int func_0207D3E4(int enable)
{
    int rval = (reg_GX_DISPSTAT & REG_GX_DISPSTAT_VBI_MASK);

    if (enable)
    {
        reg_GX_DISPSTAT |= REG_GX_DISPSTAT_VBI_MASK;
    }
    else
    {
        reg_GX_DISPSTAT &= ~REG_GX_DISPSTAT_VBI_MASK;
    }
    return rval;
}
