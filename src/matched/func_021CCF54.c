/*
 * function: func_021CCF54
 * address:  0x021CCF54
 * packet:   pkt_021CCF54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call on the word at +0xac.
 *
 * symbols:
 *   func_021909E4  0x021909E4  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021909E4(u32 v);

void func_021CCF54(u8 *p)
{
    func_021909E4(*(u32 *)(p + 0xac));
}
