/*
 * function: func_021809A4
 * address:  0x021809A4
 * packet:   pkt_ov018_021809A4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback in the shape of func_02182AA4: an 8-state sequence driving
 * the Ov018Obj at +0x10, with an early skip to state 5 while the owner
 * object is absent.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217405C  0x0217405C  thumb  ov011
 *   func_02175CF4  0x02175CF4  thumb  ov011
 *   func_0201F02C  0x0201F02C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201F184  0x0201F184  thumb
 *   func_0217F3C4  0x0217F3C4  thumb
 *   func_0217F40C  0x0217F40C  thumb
 *   func_0217F420  0x0217F420  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0217FE38  0x0217FE38  thumb
 *   func_021804F8  0x021804F8  thumb
 *   func_0201235C  0x0201235C  thumb
 *   d_02183870     0x02183870  data   a2
 *   d_0218387A     0x0218387A  data   a2
 *   d_02183884     0x02183884  data   a2
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
    u8 pad40[2];
    u8 f42;             /* 0x42 */
    u8 pad43[0x58 - 0x43];
    u16 f58;            /* 0x58 */
    u8 pad5A[0x78 - 0x5A];
    u8 f78[0x98 - 0x78]; /* 0x78 */
    int f98;            /* 0x98 */
    int f9C;            /* 0x9C */
} Outer;

extern u16 d_02183870[];
extern u16 d_0218387A[];
extern u16 d_02183884[];

typedef signed int     s32;
struct Ctx;
struct Obj;
struct S0201235C;
struct WordSet;
void *func_020124E4(struct Obj *p);
u32 func_02012138(const struct Ctx *p);
u8 *func_02158344(void *);
int func_0217405C(u8 *, u8 *);
int func_02175CF4(u8 *, u8 *);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void *func_020120F4(const struct Ctx *p);
u8 *func_02012944(void *p);
void func_0201F184(struct WordSet *p, u32 i, s32 v);
void func_0217F3C4(Ov018Obj *p, int a);
int func_0217F40C(Ov018Obj *p);
int func_0217F420(void);
void func_020061E4(u32 a);
void func_0217FE38(u8 *v, Outer *c);
void *func_021804F8(void *, int);
void func_0201235C(struct S0201235C *o, u32 *out);

int func_021809A4(void *a, int *state, Outer *c)
{
    void *sub;
    u8 *v;

    sub = func_020124E4(a);
    v = func_02158344((void *)func_02012138(sub));
    if (v == 0 && *state <= 1) {
        if (func_0217F40C(&c->obj) == 0) {
            return 0;
        }
        if (*state < 5) {
            func_0217F3C4(&c->obj, 4);
            *state = 5;
            c->f98 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        if (func_0217405C(v, v + 0x1AC) == 1) {
            (*state)++;
        }
        break;
    case 1:
        if (func_02175CF4(v, v + 0x1AC) != 0) {
            c->f9C = 1;
            (*state)++;
        }
        break;
    case 2:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0201F02C(c->obj.f00, 1, func_02012944(func_020120F4(sub)));
        func_0201F184(c->obj.f00, 2, c->f58);
        func_0217F3C4(&c->obj, d_02183870[c->f42]);
        (*state)++;
        break;
    case 3:
        if (func_0217F40C(&c->obj) == 1) {
            func_0217F3C4(&c->obj, d_0218387A[c->f42]);
            (*state)++;
        }
        break;
    case 4:
        if (func_0217F40C(&c->obj) == 1) {
            func_0217F3C4(&c->obj, d_02183884[c->f42]);
            func_020061E4(0x5E0);
            (*state)++;
        }
        break;
    case 5:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 6;
        }
        break;
    case 6:
        if (func_0217F420() == 1) {
            *state = 7;
        }
        break;
    case 7:
        func_0217FE38(v, c);
        func_0201235C(a, func_021804F8(sub, c->f9C));
        return 0;
    }
    return 0;
}
