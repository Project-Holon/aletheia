/*
 * function: func_021A36BC
 * address:  0x021A36BC
 * packet:   pkt_021A5A00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards the field at +0xc of the object to func_021A5A0C.
 *
 * symbols:
 *   func_021A5A0C  0x021A5A0C  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A5A0C(u32 v);

void func_021A36BC(u8 *p)
{
    func_021A5A0C(*(u32 *)(p + 0xc));
}
