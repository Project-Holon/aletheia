/*
 * function: func_021C8CF0
 * address:  0x021C8CF0
 * packet:   pkt_021C8CF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021C8BC4 with no argument change.
 *
 * symbols:
 *   func_021C8BC4  0x021C8BC4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021C8BC4(u32 a);

int func_021C8CF0(u32 a)
{
    return func_021C8BC4(a);
}
