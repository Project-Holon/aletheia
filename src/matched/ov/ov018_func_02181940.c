/*
 * function: func_02181940
 * address:  0x02181940
 * packet:   pkt_ov018_02181940
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
 *   d_02183928     0x02183928  data  a2
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

extern unsigned short d_02183928[];

typedef unsigned int   u32;
struct Ctx;
struct Obj;
struct WordSet;
void *func_020124E4(struct Obj *p);
u32 func_02012138(const struct Ctx *p);
int func_02158344(int a0);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0217F3C4(Ov018Obj *p, int a);
int func_0217F40C(Ov018Obj *p);
int func_0217F420(void);
void func_0217FE38(int v, Ov018Outer *c);

int func_02181940(void *a, int *state, Ov018Outer *c)
{
    int v;

    v = func_02158344(func_02012138(func_020124E4(a)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, &c->f78);
        func_0217F3C4(&c->obj, d_02183928[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C(&c->obj) == 1) {
            (*state)++;
        }
        break;
    case 2:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 3;
        }
        break;
    case 3:
        if (func_0217F420() == 1) {
            *state = 4;
        }
        break;
    case 4:
        func_0217FE38(v, c);
        return 1;
    }
    return 0;
}
