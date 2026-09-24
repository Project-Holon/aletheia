/*
 * function: func_021BC788
 * address:  0x021BC788
 * packet:   pkt_021BC788
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x2c.
 *
 * symbols:
 *   func_0204ADA4  0x0204ADA4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0204ADA4();

void func_021BC788(u8 *p)
{
    func_0204ADA4(*(u32 *)(p + 0x2c));
}
