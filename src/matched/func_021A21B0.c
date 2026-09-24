/*
 * function: func_021A21B0
 * address:  0x021A21B0
 * packet:   pkt_021A21B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021A273C with no argument change.
 *
 * symbols:
 *   func_021A273C  0x021A273C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A273C();

void func_021A21B0(void)
{
    func_021A273C();
}
