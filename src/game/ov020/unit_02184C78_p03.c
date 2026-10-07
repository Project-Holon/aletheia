/*
 * file:     unit_02184C78_p03.c
 * unit:     yes
 * function: func_02185214, func_021852F0, func_02185360, func_02185410, func_02185458, func_021854B0
 * address:  0x02185214
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_020128DC  0x020128DC  thumb
 *   func_02013DD0  0x02013DD0  thumb
 *   func_02014204  0x02014204  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_02012FCC  0x02012FCC  thumb
 *   func_0200BFA4  0x0200BFA4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026484  0x02026484  thumb
 *   func_02012B78  0x02012B78  thumb
 *   func_02012B64  0x02012B64  thumb
 *   func_02012B8C  0x02012B8C  thumb
 *   func_02012B4C  0x02012B4C  thumb
 *   func_02185C4C  0x02185C4C  thumb  ov020
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3238  0x021A3238  thumb  ov021
 *   func_0217BCDC  0x0217BCDC  thumb  ov018
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02014184  0x02014184  thumb
 *   func_020141A8  0x020141A8  thumb
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021A36BC  0x021A36BC  thumb  ov021
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012894  0x02012894  thumb
 *   func_02012870  0x02012870  thumb
 *   func_02013E7C  0x02013E7C  thumb
 *   func_020128C0  0x020128C0  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_0201447C  0x0201447C  thumb
 *   func_02162694  0x02162694  thumb  ov010
 *   func_021625E8  0x021625E8  thumb  ov010
 *   func_021626E8  0x021626E8  thumb  ov010
 *   func_02184388  0x02184388  thumb  ov020
 *   func_02184CEC  0x02184CEC  thumb  ov020
 *   func_02185EB0  0x02185EB0  thumb  ov020
 *   func_02184410  0x02184410  thumb  ov020
 *   func_020142A4  0x020142A4  thumb
 *   func_02184504  0x02184504  thumb  ov020
 */
#include "../../matched/include/Obj00248.h"

struct Big;
struct BigObj;
struct Ctx;
struct t;
struct Obj00020;
struct Obj18028;
struct Desc;
struct Obj;
struct Sub02014444Obj;
struct Rec1C;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef struct { int f00; u16 f04, f06; int f08[5]; } Rec;

typedef short s16;

typedef struct { u16 a, b; s16 c; u16 d; } H4;

typedef struct { int f[7]; } S7;

void *func_020120F4(const struct Ctx *p);
void *func_0201210C(const struct Ctx *p);
Rec *func_020128DC(void *p);
int func_02013DD0(int v);
void func_02014204(struct t *p, int id);
void *func_02012EBC(struct Big *p);
u16 *func_0200BE48(void *p);
int func_02012FCC(int p0);
u64 func_0200BFA4(u8 *p, void *x, u32 n);
u32 func_02012138(const struct Ctx *p);
u32 func_0202648C(void *p);
u32 func_02026454(void *obj);
void func_02026484(void *p);
struct BigObj *func_02012B78(struct BigObj *p, u8 v);
void func_02012B64(struct BigObj *p, u8 v);
void func_02012B8C(struct BigObj *p, u32 v);
void func_02012B4C(struct BigObj *p, u8 v);
void *func_02185C4C(void *p, void *a1, Rec *r);
void *func_02188CB4(struct Obj00020 *p);
int func_021A3238(u8 *p);
void func_0217BCDC(u8 *a, void *b, int c, u8 d, u8 e);
int func_02158344(int a0);
u32 func_02188CFC(u8 *p);
u16 func_02188C9C(u8 *p);
void *func_021A3074(u8 *p);
void func_021A36BC(struct Obj18028 *p, void *a1);
void *func_0216D888(void *p);
void func_02014184(void *d, int a, s16 b, int c, int e, int f);
void func_020141A8(struct t *p, int b, int d, u16 g, u16 i, s16 h);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
S7 *func_02012894(void *p);
struct Rec1C *func_02012870(const struct BigObj *p);
u32 func_02013E7C(u32 id);
void func_020128C0(struct BigObj *p, const struct Rec1C *src);
void *func_02012B38(const struct BigObj *p);
u8 func_0201447C(struct Sub02014444Obj *o, u8 v);
int func_021625E8(int a0);
int func_02162694(int a0, int a1, int a2);
u8 func_021626E8(u8 *p);
int func_02184388(int a, int *state, u8 *p);
void func_02184CEC(void **o, void *p);
void func_02185EB0(int a, u16 *p);
int func_02184410(int a, int *state, u8 *p);
u32 func_020142A4(u32 idx);
int func_02184504(int a, int *state, u8 *p);
void *func_02185214(void *a);
void func_021852F0(void *dst, int x);
void *func_02185360(void *p, int u, int a, int b);
void *func_02185410(void *p, int u, int a, int b);
void *func_02185458(void *p, int u, int b, s16 a, const int *s, u16 x);
void *func_021854B0(void *p, int u, s16 a, const int *s, u16 x);

static inline void create_result(void *a, void *r6, Rec *s, void **out)
{
    *out = func_02185C4C(a, r6, s);
}

static inline void *finish(void *a, void *r4, void *r6, void *ret)
{
    u16 *t;
    void *h;
    t = func_0200BE48(func_02012EBC(r4));
    func_0200BFA4((u8 *)t, (void *)func_02012FCC((int)r4), 1);
    h = (void *)func_02012138(a);
    func_0202648C(h);
    if (func_02026454(h) == 0)
        func_02026484(h);
    if (func_021A3238(func_02188CB4(r6)) == 0)
        func_0217BCDC(0, a, 0, 0, 0);
    func_02012B78(r4, 0);
    if (func_02158344(func_02012138(a)) == 0) {
        func_02012B64(r4, 0);
        func_02012B8C(r4, 0);
        func_02012B4C(r4, 1);
    }
    return ret;
}

/*
 * Lever: func_0202648C reads its pointer argument in the matched ARM9
 * unit_02026454.c. The original forwards func_02012138(a) in r0 with
 * no intervening argument setup. Explicitly passing h restores the
 * return-value spill and all frame/register choices (DIFF22 -> EXACT).
 * Runs this retry: 2; the prior consumed permuter was not repeated.
 */
void *func_02185214(void *a)
{
    void *r4;
    void *r6;
    Rec s;
    void *ret;
    r4 = func_020120F4(a);
    r6 = func_0201210C(a);
    s = *func_020128DC(r4);
    if (func_02013DD0(s.f04) == 1)
        func_02014204((struct t *)(&s), s.f04);
    create_result(a, r6, &s, &ret);
    return finish(a, r4, r6, ret);
}


/*
 * Thumb leaf, sole caller in range). Evidence class: label / sole-ref/code.
 * Leaf 0x02014184 (arm9, Thumb, EXACT with match.py one, Ilias's to file):
 *   typedef short s16;
 *   typedef struct { int f0; s16 h4, h6, h8, ha; int fc, f10, f14, f18; } Obj;
 *   void func_02014184(Obj *o, s16 a, s16 b, int c, int d, int e)
 *   { o->f0 = 1; o->h4 = a; o->h6 = -1; o->h8 = b; o->ha = 0; o->fc = 0;
 *     o->f10 = c; o->f14 = d; o->f18 = e; }
 */
void func_021852F0(void *dst, int x)
{
    H4 h;
    int r5 = (int)func_02188CB4((struct Obj00020 *)x);

    if (func_02188CFC((u8 *)x) == 0) {
        int *v;

        v = func_0216D888(func_021A3074((u8 *)r5));
        func_02014184(dst, func_02188C9C((u8 *)x), 1, v[0], v[1], v[2]);
        return;
    }
    func_021A36BC((struct Obj18028 *)r5, &h);
    func_020141A8(dst, func_02188C9C((u8 *)x), 2, h.a, h.d, h.c);
}


void *func_02185360(void *p, int u, int a, int b)
{
    char *r4;
    void *r5 = func_020120F4(p);
    void *r0v = func_020122C0(p, 0, func_02184388, 0x9c);
    u16 *r6;

    r4 = func_020124E8(r0v);
    func_02184CEC((void **)r4, p);
    ((struct Obj00248 *)r4)->f40 = 1;
    if (func_021625E8(a) != 0) {
        *(S7 *)(r4 + 0x10) = *func_02012894(r5);
    } else {
        func_02162694(a, (int)(r4 + 0x10), b);
    }
    ((struct Obj00248 *)r4)->f2C = func_021626E8((u8 *)a);
    r6 = (u16 *)func_02012870(r5);
    if (func_02013E7C(r6[2]) == 1 && func_02013E7C(((struct Obj00248 *)r4)->f14) == 0) {
        func_020128C0(r5, (const struct Rec1C *)r6);
    }
    func_02185EB0((int)r5, (u16 *)(r4 + 0x10));
    func_0201447C(func_02012B38(r5), 2);
    return r0v;
}


void *func_02185410(void *p, int u, int a, int b)
{
    void *r0v;
    char *r4;

    func_020120F4(p);
    r0v = func_020122C0(p, 0, func_02184410, 0x9c);
    r4 = func_020124E8(r0v);
    func_02184CEC((void **)r4, p);
    ((struct Obj00248 *)r4)->f40 = 1;
    func_02162694(a, (int)(r4 + 0x10), b);
    ((struct Obj00248 *)r4)->f2C = func_021626E8((u8 *)a);
    return r0v;
}


void *func_02185458(void *p, int u, int b, s16 a, const int *s, u16 x)
{
    void *r0v = func_020122C0(p, 0, func_02184504, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC((void **)r4, p);
    x = func_020142A4(x);
    func_02014184(r4 + 0x10, a, x, s[0], s[1], s[2]);
    *(int *)(r4 + 0x2c) = 0;
    *(u8 *)(r4 + 0x30) = b;
    return r0v;
}

void *func_021854B0(void *p, int u, s16 a, const int *s, u16 x)
{
    return func_02185458(p, u, 0, a, s, x);
}
