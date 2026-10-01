/*
 * function: func_021AF6E8
 * address:  0x021AF6E8
 * packet:   pkt_ov021_021AF6E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 func_0215A5CC(u32 a);
extern u32 func_02159B10(u32 a, u32 b);
extern u16 *func_02159AE8(u32 a, u32 b);
extern u16 func_02020FE4(u32 a, u32 b, u32 c);

int func_021AF6E8(u32 a, u32 b)
{
    u32 y = func_0215A5CC(b);
    u32 x = func_02159B10(a, b);

    *func_02159AE8(a, b) = func_02020FE4(x, 5, y);
    return 0;
}
