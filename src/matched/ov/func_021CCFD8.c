/*
 * function: func_021CCFD8
 * address:  0x021CCFD8
 * packet:   pkt_021CCFD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call on the word at +0xb0.
 *
 * symbols:
 *   func_02190E40  0x02190E40  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_02190E40(u32 a);

void func_021CCFD8(u8 *p)
{
    func_02190E40(*(u32 *)(p + 0xb0));
}
