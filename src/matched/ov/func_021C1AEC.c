/*
 * function: func_021C1AEC
 * address:  0x021C1AEC
 * packet:   pkt_021C1AEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_02050BE8 with no argument change.
 *
 * symbols:
 *   func_02050BE8  0x02050BE8  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02050BE8();

void func_021C1AEC(void)
{
    func_02050BE8();
}
