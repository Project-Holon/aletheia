/*
 * function: func_021A5334
 * address:  0x021A5334
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
 *   func_021A530C  0x021A530C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021A530C(u32 a, u32 b);

void func_021A5334(u32 a)
{
    func_021A530C(a, 1);
}
