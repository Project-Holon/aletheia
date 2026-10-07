/*
 * file:     intrude_subdisp_p15.c
 * unit:     yes
 * function: func_0217F574, func_0217F58C, func_0217F5A0, func_0217F5F0, func_0217F648, func_0217F67C, func_0217F6A0, func_0217F8A0, func_0217F8D0, func_0217F914
 * address:  0x0217F574
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217F470 0x0217F470 thumb ov018
 *   func_02190728  0x02190728  thumb  ov021
 *   func_02175DA8  0x02175DA8  thumb  ov011
 *   func_02175B34  0x02175B34  thumb  ov011
 *   func_02026478 0x02026478 thumb
 *   func_02012B58 0x02012B58 thumb
 *   func_02012950 0x02012950 thumb
 *   func_02008550 0x02008550 thumb
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_0215897C 0x0215897C thumb ov010
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02012B80  0x02012B80  thumb
 *   func_021757A8  0x021757A8  thumb  ov011
 *   func_0217BF1C  0x0217BF1C  thumb  ov018
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_021907A8  0x021907A8  thumb  ov021
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0215841C  0x0215841C  thumb  ov010
 *   func_02190740  0x02190740  thumb  ov021
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_021583EC  0x021583EC  thumb  ov010
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02190758  0x02190758  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02173D2C  0x02173D2C  thumb  ov011
 *   func_02175FB4  0x02175FB4  thumb  ov011
 *   func_02173C6C  0x02173C6C  thumb  ov011
 *   func_0217BF28  0x0217BF28  thumb  ov018
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_02175B8C  0x02175B8C  thumb  ov011
 *   func_0217F938 0x0217F938 thumb ov018
 */
#include "../../matched/include/Obj19364.h"
#include "../../matched/include/Obj12499.h"

struct BigObj;
struct Rec44;
struct Sub24;
struct Sub0200852CObj;
struct Desc;
struct Obj;
struct Ctx;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj_0217F58C;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    u8 pad0[0x30];
    u16 f30;
} Rec;

typedef struct {
    u8 pad0[0x1A5];
    u8 lo1A5 : 2;
    u8 bit1A5 : 1;
} Ov018Obj_0217F5A0;

typedef struct {
    u8 pad0[0x18];
    u16 f18;
    u8 f1A : 4;
} Ent;

typedef struct {
    u8 pad0[4];
    void *f04;
    u8 pad8[0x70 - 8];
    Ent cur;
    Ent arr[];
} Ov018Obj_0217F5F0;

typedef struct {
    int f0;
    int f4;
    int f8;
    u16 *fC;
} Ctx;

typedef struct {
    u8 pad0[0x93F];
    u8 lo93F : 3;
    u8 bit93F : 1;
} Sys;

extern void func_0217F470(void **, void *, void *, unsigned int, int, int);
int func_02190728(void *a);
int func_02175DA8(u8 *p);
u8 *func_02175B34(u8 *p);
unsigned int func_02026478(void *obj);
u8 func_02012B58(const struct BigObj *p);
struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_0215A5F4(void *);
extern void *func_0215A5DC(void *);
extern u16 *func_02159AE8(void *, void *);
extern void func_0215897C(void *, void *);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
void *func_020124E4(struct Obj *p);
void *func_020120F4(const struct Ctx *p);
u32 func_02012138(const struct Ctx *p);
void *func_0201210C(const struct Ctx *p);
int func_02158344(int a0);
u32 func_0200FB24(void);
u8 func_02012B80(const struct BigObj *p);
void func_021757A8(u8 *p);
void func_0217BF1C(void *p);
u32 func_02188C54(u8 *p);
int func_021904B0(u32 a, u32 b);
int func_021907A8(void *a0, int a1);
struct WordSet *func_0201EC64(u32 heap);
void func_020061E4(u32 a);
u8 func_0215841C(void *p);
int func_02190740(u32 a, u32 b, u32 c, u32 d);
struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
void *func_02045EC0(struct MsgBank *bank, u32 index);
int func_021583EC(void *a0, int a1);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0201F250(struct WordSet *ws, void *dst, void *src);
int func_02190758(u32 a, u32 b, u32 c, u32 d);
void func_02045808(struct U16Vec *vec);
int func_0203D1B4(void);
int func_02173D2C(int a0, int a1);
int func_02175FB4(u8 *p);
int func_02173C6C(int a, int b);
u8 func_0217BF28(u8 *p);
int func_0219077C(u8 *p);
u32 func_020362DC(void);
u32 func_0201ED04(struct WordSet *p);
u32 func_02045C04(struct Rec *rec);
int func_02175B8C(u8 *p);
extern void *func_0217F938(void *);
void func_0217F574(void **p, unsigned int index, int a, int b);
void func_0217F58C(Ov018Obj_0217F58C *p);
int func_0217F5A0(Ov018Obj_0217F5A0 *p);
int func_0217F5F0(Ov018Obj_0217F5F0 *p, int idx);
int func_0217F648(void *a, void *vm);
void *func_0217F67C(void *owner, u16 *out);
int func_0217F6A0(void *a0, int *state, Ctx *c);
int func_0217F8A0(void *a, void *vm);
int func_0217F8D0(void *a0, int a);
int func_0217F914(void *unused, void *vm);

void func_0217F574(void **p, unsigned int index, int a, int b)
{
    func_0217F470(p, p[5], p[8], index, a, b);
}


void func_0217F58C(Ov018Obj_0217F58C *p)
{
    if (p->f20 != 0) {
        func_02190728((void *)p->f20);
        p->f20 = 0;
    }
}


int func_0217F5A0(Ov018Obj_0217F5A0 *p)
{
    Rec *r;

    if (func_02175DA8((u8 *)p) == 1) {
        return 4;
    }
    r = (Rec *)func_02175B34((u8 *)p);
    if (r == 0) {
        return 0;
    }
    if (r->f30 == 0) {
        if (p->bit1A5 == 1) {
            return 3;
        }
        return 1;
    }
    if (p->bit1A5 == 1) {
        return 2;
    }
    return 1;
}


/*
 * lever: a switch with empty sentinel and default arms retains the dead
 * comparison before the shared bitfield return.
 */
int func_0217F5F0(Ov018Obj_0217F5F0 *p, int idx)
{
    Ent *e;
    enum Guard { ZERO, INVALID = 0xFFFF } h;

    void *sub;

    sub = (void *)func_02026478(p->f04);
    if (idx == func_02012B58(sub)) {
        e = &p->cur;
    } else {
        e = &p->arr[idx];
    }
    h = e->f18;
    switch (h) {
    case 0:
        if (func_02008550((const struct Sub0200852CObj *)func_02012950((struct Sub24 *)func_02026478(p->f04), idx)) == 0) {
            return 3;
        }
        return 4;
    case 0xFFFF:
        break;
    default:
        break;
    }
    return e->f1A;
}

/*
 * extent: Two bytes of alignment padding at 0x0217F67A.
 */
int func_0217F648(void *a, void *vm)
{
    void *owner = func_0215A5F4(vm);
    void *sys = func_0215A5DC(vm);
    func_0215897C(owner, func_0217F67C(sys, func_02159AE8(a, vm)));
    return 1;
}

void *func_0217F67C(void *owner, u16 *out)
{
    void *task;
    u8 *work;
    int zero;
    zero = 0;
    task = func_020122C0(owner, 0, func_0217F6A0, 0x10);
    work = func_020124E8(task);
    *(u16 * *)&((struct Obj19364 *)work)->fC = out;
    *out = zero;
    return task;
}


int func_0217F6A0(void *a0, int *state, Ctx *c)
{
    void *h;
    void *s;
    u32 k;
    u8 *w;
    void *t;
    int flag;

    h = func_020124E4(a0);
    s = func_020120F4(h);
    k = func_02012138(h);
    t = func_0201210C(h);
    flag = 0;
    w = (u8 *)func_02158344(k);
    if (w == 0 && *state > 0 && *state < 5) {
        *state = 5;
    }
    switch (*state) {
    case 0: {
        void *g;
        int a;
        int b;

        if (func_0200FB24() != 0 || (w == 0 && func_02012B80(s) != func_02012B58(s))) {
            *state = 7;
            break;
        }
        if (w != 0) {
            func_021757A8(w + 0x1AC);
            func_0217BF1C(w + 0x914);
        }
        g = (void *)func_02188C54(t);
        c->f0 = func_021904B0((int)g, 0x2D);
        c->f4 = func_021907A8(g, c->f0);
        c->f8 = (int)func_0201EC64(4);
        func_020061E4(0x547);
        if (w == 0 || func_0215841C(s) == func_02012B58(s)) {
            func_02190740(c->f4, 0, 0, 0x49);
            flag = 1;
        } else {
            a = (int)func_020457B0(0x100, 0x15);
            b = (int)func_02045EC0((struct MsgBank *)c->f0, 0x4A);
            func_0201F02C((struct WordSet *)c->f8, 0, (void *)func_021583EC(s, func_0215841C(s)));
            func_0201F250((struct WordSet *)c->f8, (void *)a, (void *)b);
            func_02190758(c->f4, 0, 0, a);
            func_02045808((struct U16Vec *)b);
            func_02045808((struct U16Vec *)a);
        }
        if (func_0203D1B4() <= 1) {
            if (flag == 0) {
                *c->fC = 0;
            } else {
                *c->fC = 1;
            }
            *state = 5;
            break;
        }
        (*state)++;
    }
    case 1:
        if (func_02173D2C((int)w, func_0215841C(s)) == 1) {
            (*state)++;
        }
        break;
    case 2:
        if (func_02175FB4(w + 0x1AC + func_0215841C(s) * 0x28) == 1) {
            (*state)++;
        }
        break;
    case 3:
        if (func_02173C6C((int)w, func_0215841C(s)) == 1) {
            (*state)++;
        }
        break;
    case 4:
        if (func_0217BF28(w + 0x914) == 1) {
            *c->fC = 1;
            *state = 5;
        }
        break;
    case 5:
        if (func_0219077C((u8 *)c->f4) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (func_020362DC() & 0xF3) {
            func_0201ED04((struct WordSet *)c->f8);
            func_02190728((void *)c->f4);
            func_02045C04((struct Rec *)c->f0);
            (*state)++;
        }
        break;
    case 7:
        return 1;
    }
    return 0;
}

/*
 * extent: two bytes of zero alignment padding follow at 0x0217F8CE.
 * lever: stores in both arms keep the branch to the shared store.
 */
int func_0217F8A0(void *a, void *vm)
{
    u16 *out;
    u8 *p;
    int v;
    out = func_02159AE8(a, vm);
    p = (u8 *)func_02158344((int)((void *)func_02012138(func_0215A5DC(vm))));
    if (p == 0 || ((struct Obj12499 *)p)->f88 == 0) {
        *out = 0;
    } else {
        *out = ((struct Obj12499 *)p)->f88;
    }
    return 0;
}


int func_0217F8D0(void *a0, int a)
{
    u16 *out;
    Sys *s;
    int v;

    out = func_02159AE8(a0, (void *)a);
    s = (Sys *)func_02158344(func_02012138(func_0215A5DC((void *)a)));
    if (s != 0 && s->bit93F == 0 && func_02175B8C((u8 *)s + 0x1AC) == 1) {
        v = 1;
    } else {
        v = 0;
    }
    *out = v;
    return 0;
}

int func_0217F914(void *unused, void *vm)
{
    void *owner;
    owner = func_0215A5F4(vm);
    func_0215897C(owner, func_0217F938(func_0215A5DC(vm)));
    return 1;
}
