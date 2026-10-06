/*
 * function: func_0219E938
 * address:  0x0219E938
 * packet:   pkt_0219E938
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_0201441C with no argument change.
 *
 * symbols:
 *   func_0201441C  0x0201441C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 func_0201441C(int i);

u32 func_0219E938(int a0)
{
    return func_0201441C(a0);
}
