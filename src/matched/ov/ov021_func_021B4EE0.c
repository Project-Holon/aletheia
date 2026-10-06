/*
 * function: func_021B4EE0
 * address:  0x021B4EE0
 * packet:   pkt_ov021_021B4EE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02011290  0x02011290  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0215898C  0x0215898C  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215F8A8  0x0215F8A8  thumb  ov010
 */

typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern unsigned int func_02159B10(void *, void *);
extern void *func_0215F8A8(void *p, int a1);
struct ScriptVm;
extern void func_0215898C(int a, int b);
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);

int func_021B4EE0(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);

    func_0201210C((void *)d);
    func_0215898C((int)s, (int)func_0215F8A8(d, func_02159B10((void *)a, (void *)b)));
    func_02011290((struct ScriptVm *)a);
    return 1;
}
