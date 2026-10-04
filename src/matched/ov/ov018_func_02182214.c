/*
 * function: func_02182214
 * address:  0x02182214
 * packet:   pkt_ov018_02182214
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217405C  0x0217405C  thumb  ov011
 *   func_02175CF4  0x02175CF4  thumb  ov011
 *   func_021745F8  0x021745F8  thumb  ov011
 *   func_02012944  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EF40  0x0201EF40  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_0217F5F0  0x0217F5F0  thumb
 *   func_0217F318  0x0217F318  thumb
 *   func_0217F3C4  0x0217F3C4  thumb
 *   func_0217F40C  0x0217F40C  thumb
 *   func_0217F420  0x0217F420  thumb
 *   func_021804F8  0x021804F8  thumb
 *   func_0201235C  0x0201235C  thumb
 *   d_02183998     0x02183998  data  a2
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
    Ov018Obj obj;       /* 0x00 */
    u8 f30[0x40 - 0x30]; /* 0x30 */
    u16 f40;            /* 0x40 */
    u8 pad42[2];
    u16 f44;            /* 0x44 */
    u8 pad46[2];
    int f48;            /* 0x48 */
    int f4C;            /* 0x4C */
    int f50;            /* 0x50 */
} Ov018Work;

extern const u16 d_02183998[];

struct Ctx;
struct Obj;
struct S0201235C;
struct WordSet;
void *func_020124E4(struct Obj *p);
u32 func_02012138(const struct Ctx *p);
void *func_020120F4(const struct Ctx *p);
void *func_0201210C(const struct Ctx *p);
int func_02158344(int a0);
int func_0217405C(void *, void *);
int func_02175CF4(void *, void *);
int func_021745F8(u8, void *);
u8 *func_02012944(void *p);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0201EF40(struct WordSet *p, u32 i, u32 v);
int func_02012B58(void *);
int func_0217F5F0(void *, u8);
void func_0217F318(Ov018Obj *p);
void func_0217F3C4(Ov018Obj *p, u16 a);
int func_0217F40C(Ov018Obj *p);
int func_0217F420(void);
void *func_021804F8(void *, int);
void func_0201235C(struct S0201235C *o, u32 *out);

int func_02182214(void *a, int *state, Ov018Work *c)
{
    void *sub;
    void *x;
    u8 *v;
    int idx;

    sub = func_020124E4(a);
    v = (u8 *)func_02012138(sub);
    x = func_020120F4(sub);
    func_0201210C(sub);
    v = (u8 *)func_02158344((int)v);
    if (v == 0) {
        if (func_0217F40C(&c->obj) == 0) {
            return 0;
        }
        if (*state < 4) {
            func_0217F3C4(&c->obj, 6);
            *state = 4;
            c->f48 = 1;
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
        if ((c->f50 = func_02175CF4(v, v + 0x1AC)) != 0) {
            (*state)++;
        }
        break;
    case 2:
        func_0201F02C(c->obj.f00, 0, func_02012944(x));
        func_0201EF40(c->obj.f00, 1, c->f40);
        if (c->f50 == 1) {
            idx = d_02183998[func_0217F5F0(v, func_02012B58(x))];
            c->f4C = 1;
        } else {
            idx = 5;
        }
        func_0217F3C4(&c->obj, idx);
        (*state)++;
        break;
    case 3:
        if (c->f4C == 1) {
            if (func_021745F8(c->f44, c->f30) == 1) {
                (*state)++;
            }
        } else {
            (*state)++;
        }
        break;
    case 4:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 5;
        }
        break;
    case 5:
        if (func_0217F420() == 1) {
            *state = 6;
        }
        break;
    case 6:
        func_0217F318(&c->obj);
        func_0201235C(a, func_021804F8(sub, c->f4C));
        return 0;
    }
    return 0;
}
