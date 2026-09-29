/*
 * function: func_021CE724
 * address:  0x021CE724
 * packet:   pkt_ov021_021CE724
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (a `.word` run in the listing); filed as the witness for
 * the tail-call stub func_021CF2E4 in ov021_func_021CF288.c.
 *
 * symbols:
 *   func_0203D7BC  0x0203D7BC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

extern void func_0203D7BC(u8 a);

void func_021CE724(u8 *p)
{
    p[0x576] = 1;
    p[0x577] = 1;
    func_0203D7BC(1);
}
