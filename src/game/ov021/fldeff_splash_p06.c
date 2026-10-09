/*
 * file:     fldeff_splash_p06.c
 * unit:     yes
 * function: func_021C577C, func_021C5880, func_021C58CC, func_021C59A8, func_021C59BC, func_021C59F8, func_021C5A28, func_021C5A54, func_021C5AAC, func_021C5B58, func_021C5BD0, func_021C5C08, func_021C5C64, func_021C5D10, func_021C5DF4
 * address:  0x021C577C
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
 *   func_02020350 0x02020350 thumb
 *   func_02020314 0x02020314 thumb
 *   func_02020324 0x02020324 thumb
 *   func_020202FC 0x020202FC thumb
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0200C468 0x0200C468 thumb
 *   func_0200C464 0x0200C464 thumb
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_021C576C 0x021C576C thumb ov021
 *   func_0201FF30 0x0201FF30 thumb
 *   d_021DAA80    0x021DAA80 data  a4
 *   func_0202020C  0x0202020C  thumb
 *   func_0201F868  0x0201F868  thumb
 *   func_020146F8  0x020146F8  thumb
 *   func_02014728  0x02014728  thumb
 *   func_02012374  0x02012374  thumb
 *   abs_id_C2      0x000000C2  data
 *   d_021F5580     0x021F5580  data  ov075  a4
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0216BFD4  0x0216BFD4  thumb  ov010
 *   func_02017E40  0x02017E40  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_0216C0C0  0x0216C0C0  thumb  ov010
 *   ov171_id       0x000000AB  data  a1
 *   d_021DEA44    0x021DEA44  data  ov021  a1
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021A3364  0x021A3364  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_0218DAEC  0x0218DAEC  thumb
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB2E8  0x021AB2E8  thumb  ov021
 *   func_021AB3B0  0x021AB3B0  thumb
 *   func_02164208  0x02164208  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A34EC  0x021A34EC  thumb  ov021
 *   func_021AA900  0x021AA900  thumb  ov021
 *   func_021AA180  0x021AA180  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_021A2F48  0x021A2F48  thumb  ov021
 *   func_021A2F54  0x021A2F54  thumb  ov021
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_021C5FA8  0x021C5FA8  thumb  ov021
 *   func_021C602C  0x021C602C  thumb  ov021
 *   func_02005728  0x02005728  thumb
 *   func_021C5FC0  0x021C5FC0  thumb  ov021
 *   func_021C5FEC  0x021C5FEC  thumb  ov021
 *   func_021C6018  0x021C6018  thumb  ov021
 *   func_021C6054  0x021C6054  thumb  ov021
 *   func_02158780  0x02158780  thumb  ov010
 *   func_021AA8EC  0x021AA8EC  thumb  ov021
 *   func_020130B4  0x020130B4  thumb
 *   func_0216E7C8  0x0216E7C8  thumb  ov010
 *   func_0201235C  0x0201235C  thumb
 */
#include "../../matched/include/Obj04282.h"
#include "../../matched/include/Obj00874.h"
#include "../../matched/include/Obj12133.h"
#include "../../matched/include/Obj09688.h"

struct Obj;
struct Slot;
struct Src;
struct Actor;
struct PtS;
struct Vec2;
struct Desc;
struct Evt;
struct Big;
struct BigObj;
struct Ctx;
struct Sub02008C20Obj;
struct Obj00020;
struct Self;
struct VecFx32;
struct S0201235C;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    void *arr;
    void *cb04;
    void *cb08;
    u32 w0c;
    u16 count;
    u16 rows;
    u8 f14[8];
    void *w1c;
    u16 h20;
    u16 h22;
    u32 w24;
    void *w28;
    u32 w2c;
    u32 w30;
} Tmpl;

typedef signed short   s16_021C59A8;

typedef signed char    s8;

typedef short s16_021C59F8;

typedef struct {
    s16_021C59F8 x;
    s16_021C59F8 y;
} P2;

typedef struct {
    u8 pad[0x28];
    u32 h[3];
} S;

struct Work_021C5AAC {
    void *a;
    void *f04;
    int *f08;
    int f0C;
    int f10;
    int f14;
};

typedef struct {
    void *owner;
    void *f4;
    u32 f8;
    u16 hC;
    u16 pad;
    u32 f10;
} W;

typedef struct {
    int f0;
    int f4;
    u16 f8[3];
    u16 fE;
    u16 *f10;
} Arg;

typedef short s16;

typedef int fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct {
    void *f0;
    void *f4;
    u8 *f8;
    void *fC;
    u32 f10;
    void *f14;
    void *f18;
    void *f1C;
    s16 f20[3];
    u16 pad26;
    u32 f28;
    u8 pad2C[8];
    VecFx32 f34;
    VecFx32 f40;
    u8 pad4C[0xC];
    u8 f58;
    u8 f59;
    u16 f5A;
    u8 pad5C[8];
    void *f64;
} Work_021C5D10;

typedef struct {
    void *f0;
    void *f4;
    u8 *f8;
    void *fC;
    u32 f10;
    void *f14;
    u32 f18;
    u32 f1C;
    u8 pad20[0x39];
    u8 f59;
    u16 f5A;
    u32 f5C;
    u32 f60;
    void *f64;
} Work_021C5DF4;

extern u32 func_02020350(struct Obj *obj, u32 what);
extern u16 func_02020314(struct Obj *obj);
extern u16 func_02020324(struct Obj *obj, u32 n);
extern void func_020202FC(struct Obj *obj, u16 *a, u16 *b);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 bit);
extern u16 func_0200C468(const u8 *a);
extern u8 func_0200C464(const u8 *a, u32 i);
extern void *func_0201F81C(int n, u32 heap);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern void func_021C576C(void *a);
extern struct Obj *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap);
extern u32 func_0201F868(void *p);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
extern void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
extern void *func_02014728(char *a0, int a1, int a2, int a3, int a4);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *a);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_0201AB28(void *p, u32 idx);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *a);
extern u32 func_02017E1C(void *a, u32 b, u32 c);
extern int *func_0216BFD4(int a, int b, int c, int d, int e, int f, void *g);
extern void func_02017E40(void *p, u32 id, u32 v);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern int func_0216C0C0(int a0);
extern u32 func_02188C98(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(u8 *p);
extern u16 func_0216D5F8(void *p);
extern void func_021A3364(u32 *a, int b, int *out);
extern u32 func_02188CFC(u8 *p);
extern int func_0218DAEC(u32 a, int *b, u32 *out);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB2E8(int id);
extern int func_021AB3B0(u16 id);
extern void func_02164208(int dir, int *p, int amt);
extern u32 func_02082BCC(void *p, int v, u32 n);
extern u32 func_02188CE8(u8 *p);
extern void *func_02188C7C(u8 *q);
extern void func_021A3038(unsigned char *id, struct VecFx32 *out);
extern int func_021A34EC(u8 *p);
extern int func_021AA900(struct Self *self, short *pos);
/* Retain the mode used to store f59 for the helper's second argument. */
extern struct Obj *func_021AA180(struct Ctx *ctx, int mode);
extern void func_0216D9A0(void *o);
extern void func_021A2F48(u8 *p, u32 a1);
extern int func_021A2F54(u8 *p);
extern void func_0216D674(void *p, u16 v);
extern void func_020061E4(u32 a);
extern int func_021C5FA8(Work_021C5DF4 *w, u32 n);
extern void func_021C602C(u8 *p);
extern u32 func_02005728(u32 v);
extern int func_021C5FC0(u8 *p, u32 lim);
extern void func_021C5FEC(u8 *p);
extern void func_021C6018(u32 *p);
extern void func_021C6054(u32 *p);
extern int func_02158780(void *p, u16 b, int c, int d, u16 e);
extern void func_021AA8EC(u8 *p);
extern int func_020130B4(int a0);
extern int func_0216E7C8(int a0, int a1, int a2, int a3, int a4);
extern void func_0201235C(struct S0201235C *o, u32 *out);
void func_021C577C(void *list);
void func_021C5880(u16 *a, u16 *b, u16 c);
void func_021C58CC(char *p, u16 a, u16 b, u32 heap);
int func_021C59A8(u32 a, u32 b, u32 c);
void func_021C59BC(void *a, u8 *p);
void func_021C59F8(S *p, int v);
void *func_021C5A28(void *a, u32 b, u32 c, u32 d);
int func_021C5A54(int a, int *st, int *c);
int func_021C5AAC(void *a, int b, int c, int d);
int func_021C5B58(int a, int *st, int *c);
void *func_021C5BD0(void *a, u32 b, u32 c);
int func_021C5C08(void *a, int *st, Arg *p);
int func_021C5C64(u32 unused, u32 a, u32 *out);
void *func_021C5D10(struct Obj00020 *a, void *b);
int func_021C5DF4(void *task, int *state, Work_021C5DF4 *w);
extern const Tmpl d_021DAA80;
extern char d_021F5580;
extern unsigned char abs_id_C2[];
extern char d_021DEA44[];
extern char ov171_id[];



void func_021C577C(void *list)
{
    u16 v[2];
    char *w;
    u16 x;
    u32 y;
    u32 s;
    u32 t;
    u32 d;
    u16 a;

    w = (char *)func_02020350(list, 0x13);
    x = func_02020314(list) >> 3;
    y = func_02020350(list, 9) >> 3;
    if (((struct Obj04282 *)w)->f24 == 0) {
        func_020413B0(1, 1, 12, 30, 12, 11);
        func_020413B0(1, 1, x + 12, 30, y, 12);
        func_020413B0(1, 0, 11, 32, 1, 10);
        func_02041B6C(1);
    } else if (((struct Obj04282 *)w)->f24 == 1) {
        func_020413B0(1, 1, 12, 30, 12, 11);
        func_020202FC(list, &v[1], &v[0]);
        s = func_02020350(list, 8);
        t = func_02020350(list, 9);
        d = ((struct Obj04282 *)w)->f1E + ((struct Obj04282 *)w)->f1C - v[1];
        s = s + d * t;
        func_020413B0(1, 1, (s >> 3) + 12, 30, y, 12);
        func_020413B0(1, 0, 11, 32, 1, 10);
        func_02041B6C(1);
    }
    if (((struct Obj04282 *)w)->f40 == 1) {
        a = func_02020350(((struct Obj04282 *)w)->f4, 3);
        a = func_02020324(((struct Obj04282 *)w)->f4, a) >> 3;
        func_021C59F8((S *)w, (a + 12) << 3);
    } else {
        func_021C59F8((S *)w, (x + 12) << 3);
    }
}



void func_021C5880(u16 *a, u16 *b, u16 c)
{
    int s = *a + *b;

    if (c <= 5) {
        *b = s;
        *a = 0;
        return;
    }
    if (s <= 3) {
        *b = s;
        *a = 0;
        return;
    }
    if (s <= (int)c - 2 && s > 3) {
        *a = s - 3;
        *b = 3;
        return;
    }
    if (s == (int)c - 1) {
        *a = s - 4;
        *b = 4;
    }
}



void func_021C58CC(char *p, u16 a, u16 b, u32 heap)
{
    Tmpl t;
    u32 n;
    u32 i;

    n = func_0200C468(((struct Obj00874 *)p)->f20);
    ((struct Obj00874 *)p)->f0 = func_0201F81C(n, heap);
    for (i = 0; i < n; i++) {
        u8 v = func_0200C464(((struct Obj00874 *)p)->f20, (u8)i);
        func_0201F878(((struct Obj00874 *)p)->f0, ((struct Obj00874 *)p)->f38, (int)v, (int)v, heap);
    }
    while (b + a >= n) {
        if (b != 0) {
            b--;
        } else if (a != 0) {
            a--;
        }
    }
    func_021C5880(&a, &b, n);
    t = d_021DAA80;
    t.arr = ((struct Obj00874 *)p)->f0;
    t.count = n;
    t.cb04 = (void *)func_021C576C;
    t.cb08 = 0;
    t.w0c = *(u32 *)&((struct Obj00874 *)p)->f8;
    t.w1c = p;
    t.w24 = ((struct Obj00874 *)p)->f38;
    t.w28 = p + 0x10;
    t.w2c = ((struct Obj00874 *)p)->fC;
    t.w30 = ((struct Obj00874 *)p)->f3C;
    ((struct Obj00874 *)p)->f4 = func_0201FF30((struct Src *)(&t), a, b, heap);
}




/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C59A8(u32 a, u32 b, u32 c)
{
func_0202020C((struct Obj *)(((struct Obj12133 *)((u8 *)(a)))->f4), (u16 *)b, (u16 *)c);
return func_0201F868((void *)(((struct Obj12133 *)((u8 *)(a)))->f0));
}




/*
 * Scroll step: slides the BG by 0xC0/4 per frame and flags the end after 4.
 */
void func_021C59BC(void *a, u8 *p)
{
    u16 n = ((struct Obj09688 *)p)->f72;
    int v = n * 0xC0 / 4 - 0xC0;

    (((struct Obj09688 *)p)->f72)++;
    if (n >= 4) {
        v = 0;
        ((struct Obj09688 *)p)->f80 = 1;
    }
    func_02040618(1, 3, v);
}




/*
 * Sets the y offset of the three sprite handles (EXACT*: pad). The split i =
 * 0; y = v; ordering is what schedules the zero before the sign extension.
 */
void func_021C59F8(S *p, int v)
{
    s16_021C59F8 y;
    int i;
    P2 t;

    i = 0;
    y = v;
    for (; i < 3; i++) {
        func_0204B454((struct Actor *)p->h[i], (struct PtS *)&t, 0);
        t.y = y;
        func_0204B404((struct Obj *)p->h[i], (const struct Vec2 *)(&t), 0);
    }
}




/*
 * Spawns the func_021C5A54 task with a four-word work area.
 */
void *func_021C5A28(void *a, u32 b, u32 c, u32 d)
{
    void *t = func_020122C0(a, 0, func_021C5A54, 0x10);
    u32 *w = func_020124E8(t);

    w[0] = (u32)a;
    w[1] = b;
    w[2] = c;
    w[3] = d;
    return t;
}




/*
 * Blocked (MATCH, every concrete byte right): the pooled word 0x000000C2 is a
 * pooled small constant (abs_id_C2, R_ARM_ABS32) passed as the third argument
 * to func_020146F8 / func_02014728, neither of which is in match.py's
 * OVERLAY_ID_CONSUMERS, and no other pool word image-wide holds 0x000000C2,
 * so no evidence class attests it.  d_021F5580 resolves with the ov075 token.
 */
int func_021C5A54(int a, int *st, int *c)
{
    int r;

    switch (*st) {
    case 0:
        if (c[3] != 0) {
            r = (int)func_020146F8((char *)c[0], c[1], (int)abs_id_C2, (int)(&d_021F5580), c[2]);
        } else {
            r = (int)func_02014728((char *)c[0], c[1], (int)abs_id_C2, (int)(&d_021F5580), c[2]);
        }
        func_02012374((struct Evt *)a, (struct Evt **)r);
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}




int func_021C5AAC(void *a, int b, int c, int d)
{
    int h;
    struct Work_021C5AAC *p;
    int e;
    void *r6;
    int x;
    int y;

    if ((int)func_0201AA18(func_02012934(func_020120F4(a))) <= c) {
        c = 0;
    }
    h = (int)func_020122C0(a, 0, (void *)func_021C5B58, 0x18);
    p = func_020124E8((struct Obj *)h);
    p->a = a;
    p->f04 = func_0201210C(a);
    p->f10 = b;
    p->f14 = d;
    r6 = func_020120F4(p->a);
    e = (int)func_0201AB28(func_02012934(r6), c);
    r6 = func_0200C0F0(func_02012EBC(r6));
    x = func_02017E1C((void *)e, 5, 0);
    y = func_02017E1C((void *)e, 0x6f, 0) | (func_02017E1C((void *)e, 0x6e, 0) << 8);
    p->f08 = func_0216BFD4(4, 1, x, y, 0xa, 0, r6);
    p->f0C = e;
    return h;
}




int func_021C5B58(int a, int *st, int *c)
{
    int *q;
    int f;

    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, func_021C5A28((void *)c[0], c[1], c[2], c[5]));
        (*st)++;
        break;
    case 1:
        q = (int *)c[2];
        if (q[7] != 1) {
            func_02017E40((void *)c[3], 0x73, q[8]);
        }
        f = 1;
        if (((int *)c[2])[7] == 1) {
            f = 0;
        }
        *(u16 *)c[4] = f;
        if (*(u16 *)c[4] == 1) {
            func_02008DF0(func_02012F2C(func_020120F4((const struct Ctx *)c[0])), 0x1e);
        }
        func_0216C0C0(c[2]);
        return 1;
    }
    return 0;
}




/*
 * Spawns the func_021C5C08 task with a 0x14-byte work area.
 */
void *func_021C5BD0(void *a, u32 b, u32 c)
{
    void *t = func_020122C0(a, 0, func_021C5C08, 0x14);
    W *w = func_020124E8(t);

    w->owner = a;
    w->f4 = func_0201210C(a);
    w->f10 = c;
    w->f8 = (u32)func_020120F4(a);
    w->hC = b;
    return t;
}




/*
 *           func_020146F8 (0x020146F8), which is not in match.py
 *           OVERLAY_ID_CONSUMERS, so the ABS32 has no witness (literal class
 *           refuses the range's own pool word).  Every concrete byte matches.
 */
int func_021C5C08(void *a, int *st, Arg *p)
{
    int v;

    switch (*st) {
    case 0:
        func_02012374(a, func_020146F8((char *)p->f0, p->f4, (int)ov171_id, (int)d_021DEA44, (int)p->f8));
        *st = *st + 1;
        break;
    case 1:
        switch (p->fE) {
        case 0:
            v = 0;
            *p->f10 = v;
            break;
        case 1:
            v = 1;
            *p->f10 = v;
            break;
        }
        return 1;
    }
    return 0;
}




int func_021C5C64(u32 unused, u32 a, u32 *out)
{
    int v[3];
    u32 w[4];
    void *h1;
    u32 r;
    u8 s;

    r = func_02188C98((u8 *)a);
    h1 = func_02188CB4((void *)a);
    s = func_0216D5F8(func_021A3074((void *)h1));
    func_021A3364(h1, s, v);
    if (func_02188CFC((u8 *)a) == 1)
        return 0;
    if (func_0218DAEC(r, v, w) == 0)
        return 0;
    if (func_021AB2E8(func_021AB0F0(w[2])) == 1) {
        func_02164208(s, v, 0x10000);
        if (func_0218DAEC(r, v, w) == 0)
            return 0;
    }
    if (func_021AB3B0(func_021AB0F0(w[2])) == 0)
        return 0;
    if (out != 0) {
        out[0] = v[0];
        out[1] = w[3];
        out[2] = v[2];
    }
    return 1;
}




void *func_021C5D10(struct Obj00020 *a, void *b)
{
    void *task;
    Work_021C5D10 *w;
    int mode;

    task = func_020122C0(b, 0, func_021C5DF4, sizeof(Work_021C5D10));
    w = func_020124E8(task);
    func_02082BCC(w, 0, sizeof(Work_021C5D10));
    w->f0 = b;
    w->f8 = (u8 *)a;
    w->f4 = func_020120F4(b);
    w->fC = (void *)func_02188CE8(w->f8);
    w->f10 = (u32)func_02012F2C(w->f4);
    w->f14 = func_02188C7C(w->f8);
    w->f18 = func_02188CB4(a);
    w->f1C = func_021A3074(w->f18);
    w->f58 = func_0216D5F8(w->f1C);
    func_021A3038(w->f18, (struct VecFx32 *)&w->f34);
    w->f28 = func_021A34EC(w->f18);
    if (func_021C5C64((u32)w->f4, (u32)w->f8, (u32 *)(&w->f40)) == 0)
        w->f5A = 1;
    w->f20[0] = (w->f40.x >> 4) / 4096;
    w->f20[1] = (w->f40.y >> 4) / 4096;
    w->f20[2] = (w->f40.z >> 4) / 4096;
    if (func_021AA900(w->fC, w->f20))
        w->f59 = mode = 1;
    else
        w->f59 = mode = 0;
    w->f64 = func_021AA180(w->fC, mode);
    func_0216D9A0(w->f14);
    return task;
}




int func_021C5DF4(void *task, int *state, Work_021C5DF4 *w)
{
    int r;

    switch (*state) {
    case 0:
        if (w->f5A != 0) {
            *state = 8;
            break;
        }
        func_021A2F48((u8 *)w->f18, 0x200);
        (*state)++;
    case 1:
        if (func_021A2F54((u8 *)w->f18) != 1)
            break;
        func_0216D674((void *)w->f1C, 0);
        func_020061E4(0x684);
        (*state)++;
        break;
    case 2:
        if (func_021C5FA8(w, 15) == 0)
            break;
        func_021C602C((u8 *)w);
        if (w->f64 == 0) {
            *state = 5;
            break;
        }
        w->f5C = func_02005728(0x5a) + 0x1e;
        (*state)++;
        break;
    case 3:
        r = func_021C5FC0((u8 *)w, w->f5C);
        if (r == 1) {
            *state = 6;
            break;
        }
        if (r != 2)
            break;
        func_021C5FEC((u8 *)w);
        (*state)++;
        break;
    case 4:
        r = func_021C5FC0((u8 *)w, 0x1e);
        if (r == 0)
            break;
        func_021C6018((u32 *)w);
        if (r == 1) {
            func_021C6054((u32 *)w);
            func_0216D674((void *)w->f1C, 3);
            func_02158780(task, (u16)0x2796, (u32)0, (u32)0, (u32)0x15);
            *state = 10;
            break;
        }
        if (r != 2)
            break;
        func_02008DF0((struct Sub02008C20Obj *)w->f10, 0x50);
        *state = 7;
        break;
    case 5:
        r = func_021C5FC0((u8 *)w, 0x78);
        if (r != 2) {
            if (r == 1)
                *state = 6;
            break;
        }
    case 6:
    case 7:
        func_021C6054((u32 *)w);
        if (w->f64 != 0) {
            if (w->f59 == 1)
                func_021AA8EC(w->fC);
            func_020130B4((int)w->f64);
        }
        func_0216D674((void *)w->f1C, 1);
        func_02158780(task, (u16)(*state + 0x2792), (u32)0, (u32)0, (u32)0x15);
        *state = 8;
        break;
    case 8:
        func_021A2F48((u8 *)w->f18, 8);
        *state = 9;
    case 9:
        if (func_021A2F54((u8 *)w->f18) == 1)
            return 1;
        break;
    case 10:
        func_02008DF0((struct Sub02008C20Obj *)w->f10, 8);
        func_0201235C(task, (u32 *)func_0216E7C8((int)w->f0, (int)w->f8, (int)w->f64, 0, (u8)(w->f59 == 1 ? 1 : 4)));
        return 0;
    }
    return 0;
}
