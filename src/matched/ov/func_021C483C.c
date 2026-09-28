/*
 * function: func_021C483C
 * address:  0x021C483C
 * packet:   pkt_021C483C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with two fields and a constant one.
 *
 * symbols:
 *   func_02050278  0x02050278  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02050278(u32 a, u32 b, u32 c);

void func_021C483C(u8 *p)
{
    func_02050278(*(u32 *)(p + 4), *(u16 *)(p + 8), 1);
}
