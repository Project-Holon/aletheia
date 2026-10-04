/*
 * function: func_021B50F8
 * address:  0x021B50F8
 * packet:   pkt_ov021_021B50F8
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
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0216E95C  0x0216E95C  thumb  ov010
 */

typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_0216E95C(void *sys, u32 arg, u32 heap);
extern void func_0215897C(void *vm, void *task);

int func_021B50F8(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);

    func_0215897C(s, func_0216E95C(d, (u32)func_0201210C((void *)d), 4));
    return 1;
}
