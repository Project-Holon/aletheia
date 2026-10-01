/*
 * function: func_021A01FC
 * address:  0x021A01FC
 * packet:   pkt_ov021_021A01FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A0260  0x021A0260  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void func_021A0260(u8 *p, u32 a, u32 b, u16 c, u16 d, u16 e);

void func_021A01FC(u8 *p, u32 a, u32 b, u32 c)
{
    func_021A0260(p + 0x2c, *(u32 *)(p + 4), a, p[2], b, c);
}
