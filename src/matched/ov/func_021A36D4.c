/*
 * function: func_021A36D4
 * address:  0x021A36D4
 * packet:   pkt_021A5A00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards the field at +0xc of the object to func_021A5A24.
 *
 * symbols:
 *   func_021A5A24  0x021A5A24  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A5A24(u32 v);

void func_021A36D4(u8 *p)
{
    func_021A5A24(*(u32 *)(p + 0xc));
}
