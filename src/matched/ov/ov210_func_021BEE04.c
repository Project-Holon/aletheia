/*
 * function: func_021BEE04
 * address:  0x021BEE04
 * packet:   pkt_ov210_021BEE04
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 * Addresses are Black-image addresses.
 */

extern void func_0204B3F4(int h);

void func_021BEE04(int p, int i)
{
    func_0204B3F4(((int *)(p + i * 4))[0xa]);
}
