/*
 * function: func_02198758
 * address:  0x02198758
 * packet:   pkt_ov021_02198758
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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

int func_02198758(u8 *a)
{
    func_0219852C(a, 1, 0x2000, 8, 3, 0, 0x200);
    return 1;
}
