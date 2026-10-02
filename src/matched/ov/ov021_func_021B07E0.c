/*
 * function: func_021B07E0
 * address:  0x021B07E0
 * packet:   pkt_ov021_021B07E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188D48  0x02188D48  thumb  ov021
 *   func_02188D4C  0x02188D4C  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(void *p);
extern int func_02188D48(void *a);
extern int func_02190728(u32 a);
extern void func_02188D4C(void *a, u32 b);

int func_021B07E0(u32 a, u32 b)
{
    void *x = func_0201210C(func_0215A5DC((void *)b));
    u32 y = func_02188D48(x);

    if (y != 0) {
        func_02190728(y);
        func_02188D4C(x, 0);
    }
    return 0;
}
