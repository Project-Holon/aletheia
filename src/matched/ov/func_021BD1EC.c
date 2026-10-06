/*
 * function: func_021BD1EC
 * address:  0x021BD1EC
 * packet:   pkt_021BD1EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021BD2F4 with no argument change.
 *
 * symbols:
 *   func_021BD2F4  0x021BD2F4  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 func_021BD2F4(u8 *p);

int func_021BD1EC(u8 *a0)
{
    return func_021BD2F4(a0);
}
