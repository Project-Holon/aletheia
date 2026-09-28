/*
 * function: func_02189B28
 * address:  0x02189B28
 * packet:   pkt_02189B28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_02013B50 with no argument change.
 *
 * symbols:
 *   func_02013B50  0x02013B50  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02013B50();

void func_02189B28(void)
{
    func_02013B50();
}
