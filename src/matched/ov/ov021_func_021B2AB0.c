/*
 * function: func_021B2AB0
 * address:  0x021B2AB0
 * packet:   pkt_ov021_021B2AB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02158F50  0x02158F50  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021C0AA0  0x021C0AA0  thumb  ov021
 */

typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
extern void *func_02158F50(void *p);
extern u32 func_021C0AA0(void *, void *);
extern void func_0215897C(void *, u32);

int func_021B2AB0(u32 a, u32 b)
{
    void *d = func_0215A5DC((void *)b);
    void *s = func_0215A5F4((void *)b);

    func_0215897C(s, func_021C0AA0(d, func_02158F50((void *)s)));
    return 1;
}
