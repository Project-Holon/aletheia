/*
 * function: func_02190270
 * address:  0x02190270
 * packet:   pkt_02190270
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: pins the second argument to 1.
 *
 * symbols:
 *   func_02192BD0  0x02192BD0  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02192BD0();

void func_02190270(u32 a)
{
    func_02192BD0(a, 1);
}
