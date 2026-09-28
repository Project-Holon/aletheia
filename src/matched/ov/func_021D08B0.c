/*
 * function: func_021D08B0
 * address:  0x021D08B0
 * packet:   pkt_021D08B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: pins arguments 2 and 3 to 0 and 20.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02082BCC();

void func_021D08B0(u32 a)
{
    func_02082BCC(a, 0, 20);
}
