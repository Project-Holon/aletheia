/*
 * function: func_021B2B24
 * address:  0x021B2B24
 * packet:   pkt_ov021_021B2B24
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
 *   func_021C978C  0x021C978C  thumb  ov021
 */

typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02158F50(void *p);
extern u32 func_021C978C(u32 a, u32 b, u32 c);
extern void func_0215897C(void *vm, void *task);

int func_021B2B24(u32 a, u32 b)
{
    void *d = func_0215A5DC((void *)b);
    void *s = func_0215A5F4((void *)b);
    void *w = func_0201210C((void *)d);

    func_0215897C(s, (void *)func_021C978C((u32)func_02158F50((void *)s), (u32)d, (u32)w));
    return 1;
}
