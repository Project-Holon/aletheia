/*
 * function: func_021A36B0
 * address:  0x021A36B0
 * packet:   pkt_021A5A00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards the field at +0xc of the object to func_021A5A00.
 *
 * symbols:
 *   func_021A5A00  0x021A5A00  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A5A00(u8 *p, void *r);

void func_021A36B0(u8 *p, void *r)
{
    func_021A5A00(*(u8 **)(p + 0xc), r);
}
