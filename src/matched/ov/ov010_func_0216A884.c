/*
 * function: func_0216A884
 * address:  0x0216A884
 * packet:   pkt_ov010_0216A884
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0216A8F0  0x0216A8F0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Desc;

extern void *func_0215A5E4(void *a0);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern int func_02159B10();
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int *func_020124E8(struct Desc *p);
struct Ctx;
struct Orbit;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C7C(unsigned char *p);
extern void *func_0216DE94(void *map, u32 id);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern void func_0215897C(void *vm, void *task);
extern int func_0216A8F0(void *unused, u32 *mode, struct Orbit *o);

int func_0216A884(int a0, int a1)
{
    void *l0;
    void *r4;
    int r6;
    struct Desc *r7;
    void *m;
    int *r5;

    func_0215A5E4((void *)a1);
    l0 = func_0215A5F4((void *)a1);
    r4 = func_0215A5DC((void *)a1);
    r6 = func_02159B10(a0, a1);
    r7 = func_020122C0((void *)r4, 0, (void *)func_0216A8F0, 0x14);
    r5 = func_020124E8(r7);
    r5[0] = 0;
    m = func_0216DE94((void *)func_02188C7C(func_0201210C((void *)r4)), r6);
    func_0216D88C((const struct Actor *)m, (struct VecFx32 *)(r5 + 2));
    ((void **)r5)[1] = m;
    func_0215897C(l0, r7);
    return 1;
}
