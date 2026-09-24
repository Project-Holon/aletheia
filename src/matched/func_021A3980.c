/*
 * function: func_021A3980
 * address:  0x021A3980
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
 *   func_02012B2C  0x02012B2C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02012B2C();

void func_021A3980(u8 *p)
{
    func_02012B2C(*(u32 *)(p + 0xc));
}
