/*
 * function: func_021BEE80
 * address:  0x021BEE80
 * packet:   pkt_ov210_021BEE80
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B84C 0x0204B84C arm
 * Addresses are Black-image addresses.
 */

extern void func_0204B84C(int h, unsigned v);

void func_021BEE80(int p, int i, unsigned v)
{
    func_0204B84C(((int *)(p + i * 4))[0xa], (unsigned char)v);
}
