/*
 * file:     pdw_postman_p05.c
 * unit:     yes
 * function: func_021B79F0, func_021B7A84, func_021B7C04
 * address:  0x021B79F0
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
 *   func_021B91AC  0x021B91AC  thumb
 *   func_021B8048  0x021B8048  thumb
 *   func_021B8820  0x021B8820  thumb
 *   func_021B8870  0x021B8870  thumb
 *   func_021B9510  0x021B9510  thumb  ov021
 *   func_021B87D8  0x021B87D8  thumb  ov021
 *   func_021B8848  0x021B8848  thumb  ov021
 *   func_021B88B8  0x021B88B8  thumb  ov021
 *   func_021B9828  0x021B9828  thumb  ov021
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CAE8  0x0207CAE8  arm
 *   func_0207CF3C  0x0207CF3C  arm
 *   d_021D9A00     0x021D9A00  data   a4
 *   func_021B94C0  0x021B94C0  thumb ov021
 *   func_021B9478  0x021B9478  thumb ov021
 *   func_021B949C  0x021B949C  thumb ov021
 */
#include "../../matched/include/Obj20053.h"

typedef unsigned short u16;

typedef unsigned int u32;

struct Info { char pad00[0x10]; u32 f10; char pad14[0x28]; u32 f3C; };

struct Sub { u16 f0; u16 pad2; struct Info *f4; char pad08[0x1C]; void *f24; };

typedef void (*Cb)(void *);

struct Obj { char pad00[2]; u16 f2; u16 f4; char pad06[0xE]; struct Sub *f14; u32 f18; };

typedef unsigned char  u8;

typedef int            fx32;

typedef struct { fx32 x, y, z; } VecFx32;

typedef struct { u16 a, b, c, d; } Rect4;

typedef struct Node {
    u8 pad[0x30];
    VecFx32 pos;
} Node;

typedef int (*HitFn)(int i, u8 *p, VecFx32 *hit, Rect4 *r, VecFx32 *out);

extern int func_021B91AC(u32 a);
extern u8 func_021B8048(u8 *p);
extern u32 *func_021B8820(void *p);
extern Cb func_021B8870(void *p, u32 v);
extern u8 *func_021B9510(u16 *p, u8 *q, u32 v);
extern u8 *func_021B87D8(u8 *p, u32 idx);
extern u32 *func_021B8848(u8 *a, u32 b);
extern HitFn func_021B88B8(u8 *a, u32 b);
extern int func_021B9828(VecFx32 *a, VecFx32 *b, VecFx32 *c, VecFx32 *d, VecFx32 *e, VecFx32 *f);
extern void func_0207CA00(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
extern void func_0207CAE8(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb);
extern fx32 func_0207CF3C(const VecFx32 *v1, const VecFx32 *v2);
extern int func_021B94C0(u16 *p, u16 v);
extern void func_021B9478(u16 *p, u16 v);
extern void func_021B949C(u16 *p, u16 v);
int func_021B79F0(struct Obj *o, int flag);
int func_021B7A84(u8 *p, const VecFx32 *pa, const VecFx32 *pb, Rect4 *r, VecFx32 *out);
void func_021B7C04(u8 *o, int k, int flag);
extern const VecFx32 d_021D9A00;


/*
 * Addresses are Black-image addresses.
 */
int func_021B79F0(struct Obj *o, int flag)
{
    struct Sub *t;
    Cb cb;

    cb = 0;
    t = o->f14;
    if (o->f2 == 0)
        return 0;
    if (o->f4 == 0)
        return 0;
    if (t == 0)
        return 0;
    if (func_021B91AC((u32)t) == 0)
        return 0;
    if (func_021B8048((u8 *)t) == 0 && o->f18 == 0 && flag == 0)
        return 0;
    switch (t->f0) {
    case 0:
        if (t->f4->f3C == 0xFFFF)
            break;
        goto lookup;
    case 1:
        if (t->f4->f10 == 0xFFFF)
            break;
lookup:
        cb = func_021B8870(t->f24, *func_021B8820(t->f24));
        break;
    }
    if (cb)
        cb(o);
    o->f18 = 0;
    return 1;
}


int func_021B7A84(u8 *p, const VecFx32 *pa, const VecFx32 *pb, Rect4 *r, VecFx32 *out)
{
    VecFx32 hit;
    VecFx32 d;
    VecFx32 n;
    VecFx32 up;
    VecFx32 bestPos;
    VecFx32 a;
    VecFx32 b;
    Rect4 bestR;
    int i;
    fx32 best;
    int found;
    u32 *t;
    Node *n0;
    Node *n1;
    u32 *m;
    HitFn f;
    fx32 dist;

    up = d_021D9A00;
    a = *pa;
    b = *pb;
    found = 0;
    for (i = 0; i < ((struct Obj20053 *)p)->f22; i++) {
        t = (u32 *)func_021B9510((u16 *)(p + 0x50), p + 0x20, i);
        if (t == 0) {
            continue;
        }
        n0 = (Node *)func_021B87D8(p + 0x20, t[0]);
        n1 = (Node *)func_021B87D8(p + 0x20, t[1]);
        m = func_021B8848(p + 0x20, t[3]);
        func_0207CA00(&n0->pos, &n1->pos, &d);
        func_0207CAE8(&d, &up, &n);
        if (func_021B9828(&d, &n, &n1->pos, &a, &b, &hit) == 0) {
            continue;
        }
        f = func_021B88B8(p + 0x20, *m);
        if (f == 0) {
            continue;
        }
        if (f(i, p, &hit, r, out) == 0) {
            continue;
        }
        if (!found) {
            bestR = *r;
            bestPos = *out;
            best = func_0207CF3C(&a, out);
            found = 1;
        } else {
            dist = func_0207CF3C(&a, out);
            if (dist < best) {
                bestR = *r;
                bestPos = *out;
                best = dist;
            }
        }
    }
    if (found) {
        *r = bestR;
        *out = bestPos;
    }
    return found;
}


void func_021B7C04(u8 *o, int k, int flag)
{
    if (flag == 0) {
        if (func_021B94C0((u16 *)(o + 0x50), k) == 0) {
            func_021B9478((u16 *)(o + 0x50), k);
        }
    } else {
        func_021B949C((u16 *)(o + 0x50), k);
    }
}
