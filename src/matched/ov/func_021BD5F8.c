/*
 * function: func_021BD5F8
 * address:  0x021BD5F8
 * packet:   pkt_021BD5F8
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
 *   func_02025774  0x02025774  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02025774();

void func_021BD5F8(u8 *p)
{
    func_02025774(*(u32 *)(p + 0xc));
}
