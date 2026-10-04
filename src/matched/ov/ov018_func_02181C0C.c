/*
 * function: func_02181C0C
 * address:  0x02181C0C
 * packet:   pkt_ov018_02181C0C
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
 *   func_0217405C  0x0217405C  thumb  ov011
 *   func_02175CF4  0x02175CF4  thumb  ov011
 *   func_0217456C  0x0217456C  thumb  ov011
 *   func_021762D8  0x021762D8  thumb  ov011
 *   func_0217F3C4  0x0217F3C4  thumb
 *   func_0217F40C  0x0217F40C  thumb
 *   func_0217F420  0x0217F420  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0217FE38  0x0217FE38  thumb
 *   func_021804F8  0x021804F8  thumb
 *   func_0201235C  0x0201235C  thumb
 *   d_02183950     0x02183950  data  a2
 *   d_0218395A     0x0218395A  data  a2
 *   d_02183964     0x02183964  data  a2
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
    u16 f00;            /* 0x00 */
    u8 pad02[0x10 - 0x02];
    Ov018Obj obj;       /* 0x10 */
    u8 f40;             /* 0x40 */
    u8 pad41;
    u8 f42;             /* 0x42 */
    u8 pad43;
    u8 f44[0x5C - 0x44]; /* 0x44 */
    u8 f5C[0x98 - 0x5C]; /* 0x5C */
    int f98;            /* 0x98 */
    int f9C;            /* 0x9C */
    int fA0;            /* 0xA0 */
} Ov018Outer;

extern const u16 d_02183950[];
extern const u16 d_0218395A[];
extern const u16 d_02183964[];

struct Obj;
struct S0201235C;
void *func_020124E4(struct Obj *p);
struct Ctx;
u32 func_02012138(const struct Ctx *p);
int func_02158344(int a0);
int func_0217405C(void *, void *);
int func_02175CF4(void *, void *);
int func_0217456C(int a, int b, int c, ...);
void func_021762D8(void *, void *, void *, u32);
void func_0217F3C4(Ov018Obj *p, u16 a);
int func_0217F40C(Ov018Obj *p);
int func_0217F420(void);
void func_020061E4(u32 a);
void func_0217FE38(void *v, Ov018Outer *c);
void *func_021804F8(void *, int);
void func_0201235C(struct S0201235C *o, u32 *out);

int func_02181C0C(void *a, int *state, Ov018Outer *c)
{
    void *sub;
    u8 *v;
    int r;

    sub = func_020124E4(a);
    v = (u8 *)func_02158344((int)((void *)func_02012138(sub)));
    if (v == 0 && *state <= 2 && *state < 6) {
        func_0217F3C4(&c->obj, 4);
        *state = 6;
        c->f98 = 1;
        return 0;
    }
    switch (*state) {
    case 0:
        if (func_0217405C(v, v + 0x1AC) == 1) {
            (*state)++;
        }
        break;
    case 1:
        r = c->fA0 = func_02175CF4(v, v + 0x1AC);
        switch (r) {
        case 1:
            *state = 2;
            break;
        case 2:
            *state = 5;
            break;
        }
        break;
    case 2:
        if (func_0217456C((int)v, c->f40, 2) == 1) {
            (*state)++;
        }
        break;
    case 3:
        c->f9C = 1;
        func_021762D8(c->f44, c->f5C, c->obj.f00, c->f00);
        func_0217F3C4(&c->obj, d_02183950[c->f42]);
        (*state)++;
        break;
    case 4:
        if (func_0217F40C(&c->obj) == 1) {
            func_0217F3C4(&c->obj, d_0218395A[c->f42]);
            func_020061E4(0x5E0);
            *state = 6;
        }
        break;
    case 5:
        c->f9C = 1;
        func_021762D8(c->f44, c->f5C, c->obj.f00, c->f00);
        func_0217F3C4(&c->obj, d_02183964[c->f42]);
        *state = 6;
        break;
    case 6:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 7;
        }
        break;
    case 7:
        if (func_0217F420() == 1) {
            *state = 8;
        }
        break;
    case 8:
        func_0217FE38(v, c);
        if (c->fA0 == 1) {
            func_0201235C(a, func_021804F8(sub, c->f9C));
            return 0;
        }
        return 1;
    }
    return 0;
}
