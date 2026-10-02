/*
 * function: func_021B2970
 * address:  0x021B2970
 * packet:   pkt_ov021_021B2970
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021B2EBC  0x021B2EBC  thumb  ov021
 */

typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(void *p);
extern void func_021B2EBC(u32, u32, u32, u32, u32);

int func_021B2970(u32 a, u32 b)
{
    void *d;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    func_021B2EBC(d, func_0201210C((void *)d), 0, 1, 0);
    return 0;
}
