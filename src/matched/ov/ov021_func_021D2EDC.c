/*
 * function: func_021D2EDC
 * address:  0x021D2EDC
 * packet:   pkt_ov021_021D2EDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021F3CFC  0x021F3CFC  thumb  ov059
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern unsigned int func_02159B10(void *a, void *b);
extern void *func_0215A5EC(void *p);
extern void *func_0216DE94(void *map, u32 id);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void *func_021F3CFC(void *a, int *v, u32 b, u32 c);
extern void func_0215897C(void *a, void *b);

u32 func_021D2EDC(u32 a, u32 b)
{
    int v[3];
    void *r7;
    void *s0;
    u32 r6;
    u32 r5;
    void *r;

    r7 = func_0215A5F4((void *)b);
    s0 = func_0215A5DC((void *)b);
    func_0201210C(s0);
    r6 = func_02159B10((void *)a, (void *)b);
    r5 = func_02159B10((void *)a, (void *)b);
    func_0216D88C((const struct Actor *)func_0216DE94(func_0215A5EC((void *)b), r6), (struct VecFx32 *)v);
    r = func_021F3CFC(s0, v, r6, r5);
    if (r == 0) {
        return 1;
    }
    func_0215897C(r7, r);
    return 1;
}
