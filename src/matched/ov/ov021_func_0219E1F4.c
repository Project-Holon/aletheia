/*
 * function: func_0219E1F4
 * address:  0x0219E1F4
 * packet:   pkt_ov021_0219E1F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0219E084  0x0219E084  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void func_0219E084(u32, u32, u32, u32, u16, s16, u16);

int func_0219E1F4(u32 a)
{
    func_0219E084(a, 2, 0x2000, 8, 3, 0, 0x200);
    return 1;
}
