/*
 * function: func_021A3974
 * address:  0x021A3974
 * packet:   pkt_021A3810
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
 *   func_02012B28  0x02012B28  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02012B28();

void func_021A3974(u8 *p)
{
    func_02012B28(*(u32 *)(p + 0xc));
}
