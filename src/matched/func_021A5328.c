/*
 * function: func_021A5328
 * address:  0x021A5328
 * packet:   pkt_021A5328
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
 *   func_021A5304  0x021A5304  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A5304();

void func_021A5328(u32 a)
{
    func_021A5304(a, 1);
}
