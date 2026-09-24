/*
 * function: func_021BDD34
 * address:  0x021BDD34
 * packet:   pkt_021BDD34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x54.
 *
 * symbols:
 *   func_0218FF20  0x0218FF20  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0218FF20();

void func_021BDD34(u8 *p)
{
    func_0218FF20(*(u32 *)(p + 0x54));
}
