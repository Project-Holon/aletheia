/*
 * file:     fldeff_namipoke_p04.c
 * unit:     yes
 * function: func_021AD7A0, func_021AD7B4, func_021AD7E4, func_021AD82C, func_021AD8A4, func_021AD8DC, func_021AD96C, func_021ADA1C, func_021ADAAC, func_021ADB4C, func_021ADB5C, func_021ADB6C, func_021ADBAC, func_021ADBB0, func_021ADC04
 * address:  0x021AD7A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   d_021DE0E8  0x021DE0E8  data
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   d_021DE094     0x021DE094  data  a2
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_021ABE28  0x021ABE28  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_021ABE2C  0x021ABE2C  thumb  ov021
 *   func_02046EFC  0x02046EFC  arm
 *   func_020470D0  0x020470D0  arm
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D9238     0x021D9238  data  a1
 *   d_021D9240     0x021D9240  data  a4
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021AC1A0  0x021AC1A0  thumb  ov021
 *   func_021AC178  0x021AC178  thumb  ov021
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_02047910  0x02047910  arm
 *   func_02047828  0x02047828  arm
 *   func_021AAA4C  0x021AAA4C  thumb  ov021
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_02012A30  0x02012A30  thumb
 *   func_02028ACC  0x02028ACC  thumb
 *   d_021D9234     0x021D9234  data   a1
 */
#include "../../matched/include/Obj05043.h"
#include "../../matched/include/Obj12797.h"
#include "../../matched/include/Obj19888.h"

#define R(a) ((Rec *)((char *)(a) + 0x88))
struct Q;
struct Desc;
struct P;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Rec;
struct A;
struct B;
struct W;
struct Z;
struct Tagged;
struct AnmCtl;
struct SoundSys2;
struct Self;
struct BigObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct P { u32 f0; } P;

typedef struct Rec {
    u16 h[7];
} Rec;

typedef struct A {
    u32 f0;
    u32 f4[4];
    u32 f14;
} A;

typedef struct B {
    u8 pad0[8];
    u32 f8[4];
    u32 f18[28];
    u8 f88;
} B;

typedef struct Z { u32 f0; u32 arr[4]; u32 f14; } Z;

typedef struct W { u8 pad[0x88]; u8 n; } W;

typedef struct Desc_021AD8DC {
    u8 n;
    u8 lo : 3;
    u8 mid : 3;
    u8 b6 : 1;
    u8 b7 : 1;
    u16 pad2;
    u16 h4;
    u16 h6;
} Desc_021AD8DC;

typedef struct P_021AD8DC {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
} P_021AD8DC;

typedef struct Desc_021AD96C {
    u8 n;
    u8 lo : 3;
    u8 mid : 3;
    u8 b6 : 1;
    u8 b7 : 1;
    u16 pad2;
    u16 h4;
    u16 tab[1];
} Desc_021AD96C;

typedef struct P_021AD96C {
    int f0;
    int f4;
    int f8[4];
    int f18[1];
} P_021AD96C;

typedef struct Q {
    int f0;
    int f4;
    int f8[4];
    int f18[28];
    u8 n;
    u8 cnt : 3;
} Q;

typedef struct L {
    int f0;
    int f4;
    void *f8;
    int fc;
    u16 h10;
    u16 h12;
    int f14;
    u8 b18;
    u8 pad19[3];
    int f1c;
    int f20;
    int f24;
} L;

typedef struct S40 {
    int w[10];
} S40;

typedef struct Dst {
    u16 h0;
    u16 pad2;
    S40 s4;
    int pad2c[2];
    int f34;
} Dst;

extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021ABE24(u8 *p);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void func_0204762C(struct Rec *p);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern u8 func_021ABE28(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern int func_02046FF8(int *self);
extern u8 func_021ABE2C(u8 *p);
extern void func_02046EFC(struct Tagged *p);
extern int func_020470D0(u32 *p);
extern unsigned int func_021ABE14(u8 *p);
extern unsigned int func_02188CFC(u8 *p);
extern int func_021ABEA0(u32 a, u32 b);
extern void *func_02082BCC(void *p, u8 v, unsigned n);
extern void *func_02188C7C(unsigned char *p);
extern u8 func_021ABFA8(int a, void *b, int c, int d, void *e, int f);
extern int func_021AC1E0(u32 a);
extern int func_021AC1AC(unsigned int a);
extern void func_021AC1CC(int a, int *b);
extern int func_021AC1A0(u32 a);
extern void func_021AC178(int a);
extern int func_02188BE8(void *a);
extern int func_02047910(void *a, int idx, int amount);
extern u32 func_02047828(struct AnmCtl *c, u32 idx, s32 *frame);
extern int func_021AAA4C(struct Self *self, short *out);
extern u16 func_0209C0A4(int a, int b);
extern unsigned int func_02012A30(const struct BigObj *p);
extern void func_02028ACC(struct SoundSys2 *s, u32 id, u32 who);
void func_021AD7A0(u32 a, u8 *p);
P *func_021AD7B4(u32 a, int heap, u32 c);
void func_021AD7E4(int *a, u32 b);
void func_021AD82C(A *a, B *b, int c);
void func_021AD8A4(Z *z, W *w);
void func_021AD8DC(P_021AD8DC *a, Desc_021AD8DC *d, int c);
void func_021AD96C(P_021AD96C *a, Desc_021AD96C *d, int c);
void func_021ADA1C(Q *a);
u8 func_021ADAAC(int a, u8 *b, int c, int d, int e, int f);
void func_021ADB4C(u32 a, int v);
void func_021ADB5C(int a, int v);
void func_021ADB6C(int a, Dst *b);
void func_021ADBAC(void);
void func_021ADBB0(int a, u8 *w);
void func_021ADC04(u8 *w, u8 *o);
extern char d_021DE0E8[];
extern Rec d_021DE094[];
extern u8 d_021D9238[];
extern int d_021D9240[];
extern u8 d_021D9234[];





/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021AD7A0(u32 a, u8 *p)
{
    func_021ADA1C((Q *)((struct Q *)p));
    func_020307B0(p);
}





P *func_021AD7B4(u32 a, int heap, u32 c)
{
    P *p;

    p = (P *)func_02030734(heap, 0x98, 1, d_021DE0E8, 0x11e);
    p->f0 = a;
    func_021AD7E4((int *)p, c);
    return p;
}





void func_021AD7E4(int *a, u32 b)
{
    int t;

    *R(a) = d_021DE094[b];
    t = func_021ABE24((u8 *)(*a));
    if (b == 0) {
        func_021AD8DC((P_021AD8DC *)((struct P *)a), (Desc_021AD8DC *)((struct Desc *)R(a)), t);
    } else {
        func_021AD96C((P_021AD96C *)((struct P *)a), (Desc_021AD96C *)((struct Desc *)R(a)), t);
    }
}







/*
 * Lever: func_0204767C takes three arguments (see ov019_func_0217FA10); the
 * third is b->f88, which is what keeps the loop bound in r2.
 */
void func_021AD82C(A *a, B *b, int c)
{
    int i = 0;

    a->f14 = (u32)func_02047400((void *)b->f8[c], 0, (void *)b->f8[c]);
    for (; i < b->f88; i++)
        a->f4[i] = (u32)func_02047564((struct G3dOwner *)a->f14, (const struct G3dOwner *)b->f18[c * b->f88 + i], 0);
    a->f0 = (u32)func_0204767C(a->f14, a->f4, b->f88);
    for (i = 0; i < b->f88; i++)
        func_020477A4((struct G3dSys *)a->f0, (u16)i);
}







void func_021AD8A4(Z *z, W *w)
{
    int i;

    for (i = 0; i < w->n; i++)
        func_0204762C((struct Rec *)z->arr[i]);
    func_02047738((struct Rec *)z->f0);
    func_02047504((struct Rec *)z->f14);
}







void func_021AD8DC(P_021AD8DC *a, Desc_021AD8DC *d, int c)
{
    int r7;

    r7 = func_021ABE28((u8 *)a->f0);
    func_02046FF8((int *)(a->f8 = (int)func_02046E24(c, d->h4 + r7)));
    a->f18 = (int)func_02046E24(c, d->h6 + r7);
    func_021AD82C((struct A *)((char *)a + 0x28), (struct B *)a, 0);
    r7 += d->mid;
    func_02046FF8((int *)(a->fc = (int)func_02046E24(c, d->h4 + r7)));
    a->f1c = (int)func_02046E24(c, d->h6 + r7);
    func_021AD82C((struct A *)((char *)a + 0x40), (struct B *)a, 1);
    func_02046FF8((int *)(a->f10 = (int)func_02046E24(c, d->h4)));
    a->f20 = (int)func_02046E24(c, d->h6);
    func_021AD82C((struct A *)((char *)a + 0x58), (struct B *)a, 2);
}







void func_021AD96C(P_021AD96C *a, Desc_021AD96C *d, int c)
{
    int base;
    int i;
    int j;
    int t;

    base = 0;
    if (d->b6) {
        base = func_021ABE28((u8 *)a->f0);
    } else if (d->b7) {
        base = func_021ABE2C((u8 *)a->f0);
    }
    for (i = 0; i < d->lo; i++) {
        t = base + i * d->mid;
        a->f8[i] = (int)func_02046E24(c, d->h4 + t);
        func_02046FF8((int *)a->f8[i]);
        for (j = 0; j < d->n; j++) {
            a->f18[i * d->n + j] = (int)func_02046E24(c, t + d->tab[j]);
        }
        func_021AD82C((struct A *)((char *)a + 0x28 + i * 0x18), (struct B *)a, (u8)i);
    }
}







void func_021ADA1C(Q *a)
{
    int i;

    for (i = 0; i < a->cnt; i++) {
        func_021AD8A4((struct Z *)((char *)a + 0x28 + i * 0x18), (struct W *)a);
    }
    for (i = 0; i < a->n * a->cnt; i++) {
        func_02046EFC((struct Tagged *)a->f18[i]);
    }
    for (i = 0; i < a->cnt; i++) {
        func_020470D0((u32 *)a->f8[i]);
        func_02046EFC((struct Tagged *)a->f8[i]);
    }
}







u8 func_021ADAAC(int a, u8 *b, int c, int d, int e, int f)
{
    int t;
    int k;
    int r;
    L l;

    t = func_021ABE14(b);
    if (func_02188CFC((u8 *)t) != 0) {
        return 0;
    }
    k = d_021D9238[f];
    r = func_021ABEA0((u32)b, k + 0x12);
    if (r == 0) {
        return 0;
    }
    func_02082BCC(&l, 0, 0x28);
    l.f0 = a;
    l.f4 = r;
    l.f8 = func_02188C7C((void *)t);
    l.h10 = c;
    l.h12 = d;
    l.f14 = k;
    if (k == 0) {
        l.b18 = f;
    } else {
        l.b18 = 0;
    }
    l.f1c = (c << 16) + 0x8000;
    l.f24 = (d << 16) + 0x8000;
    l.f20 = e;
    return func_021ABFA8((int)b, d_021D9240, 0, 1, &l, 0);
}







void func_021ADB4C(u32 a, int v)
{
    if (a != 0)
        ((u8 *)func_021AC1E0(a))[2] = v;
}







void func_021ADB5C(int a, int v)
{
    if (a != 0)
        ((u8 *)func_021AC1E0(a))[3] = v;
}





void func_021ADB6C(int a, Dst *b)
{
    int *s = (int *)func_021AC1AC(a);

    b->f34 = s[0];
    b->s4 = *(S40 *)s;
    func_021AC1CC(a, s + 7);
    if (func_021AC1A0(a) == 0) {
        b->h0 = 1;
    }
    func_021AC178(a);
}



void func_021ADBAC(void) {}



void func_021ADBB0(int a, u8 *w)
{
    int i;
    u8 *o = *(u8 * *)&((struct Obj05043 *)w)->f8;

    if (func_02188BE8((void *)func_021ABE14((u8 *)(((struct Obj12797 *)o)->f0))) != 0 && w[2] == 0) {
        func_021ADC04(w, o);
        for (i = 0; i < o[0x88]; i++) {
            func_02047910((void *)(*(int *)(o + 0x28 + w[0x1c] * 0x18)), (u16)i, 0x1000);
        }
    }
}



/*
 * Levers: func_02047828's second parameter is an index (the zero stored to v
 * is passed in r1), not &v; the final call's arguments are named locals with
 * the inner call bound to a local after them, which keeps both loads above
 * the call in callee-saved registers.
 */
void func_021ADC04(u8 *w, u8 *o)
{
    u16 v;
    int z;
    u8 c;
    u16 k;
    void *x;

    v = 0;
    func_02047828(*(void **)(o + 0x28 + w[0x1c] * 0x18), 0, &z);
    if (z == 0 && func_021AAA4C((struct Self *)(((struct Obj05043 *)w)->f34), (short int *)(&v)) != 0) {
        v = func_0209C0A4(v, 5);
        if (v > 3)
            v = 3;
        c = d_021D9234[v];
        k = ((struct Obj19888 *)o)->f8A;
        x = (void *)func_02012A30(*(void **)(((struct Obj05043 *)w)->f34 + 8));
        func_02028ACC(x, k, c);
    }
}
