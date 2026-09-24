/*
 * function: func_021A3898
 * address:  0x021A3898
 * packet:   pkt_021A3810
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x1c.
 *
 * symbols:
 *   func_0216D88C  0x0216D88C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0216D88C();

void func_021A3898(u8 *p)
{
    func_0216D88C(*(u32 *)(p + 0x1c));
}
