/*
 * function: func_021A063C
 * address:  0x021A063C
 * packet:   pkt_ov021_021A063C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A0C60  0x021A0C60  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void func_021A0C60(u16 *p, u16 a, u16 b);

void func_021A063C(u8 *p, u16 a, u32 b)
{
    func_021A0C60((u16 *)(p + 0x484), b, a);
    *(u16 *)p = 1;
}
