/*
 * function: func_021AA8EC
 * address:  0x021AA8EC
 * packet:   pkt_021AA8EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with the object and the word at +0x10.
 *
 * symbols:
 *   func_021AAFA0  0x021AAFA0  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021AAFA0(u8 *p, u32 v);

void func_021AA8EC(u8 *p)
{
    func_021AAFA0(p, *(u32 *)(p + 0x10));
}
