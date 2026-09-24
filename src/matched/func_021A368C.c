/*
 * function: func_021A368C
 * address:  0x021A368C
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
 *   func_021A5964  0x021A5964  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A5964();

void func_021A368C(u8 *p)
{
    func_021A5964(*(u32 *)(p + 0xc));
}
