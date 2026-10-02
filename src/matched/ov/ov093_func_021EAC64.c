/*
 * function: func_021EAC64
 * address:  0x021EAC64
 * packet:   pkt_ov093_021EAC64
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

void func_021EAC64(u8 *p, u8 a, int c)
{
    func_021E9984(p, p + 0x10c, 4, a, c);
    p[0x174] = 0;
}
