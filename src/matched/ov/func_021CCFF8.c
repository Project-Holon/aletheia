/*
 * function: func_021CCFF8
 * address:  0x021CCFF8
 * packet:   pkt_021CCFF8
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
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02190EF0(u32 *p);

void func_021CCFF8(u8 *p)
{
    func_02190EF0((u32 *)(*(u32 *)(p + 0xb0)));
}
