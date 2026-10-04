/*
 * function: func_02181A98
 * address:  0x02181A98
 * packet:   pkt_ov018_02181A98
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
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0217F3C4  0x0217F3C4  thumb
 *   func_0217F40C  0x0217F40C  thumb
 *   func_0217F420  0x0217F420  thumb
 *   func_0217FE38  0x0217FE38  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0217CA1C  0x0217CA1C  thumb
 *   func_0201235C  0x0201235C  thumb
 *   d_02183932     0x02183932  data  a2
 */

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
    unsigned char pad00[0x10];
    Ov018Obj obj;
    unsigned char pad40[2];
    unsigned char f42;
    unsigned char pad43[0x35];
    int f78;
} Ov018Outer;

extern unsigned short d_02183932[];

typedef unsigned int   u32;
struct Obj;
struct WordSet;
void *func_020124E4(struct Obj *p);
struct Ctx;
u32 func_02012138(const struct Ctx *p);
struct S0201235C;
int func_02158344(int a0);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0217F3C4(Ov018Obj *p, int a);
int func_0217F40C(Ov018Obj *p);
int func_0217F420(void);
void func_0217FE38(int v, Ov018Outer *c);
void func_020061E4(u32 a);
void *func_0217CA1C(void *p);
void func_0201235C(struct S0201235C *o, u32 *out);

int func_02181A98(void *a, int *state, Ov018Outer *c)
{
    void *sub;
    void *sys;
    int v;

    sub = func_020124E4(a);
    sys = (void *)func_02012138(sub);
    v = func_02158344((int)sys);
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, &c->f78);
        func_0217F3C4(&c->obj, d_02183932[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *state = 3;
        }
        break;
    case 3:
        func_0217FE38(v, c);
        if (func_02158344((int)sys) != 0) {
            func_020061E4(0x737);
            func_0201235C(a, func_0217CA1C(sub));
            return 0;
        }
        return 1;
    }
    return 0;
}
