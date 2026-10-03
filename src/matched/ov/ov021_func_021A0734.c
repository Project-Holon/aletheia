/*
 * function: func_021A0734
 * address:  0x021A0734
 * packet:   pkt_ov021_021A0734
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A0748  0x021A0748  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void func_021A0748(u8 *a, u32 b, u32 c);

void func_021A0734(u8 *a, u32 b)
{
    *(u16 *)(a + 0x354) = b;
    func_021A0748(a, 0x3d, b);
}
