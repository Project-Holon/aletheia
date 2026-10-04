/*
 * function: func_021A3050
 * address:  0x021A3050
 * packet:   pkt_021A2F48
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
 *   func_021A3920  0x021A3920  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 func_021A3920(u8 *p);

u16 func_021A3050(u8 *p)
{
    return func_021A3920((u8 *)(*(u32 *)(p + 0x4)));
}
