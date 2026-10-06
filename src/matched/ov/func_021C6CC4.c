/*
 * function: func_021C6CC4
 * address:  0x021C6CC4
 * packet:   pkt_021C6CC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021C6CE4 with no argument change.
 *
 * symbols:
 *   func_021C6CE4  0x021C6CE4  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021C6CE4(u32 *p);

void func_021C6CC4(u32 *a0)
{
    func_021C6CE4(a0);
}
