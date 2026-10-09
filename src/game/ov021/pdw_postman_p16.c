/*
 * file:     pdw_postman_p16.c
 * unit:     yes
 * function: func_021B835C, func_021B836C, func_021B8378, func_021B83B0, func_021B83FC, func_021B8484, func_021B8514, func_021B854C, func_021B8658, func_021B8674, func_021B868C
 * address:  0x021B835C
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
 *   func_021B8848  0x021B8848  thumb  ov021
 *   func_021B8820  0x021B8820  thumb  ov021
 *   func_021B9280  0x021B9280  thumb
 *   func_021B7DC0  0x021B7DC0  thumb  ov021
 *   func_021B7EE4  0x021B7EE4  thumb  ov021
 *   func_021B91F8  0x021B91F8  thumb  ov021
 *   func_021B9510  0x021B9510  thumb
 *   func_021B87FC  0x021B87FC  thumb
 *   func_021B95C0  0x021B95C0  thumb
 *   func_021B87D8  0x021B87D8  thumb
 *   func_021B93D4  0x021B93D4  thumb
 *   func_021B9278  0x021B9278  thumb
 *   func_021B963C  0x021B963C  thumb
 */
#include "../../matched/include/Obj00454.h"
#include "../../matched/include/Obj18118.h"
#include "../../matched/include/Obj18119.h"
#include "../../matched/include/Obj03135.h"
#include "../../matched/include/Obj00010.h"
#include "../../matched/include/Obj02052.h"
#include "../../matched/include/Obj04134.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int s32;

struct Ent { char pad[0x48]; };

struct Tbl { char pad00[2]; volatile u16 f2; char pad04[0x10]; struct Ent *f14; };

struct Obj {
    char pad00[4];
    struct Ent *f4;
    char pad08[4];
    s32 fC;
    s32 f10;
    s32 f14;
    char pad18[0xC];
    struct Tbl *f24;
};

typedef struct { u16 a, b, c, d; } Q;

typedef struct { int x, y, z; } V;

extern void func_021B8848(u32 a, u32 b);
extern void func_021B8820(u32 a, u32 b);
extern int func_021B9280(u8 *a, u32 arg2, u32 arg3, u8 *tbl);
void func_021B7DC0(u8 *p, Q *q);
void func_021B7EE4(u8 *p, Q *q);
void func_021B91F8(u8 *p, V *v);
u8 *func_021B9510(u16 *p, u8 *q, u32 v);
u8 *func_021B87FC(u8 *p, u32 idx);
int func_021B95C0(u8 *p, u8 *q, int a3, int a4, u8 *sr, u32 a6);
u8 *func_021B87D8(u8 *p, u32 idx);
int func_021B93D4(int dir);
int func_021B9278(u32 a, u32 b, u32 c);
int func_021B963C(u8 *a, u8 *b);
void func_021B835C(u8 *p);
void func_021B836C(u8 *p, u8 *q);
int func_021B8378(int x);
int func_021B83B0(const s32 *a, const s32 *b, s32 r);
void func_021B83FC(struct Obj *o, u16 *out0, u16 *out1, u16 *out2);
void func_021B8484(u8 *p, u32 a, u32 b, int c);
u8 *func_021B8514(u8 *p, u32 v, u8 *q, u16 *r, int flag);
int func_021B854C(u8 *p, u8 *a, u32 arg3, int arg4, int arg5, int arg6, int arg7);
void func_021B8658(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
int func_021B8674(u8 *p, u32 *q, u32 v);
int func_021B868C(u8 *p, u32 *q, void *v);



void func_021B835C(u8 *p)
{
    func_021B8848(*(u32 *)&((struct Obj00454 *)p)->f24, *(u32 *)(*(u32 *)&((struct Obj00454 *)p)->f4 + 0xc));
}



/*
 * Tail call with a field of each argument.
 *
 * Addresses are Black-image addresses.
 */
void func_021B836C(u8 *p, u8 *q)
{
    func_021B8820(((struct Obj18118 *)p)->f24, ((struct Obj18119 *)q)->f3C);
}



int func_021B8378(int x)
{
    u32 ax = x < 0 ? -x : x;

    if ((ax & 15) >= 8) {
        if (x >= 0) {
            return x / 16 + 1;
        } else {
            return x / 16 - 1;
        }
    }
    return x / 16;
}



/*
 * Addresses are Black-image addresses.
 */
int func_021B83B0(const s32 *a, const s32 *b, s32 r)
{
    s32 dx, dz, dy, rr, d2, r2;

    dx = (a[0] >> 12) - (b[0] >> 12);
    dz = (a[2] >> 12) - (b[2] >> 12);
    d2 = dx * dx + dz * dz;
    dy = a[1] - b[1];
    if (dy < 0)
        dy = -dy;
    rr = (r >> 12) * 2;
    r2 = rr * rr;
    if (dy < 0x8000 && d2 < r2)
        return 1;
    return 0;
}



/*
 * note: Tbl.f2 is volatile: the original re-reads the count on every pass and the
 *       loop names o->f24 directly (no local for it).
 *
 * Addresses are Black-image addresses.
 */
void func_021B83FC(struct Obj *o, u16 *out0, u16 *out1, u16 *out2)
{
    s32 idx, i, m, n;

    m = func_021B9280((u8 *)o->f4, 0, o->f10, (u8 *)o->f24);
    n = func_021B9280((u8 *)o->f4, o->f10, o->f10, (u8 *)o->f24);
    if (m < n)
        m = n;
    idx = 0;
    for (i = 0; i < o->f24->f2; i++) {
        if (o->f4 == o->f24->f14 + i)
            idx = i;
    }
    *out0 = idx;
    *out1 = o->fC / 16;
    *out2 = o->f14 / 16 + m / 16;
}



void func_021B8484(u8 *p, u32 a, u32 b, int c)
{
    Q q;

    func_021B7DC0(p, &q);
    q.a = a;
    q.c = 0;
    q.d = b;
    func_021B7EE4(p, &q);
    q.c = c - ((struct Obj03135 *)p)->f18 / 16;
    func_021B91F8(p, (V *)(p + 0x38));
    ((struct Obj03135 *)p)->f5C = q.a;
    ((struct Obj03135 *)p)->f5E = q.b;
    ((struct Obj03135 *)p)->f60 = q.c;
    ((struct Obj03135 *)p)->f62 = q.d;
    ((struct Obj03135 *)p)->f64 = q.a;
    ((struct Obj03135 *)p)->f66 = q.b;
    ((struct Obj03135 *)p)->f68 = q.c;
    ((struct Obj03135 *)p)->f6A = q.d;
    *(V *)(p + 0x44) = *(V *)(p + 0x38);
}



u8 *func_021B8514(u8 *p, u32 v, u8 *q, u16 *r, int flag)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (v == ((u32 *)p)[i + 4]) {
            if (flag)
                return func_021B9510(r, q, ((u32 *)p)[i]);
            return func_021B87FC(q, ((u32 *)p)[i]);
        }
    }
    return 0;
}



/*
 * closed 2026-09-27 (tree_ov018): the early exit is one guard,
 * if (arg4 < arg6 && arg4 >= 0) goto tail; ahead of a plain if/else for the
 * two row lookups, and arg6 is reassigned in place of a separate m local.
 * Addresses are Black-image addresses.
 */
int func_021B854C(u8 *p, u8 *a, u32 arg3, int arg4, int arg5, int arg6, int arg7)
{
    int res;

    if (func_021B95C0(*(u8 * *)&((struct Obj00010 *)p)->f28, a, arg4, arg5,
                      *(u8 * *)&((struct Obj00010 *)p)->f24, *(u32 *)&((struct Obj00010 *)p)->f1C) == 0)
        return 0;
    if ((arg5 < 0 ? -arg5 : arg5) > arg7)
        return 0;
    if (arg4 < arg6 && arg4 >= 0)
        goto tail;
    if (arg4 >= arg6) {
        u8 *row = func_021B87D8(*(u8 * *)&((struct Obj00010 *)p)->f24, ((struct Obj02052 *)a)->f4);
        res = (int)func_021B8514(row, ((struct Obj02052 *)a)->f8,
                                  *(u8 * *)&((struct Obj00010 *)p)->f24, *(u16 * *)&((struct Obj00010 *)p)->f28, 1);
    } else {
        u8 *row = func_021B87D8(*(u8 * *)&((struct Obj00010 *)p)->f24, ((struct Obj02052 *)a)->f0);
        res = (int)func_021B8514(row, func_021B93D4(((struct Obj02052 *)a)->f8),
                                  *(u8 * *)&((struct Obj00010 *)p)->f24, *(u16 * *)&((struct Obj00010 *)p)->f28, 1);
    }
    if (res == 0) {
        if (arg4 > arg6)
            return 0;
        goto tail;
    }
    a = (u8 *)res;
    if (arg4 >= arg6) {
        arg4 -= arg6;
        arg6 = func_021B9278(res, *(u32 *)&((struct Obj00010 *)p)->f1C, *(u32 *)&((struct Obj00010 *)p)->f24);
        arg7 = (u32)func_021B9280((u8 *)res, arg4, arg6, *(u8 * *)&((struct Obj00010 *)p)->f24);
    } else if (arg4 < 0) {
        arg6 = func_021B9278(res, *(u32 *)&((struct Obj00010 *)p)->f1C, *(u32 *)&((struct Obj00010 *)p)->f24);
        arg4 += arg6;
        arg7 = (u32)func_021B9280((u8 *)res, arg4, arg6, *(u8 * *)&((struct Obj00010 *)p)->f24);
    }
    if (arg4 >= arg6)
        return 0;
    if ((arg5 < 0 ? -arg5 : arg5) > (int)arg7)
        return 0;
tail:
    func_021B8658(p, (u32)a, arg3, arg4, arg5, arg6, (int)arg7);
    func_021B963C(a, *(u8 * *)&((struct Obj00010 *)p)->f24);
    return arg3;
}



void func_021B8658(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f)
{
    ((struct Obj04134 *)p)->f0 = 1;
    ((struct Obj04134 *)p)->f4 = a;
    ((struct Obj04134 *)p)->f14 = d;
    ((struct Obj04134 *)p)->f10 = e;
    ((struct Obj04134 *)p)->f20 = b;
    ((struct Obj04134 *)p)->fC = c;
    ((struct Obj04134 *)p)->f18 = f;
}



int func_021B8674(u8 *p, u32 *q, u32 v)
{
    return func_021B87D8(p, *q) == (u8 *)v;
}



int func_021B868C(u8 *p, u32 *q, void *v)
{
    return func_021B87D8(p, q[1]) == (u8 *)v;
}
