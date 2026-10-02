/*
 * function: func_021B5094
 * address:  0x021B5094
 * packet:   pkt_ov021_021B5094
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021BE92C  0x021BE92C  thumb  ov021
 */

typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(void *p);
extern u32 func_021BE92C(u32, u32, u32, u32, u32, u32, u32);
extern void func_0215897C(u32, u32);

int func_021B5094(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);

    func_0215897C(s, func_021BE92C(d, func_0201210C((void *)d), 0, 0, 1, 0, 0));
    return 1;
}
