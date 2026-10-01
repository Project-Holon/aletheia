/*
 * function: func_02199C50
 * address:  0x02199C50
 * packet:   pkt_ov021_02199C50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02199888  0x02199888  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_02199888(u32 a, int b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h, u8 i);

int func_02199C50(u32 a)
{
    func_02199888(a, -0x2000, 0, 1, 8, 3, 2, 1, 0);
    return 1;
}
