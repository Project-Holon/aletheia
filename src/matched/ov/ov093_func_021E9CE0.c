/*
 * function: func_021E9CE0
 * address:  0x021E9CE0
 * packet:   pkt_ov093_021E9CE0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E9984  0x021E9984  thumb  ov093
 */
typedef unsigned char u8;

extern void func_021E9984(u8 *p, u8 *q, int mode, u8 x, int y);

void func_021E9CE0(u8 *p, u8 a, u8 b)
{
    func_021E9984(p, p + 0x10c, 5, a, 0);
    p[0x157] = b;
    p[0x174] = 0;
}
