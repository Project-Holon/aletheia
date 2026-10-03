/*
 * function: func_021A3698
 * address:  0x021A3698
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
 *   func_021A59EC  0x021A59EC  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021A59EC(u32 p);

void func_021A3698(u8 *p)
{
    func_021A59EC(*(u32 *)(p + 0xc));
}
