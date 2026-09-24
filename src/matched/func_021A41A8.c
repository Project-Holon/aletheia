/*
 * function: func_021A41A8
 * address:  0x021A41A8
 * packet:   pkt_021A41A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020307B0();

void func_021A41A8(void)
{
    func_020307B0();
}
