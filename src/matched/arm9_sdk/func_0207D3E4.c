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
 * sdk:      GX_VBlankIntr (gx.o)
 *
 * symbols:
 *   (none)
 */

#define reg_GX_DISPSTAT (*(volatile unsigned short *)0x04000004)

long func_0207D3E4(int enable)
{
    long rval = reg_GX_DISPSTAT & 0x8;

    if (enable) {
        reg_GX_DISPSTAT |= 0x8;
    } else {
        reg_GX_DISPSTAT &= ~0x8;
    }
    return rval;
}
