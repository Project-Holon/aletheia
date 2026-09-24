/*
 * function: func_021C8E5C
 * address:  0x021C8E5C
 * packet:   pkt_021C8E5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x24.
 *
 * symbols:
 *   func_020061F8  0x020061F8  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020061F8();

void func_021C8E5C(u8 *p)
{
    func_020061F8(*(u32 *)(p + 0x24));
}
