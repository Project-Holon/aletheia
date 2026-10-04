/*
 * function: func_021A2130
 * address:  0x021A2130
 * packet:   pkt_ov021_021A2130
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A0618  0x021A0618  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A0618(u8 *p, u32 a, u32 b, u32 c);

void func_021A2130(u8 *p, u32 b, u32 c, u32 d)
{
    func_021A0618((u8 *)(*(u32 *)(p + 8)), b, c, d);
}
