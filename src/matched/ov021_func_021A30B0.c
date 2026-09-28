/*
 * function: func_021A30B0
 * address:  0x021A30B0
 * packet:   pkt_ov021_021A30B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Forwards the +4 member to 0x021A398C (unlabelled start).
 *
 * symbols:
 *   func_021A398C  0x021A398C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A398C(u32 a);

void func_021A30B0(u8 *p)
{
    func_021A398C(*(u32 *)(p + 4));
}
