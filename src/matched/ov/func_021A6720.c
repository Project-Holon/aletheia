/*
 * function: func_021A6720
 * address:  0x021A6720
 * packet:   pkt_021A6708
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
 *   func_021A66E4  0x021A66E4  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A66E4(u32 *p, u32 v);

void func_021A6720(void *a)
{
    func_021A66E4(a, 2);
}
