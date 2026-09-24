/*
 * function: func_021902A4
 * address:  0x021902A4
 * packet:   pkt_02190270
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_02192FA4 with no argument change.
 *
 * symbols:
 *   func_02192FA4  0x02192FA4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02192FA4();

void func_021902A4(void)
{
    func_02192FA4();
}
