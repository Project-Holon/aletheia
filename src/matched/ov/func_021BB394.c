/*
 * function: func_021BB394
 * address:  0x021BB394
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
 *   func_021B7970  0x021B7970  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021B7970();

void func_021BB394(u8 *p)
{
    func_021B7970(*(u32 *)p);
}
