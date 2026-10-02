/*
 * function: func_021A3920
 * address:  0x021A3920
 * packet:   pkt_021A3810
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x1c.
 *
 * symbols:
 *   func_0216D5F8  0x0216D5F8  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 func_0216D5F8(u32);

u16 func_021A3920(u8 *p)
{
    return func_0216D5F8(*(u32 *)(p + 0x1c));
}
