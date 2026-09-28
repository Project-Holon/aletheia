/*
 * function: func_02190A6C
 * address:  0x02190A6C
 * packet:   pkt_02190A20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_0201F8F4 with no argument change.
 *
 * symbols:
 *   func_0201F8F4  0x0201F8F4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0201F8F4();

void func_02190A6C(void)
{
    func_0201F8F4();
}
