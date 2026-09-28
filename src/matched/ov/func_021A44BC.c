/*
 * function: func_021A44BC
 * address:  0x021A44BC
 * packet:   pkt_021A44BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0xc.
 *
 * symbols:
 *   func_021A3AA0  0x021A3AA0  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A3AA0();

void func_021A44BC(u8 *p)
{
    func_021A3AA0(*(u32 *)(p + 0xc));
}
