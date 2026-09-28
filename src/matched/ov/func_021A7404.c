/*
 * function: func_021A7404
 * address:  0x021A7404
 * packet:   pkt_021A74F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards p + 8 to func_021A74F4.
 *
 * symbols:
 *   func_021A74F4  0x021A74F4  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A74F4(u8 *p);

void func_021A7404(u8 *p)
{
    func_021A74F4(p + 8);
}
