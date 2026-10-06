/*
 * function: func_021ABE04
 * address:  0x021ABE04
 * packet:   pkt_021ABE04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021ABFDC with no argument change.
 *
 * symbols:
 *   func_021ABFDC  0x021ABFDC  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021ABFDC();

void func_021ABE04(u32 a)
{
    func_021ABFDC();
}
