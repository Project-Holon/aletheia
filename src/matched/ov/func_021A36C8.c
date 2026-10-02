/*
 * function: func_021A36C8
 * address:  0x021A36C8
 * packet:   pkt_021A5A00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards the field at +0xc of the object to func_021A5A18.
 *
 * symbols:
 *   func_021A5A18  0x021A5A18  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021A5A18(u8 *p, u32 k, void *buf);

int func_021A36C8(u8 *p, u32 k, void *buf)
{
    return func_021A5A18(*(u8 **)(p + 0xc), k, buf);
}
