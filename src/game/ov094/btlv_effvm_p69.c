/*
 * file:     btlv_effvm_p69.c
 * unit:     yes
 * function: func_021FFF68, func_021FFFAC, func_021FFFD8, func_02200108, func_02200140, func_022001DC, func_02200218, func_02200344
 * address:  0x021FFF68
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02019C90  0x02019C90  thumb
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_02015F24  0x02015F24  thumb
 *   func_020172AC 0x020172AC thumb
 *   func_02014CF8 0x02014CF8 thumb
 *   func_02015F2C 0x02015F2C thumb
 *   func_02201718 0x02201718 thumb ov094
 *   func_0202D060 0x0202D060 thumb
 *   func_021FFE24 0x021FFE24 thumb ov094
 *   func_02016078  0x02016078  thumb
 *   sub_02014CF8   0x02014CF8  thumb
 *   func_021F8754  0x021F8754  thumb  ov094
 *   func_021B994C  0x021B994C  thumb
 *   func_02006984  0x02006984  thumb
 *   func_02006A8C  0x02006A8C  thumb
 *   func_02006AEC  0x02006AEC  thumb
 *   d_02209FC0  0x02209FC0  data  ov094
 *   d_02209FE0  0x02209FE0  data  ov094
 *   d_02209FF0  0x02209FF0  data  ov094
 *   d_0220A068  0x0220A068  data  ov094
 *   sub_02030734   0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_021F896C  0x021F896C  thumb  ov094
 *   func_02201408  0x02201408  thumb  ov094
 *   func_02201700  0x02201700  thumb  ov094
 *   d_0220AE7C     0x0220AE7C  data   ov094  a1
 */
#include "../../matched/include/Obj01047.h"

struct Sub02014CF8Ctx;
struct Sub02014CF8Rec;
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x28];
    u32 a;                  /* 0x2c (w+0x34) */
    u32 b;                  /* 0x30 (w+0x38) */
    char pad34[0x28];
} Entry_021FFF68;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FFF68 e[14];            /* 0x008 */
} Work_021FFF68;

typedef struct {
    int w[9];
} Rec_021FFFAC;

typedef struct {
    void *h;                /* 0x00 */
    Rec_021FFFAC rec;                /* 0x04 */
    char pad28[0x0c];
    int k34;                /* 0x34 */
    char pad38[0x24];
} Entry_021FFFAC;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FFFAC e[14];            /* 0x008 */
} Work_021FFFAC;

typedef struct { u32 v[9]; } Rec_021FFFD8;

typedef struct {
    int w[9];
} Rec_02200108;

typedef struct {
    void *h;                /* 0x00 */
    Rec_02200108 rec;                /* 0x04 */
    char pad28[0x0c];
    int k34;                /* 0x34 */
    char pad38[0x24];
} Entry_02200108;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_02200108 e[14];            /* 0x008 */
} Work_02200108;

typedef struct {
    int a, b, c, d;
} Quad;

typedef struct {
    void *h;                /* 0x00 */
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    char pad24[0x08];
    Quad q;                 /* 0x2c */
    char pad3c[0x20];
} Entry_02200140;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_02200140 e[14];            /* 0x008 */
} Work_02200140;

typedef struct {
    int w[9];
} Rec_022001DC;

typedef struct {
    void *h;                /* 0x00 */
    Rec_022001DC rec;                /* 0x04 */
    char pad28[0x0c];
    int k34;                /* 0x34 */
    char pad38[0x24];
} Entry_022001DC;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_022001DC e[14];            /* 0x008 */
} Work_022001DC;

typedef unsigned char u8;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x28];
    u32 k2c;                /* 0x2c */
    u32 k30;                /* 0x30 */
    char pad34[0x06];
    u16 k3a;                /* 0x3a */
    char pad3c[0x20];
} Entry_02200218;

typedef struct {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
} Flags;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_02200218 e[14];            /* 0x008 */
    Flags flags;            /* 0x510 */
} Work_02200218;

typedef struct {
    void *owner;            /* 0x000 */
    char pad004[0x510 - 4];
    u32 flags;              /* 0x510 */
    char pad514[0x540 - 0x514];
    u16 heap;               /* 0x540 */
} Work_02200344;

typedef struct {
    Work_02200344 *w;                /* 0x00 */
    u32 a : 31;             /* 0x04 */
    u32 flag : 1;
    int f8;                 /* 0x08 */
    int fc;                 /* 0x0c */
} Obj;

extern int func_022019F4(char *p, int key);
extern u32 func_02019C90(u16 a, u16 b, u32 k);
extern int func_02015F24(void *h);
extern void func_020172AC(int a0, int a1);
extern void func_02014CF8(void *a, struct Sub02014CF8Ctx *b, const struct Sub02014CF8Rec *c);
extern void func_02015F2C(void *, int, void (*)(int), int);
extern void func_02201718(int);
extern int func_0202D060(void);
extern void func_021FFE24(char *, int);
extern void func_02016078(void *obj, void *h, int v);
extern void sub_02014CF8(void *a, struct Sub02014CF8Ctx *b, const struct Sub02014CF8Rec *c);
extern int func_021F8754(void);
extern int func_021B994C(void *p, int key, u32 *out);
extern u32 func_02006984(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern void func_02006A8C(u32 idx, int delta);
extern void func_02006AEC(u32 idx, u32 delta);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *owner, void *fn, void *p, u32 a3);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_02201408(void *h);
extern void func_02201700(void *h);
int func_021FFF68(Work_021FFF68 *w, int key);
int func_021FFFAC(Work_021FFFAC *w, int key);
void func_021FFFD8(char *w, int key, int flag, int clear);
void func_02200108(Work_02200108 *w, int key, int v);
void func_02200140(Work_02200140 *w, int key1, int key2);
void func_022001DC(Work_022001DC *w, int key, Rec_022001DC *r);
u32 func_02200218(Work_02200218 *w, int key, int pitch, int pan, u32 a4, u32 a5, u32 a6);
void func_02200344(Work_02200344 *w, int a, int b, int flag);
extern u32 d_02209FC0[];
extern u32 d_02209FE0[];
extern u32 d_02209FF0[];
extern u32 d_0220A068[];
extern const char d_0220AE7C[];


int func_021FFF68(Work_021FFF68 *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return 0;
    if (w->e[idx].h == 0)
        return 0;
    if (func_02019C90(w->e[idx].a, w->e[idx].b, 0x10))
        return 1;
    return 0;
}


int func_021FFFAC(Work_021FFFAC *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return 0;
    if (w->e[idx].h == 0)
        return 0;
    return func_02015F24(w->e[idx].h);
}


void func_021FFFD8(char *w, int key, int flag, int clear)
{
    int idx = func_022019F4(w, key);
    char *e;
    int off;
    Rec_021FFFD8 r;
    int odd;

    if (idx == -1)
        return;
    e = w;
    e += 8;
    off = idx * 0x5c;
    if (*(void **)(e + off) == 0)
        return;
    if (flag == 0) {
        func_020172AC((int)(((struct Obj01047 *)w)->f4), *(u32 *)(w + off + 0x3c));
        func_02014CF8(((struct Obj01047 *)w)->f4, *(void **)(w + 8 + off), (const struct Sub02014CF8Rec *)(w + 0xc + off));
        func_02015F2C(*(void **)(w + 8 + off), idx, func_02201718, 1);
        if (clear)
            *(u32 *)(w + 0x48 + off) &= ~1u;
        *(u32 *)(w + 0x48 + off) &= ~4u;
    } else {
        r.v[0] = func_0202D060();
        odd = key & 1;
        r.v[1] = odd ? 0x37a0 : 0x37a6;
        r.v[2] = 0x37ac;
        r.v[3] = odd ? 0x37a1 : 0x37a7;
        r.v[4] = odd ? 0x37a2 : 0x37a8;
        r.v[5] = odd ? 0x37a3 : 0x37a9;
        r.v[6] = odd ? 0x37a4 : 0x37aa;
        r.v[7] = odd ? 0x37a5 : 0x37ab;
        r.v[8] = 0;
        func_02014CF8(((struct Obj01047 *)w)->f4, *(void **)(e + off), (const struct Sub02014CF8Rec *)(&r));
        func_021FFE24(w, key);
        if (clear)
            *(u32 *)(w + 0x48 + off) |= 1;
        *(u32 *)(w + 0x48 + off) |= 4;
    }
}


void func_02200108(Work_02200108 *w, int key, int v)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    func_020172AC((int)w->obj, w->e[idx].k34);
    func_02016078(w->obj, w->e[idx].h, v);
}


void func_02200140(Work_02200140 *w, int key1, int key2)
{
    int i1 = func_022019F4((char *)w, key1);
    int i2 = func_022019F4((char *)w, key2);

    w->e[i2].f04 = w->e[i1].f04;
    w->e[i2].f0c = w->e[i1].f0c;
    if (key1 & 1) {
        w->e[i2].f08 = w->e[i1].f08 + 9;
        w->e[i2].f10 = w->e[i1].f10 + 9;
        w->e[i2].f14 = w->e[i1].f14 + 9;
        w->e[i2].f18 = w->e[i1].f18 + 9;
        w->e[i2].f1c = w->e[i1].f1c + 9;
        w->e[i2].f20 = w->e[i1].f20 + 9;
    } else {
        w->e[i2].f08 = w->e[i1].f08 - 9;
        w->e[i2].f10 = w->e[i1].f10 - 9;
        w->e[i2].f14 = w->e[i1].f14 - 9;
        w->e[i2].f18 = w->e[i1].f18 - 9;
        w->e[i2].f1c = w->e[i1].f1c - 9;
        w->e[i2].f20 = w->e[i1].f20 - 9;
    }
    w->e[i2].q = w->e[i1].q;
    sub_02014CF8(w->obj, w->e[i2].h, (const struct Sub02014CF8Rec *)(&w->e[i2].f04));
}


void func_022001DC(Work_022001DC *w, int key, Rec_022001DC *r)
{
    int idx = func_022019F4((char *)w, key);

    w->e[idx].rec = *r;
    func_020172AC((int)w->obj, w->e[idx].k34);
    func_02014CF8(w->obj, w->e[idx].h, (const struct Sub02014CF8Rec *)(&w->e[idx].rec));
}


u32 func_02200218(Work_02200218 *w, int key, int pitch, int pan, u32 a4, u32 a5, u32 a6)
{
    int idx = func_022019F4((char *)w, key);
    u32 id;
    u32 buf;
    u32 *out;
    int flag;
    void *p;
    u32 r;

    if (idx == -1)
        return 0;
    if (w->e[idx].h == 0)
        return 0;
    switch (key) {
    case 0:
    case 1:
        id = d_02209FC0[key];
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        if (w->flags.b1)
            id = d_02209FF0[key - 2];
        else if (w->flags.b0)
            id = d_0220A068[key - 2];
        else
            id = d_02209FE0[key - 2];
        break;
    case 6:
    case 7:
        if (w->flags.b1)
            id = d_02209FF0[key - 2];
        else
            id = d_0220A068[key - 2];
        break;
    }
    p = (void *)func_021F8754();
    out = &buf;
    flag = 0;
    if (p != 0) {
        if (func_021B994C(p, key, out) == 0)
            out = 0;
    } else {
        out = 0;
    }
    if (a4 != 0 || a5 != 0)
        flag = 1;
    if (pitch == (int)0x80000000) {
        if (w->e[idx].k3a == 1)
            pitch = -0xa00;
        else
            pitch = 0;
    }
    r = func_02006984(w->e[idx].k2c, w->e[idx].k30, (u8)id, flag, a4, a5, a6, (u32)out);
    func_02006A8C(r, (signed char)pan);
    func_02006AEC(r, pitch);
    return r;
}


void func_02200344(Work_02200344 *w, int a, int b, int flag)
{
    Obj *o = sub_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x24, 0, d_0220AE7C, 0x8f2);

    o->w = w;
    o->a = 0;
    o->flag = flag;
    o->f8 = a;
    o->fc = b;
    w->flags |= 4;
    func_021F896C(func_02030DA8(w->owner, func_02201408, o, 0), func_02201700, 2);
}
