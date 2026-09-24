/*
 * function: func_021A6BAC
 * address:  0x021A6BAC
 * packet:   pkt_021A6BAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021A6B88 with no argument change.
 *
 * symbols:
 *   func_021A6B88  0x021A6B88  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A6B88();

void func_021A6BAC(void)
{
    func_021A6B88();
}
