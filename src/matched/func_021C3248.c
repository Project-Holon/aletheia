/*
 * function: func_021C3248
 * address:  0x021C3248
 * packet:   pkt_021C31FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_0201B9F0 with no argument change.
 *
 * symbols:
 *   func_0201B9F0  0x0201B9F0  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0201B9F0();

void func_021C3248(void)
{
    func_0201B9F0();
}
