/*
 * function: func_021A6750
 * address:  0x021A6750
 * packet:   pkt_021A6708
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: pins the second argument to 8.
 *
 * symbols:
 *   func_021A66EC  0x021A66EC  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A66EC();

void func_021A6750(u32 a)
{
    func_021A66EC(a, 8);
}
