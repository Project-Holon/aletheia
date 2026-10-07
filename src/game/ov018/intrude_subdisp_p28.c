/*
 * file:     intrude_subdisp_p28.c
 * unit:     yes
 * function: func_0218123C, func_0218152C, func_02181584, func_0218186C, func_021818C4
 * address:  0x0218123C
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
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0215839C  0x0215839C  thumb  ov010
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0217F2B4  0x0217F2B4  thumb
 *   func_0217F318  0x0217F318  thumb
 *   func_0217F3C4  0x0217F3C4  thumb
 *   func_0217F40C  0x0217F40C  thumb
 *   func_0217F420  0x0217F420  thumb
 *   func_02175514  0x02175514  thumb  ov011
 *   func_020362DC  0x020362DC  arm
 *   func_02173B9C  0x02173B9C  thumb
 *   func_021753B8  0x021753B8  thumb
 *   func_0217405C  0x0217405C  thumb
 *   func_02175CF4  0x02175CF4  thumb
 *   func_021756F0  0x021756F0  thumb
 *   func_021744D0  0x021744D0  thumb
 *   func_021766CC  0x021766CC  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0217FE38  0x0217FE38  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_021804F8  0x021804F8  thumb
 *   func_0217CA84  0x0217CA84  thumb
 *   func_0201235C  0x0201235C  thumb
 *   d_021838F6     0x021838F6  data  a2
 *   d_02183900     0x02183900  data  a2
 *   d_0218390A     0x0218390A  data  a2
 *   d_02183914     0x02183914  data  a2
 *   d_0218391E     0x0218391E  data  a2
 *   func_0201232C  0x0201232C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0217F4C4  0x0217F4C4  thumb
 *   func_0217F4D8  0x0217F4D8  thumb
 *   func_0217F508  0x0217F508  thumb
 *   func_02173AE0  0x02173AE0  thumb  ov011
 *   func_021763D8  0x021763D8  thumb  ov011
 *   func_020120F4  0x020120F4  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_02026400  0x02026400  thumb
 *   d_021838C4     0x021838C4  data  a2
 *   d_021838CE     0x021838CE  data  a2
 *   d_021838D8     0x021838D8  data  a2
 *   d_021838E2     0x021838E2  data  a2
 *   d_021838EC     0x021838EC  data  a2
 */
#include "../../matched/include/Obj04961.h"
#include "../../matched/include/Obj04963.h"
#include "../../matched/include/Obj04964.h"

struct Evt;
struct Obj;
struct S0201235C;
struct WordSet;
struct Ctx;
struct Comm;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

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
} Ov018Obj;

typedef struct {
    u8 pad00[0x10];
    Ov018Obj obj;       /* 0x10 */
    u8 f40;             /* 0x40 */
    u8 pad41;
    u8 f42;             /* 0x42 */
    u8 pad43[0x58 - 0x43];
    u16 f58;            /* 0x58 */
    u8 pad5A[0x78 - 0x5A];
    u8 f78[0x98 - 0x78]; /* 0x78 */
    int f98;            /* 0x98 */
    int f9C;            /* 0x9C */
    u8 fA0;
    u8 fA1;             /* 0xA1 */
    u8 padA2[2];
    int fA4;            /* 0xA4 */
    int fA8;            /* 0xA8 */
    int fAC;            /* 0xAC */
} Ov018Outer;

typedef struct {
    u8 pad00[0x40];
    u8 f40;
    u8 pad41[0x17];
    u16 f58;
} Ov018Src;

void *func_020124E4(struct Obj *p);
u32 func_02012138(const struct Ctx *);
int func_02158344(int a0);
int func_0215839C(u8 *p, int m, int a2);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
void func_0217F2B4(Ov018Obj *p, void *);
void func_0217F318(Ov018Obj *p);
void func_0217F3C4(Ov018Obj *p, u16 a);
int func_0217F40C(Ov018Obj *p);
int func_0217F420(void);
int func_02175514(u8 *p);
u32 func_020362DC(void);
int func_02173B9C(int, int);
void func_021753B8(void *);
int func_0217405C(void *, void *);
int func_02175CF4(void *, void *);
void func_021756F0(void *, int);
int func_021744D0(void *, int, int);
void *func_021766CC(void *, int *);
void func_02012374(struct Evt *evt, struct Evt **out);
void func_0217FE38(void *v, Ov018Outer *c);
u32 func_02026454(void *obj);
u32 func_02026474(void *obj);
void *func_021804F8(void *, int);
int func_0217CA84(void *a, int b);
void func_0201235C(struct S0201235C *o, u32 *out);
void func_0201232C(char *p, int a1, int a2);
void *func_020124E8(struct Obj *p);
void func_02082D44(void *, void *, int);
void func_0217F4C4(Ov018Obj *p);
void func_0217F4D8(void **p, int a);
int func_0217F508(void **p);
int func_02173AE0(int a, int b, int c, int d);
void func_021763D8(u8 *p, u32 key);
void *func_020120F4(const struct Ctx *p);
void *func_020127B8(void *);
void func_02026400(struct Comm *p);
int func_0218123C(void *a, int *state, Ov018Outer *c);
void func_0218152C(void *a, Ov018Src *src);
int func_02181584(void *a, int *state, Ov018Outer *c);
void func_0218186C(void *a, Ov018Src *src);
void func_021818C4(void *a, Ov018Src *src);
extern const u16 d_021838F6[];
extern const u16 d_02183900[];
extern const u16 d_0218390A[];
extern const u16 d_02183914[];
extern const u16 d_0218391E[];
extern const u16 d_021838C4[];
extern const u16 d_021838CE[];
extern const u16 d_021838D8[];
extern const u16 d_021838E2[];
extern const u16 d_021838EC[];


int func_0218123C(void *a, int *state, Ov018Outer *c)
{
    void *sub;
    void *t;
    u8 *v;
    void *r;

    sub = func_020124E4(a);
    t = (void *)func_02012138(sub);
    v = (u8 *)func_02158344((int)t);
    if (v == 0) {
        if (func_0217F40C(&c->obj) == 0) {
            return 0;
        }
        if (*state < 13) {
            func_0217F2B4(&c->obj, sub);
            func_0217F3C4(&c->obj, 4);
            *state = 13;
            c->f98 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0201EFA4(c->obj.f00, 1, c->fA1, 3, 0, 1);
        func_0217F3C4(&c->obj, c->fA4 == 0 ? d_021838F6[c->f42] : d_02183900[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C(&c->obj) == 1) {
            switch (func_02175514(v)) {
            case 4:
                *state = 2;
                break;
            case 2:
            case 3:
                *state = 11;
                break;
            default:
                if ((func_020362DC() & 2) && func_02173B9C(v[0x154], v[0x158]) == 1) {
                    func_021753B8(v);
                    *state = 12;
                }
                break;
            }
        }
        break;
    case 2:
        func_0217F3C4(&c->obj, d_0218390A[c->f42]);
        *state = 3;
        break;
    case 3:
        if (func_0217405C(v, v + 0x1AC) == 1) {
            (*state)++;
        }
        break;
    case 4:
        if (func_02175CF4(v, v + 0x1AC) != 0) {
            func_021756F0(v, 1);
            *state = 5;
        }
        break;
    case 5:
        if (func_0217F40C(&c->obj) == 1 && func_021744D0(v, c->f40, 1) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (func_0215839C(v, 1, c->f40) == 1) {
            *state = 7;
        } else if ((func_020362DC() & 2) && func_02173B9C(v[0x154], v[0x158]) == 1) {
            func_021753B8(v);
            *state = 12;
        }
        break;
    case 7:
        if (func_021744D0(v, c->f40, 2) == 1) {
            (*state)++;
        }
        break;
    case 8:
        if (func_0215839C(v, 2, c->f40) == 1) {
            func_0217F318(&c->obj);
            *state = 9;
        } else if (func_02175514(v) == 3) {
            func_0217F3C4(&c->obj, 4);
            *state = 13;
        }
        break;
    case 9:
        c->fA8 = 1;
        func_02012374(a, func_021766CC(sub, &c->f9C));
        (*state)++;
        break;
    case 10:
        func_0217F2B4(&c->obj, sub);
        func_0217F3C4(&c->obj, d_02183914[c->f42]);
        *state = 13;
        break;
    case 11:
        func_0217F3C4(&c->obj, d_0218391E[c->f42]);
        *state = 13;
        break;
    case 12:
        c->fAC = 1;
        *state = 15;
        break;
    case 13:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 14;
        }
        break;
    case 14:
        if (func_0217F420() == 1) {
            *state = 15;
        }
        break;
    case 15:
        func_0217FE38(v, c);
        if (func_02026454(t) == 2 && func_02026474(t) != 0) {
            func_021756F0((void *)func_02026474(t), 0);
        }
        if (c->fA8 == 1) {
            r = func_021804F8(sub, c->fA8);
        } else if (c->fAC == 0) {
            r = (void *)func_0217CA84(sub, 1);
        } else {
            r = (void *)func_0217CA84(sub, 0);
        }
        func_0201235C(a, r);
        return 0;
    }
    return 0;
}


void func_0218152C(void *a, Ov018Src *src)
{
    void *r;
    u8 *t;

    r = func_020124E4(a);
    func_0201232C(a, (int)func_02181584, 0xB0);
    t = func_020124E8(a);
    func_02082D44(src, t, 0x98);
    ((struct Obj04961 *)t)->fA4 = 0;
    ((struct Obj04961 *)t)->f9C = r;
    t[0xA0] = t[0x40];
    t[0xA1] = src->f58;
    t[0xA2] = 2;
}


int func_02181584(void *a, int *state, Ov018Outer *c)
{
    void *sub;
    void *t;
    u8 *v;

    sub = func_020124E4(a);
    t = (void *)func_02012138(sub);
    v = (u8 *)func_02158344((int)t);
    if (v == 0) {
        if (func_0217F40C(&c->obj) == 0) {
            return 0;
        }
        if (*state < 14 && *state != 1 && *state != 2) {
            func_0217F2B4(&c->obj, sub);
            func_0217F3C4(&c->obj, 4);
            *state = 14;
            c->f98 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0201EFA4(c->obj.f00, 1, c->fA1, 3, 0, 1);
        func_0217F3C4(&c->obj, c->fA4 == 0 ? d_021838C4[c->f42] : d_021838CE[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C(&c->obj) == 1) {
            func_0217F4D8((void **)(&c->obj), (int)sub);
            (*state)++;
        }
        break;
    case 2:
        switch (func_0217F508((void **)(&c->obj))) {
        case 0:
            func_0217F4C4(&c->obj);
            *state = 3;
            break;
        case 1:
            func_0217F4C4(&c->obj);
            *state = 11;
            break;
        }
        break;
    case 3:
        if (func_02173AE0((int)v, v[0x154], 4, v[0x158]) == 1) {
            func_021756F0(v, 1);
            *state = 4;
        }
        break;
    case 4:
        func_0217F3C4(&c->obj, d_021838D8[c->f42]);
        (*state)++;
        break;
    case 5:
        if (func_0217F40C(&c->obj) == 1 && func_021744D0(v, c->f40, 1) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (func_0215839C(v, 1, c->f40) == 1) {
            *state = 7;
        } else if (func_020362DC() & 2) {
            if (func_02173B9C(v[0x154], v[0x158]) == 1) {
                func_021753B8(v);
                *state = 13;
                func_02026400(t);
            }
        } else if (func_02175514(v) == 3) {
            func_0217F3C4(&c->obj, 4);
            *state = 14;
        }
        break;
    case 7:
        if (func_021744D0(v, c->f40, 2) == 1) {
            (*state)++;
        }
        break;
    case 8:
        if (func_0215839C(v, 2, c->f40) == 1) {
            func_0217F318(&c->obj);
            *state = 9;
        } else if (func_02175514(v) == 3) {
            func_0217F3C4(&c->obj, 4);
            *state = 14;
        }
        break;
    case 9:
        func_02012374(a, func_021766CC(sub, &c->f9C));
        (*state)++;
        break;
    case 10:
        func_0217F2B4(&c->obj, sub);
        func_0217F3C4(&c->obj, d_021838E2[c->f42]);
        *state = 14;
        break;
    case 11:
        if (func_02173AE0((int)v, v[0x154], 2, v[0x158]) == 1) {
            func_021763D8(func_020127B8(func_020120F4(sub)), 0);
            *state = 12;
        }
        break;
    case 12:
        func_0217F3C4(&c->obj, d_021838EC[c->f42]);
        *state = 14;
        break;
    case 13:
        *state = 16;
        break;
    case 14:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 15;
        }
        break;
    case 15:
        if (func_0217F420() == 1) {
            *state = 16;
        }
        break;
    case 16:
        func_0217FE38(v, c);
        if (func_02026454(t) == 2 && func_02026474(t) != 0) {
            func_021756F0((void *)func_02026474(t), 0);
        }
        return 1;
    }
    return 0;
}


void func_0218186C(void *a, Ov018Src *src)
{
    void *r;
    u8 *t;

    r = func_020124E4(a);
    func_0201232C(a, (int)func_0218123C, 0xB0);
    t = func_020124E8(a);
    func_02082D44(src, t, 0x98);
    ((struct Obj04963 *)t)->fA4 = 1;
    ((struct Obj04963 *)t)->f9C = r;
    t[0xA0] = t[0x40];
    t[0xA1] = src->f58;
    t[0xA2] = 2;
}


void func_021818C4(void *a, Ov018Src *src)
{
    void *r;
    u8 *t;

    r = func_020124E4(a);
    func_0201232C(a, (int)func_02181584, 0xB0);
    t = func_020124E8(a);
    func_02082D44(src, t, 0x98);
    ((struct Obj04964 *)t)->fA4 = 1;
    ((struct Obj04964 *)t)->f9C = r;
    t[0xA0] = t[0x40];
    t[0xA1] = src->f58;
    t[0xA2] = 2;
}
