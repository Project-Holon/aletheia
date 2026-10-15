/*
 * function: GX_HBlankIntr
 * address:  0x0207D3AC
 * packet:   pkt_0207D3AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GX_HBlankIntr (gx.o)
 *
 * symbols:
 *   (none)
 */

#define reg_GX_DISPSTAT (*(volatile unsigned short *)0x04000004)

long GX_HBlankIntr(int enable)
{
    long rval = reg_GX_DISPSTAT & 0x10;

    if (enable) {
        reg_GX_DISPSTAT |= 0x10;
    } else {
        reg_GX_DISPSTAT &= ~0x10;
    }
    return rval;
}
