/*
 * function: func_021C7FAC
 * address:  0x021C7FAC
 * packet:   pkt_021C8000
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021C8000 with no argument change.
 *
 * symbols:
 *   func_021C8000  0x021C8000  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021C8000(u8 *p);

void func_021C7FAC(u32 a)
{
    func_021C8000((u8 *)a);
}
