/*
 * function: func_021C7FB4
 * address:  0x021C7FB4
 * packet:   pkt_021C8000
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021C800C with no argument change.
 *
 * symbols:
 *   func_021C800C  0x021C800C  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021C800C();

void func_021C7FB4(void)
{
    func_021C800C();
}
