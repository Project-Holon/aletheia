/*
 * function: func_0219E418
 * address:  0x0219E418
 * packet:   pkt_0219E418
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: pins the third argument to 0.
 *
 * symbols:
 *   func_0219E424  0x0219E424  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0219E424(u32 o, u32 k, u32 x);

void func_0219E418(u32 a, u32 b)
{
    func_0219E424(a, b, 0);
}
