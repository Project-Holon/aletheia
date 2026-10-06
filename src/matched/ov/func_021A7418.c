/*
 * function: func_021A7418
 * address:  0x021A7418
 * packet:   pkt_021A7418
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021A75B0 with no argument change.
 *
 * symbols:
 *   func_021A75B0  0x021A75B0  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A75B0(u32 *p);

void func_021A7418(void *p)
{
    func_021A75B0(p);
}
