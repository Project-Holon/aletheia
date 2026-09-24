/*
 * function: func_021BD1F4
 * address:  0x021BD1F4
 * packet:   pkt_021BD1EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021BD2FC with no argument change.
 *
 * symbols:
 *   func_021BD2FC  0x021BD2FC  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021BD2FC();

void func_021BD1F4(void)
{
    func_021BD2FC();
}
