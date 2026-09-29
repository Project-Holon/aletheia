/*
 * function: func_0218123C
 * address:  0x0218123C
 * packet:   pkt_ov018_0218123C
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

extern const u16 d_021838F6[];
extern const u16 d_02183900[];
extern const u16 d_0218390A[];
extern const u16 d_02183914[];
extern const u16 d_0218391E[];

void *func_020124E4(void *);
void *func_02012138(void *);
u8 *func_02158344(void *);
int func_0215839C(void *, int, int);
void func_0201F02C(void *, int, void *);
void func_0201EFA4(void *, int, int, int, int, int);
void func_0217F2B4(Ov018Obj *p, void *);
void func_0217F318(Ov018Obj *p);
void func_0217F3C4(Ov018Obj *p, u16 a);
int func_0217F40C(Ov018Obj *p);
int func_0217F420(void);
int func_02175514(void *);
int func_020362DC(void);
int func_02173B9C(int, int);
void func_021753B8(void *);
int func_0217405C(void *, void *);
int func_02175CF4(void *, void *);
void func_021756F0(void *, int);
int func_021744D0(void *, int, int);
void *func_021766CC(void *, int *);
void func_02012374(void *, void *);
void func_0217FE38(void *v, Ov018Outer *c);
int func_02026454(void *);
void *func_02026474(void *);
void *func_021804F8(void *, int);
void *func_0217CA84(void *, int);
void func_0201235C(void *, void *);

int func_0218123C(void *a, int *state, Ov018Outer *c)
{
    void *sub;
    void *t;
    u8 *v;
    void *r;

    sub = func_020124E4(a);
    t = func_02012138(sub);
    v = func_02158344(t);
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
            func_021756F0(func_02026474(t), 0);
        }
        if (c->fA8 == 1) {
            r = func_021804F8(sub, c->fA8);
        } else if (c->fAC == 0) {
            r = func_0217CA84(sub, 1);
        } else {
            r = func_0217CA84(sub, 0);
        }
        func_0201235C(a, r);
        return 0;
    }
    return 0;
}
