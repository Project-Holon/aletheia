/*
 * function: func_021AA8F8
 * address:  0x021AA8F8
 * packet:   pkt_021AA8F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021AAF54 with no argument change.
 *
 * symbols:
 *   func_021AAF54  0x021AAF54  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021AAF54();

void func_021AA8F8(void)
{
    func_021AAF54();
}
