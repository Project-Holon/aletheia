/*
 * function: func_021BD1CC
 * address:  0x021BD1CC
 * packet:   pkt_021BD1CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021BD3BC with no argument change.
 *
 * symbols:
 *   func_021BD3BC  0x021BD3BC  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021BD3BC();

void func_021BD1CC(void)
{
    func_021BD3BC();
}
