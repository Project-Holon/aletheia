/*
 * function: func_021B05AC
 * address:  0x021B05AC
 * packet:   pkt_ov021_021B05AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159190  0x02159190  thumb  ov010
 *   func_0215A630  0x0215A630  thumb  ov010
 *   func_0202F038  0x0202F038  thumb
 *   func_0215A624  0x0215A624  thumb  ov010
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_021911B4  0x021911B4  thumb  ov021
 *   func_020056BC  0x020056BC  thumb
 *   func_0202EE30  0x0202EE30  thumb
 */

typedef unsigned int u32;

extern u32 func_0215A5DC(u32);
extern u32 func_0201210C(u32);
extern u32 func_02188C84(u32);
extern u32 func_02159B10(u32, u32);
extern u32 func_02159190(u32);
extern u32 func_0215A630(u32);
extern void func_0202F038(void *p);
extern void func_0215A624(u32, u32);
extern u32 func_0215A61C(u32);
extern u32 func_021911B4(u32);
extern u32 func_020056BC(void);
extern u32 func_0202EE30(u32, u32, u32, u32, u32);

int func_021B05AC(u32 a, u32 b)
{
    u32 r6, r4, t0;

    r6 = func_02188C84(func_0201210C(func_0215A5DC(b)));
    r4 = func_02159B10(a, b);
    if (!func_02159190(1)) {
        return 0;
    }
    t0 = func_0215A630(b);
    if (t0) {
        func_0202F038((void *)t0);
        func_0215A624(b, 0);
    }
    if (r4 == 0) {
        u32 t = func_021911B4(func_0215A61C(b));
        func_0215A624(b, func_0202EE30(func_020056BC(), t, 0xf, 0x10, r6));
    }
    return 0;
}
