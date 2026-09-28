/*
 * function: func_021A1BDC
 * address:  0x021A1BDC
 * packet:   pkt_021A1BDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021A1C34 with no argument change.
 *
 * symbols:
 *   func_021A1C34  0x021A1C34  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A1C34();

void func_021A1BDC(void)
{
    func_021A1C34();
}
