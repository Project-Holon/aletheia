/*
 * function: func_021A3674
 * address:  0x021A3674
 * packet:   pkt_021A3674
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
 *   func_021A596C  0x021A596C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A596C();

void func_021A3674(u8 *p)
{
    func_021A596C(*(u32 *)(p + 0xc));
}
