/*
 * function: func_021BD204
 * address:  0x021BD204
 * packet:   pkt_021BD204
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021BD2E8 with no argument change.
 *
 * symbols:
 *   func_021BD2E8  0x021BD2E8  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021BD2E8(u32 *p);

void func_021BD204(u32 *a0)
{
    func_021BD2E8(a0);
}
