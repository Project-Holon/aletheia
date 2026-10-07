/*
 * file:     fldeff_iwakudaki_p04.c
 * unit:     yes
 * function: func_021AE050, func_021AE090, func_021AE0CC, func_021AE198, func_021AE1FC, func_021AE288, func_021AE348, func_021AE430, func_021AE454
 * address:  0x021AE050
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
 *   func_02047910  0x02047910  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   d_021D92FC  0x021D92FC  data
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_0215A4C8  0x0215A4C8  thumb  ov010
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0218B6AC  0x0218B6AC  thumb  ov021
 *   func_021AE930  0x021AE930  thumb  ov021
 *   func_0215A438  0x0215A438  thumb  ov010
 *   func_021AE8D4  0x021AE8D4  thumb  ov021
 *   func_021AE8B4  0x021AE8B4  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D828  0x0216D828  thumb  ov010
 *   func_021AE7A8  0x021AE7A8  thumb  ov021
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_021AE890  0x021AE890  thumb  ov021
 *   func_021AE79C  0x021AE79C  thumb  ov021
 *   func_0216D63C  0x0216D63C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   d_021D9338  0x021D9338  data  a4
 *   func_021AE754  0x021AE754  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   d_021DE138     0x021DE138  data  a4
 */
#include "../../matched/include/Obj07517.h"

#define FX_F32_TO_FX32(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))
struct Arg;
struct S;
struct Obj00020;
struct Ctx;
struct Rec;
struct Desc;
struct Obj;
typedef struct Owner {
    char pad00[0xC];
    void *obj;
} Owner;

typedef struct Arg {
    Owner *owner;
    unsigned short n;
} Arg;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16_021AE090;

typedef signed char    s8;

typedef struct V3 { int x, y, z; } V3;

typedef struct M33 { int m[9]; } M33;

typedef struct Xf { V3 pos; V3 scale; M33 rot; } Xf;

typedef struct Q { u32 f0; u32 f4; u32 f8; u32 fc; } Q;

typedef struct Rec {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
} Rec;

typedef short s16_021AE198;

typedef short s16_021AE288;

typedef short s16_021AE348;

typedef int (*CmpFn)(int, const s16_021AE348 *, const s16_021AE348 *);

typedef signed short   s16_021AE430;

typedef struct { int w[6]; } S24;

extern int func_02047910(void *a, int idx, int amount);
extern void func_0207ADC4(M33 *m);
extern void func_021AC1B8(u32 a, V3 *out);
extern int func_02047AC8(void *a0, struct Arg *a1);
extern int func_0215A4C8(int a0);
extern void *func_02188C80(void *p);
extern int func_0218B6AC(void *ctx);
extern int func_021AE930(int a, u32 b);
extern void func_0215A438(int a, int b, Rec *src);
extern u32 func_021AE8D4(u32 a, u16 b);
extern void func_021AE8B4(struct S *s, u32 a, u32 b, u32 c);
extern void *func_0216D67C(void *a0);
extern void *func_0216DE94(void *map, u32 id);
extern void func_0216D828(int a, int *b);
extern int func_021AE7A8(u32 a, u32 dir, int n, void *p);
extern u32 func_02188CE8(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern void *func_02188C7C(unsigned char *p);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_021AE890(u32 a, u32 b);
extern int func_021AE79C(u32 a);
extern int func_0216D63C(char *a0, int a1);
extern u16 func_0216D5F8(void *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int func_021AE754(u32 a, u32 b, u32 *c);
void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);
void func_021AE050(void *self, Arg *arg);
void func_021AE090(u32 a, Q **pq);
int func_021AE0CC(int a);
int func_021AE198(int a, int b, int c, int d);
int func_021AE1FC(int a, void *b, int c);
int func_021AE288(int a, int b, int c, u16 *d);
int func_021AE348(int idx, int a, const s16_021AE348 *p, const s16_021AE348 *q);
int func_021AE360(int a, const s16_021AE348 *p, const s16_021AE348 *q);
int func_021AE394(int a, const s16_021AE348 *p, const s16_021AE348 *q);
int func_021AE3C8(int a, const s16_021AE348 *p, const s16_021AE348 *q);
int func_021AE3FC(int a, const s16_021AE348 *p, const s16_021AE348 *q);
u32 func_021AE430(u32 a, u32 x, u32 y);
void *func_021AE454(int a, int b, S24 *src, int c);
extern Xf d_021D92FC;
extern CmpFn d_021D9338[];
extern int d_021DE138;


/*
 * Set channel 0 of the object at +0xC of *arg->owner to (2*arg->n + 1)
 * converted through FX_F32_TO_FX32.
 */
void func_021AE050(void *self, Arg *arg)
{
    Owner *owner = arg->owner;
    func_02047910(owner->obj, 0, FX_F32_TO_FX32(arg->n * 2 + 1));
}


void func_021AE090(u32 a, Q **pq)
{
    Q *q = *pq;
    Xf x = d_021D92FC;

    func_0207ADC4(&x.rot);
    func_021AC1B8(a, &x.pos);
    func_02047AC8((void *)q->fc, (struct Arg *)(&x));
}


int func_021AE0CC(int a)
{
    Rec b;
    Rec c;
    u32 kind;
    u32 n;
    int z = 0;
    int ret = 0;

    if (func_021AE1FC(a, 0, (int)(&b)) == 1) {
        kind = (u32)func_0215A4C8((u16)b.f10);
        n = func_0218B6AC(func_02188C80((void *)a));
        if (kind == 0) {
            if (n < 2 || func_021AE1FC(a, (void *)b.f0, (int)(&c)) == 0) {
                ret = func_021AE930(a, b.f0);
                b.f14 = 0;
                func_0215A438(ret, 0, &b);
            } else {
                ret = func_021AE930(a, b.f0);
                b.f14 = 2;
                func_0215A438(ret, z, &b);
                c.f14 = 2;
                func_0215A438(ret, 1, &c);
            }
        } else if (kind == 1) {
            if (n >= 2) {
                func_021AE8B4((struct S *)(&c), func_021AE8D4(b.f0, b.f10), b.f4, (u16)b.f8);
                ret = func_021AE930(a, b.f0);
                b.f14 = 1;
                func_0215A438(ret, z, &b);
                c.f14 = 1;
                func_0215A438(ret, 1, &c);
            }
        } else if (kind == 2 || kind == 3) {
            if (n >= 3) {
                ret = func_021AE930(a, b.f0);
                b.f14 = z;
                func_0215A438(ret, z, &b);
            }
        }
    }
    return ret;
}


int func_021AE198(int a, int b, int c, int d)
{
    int q[2];
    int p[2];
    int h;
    int r;

    h = (int)func_0216DE94(func_0216D67C((void *)a), 0xff);
    if (h == 0)
        return -1;
    func_0216D828(h, p);
    func_0216D828(a, q);
    r = func_021AE348(b, (s16_021AE198)c, (const s16_021AE198 *)q, (const s16_021AE198 *)p);
    if (r != -1) {
        if (func_021AE7A8(a, b, r, (void *)d) == 1)
            r = -1;
    }
    return r;
}


int func_021AE1FC(int a, void *b, int c)
{
    int s0, s4, s8;
    u16 sc;
    void *s14;
    int s10;
    void *r4;
    void *r7;

    s0 = c;
    s4 = func_02188CE8((void *)a);
    r4 = func_021A3074(func_02188CB4((void *)a));
    r7 = func_02188C7C((void *)a);
    s14 = 0;
    s10 = 0;
    while (func_0216DD1C(r7, (struct Rec **)(&s14), (u32 *)(&s10)) == 1) {
        if (s14 != r4 && (b == 0 || b != s14)) {
            s8 = func_021AE288(s4, (int)s14, (int)r4, &sc);
            if (s8 != -1 && func_021AE890((u32)((void *)a), (u32)s14) == 0) {
                func_021AE8B4((struct S *)s0, (u32)s14, s8, sc);
                return 1;
            }
        }
    }
    return 0;
}


int func_021AE288(int a, int b, int c, u16 *d)
{
    int q[2];
    int p[2];
    int r4, r7, sc;
    u16 r5;

    r4 = func_021AE79C(b);
    if ((u16)(r4 + 0xffff) <= 1) {
        r5 = 0;
        r7 = (s16_021AE288)func_0216D63C((char *)b, 0);
        func_0216D828(b, q);
        func_0216D828(c, p);
        if (r4 == 1) {
            sc = func_0216D5F8((void *)b);
            r4 = func_021AE348(sc, r7, (const s16_021AE288 *)q, (const s16_021AE288 *)p);
            if (r4 != r5 - 1 && func_021AE7A8(b, sc, r4, (void *)a) == 0) {
                *d = sc;
                return r4;
            }
        } else {
            do {
                r4 = func_021AE348(r5, r7, (const s16_021AE288 *)q, (const s16_021AE288 *)p);
                if (r4 != -1 && func_021AE7A8(b, r5, r4, (void *)a) == 0) {
                    *d = r5;
                    return r4;
                }
                r5++;
            } while (r5 < 4);
        }
    }
    return -1;
}


/*
 * Addresses are Black-image addresses.
 * func_021AE348 dispatches through the four-entry table at 0x021D9338,
 * whose entries are the four unlabelled leaves that follow it; the unit
 * covers the whole 232-byte run.
 */
int func_021AE348(int idx, int a, const s16_021AE348 *p, const s16_021AE348 *q)
{
    return d_021D9338[idx](a, p, q);
}


int func_021AE360(int a, const s16_021AE348 *p, const s16_021AE348 *q)
{
    if (p[0] == q[0] && p[1] == q[1] && q[2] < p[2] && q[2] >= p[2] - a)
        return p[2] - q[2];
    return -1;
}


int func_021AE394(int a, const s16_021AE348 *p, const s16_021AE348 *q)
{
    if (p[0] == q[0] && p[1] == q[1] && q[2] > p[2] && q[2] <= p[2] + a)
        return q[2] - p[2];
    return -1;
}


int func_021AE3C8(int a, const s16_021AE348 *p, const s16_021AE348 *q)
{
    if (p[2] == q[2] && p[1] == q[1] && q[0] < p[0] && q[0] >= p[0] - a)
        return p[0] - q[0];
    return -1;
}


int func_021AE3FC(int a, const s16_021AE348 *p, const s16_021AE348 *q)
{
    if (p[2] == q[2] && p[1] == q[1] && q[0] > p[0] && q[0] <= p[0] + a)
        return q[0] - p[0];
    return -1;
}


u32 func_021AE430(u32 a, u32 x, u32 y)
{
    u32 h;
    u32 *p;

    h = (u32)func_020122C0((void *)a, 0, func_021AE754, 8);
    p = func_020124E8((struct Obj *)h);
    p[0] = x;
    p[1] = y;
    return h;
}


void *func_021AE454(int a, int b, S24 *src, int c)
{
    char *p = (char *)func_02030734(a, 0x38, 1, (const char *)&d_021DE138, 0x1fa);

    *(S24 *)(p + 8) = *src;
    ((struct Obj07517 *)p)->f20 = 0;
    ((struct Obj07517 *)p)->f24 = c;
    ((struct Obj07517 *)p)->f30 = b;
    ((struct Obj07517 *)p)->f34 = func_02188CB4((void *)b);
    return p;
}
