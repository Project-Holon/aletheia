/*
 * function: func_021BD1DC
 * address:  0x021BD1DC
 * packet:   pkt_021BD1CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021BD308 with no argument change.
 *
 * symbols:
 *   func_021BD308  0x021BD308  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021BD308(u8 *p);

int func_021BD1DC(u8 *a0)
{
    return func_021BD308(a0);
}
