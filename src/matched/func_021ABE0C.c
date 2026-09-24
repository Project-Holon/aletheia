/*
 * function: func_021ABE0C
 * address:  0x021ABE0C
 * packet:   pkt_021ABE04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021ABFEC with no argument change.
 *
 * symbols:
 *   func_021ABFEC  0x021ABFEC  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021ABFEC();

void func_021ABE0C(void)
{
    func_021ABFEC();
}
