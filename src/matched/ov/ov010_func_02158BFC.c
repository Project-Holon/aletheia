/*
 * function: func_02158BFC
 * address:  0x02158BFC
 * packet:   pkt_ov010_02158BFC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02158DB0  0x02158DB0  thumb  ov010
 *   func_0215A55C  0x0215A55C  thumb  ov010
 *   func_0201121C  0x0201121C  thumb
 *   func_0201126C  0x0201126C  thumb
 *   func_02158CD0  0x02158CD0  thumb  ov010
 *   func_02158D78  0x02158D78  thumb  ov010
 *   func_0215A760  0x0215A760  thumb  ov010
 *   func_0201127C  0x0201127C  thumb
 *   func_0201134C  0x0201134C  thumb
 *   func_02158E38  0x02158E38  thumb  ov010
 *   d_0217062C     0x0217062C  data  ov010
 *   d_021705D8     0x021705D8  data  ov010
 */

typedef unsigned short u16;

struct V { u16 x, y; int a; int b; int c; };
struct W { u16 w, h; int p; int q; };

extern int func_02158DB0(int);
extern int func_0215A55C(const struct V *, int);
extern int *func_0201121C(int, struct W *);
extern void func_0201126C(int *, int);
extern int func_02158CD0(int, int, u16 *, u16 *, u16 *);
extern int func_02158D78(int, int);
extern void func_0215A760(int, unsigned, unsigned);
extern void func_0201127C(int *, int);
extern int func_0201134C(int *);
extern void func_02158E38(void *a);
extern int d_0217062C;
extern int d_021705D8;

int *func_02158BFC(u16 a0, int a1, u16 a2, u16 a3, int a4)
{
    struct V v;
    struct W w;
    u16 s[4];
    int r6, t, n;
    int *o;

    r6 = func_02158DB0(a4);
    v.x = a2;
    v.y = a3;
    v.a = a4;
    v.b = r6;
    v.c = a1;
    t = func_0215A55C(&v, a0);
    w.w = 0x100;
    w.h = 0x40;
    w.p = (int)&d_0217062C;
    w.q = d_021705D8;
    o = func_0201121C(a0, &w);
    func_0201126C(o, t);
    n = func_02158CD0(a2, a3, &s[2], &s[1], &s[0]);
    o[0x2C / 4] = func_02158D78(s[2], a0);
    if (r6 == 0) {
        if (s[0] != -1)
            func_0215A760(t, s[1], s[0]);
    }
    func_0201127C(o, o[0x2C / 4]);
    o[0x14 / 4] += n << 2;
    o[0x14 / 4] += func_0201134C(o);
    func_02158E38(o);
    return o;
}
