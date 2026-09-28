/*
 * function: func_021A3680
 * address:  0x021A3680
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
 *   func_021A5928  0x021A5928  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A5928();

void func_021A3680(u8 *p)
{
    func_021A5928(*(u32 *)(p + 0xc));
}
