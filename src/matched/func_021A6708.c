/*
 * function: func_021A6708
 * address:  0x021A6708
 * packet:   pkt_021A6708
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
 *   func_021A66E4  0x021A66E4  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A66E4();

void func_021A6708(u32 a)
{
    func_021A66E4(a, 1);
}
