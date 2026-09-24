/*
 * function: func_021BD1FC
 * address:  0x021BD1FC
 * packet:   pkt_021BD1FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021BD2DC with no argument change.
 *
 * symbols:
 *   func_021BD2DC  0x021BD2DC  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021BD2DC();

void func_021BD1FC(void)
{
    func_021BD2DC();
}
