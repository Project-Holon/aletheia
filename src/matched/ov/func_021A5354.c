/*
 * function: func_021A5354
 * address:  0x021A5354
 * packet:   pkt_021A5328
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: pins the second argument to 2.
 *
 * symbols:
 *   func_021A5304  0x021A5304  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021A5304(u32 a, u32 b);

void func_021A5354(u32 a)
{
    func_021A5304(a, 2);
}
