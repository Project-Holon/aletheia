/*
 * function: func_021D25E8
 * address:  0x021D25E8
 * packet:   pkt_021D25E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with the leading word and a constant one.
 *
 * symbols:
 *   func_0201F7A8  0x0201F7A8  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0201F7A8(u32 v, u32 a);

void func_021D25E8(u32 *p)
{
    func_0201F7A8(p[0], 1);
}
