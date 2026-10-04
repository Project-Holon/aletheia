/*
 * function: func_021D2F6C
 * address:  0x021D2F6C
 * packet:   pkt_ov021_021D2F6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021F3970  0x021F3970  thumb  ov064
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern unsigned int func_02159B10(void *a, void *b);
extern void *func_02188C7C(unsigned char *p);
extern void *func_0216DE94(void *map, u32 id);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void *func_021F3970(void *a, int *v, int *w, int c, int d);
extern void func_0215897C(void *a, void *b);

u32 func_021D2F6C(u32 a, u32 b)
{
    int v[3];
    int w[3];
    void *s10;
    void *sc;
    void *s14;
    int s18;
    int s8;
    int s4;
    int r7;
    int r6;
    int r4;
    void *r;

    s10 = func_0215A5F4((void *)b);
    sc = func_0215A5DC((void *)b);
    s14 = func_0201210C(sc);
    s18 = (int)func_02159B10((void *)a, (void *)b);
    s8 = (int)func_02159B10((void *)a, (void *)b);
    s4 = (int)func_02159B10((void *)a, (void *)b);
    r7 = (int)func_02159B10((void *)a, (void *)b);
    r6 = (int)func_02159B10((void *)a, (void *)b);
    r4 = (int)func_02159B10((void *)a, (void *)b);
    r = func_0216DE94(func_02188C7C((void *)s14), s18);
    if (r != 0) {
        func_0216D88C(r, (struct VecFx32 *)v);
    }
    w[0] = (s8 << 16) + 0x8000;
    w[1] = s4 << 15;
    w[2] = (r7 << 16) + 0x8000;
    r = func_021F3970(sc, v, w, r6 << 15, r4);
    if (r == 0) {
        return 1;
    }
    func_0215897C(s10, r);
    return 1;
}
