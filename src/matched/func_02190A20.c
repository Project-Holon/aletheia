/*
 * function: func_02190A20
 * address:  0x02190A20
 * packet:   pkt_02190A20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_0201F81C with no argument change.
 *
 * symbols:
 *   func_0201F81C  0x0201F81C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0201F81C();

void func_02190A20(void)
{
    func_0201F81C();
}
