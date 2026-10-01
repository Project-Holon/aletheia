/*
 * function: func_021B0130
 * address:  0x021B0130
 * packet:   pkt_ov021_021B0130
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B010C  0x021B010C  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u16 *func_02159AE8(u32 a, u32 b);
extern u32 func_0215A5F4(u32 a);
extern u32 func_0215A5DC(u32 a);
extern u32 func_021B010C(u32 a, u32 x, u16 *y);
extern void func_0215897C(u32 a, u32 b);

int func_021B0130(u32 a, u32 b)
{
    u16 *r = func_02159AE8(a, b);
    u32 x = func_0215A5F4(b);

    func_0215897C(x, func_021B010C(func_0215A5DC(b), b, r));
    return 1;
}
