/*
 * function: func_021ABABC
 * address:  0x021ABABC
 * packet:   pkt_ov021_021ABABC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_021AB760  0x021AB760  thumb
 *   func_0218E124  0x0218E124  thumb
 *   func_021ABBA0  0x021ABBA0  thumb
 *   FX_Div         0x0207C768  arm
 *   _ll_mul        0x0209C054  arm
 *   func_0218ED34  0x0218ED34  thumb
 *   func_0218ED48  0x0218ED48  thumb
 *   func_0218ED58  0x0218ED58  thumb
 *
 * 2026-10-01: DIFF (104 bytes, 2 bytes short). Push list, frame, the pool
 * zero for the rounding adcs (only with the inline LerpL) and the x, y, z
 * order match. mwcc forward-substitutes x into the first call (past the
 * _ll_mul) unless a store sits between; `d = t` after x is the only spelling
 * found that keeps x first. Left: the image keeps t in r2 (copied out of r0)
 * and copies (b - a) into r3 before each muls, and loads base before the d
 * store. Tried: product operand orders, a diff local, an M32 inline,
 * statement orders of x/y/base/z/d, x/y as u16/short/struct/array, plain
 * expressions instead of the inlines.
 */

typedef unsigned short u16;
typedef long long s64;

extern int func_021AB760(int a);
extern void func_0218E124(int h, int b);
extern void func_021ABBA0(u16 *r, void *v, int *o1, int *o2);
extern int FX_Div(int a, int b);
extern void func_0218ED34(int h, u16 v);
extern void func_0218ED48(int h, u16 v);
extern void func_0218ED58(int h, int v);

static inline int Lerp(int a, int b, int t)
{
    return a + (b - a) * t / 4096;
}

static inline int LerpL(int a, int b, int t)
{
    return a + (int)(((s64)(b - a) * t + 0x800) >> 12);
}

void func_021ABABC(int a0, u16 *p, void *q)
{
    int h = func_021AB760(a0);
    int s;
    int d;
    int t;
    int x, y, z;

    func_0218E124(h, 0);
    func_021ABBA0(p, q, &s, &d);
    t = FX_Div(d, s);
    x = Lerp(p[6], p[10], t);
    d = t;
    y = Lerp(p[7], p[11], t);
    z = LerpL(*(int *)(p + 8), *(int *)(p + 12), t);
    func_0218ED34(h, x);
    func_0218ED48(h, y);
    func_0218ED58(h, z);
}
