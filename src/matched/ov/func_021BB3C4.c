/*
 * function: func_021BB3C4
 * address:  0x021BB3C4
 * packet:   pkt_021BB394
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x8.
 *
 * symbols:
 *   func_021BB13C  0x021BB13C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021BB13C();

void func_021BB3C4(u8 *p)
{
    func_021BB13C(*(u32 *)(p + 0x8));
}
