/*
 * function: func_021B2FB0
 * address:  0x021B2FB0
 * packet:   pkt_ov021_021B2FB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC5A0  0x021BC5A0  thumb  ov021
 */

typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(void *p);
extern u32 func_02188D20(void *);
extern u32 func_02188C9C(void *);
extern void func_021BC5A0(u32, u32);

int func_021B2FB0(u32 a, u32 b)
{
    void *w = func_0201210C(func_0215A5DC((void *)b));
    u32 x = func_02188D20(w);

    func_021BC5A0(x, func_02188C9C(w));
    return 0;
}
