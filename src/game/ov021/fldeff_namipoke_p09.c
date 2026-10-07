/*
 * file:     fldeff_namipoke_p09.c
 * unit:     yes
 * function: func_021AD82C, func_021AD8A4, func_021AD8DC, func_021AD96C, func_021ADA1C
 * address:  0x021AD82C
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
 */
struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Rec;
struct A;
struct B;
struct W;
struct Z;
struct Tagged;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

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

typedef signed short   s16;

typedef signed char    s8;

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
void func_021AD82C(A *a, B *b, int c);
void func_021AD8A4(Z *z, W *w);
void func_021AD8DC(P_021AD8DC *a, Desc_021AD8DC *d, int c);
void func_021AD96C(P_021AD96C *a, Desc_021AD96C *d, int c);
void func_021ADA1C(Q *a);


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
