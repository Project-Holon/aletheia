/*
 * function: func_021AF0F8
 * address:  0x021AF0F8
 * packet:   pkt_ov021_021AF0F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159144  0x02159144  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern u32 func_02159B10(u32 a, u32 b);
extern u32 func_020295A4(u32 a, u32 b);
extern void func_0215897C(u32 a, u32 b);
extern void func_02159144(u32 a);

int func_021AF0F8(u32 a, u32 b)
{
    void *y = func_0215A5DC((void *)b);
    void *x = func_0215A5F4((void *)b);

    func_0215897C(x, func_020295A4(y, func_02159B10(a, b)));
    func_02159144(10);
    return 1;
}
