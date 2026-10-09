/*
 * file:     event_field_proclink_p08.c
 * unit:     yes
 * function: func_021613CC, func_02161484, func_02161534, func_02161554, func_02161610, func_0216163C, func_02161668, func_021616A4, func_021616F0
 * address:  0x021613CC
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
 *   func_020120F4  0x020120F4  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02012934  0x02012934  thumb
 *   func_0202138C  0x0202138C  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_021C3CC0  0x021C3CC0  thumb  ov136
 *   func_021C3D44  0x021C3D44  thumb  ov136
 *   func_021C3DA4  0x021C3DA4  thumb  ov136
 *   ov136_id       0x00000088  data
 *   func_02034A5C 0x02034A5C arm
 *   func_021C3E00 0x021C3E00 thumb ov136
 *   func_021C3E04 0x021C3E04 thumb ov136
 *   func_021C3E24 0x021C3E24 thumb ov136
 *   func_020127A4  0x020127A4  thumb
 *   func_02012984  0x02012984  thumb
 *   func_0201B2B0  0x0201B2B0  thumb
 *   func_02030734  0x02030734  arm
 *   d_02172978     0x02172978  data  a1
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02169AB8  0x02169AB8  thumb  ov010
 */
#include "../../matched/include/Obj05854.h"
#include "../../matched/include/Obj18944.h"
#include "../../matched/include/Obj04884.h"
#include "../../matched/include/Obj00029.h"
#include "../../matched/include/Obj00654.h"

struct BigObj;
struct Ctx_02161484;
struct Desc;
struct Obj;
struct Big;
struct Ctx;
struct Work;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Ctx_021613CC {
    u8 pad00[0x18];
    u32 **f18;          /* 0x18 */
    u8 pad1c[0x60 - 0x1C];
    u8 f60;             /* 0x60 */
    u8 pad61;
    u16 f62;            /* 0x62 */
    u8 pad64[4];
    u32 f68;            /* 0x68 */
} Ctx_021613CC;

typedef struct Src_021613CC {
    u8 pad00[0x2C];
    u32 f2c;            /* 0x2C */
    u8 pad30[8];
    u32 f38;            /* 0x38 */
    u32 f3c;            /* 0x3C */
    u32 f40;            /* 0x40 */
    u16 f44;            /* 0x44 */
} Src_021613CC;

typedef signed int     s32;

typedef struct Ctx_02161484 {
    u8 pad00[8];
    u32 f08;
    u32 f0c;
    u8 pad10[8];
    u32 **f18;
    u8 pad1c[0x60 - 0x1C];
    u8 f60;
    u8 pad61[7];
    u32 f68;
} Ctx_02161484;

typedef struct Src_02161484 {
    u8 pad00[0x3C];
    u32 f3c;            /* 0x3C */
    u32 f40;            /* 0x40 */
    u16 f44;            /* 0x44 */
} Src_02161484;

typedef struct Rec {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u16 f08;            /* 0x08 */
    u8 f0a;             /* 0x0A */
    u8 f0b;             /* 0x0B */
    u32 f0c;            /* 0x0C */
    u32 f10;            /* 0x10 */
} Rec;

typedef struct { u8 pad00[0xc]; int f0C; } Sub_02161668;

typedef struct { u8 pad00[0xc]; int f0C; u8 pad10[8]; Sub_02161668 *f18; } Work_02161668;

typedef struct { u8 pad00[0xc]; int f0C; } Evt_02161668;

extern void *func_020120F4(const struct Ctx_021613CC *p);
extern int func_02034AC4(s32 handle);
extern void *func_02012934(const struct BigObj *p);
extern u8 func_0202138C(u16 v);
extern void *func_0201AB28(void *a, u32 b);
extern void *func_021C3CC0(void *a, unsigned b, unsigned c, unsigned d, unsigned heap);
extern void *func_021C3D44(void *a, void *b, unsigned heap);
extern void *func_021C3DA4(void *a, void *b, unsigned heap);
extern void func_02034A5C(s32 handle);
extern u32 func_021C3E00(u32 *p);
extern int func_021C3E04(u32 *p, void *q);
extern void func_021C3E24(unsigned char *);
extern u16 *func_020127A4(void *sv);
extern u8 func_02012984(const struct BigObj *p);
extern u32 func_0201B2B0(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void *func_02012EBC(struct Big *p);
void func_02082BCC(void *p, int v, int n);
extern int func_02169AB8(struct Work *w, u32 *state);
int func_021613CC(Ctx_021613CC *c, int a1, int mode, const Src_021613CC *src);
int func_02161484(Ctx_02161484 *c, void *p);
void func_02161534(unsigned char *p);
Rec *func_02161554(Ctx_02161484 *c, int a1, int mode, const Src_02161484 *src);
int func_02161610(int a0);
u32 *func_0216163C(char *c);
int func_02161668(Work_02161668 *w, Evt_02161668 *e);
void *func_021616A4(void *p, int a1, int a2, int a3, int a4);
int func_021616F0(int a0, int a1, int a2);
extern u8 ov136_id[];
extern const char d_02172978[];



int func_021613CC(Ctx_021613CC *c, int a1, int mode, const Src_021613CC *src)
{
    void *sv;
    void *t;
    u32 v;
    int r;
    u16 h;

    sv = func_020120F4((const struct Ctx_021613CC *)(*c->f18));
    func_02034AC4((u32)ov136_id);
    if (mode == 0) {
        t = func_02012934(sv);
        v = src->f3c;
        c->f60 = v;
        h = src->f44;
        c->f62 = h;
        if (src->f40 == 6)
            return (int)func_021C3CC0(sv, 2, (u8)src->f3c, func_0202138C(h), 4);
        c->f68 = 1;
        return (int)func_021C3D44(sv, func_0201AB28(t, v), 4);
    }
    if (src->f2c == 2) {
        r = (int)func_021C3CC0(sv, 2, (u8)src->f38, func_0202138C((u16)src->f38), 4);
        c->f62 = src->f38;
        return r;
    }
    c->f68 = 1;
    return (int)func_021C3DA4(sv, (void *)func_0202138C((u16)src->f38), 4);
}




/*
 * Lever: second state writes f0c separately in each arm; cross-jumping
 * retains the dead branch after func_021C3E04 rather than after movs #0.
 */
int func_02161484(Ctx_02161484 *c, void *p)
{
    void *sv;
    u32 v;
    sv = func_020120F4((const struct Ctx_021613CC *)((const struct Ctx_02161484 *)(*c->f18)));
    if (c->f08 == 0) {
        if (c->f68 == 0 || c->f68 == 2) {
            if (func_021C3E00(p) == 1) {
                func_021C3E04(p, func_0201AB28(func_02012934(sv), c->f60));
                v = 0;
            } else if (c->f68 == 0) {
                v = 2;
            } else {
                v = 0;
            }
        } else {
            v = 0;
        }
        c->f0c = v;
        func_02034A5C((u32)ov136_id);
        return 4;
    }
    if (c->f08 == 2) {
        if (c->f68 == 2) {
            if (func_021C3E00(p) == 1) {
                func_021C3E04(p, func_0201AB28(func_02012934(sv), c->f60));
                c->f0c = 0;
            } else {
                c->f0c = 0;
            }
        } else {
            c->f0c = 2;
        }
        func_02034A5C((u32)ov136_id);
        return 4;
    }
    c->f0c = 2;
    func_02034A5C((u32)ov136_id);
    return 4;
}




void func_02161534(unsigned char *p) { func_02034AC4((u32)ov136_id); func_021C3E24(p); func_02034A5C((u32)ov136_id); }






Rec *func_02161554(Ctx_02161484 *c, int a1, int mode, const Src_02161484 *src)
{
    Rec *r;
    void *sv;
    void *t;
    void *k;
    u32 out;
    u32 res;
    u8 x;

    sv = func_020120F4((const struct Ctx_021613CC *)((const struct Ctx_02161484 *)(*c->f18)));
    r = 0;
    if (mode == 0) {
        t = func_02012934(sv);
        if (src->f40 == 8) {
            c->f68 = 3;
            k = func_0201AB28(t, src->f3c);
            x = func_02012984(sv);
            res = func_0201B2B0(t, k, 3, src->f44, x, &out, 4);
        } else {
            c->f68 = 4;
            k = func_0201AB28(t, src->f3c);
            res = func_0201B2B0(t, k, 0, *func_020127A4(sv), func_02012984(sv), &out, 4);
        }
        r = func_02030734(4, 0x14, 0, d_02172978, 0x868);
        r->f00 = sv;
        r->f04 = t;
        r->f08 = res;
        r->f0a = src->f3c;
        r->f0b = out;
        r->f0c = 1;
        r->f10 = 1;
    }
    return r;
}






int func_02161610(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj05854 *)t4)->f18;
a0 = ((struct Obj05854 *)((char *)a0))->f0;
    func_020120F4((const struct Ctx_021613CC *)((const struct Ctx_02161484 *)a0));
loc_0216161C:
a0 = ((struct Obj05854 *)t4)->f68;
    if (a0 != 3) goto loc_0216162A;
loc_02161622:
a0 = 2;
((struct Obj05854 *)t4)->fC = a0;
a0 = 4;
    return a0;
loc_0216162A:
    if (a0 != 4) goto loc_02161636;
loc_0216162E:
a0 = 0;
((struct Obj05854 *)t4)->fC = a0;
a0 = 4;
    return a0;
loc_02161636:
a0 = 0;
    return a0;}





/*
 * Allocate an 0x10-byte record and store the save handle at +4.
 * The extent also holds the unlabelled leaf at 0x02161668.
 */
u32 *func_0216163C(char *c)
{
    u32 *r;

    r = func_02030734(4, 0x10, 1, d_02172978, 0x8AC);
    r[1] = (u32)func_020120F4((const struct Ctx_021613CC *)(**(void ** *)&((struct Obj18944 *)c)->f18));
    return r;
}

int func_02161668(Work_02161668 *w, Evt_02161668 *e)
{
    if (w->f18->f0C == 0xb) {
        switch (e->f0C) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return 0;
        }
    }
    switch (e->f0C) {
    case 0:
        w->f0C = 2;
        return 4;
    case 1:
        return 1;
    default:
        return 0;
    }
}



/*
 * Allocator with callback, zero-fills the node, then fills link fields.
 */
void *func_021616A4(void *p, int a1, int a2, int a3, int a4)
{
    void *r0v = func_020122C0(p, 0, func_021616F0, 0x1C);
    char *r4 = func_020124E8(r0v);

    func_02082BCC(r4, 0, 0x1C);
    ((struct Obj04884 *)r4)->fC = a3;
    ((struct Obj04884 *)r4)->f10 = a2;
    ((struct Obj04884 *)r4)->f4 = (int)p;
    ((struct Obj04884 *)r4)->f8 = a1;
    ((struct Obj04884 *)r4)->f0 = (int)func_02012EBC(func_020120F4(p));
    ((struct Obj04884 *)r4)->f14 = a4;
    return r0v;
}



int func_021616F0(int a0, int a1, int a2)
{
    int t4;

t4 = a2 + 0;
a0 = t4 + 0;
    a0 = func_02169AB8((struct Work *)a0, (u32 *)a1);
loc_021616FA:
    if (a0 == 0) goto loc_02161704;
loc_021616FE:
    if (a0 == 1) goto loc_0216170C;
loc_02161702:
    goto loc_02161716;
loc_02161704:
a1 = ((struct Obj00029 *)t4)->f14;
a0 = 1;
*(int *)&((struct Obj00654 *)((char *)a1))->f0 = a0;
    return a0;
loc_0216170C:
a0 = ((struct Obj00029 *)t4)->f14;
a1 = 0;
*(int *)&((struct Obj00029 *)((char *)a0))->f0 = a1;
a0 = 1;
    return a0;
loc_02161716:
a0 = 0;
    return a0;}
