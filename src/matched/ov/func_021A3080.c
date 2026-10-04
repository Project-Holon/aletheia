/*
 * function: func_021A3080
 * address:  0x021A3080
 * packet:   pkt_021A3080
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x4.
 *
 * symbols:
 *   func_021A3968  0x021A3968  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021A3968(u32 *p);

u32 func_021A3080(u8 *p)
{
    return func_021A3968((u32 *)(*(u32 *)(p + 0x4)));
}
