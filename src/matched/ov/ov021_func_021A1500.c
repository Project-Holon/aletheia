/*
 * function: func_021A1500
 * address:  0x021A1500
 * packet:   pkt_ov021_021A1500
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EFF5C  0x021EFF5C  thumb  ov034
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void func_021EFF5C(u32);

void func_021A1500(u32 *p)
{
    func_021EFF5C(p[8]);
}
