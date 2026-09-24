/*
 * function: func_021C8A74
 * address:  0x021C8A74
 * packet:   pkt_021C8A74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021C89A8 with no argument change.
 *
 * symbols:
 *   func_021C89A8  0x021C89A8  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021C89A8();

void func_021C8A74(void)
{
    func_021C89A8();
}
