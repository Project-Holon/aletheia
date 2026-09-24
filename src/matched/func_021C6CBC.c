/*
 * function: func_021C6CBC
 * address:  0x021C6CBC
 * packet:   pkt_021C6CBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021C6CF4 with no argument change.
 *
 * symbols:
 *   func_021C6CF4  0x021C6CF4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021C6CF4();

void func_021C6CBC(void)
{
    func_021C6CF4();
}
