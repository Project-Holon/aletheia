/*
 * function: func_021A25CC
 * address:  0x021A25CC
 * packet:   pkt_021A25CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with the object displaced by 0x40 and the word at +0xc.
 *
 * symbols:
 *   func_021A2C6C  0x021A2C6C  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A2C6C(u8 *p, u32 v);

void func_021A25CC(u8 *p)
{
    func_021A2C6C(p + 0x40, *(u32 *)(p + 0xc));
}
