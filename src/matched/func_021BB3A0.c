/*
 * function: func_021BB3A0
 * address:  0x021BB3A0
 * packet:   pkt_021BB394
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x0.
 *
 * symbols:
 *   func_021B79AC  0x021B79AC  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021B79AC();

void func_021BB3A0(u8 *p)
{
    func_021B79AC(*(u32 *)p);
}
