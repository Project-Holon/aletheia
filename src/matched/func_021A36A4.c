/*
 * function: func_021A36A4
 * address:  0x021A36A4
 * packet:   pkt_021A368C
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
 *   func_021A5A30  0x021A5A30  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A5A30();

void func_021A36A4(u8 *p)
{
    func_021A5A30(*(u32 *)(p + 0xc));
}
