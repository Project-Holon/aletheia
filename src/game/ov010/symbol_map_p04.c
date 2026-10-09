/*
 * file:     symbol_map_p04.c
 * unit:     yes
 * function: func_021665D0, func_021665F0, func_02166618, func_0216662C, func_02166640, func_02166658, func_0216666C, func_021666A4, func_021666B8, func_0216670C, func_02166714, func_02166734, func_021667E0, func_02166824, func_02166834, func_02166854, func_02166908, func_02166980, func_021669C0, func_02166A00, func_02166A6C
 * address:  0x021665D0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216649C  0x0216649C  thumb  ov010
 *   func_02166324  0x02166324  thumb  ov010
 *   func_021663F4  0x021663F4  thumb  ov010
 *   func_02161CDC 0x02161CDC thumb ov010
 *   func_020307B0  0x020307B0  arm
 *   func_020124E8 0x020124E8 thumb
 *   func_02012444 0x02012444 thumb
 *   ov203_id 0x000000CB data a1
 *   d_021BFB3C 0x021BFB3C data ov203 a4
 *   func_0215A5F4  0x0215A5F4  thumb ov010
 *   func_0215A5DC  0x0215A5DC  thumb ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012ED0  0x02012ED0  thumb
 *   func_02159B10  0x02159B10  thumb ov010
 *   func_02011330  0x02011330  thumb
 *   func_02159AE8  0x02159AE8  thumb ov010
 *   func_021C87A0  0x021C87A0  thumb ov021
 *   func_021C87AC  0x021C87AC  thumb ov021
 *   func_021C87B8  0x021C87B8  thumb ov021
 *   func_021C87C8  0x021C87C8  thumb ov021
 *   func_0215897C 0x0215897C thumb ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   func_02009794  0x02009794  thumb
 *   func_020095C8  0x020095C8  thumb
 *   func_0200973C  0x0200973C  thumb
 *   func_0200856C  0x0200856C  thumb
 *   ov_id_DA  0x000000DA  data
 *   d_021BAB5C  0x021BAB5C  data  a4 ov218
 *   func_02012F38  0x02012F38  thumb
 *   d_02172BA4  0x02172BA4  data  ov010  a4
 *   d_021729FC  0x021729FC  data  ov010  a4
 *   func_0207AD58  0x0207AD58  thumb
 *   func_0207D59C  0x0207D59C  arm
 *   _fadd  0x0209C95C  arm
 *   _fdiv  0x0209CE10  arm
 *   _fgr  0x0209BBB0  arm
 *   _fmul  0x0209C77C  arm
 *   _fsub  0x0209CB8C  arm
 *   _ffix  0x0209C494  arm
 */
#include "../../matched/include/Obj12051.h"
#include "../../matched/include/Obj17727.h"
#include "../../matched/include/Obj07308.h"
#include "../../matched/include/Obj00005.h"

struct Desc;
struct Obj;
struct Ctx;
struct Big;
struct Stream;
struct Sub02009470Ent;
struct Sub02009470Obj;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Work {
    u8 pad00[0x10];
    u32 f10;
    u32 f14;
    u32 f18;
    u16 *f1c;
};

typedef signed short   s16;

struct Task {
    u8 f00;
    u8 pad01[7];
    u16 h[20];
    u8 flag[232];
    u8 pad118[4];
    u32 f11c;
    u32 f120;
    u32 f124;
};

struct S {
    u8 pad0;
    u8 f1;
    u16 f2;
    int f4;
    u8 pad8[0x114];
    u16 *p11c;
    u16 *p120;
    u16 *p124;
};

extern u32 func_0216649C(void *p);
extern int func_02166324(u8 *grid, int id);
extern int func_021663F4(u8 *list, int def, unsigned dir);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02161CDC(void *, void *, u8, u8);
extern int func_020307B0();
extern void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012ED0(struct Big *p);
extern u32 func_02159B10(void *, void *);
extern u16 func_02011330(struct Stream *s);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_021C87A0(void *p, u32 i);
extern u32 func_021C87AC(void *p, u32 i);
extern u32 func_021C87B8(void *p, u32 i, u32 j);
extern u32 func_021C87C8(void *p, u32 i);
extern void func_0215897C(void *, void *);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern u32 func_02009794(const struct Sub02009470Obj *obj, u32 n);
extern u8 func_020095C8(const struct Sub02009470Obj *obj);
extern struct Sub02009470Ent *func_0200973C(struct Sub02009470Obj *obj, int i);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern int func_02012F38(int base);
extern void func_0207AD58(void *dst, int a, int b);
extern void func_0207D59C(void *reg, void *m, int a, int b, int c, int d);
int func_021665D0(int a0, int a1);
int func_021665F0(int a0, int a1, int a2);
/* * Unlabelled leaf: true when the argument plus one, truncated to a byte, * is 1. */ int func_02166618(int a0);
int func_0216662C(int a0);
/* * Unlabelled leaf (sole blocker of ov018 func_0217C37C): true when the * argument plus one, truncated to a byte, is 2, 3 or 4. Twin of * func_02166618. */ int func_02166640(int a0);
/* * Unlabelled leaf (no lr save) called from func_02166734 case 4; 18 bytes * plus 2 bytes of alignment padding before func_0216666C. */ u32 func_02166658(void *p, u32 i);
void *func_0216666C(void *a, void *b, void *c);
void func_021666A4(int a0);
int func_021666B8(void *task, u32 *state);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_0216670C.c \ * --func func_0216670C --addr 0x0216670C --region ov010 --cc dsi/1.1p1 --thumb */ int func_0216670C(void *p);
void func_02166714(u8 *p, int n);
/* * The returned task remains live as func_0215897C's second argument. */ int func_021667E0(void *a, void *b);
int func_02166824(int a0, int a1);
int func_02166834(int a0, int a1);
/* * Creates the 0x128-byte task for func_02166908, stores its arguments, * then fills a 232-entry flag byte table (+0x30) and a 20-entry halfword * table (+0x08) from a lookup object, zero padding the halfwords. */ void *func_02166854(void *a, int b, u32 c, u32 d, u32 e);
/* * Former blocker: ABS32 for 0x000000DA (overlay id 218) and 0x021BAB5C (its callback table) have no * witness outside this function; func_02012444 is not a listed overlay-id consumer and the * word is referenced only from this pool. Every concrete byte matches. * * 2026-10-05 (D8 lane 15): the callback table d_021BAB5C lives in ov218 (loaded by this function); the data line now carries the ov218 token and the relocation resolves. */ int func_02166908(void *a, int *st);
/* * blocked: listing 64 compiled 62 */ int func_02166980(int a0, int a1);
int func_021669C0(int a0, int a1);
int func_02166A00(void *a, void *b);
void func_02166A6C(void);
extern u8 ov203_id[];
extern u8 d_021BFB3C[];
extern char ov_id_DA[];
extern char d_021BAB5C[];
extern float d_02172BA4;
extern float d_021729FC;




int func_021665D0(int a0, int a1)
{
    int t4;
    void *p;

t4 = a1 + 0;
    p = (void *)func_0216649C((void *)a0);
loc_021665D8:
    if (p == 0) goto loc_021665E8;
loc_021665DC:
a1 = t4 + 1;
a1 = a1 << 0x18;
a1 = (unsigned)a1 >> 0x18;
    a0 = func_02166324(p, a1);
loc_021665E6:
    return a0;
loc_021665E8:
a0 = 0x46;
a0 = a0 << 2;
    return a0;}




int func_021665F0(int a0, int a1, int a2)
{
    int t4;
    int t5;
    void *p;

t5 = a1 + 0;
t4 = a2 + 0;
    p = (void *)func_0216649C((void *)a0);
loc_021665FA:
    if (p == 0) goto loc_02166614;
loc_021665FE:
a1 = t5 + 1;
a1 = a1 << 0x18;
a2 = t4 << 0x18;
a1 = (unsigned)a1 >> 0x18;
a2 = (unsigned)a2 >> 0x18;
    a0 = func_021663F4(p, a1, a2);
loc_0216660C:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
a0 = a0 - 1;
    return a0;
loc_02166614:
a0 = 4;
    return a0;}




/*
 * Unlabelled leaf: true when the argument plus one, truncated to a byte,
 * is 1.
 */
int func_02166618(int a0)
{
    if ((u8)(a0 + 1) == 1)
        return 1;
    return 0;
}






int func_0216662C(int a0)
{

a0 = a0 + 1;
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    if (a0 != 5) goto loc_0216663A;
loc_02166636:
a0 = 1;
    return a0;
loc_0216663A:
a0 = 0;
    return a0;}




/*
 * Unlabelled leaf (sole blocker of ov018 func_0217C37C): true when the
 * argument plus one, truncated to a byte, is 2, 3 or 4. Twin of
 * func_02166618.
 */
int func_02166640(int a0)
{
    u8 t = a0 + 1;

    if ((u8)(t + 0xFE) <= 2)
        return 1;
    return 0;
}




/*
 * Unlabelled leaf (no lr save) called from func_02166734 case 4; 18 bytes
 * plus 2 bytes of alignment padding before func_0216666C.
 */
u32 func_02166658(void *p, u32 i)
{
    if (p == 0)
        return 10;
    return *(u32 *)((u8 *)p + i * 0x1C + 0x14);
}



void *func_0216666C(void *a, void *b, void *c) {
    void *task;
    void **w;
    task = func_020122C0(a, 0, func_021666B8, 32);
    w = func_020124E8(task);
    w[6] = b;
    w[7] = c;
    func_02161CDC(w, a, 1, 0);
    ((int *)w)[2] = func_0216670C(b);
    return task;
}




void func_021666A4(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj12051 *)((char *)t4))->f0;
    if (a0 == 0) goto loc_021666B6;
loc_021666AE:
    a0 = func_020307B0(a0);
loc_021666B2:
a0 = 0;
((struct Obj12051 *)((char *)t4))->f0 = a0;
loc_021666B6:
    return;}



int func_021666B8(void *task, u32 *state)
{
    struct Work *w = func_020124E8(task);
    switch (*state) {
    case 0:
        func_02012444(task, (u32)ov203_id, (u32)d_021BFB3C, (u32)w);
        *state = *state + 1;
        break;
    case 1:
        if (w->f14 == 2) *w->f1c = 1;
        else *w->f1c = 0;
        func_02166714((u8 *)w->f18, w->f10);
        return 1;
    }
    return 0;
}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216670C.c \
 *       --func func_0216670C --addr 0x0216670C --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216670C(void *p) { return ((struct Obj17727 *)p)->f4; }



void func_02166714(u8 *p, int n) {
    int q;
    ((struct Obj07308 *)p)->f4 = n;
    q = ((struct Obj07308 *)p)->f4 / 1350;
    if (((struct Obj07308 *)p)->f8 <= q) ((struct Obj07308 *)p)->f8 = q;
}




/*
 * The five unlabelled leaf callees are filed as their own shards
 * (matched witnesses): ov010_func_02166658.c, ov021_func_021C87A0.c,
 * ov021_func_021C87AC.c, ov021_func_021C87B8.c, ov021_func_021C87C8.c.
 * (ov128_func_021C87A0.c is a different overlay's function at that
 * address; ov010 runs with ov021 loaded.)
 * lever (wave 82 R8): each arm writes the store `*(u16 *)a = ...` out
 *   itself, case 8 included (`if (...) *a = 1; else *a = 0;`). Cross-jumping
 *   then leaves cases 5-8 branching onto case 4's `b` and case 8's else as a
 *   dead `b` onto default. A shared `v` stored after the switch is 170 B
 *   (36 bytes out); with case 8's `else v = 0;` it is 172 B but DIFF21
 *   (a/p colours swapped, direct branches). An inline switch helper is the
 *   same DIFF21.
 */
int func_02166734(void *a, void *b)
{
    u8 *p;
    u32 x;
    u16 k;
    u32 y;

    func_0215A5F4(b);
    p = func_02012ED0((struct Big *)func_020120F4((const struct Ctx *)func_0215A5DC(b)));
    x = func_02159B10(a, b);
    k = func_02011330((struct Stream *)a);
    y = func_02159B10(a, b);
    a = func_02159AE8(a, b);
    switch (k) {
    case 4:
        *(u16 *)a = func_02166658(*(void **)p, x);
        break;
    case 5:
        *(u16 *)a = func_021C87A0(*(void **)p, x);
        break;
    case 6:
        *(u16 *)a = func_021C87AC(*(void **)p, x);
        break;
    case 7:
        *(u16 *)a = func_021C87B8(*(void **)p, x, y);
        break;
    case 8:
        if (func_021C87C8(*(void **)p, x) != 0)
            *(u16 *)a = 1;
        else
            *(u16 *)a = 0;
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    default:
        *(u16 *)a = 0;
        break;
    }
    return 0;
}




/*
 * The returned task remains live as func_0215897C's second argument.
 */
int func_021667E0(void *a, void *b)
{
    void *x = func_0215A5F4(b);
    void *y = func_0215A5DC(b);
    void **p;
    void *r;
    p = (void **)func_02012ED0(func_020120F4(y));
    r = func_0216666C(y, *p, func_02159AE8(a, b));
    if (r == 0)
        return 1;
    func_0215897C(x, r);
    return 1;
}






int func_02166824(int a0, int a1)
{
    int a2;
a2 = *(u8 *)((char *)a0 + 1);
    if ((unsigned)a1 < (unsigned)a2) goto loc_0216682E;
loc_0216682A:
a0 = 0xb;
    return a0;
loc_0216682E:
a0 = a0 + a1;
a0 = *(u8 *)((char *)a0 + 3);
    return a0;}






int func_02166834(int a0, int a1)
{

    if (a1 == 0) goto loc_02166842;
loc_02166838:
    if (a1 == 1) goto loc_02166846;
loc_0216683C:
    if (a1 == 2) goto loc_0216684A;
loc_02166840:
    goto loc_0216684E;
loc_02166842:
a0 = *(u8 *)((char *)a0 + 1);
    return a0;
loc_02166846:
a0 = *(u8 *)&((struct Obj00005 *)((char *)a0))->f0;
    return a0;
loc_0216684A:
a0 = *(u8 *)((char *)a0 + 2);
    return a0;
loc_0216684E:
a0 = 0;
    return a0;}




/*
 * Creates the 0x128-byte task for func_02166908, stores its arguments,
 * then fills a 232-entry flag byte table (+0x30) and a 20-entry halfword
 * table (+0x08) from a lookup object, zero padding the halfwords.
 */
void *func_02166854(void *a, int b, u32 c, u32 d, u32 e)
{
    void *task;
    struct Task *t;
    void *o;
    int i;
    int n;
    int j;

    task = func_020122C0(a, 0, func_02166908, 0x128);
    t = func_020124E8(task);
    t->f00 = b;
    t->f124 = e;
    t->f11c = c;
    t->f120 = d;
    o = func_02009470(func_02012EBC(func_020120F4(a)));
    for (i = 1; i < 0xE9; i++) {
        j = i - 1;
        if (func_02009794(o, i))
            t->flag[j] = 1;
        else
            t->flag[j] = 0;
    }
    n = func_020095C8(o);
    if (n > 20)
        n = 20;
    for (i = 0; i < n; i++)
        t->h[i] = func_0200856C((const struct Sub0200852CObj *)func_0200973C(o, i));
    for (; i < 20; i++)
        t->h[i] = 0;
    return task;
}




/*
 * Former blocker: ABS32 for 0x000000DA (overlay id 218) and 0x021BAB5C (its callback table) have no
 * witness outside this function; func_02012444 is not a listed overlay-id consumer and the
 * word is referenced only from this pool. Every concrete byte matches.
 *
 * 2026-10-05 (D8 lane 15): the callback table d_021BAB5C lives in ov218 (loaded by this function); the data line now carries the ov218 token and the relocation resolves.
 */
int func_02166908(void *a, int *st)
{
    struct S *s = func_020124E8(a);
    switch (*st) {
    case 0:
        func_02012444(a, (u32)ov_id_DA, (u32)d_021BAB5C, (u32)s);
        *st = *st + 1;
        break;
    case 1:
        if (s->f4 == 1) {
            *s->p124 = 1;
            *s->p11c = s->f1;
            *s->p120 = s->f2;
        } else {
            *s->p124 = 0;
            *s->p11c = 0;
            *s->p120 = 0;
        }
        return 1;
    }
    return 0;
}




/*
 * blocked:  listing 64 compiled 62
 */
int func_02166980(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    int t7;
    void *p;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    func_0215A5F4((void *)a0);
loc_0216698C:
a0 = t6 + 0;
    p = func_0215A5DC((void *)a0);
loc_02166992:
    p = func_020120F4((const struct Ctx *)p);
loc_02166996:
    a0 = func_02012F38((int)p);
loc_0216699A:
t7 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02011330((struct Stream *)a0);
loc_021669A2:
a0 = a0 << 0x18;
t4 = (unsigned)a0 >> 0x18;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = (int)func_02159AE8((void *)a0, (void *)a1); /* int-typed on purpose: pointer local changes codegen */
loc_021669AE:
t5 = a0 + 0;
a0 = t7 + 0;
a1 = t4 + 0;
    a0 = func_02166824(a0, a1);
loc_021669B8:
*(u16 *)&((struct Obj00005 *)((char *)t5))->f0 = a0;
a0 = 0;
    return a0;}




int func_021669C0(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    int t7;
    void *ctx;
    u16 *q;
    void *v0;
    void *v1;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_021669CC:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_021669D2:
    ctx = func_020120F4((const struct Ctx *)v1);
loc_021669D6:
    a0 = func_02012F38((int)ctx);
loc_021669DA:
t6 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_021669E4:
t7 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_021669EE:
a0 = t6 + 0;
a1 = t7 + 0;
    a0 = func_02166834(a0, a1);
loc_021669F8:
*q = a0;
a0 = 0;
    return a0;}




int func_02166A00(void *a, void *b)
{
    void *r6 = func_0215A5F4((void *)b);
    void *r7 = func_0215A5DC((void *)b);
    int v1;
    unsigned short *v2;
    unsigned short *v3;
    unsigned short *v4;
    int t;
    func_02012F38((int)func_020120F4((void *)r7));
    v1 = func_02159B10(a, b);
    v2 = func_02159AE8((void *)a, (void *)b);
    v3 = func_02159AE8((void *)a, (void *)b);
    v4 = func_02159AE8((void *)a, (void *)b);
    t = (int)func_02166854(r7, v1, (u32)v2, (u32)v3, (u32)v4);
    if (t == 0)
        return 1;
    func_0215897C(r6, (void *)t);
    return 1;
}


void func_02166A6C(void)
{
    int i;
    int m[4];
    float x;
    float t;
    float z = 0.0f;
    if (*(volatile u16 *)0x04000004 & 1) {
        x = d_02172BA4 + d_021729FC;
        d_02172BA4 = x;
        if (1.0f / x > z)
            t = 4096.0f * (1.0f / x) + 0.5f;
        else
            t = 4096.0f * (1.0f / x) - 0.5f;
        i = (int)t;
        func_0207AD58(m, i, i);
        func_0207D59C((void *)0x04000020, m, 0x80, 0x5c, 0, 0);
    }
}
