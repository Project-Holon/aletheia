/*
 * function: func_021D8BF8
 * address:  0x021D8BF8
 * packet:   pkt_021D8BF8
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Resolved: the ov121 region hint on the data symbol was contested by the
 * other overlays in the window; un-hinted, sole-ref/data picks the unique
 * overlay start, so the ABS32 pool relocation resolves.
 *
 * symbols:
 *   d_021DAA88  0x021DAA88  data  a4
 *
 * Addresses are Black-image addresses.
 */

extern unsigned int d_021DAA88;

void func_021D8BF8(int a, int b)
{
    *(unsigned int *)(d_021DAA88 + 0x814) = a;
    *(unsigned int *)(d_021DAA88 + 0x818) = b;
}
