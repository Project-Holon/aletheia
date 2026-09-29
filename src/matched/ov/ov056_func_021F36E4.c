/*
 * function: func_021F36E4
 * address:  0x021F36E4
 * packet:   pkt_ov056_021F36E4
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call leaf: forwards the second argument plus 0x3c.
 *
 * symbols:
 *   func_021F3D2C  0x021F3D2C  thumb  ov056
 */

typedef unsigned char u8;

extern void func_021F3D2C(u8 *p);

void func_021F36E4(u8 *a, u8 *b)
{
    func_021F3D2C(b + 0x3c);
}
