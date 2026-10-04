/*
 * function: func_02181584
 * address:  0x02181584
 * packet:   pkt_ov018_02181584
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 *   func_0217F4C4  0x0217F4C4  thumb
 *   func_0217F4D8  0x0217F4D8  thumb
 *   func_0217F508  0x0217F508  thumb
 *   func_02175514  0x02175514  thumb  ov011
 *   func_020362DC  0x020362DC  arm
 *   func_02173B9C  0x02173B9C  thumb
 *   func_02173AE0  0x02173AE0  thumb  ov011
 *   func_021753B8  0x021753B8  thumb
 *   func_021756F0  0x021756F0  thumb
 *   func_021744D0  0x021744D0  thumb
 *   func_021766CC  0x021766CC  thumb
 *   func_021763D8  0x021763D8  thumb  ov011
 *   func_020120F4  0x020120F4  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0217FE38  0x0217FE38  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   d_021838C4     0x021838C4  data  a2
 *   d_021838CE     0x021838CE  data  a2
 *   d_021838D8     0x021838D8  data  a2
 *   d_021838E2     0x021838E2  data  a2
 *   d_021838EC     0x021838EC  data  a2
 */

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

extern const u16 d_021838C4[];
extern const u16 d_021838CE[];
extern const u16 d_021838D8[];
extern const u16 d_021838E2[];
extern const u16 d_021838EC[];

struct Comm;
struct Ctx;
struct Evt;
struct Obj;
struct WordSet;
void *func_020124E4(struct Obj *p);
u32 func_02012138(const struct Ctx *p);
u8 *func_02158344(void *);
int func_0215839C(void *, int, int);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
void func_0217F2B4(Ov018Obj *p, void *);
void func_0217F318(Ov018Obj *p);
void func_0217F3C4(Ov018Obj *p, u16 a);
int func_0217F40C(Ov018Obj *p);
int func_0217F420(void);
void func_0217F4C4(Ov018Obj *p);
void func_0217F4D8(Ov018Obj *p, void *);
int func_0217F508(Ov018Obj *p);
int func_02175514(u8 *p);
u32 func_020362DC(void);
int func_02173B9C(int, int);
int func_02173AE0(void *, int, int, int);
void func_021753B8(void *);
void func_021756F0(void *, int);
int func_021744D0(void *, int, int);
void *func_021766CC(void *, int *);
void func_021763D8(u8 *p, u32 key);
void *func_020120F4(const struct Ctx *p);
void *func_020127B8(void *);
void func_02026400(struct Comm *p);
void func_02012374(struct Evt *evt, struct Evt **out);
void func_0217FE38(void *v, Ov018Outer *c);
u32 func_02026454(void *obj);
void *func_02026474(void *);

int func_02181584(void *a, int *state, Ov018Outer *c)
{
    void *sub;
    void *t;
    u8 *v;

    sub = func_020124E4(a);
    t = (void *)func_02012138(sub);
    v = func_02158344(t);
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
            func_0217F4D8(&c->obj, sub);
            (*state)++;
        }
        break;
    case 2:
        switch (func_0217F508(&c->obj)) {
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
        if (func_02173AE0(v, v[0x154], 4, v[0x158]) == 1) {
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
        if (func_02173AE0(v, v[0x154], 2, v[0x158]) == 1) {
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
            func_021756F0(func_02026474(t), 0);
        }
        return 1;
    }
    return 0;
}
