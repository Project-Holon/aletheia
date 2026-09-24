/*
 * function: func_021BD140
 * address:  0x021BD140
 * packet:   pkt_021BD140
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_02013E6C with no argument change.
 *
 * symbols:
 *   func_02013E6C  0x02013E6C  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02013E6C();

void func_021BD140(void)
{
    func_02013E6C();
}
