/*
 * function: func_021B2B5C
 * address:  0x021B2B5C
 * packet:   pkt_ov021_021B2B5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02158F50  0x02158F50  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021C9828  0x021C9828  thumb  ov021
 */

typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02158F50(void *p);
extern u32 func_021C9828(u32, u32, u32);
extern void func_0215897C(void *, void *);

int func_021B2B5C(u32 a, u32 b)
{
    void *d = func_0215A5DC((void *)b);
    void *s = func_0215A5F4((void *)b);
    void *w = func_0201210C((void *)d);

    func_0215897C(s, (void *)func_021C9828((u32)func_02158F50((void *)s), (u32)d, (u32)w));
    return 1;
}
