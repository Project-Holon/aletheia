/*
 * function: func_021BC7B0
 * address:  0x021BC7B0
 * packet:   pkt_021BC788
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x34.
 *
 * symbols:
 *   func_0204B1CC  0x0204B1CC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0204B1CC();

void func_021BC7B0(u8 *p)
{
    func_0204B1CC(*(u32 *)(p + 0x34));
}
