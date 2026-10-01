/*
 * function: func_0219877C
 * address:  0x0219877C
 * packet:   pkt_ov021_0219877C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0219852C 0x0219852C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void func_0219852C(u8 *a, u32 b, u32 c, u32 d, u16 e, s16 f, u16 g);

int func_0219877C(u8 *a)
{
    func_0219852C(a, 2, 0x2000, 8, 3, 0, 0x200);
    return 1;
}
