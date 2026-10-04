/*
 * function: func_02182AA4
 * address:  0x02182AA4
 * packet:   pkt_ov018_02182AA4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217F3C4  0x0217F3C4  thumb
 *   func_0217F40C  0x0217F40C  thumb
 *   func_0217F318  0x0217F318  thumb
 *   func_02158768  0x02158768  thumb  ov010
 *   func_021589D0  0x021589D0  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_0217FE38  0x0217FE38  thumb
 *   func_0217CA84  0x0217CA84  thumb
 *   func_0201235C  0x0201235C  thumb
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
    unsigned char pad40[0x5C];
    unsigned short f9C;
} Ov018Outer;

typedef unsigned short u16;
struct Evt;
struct Obj;
struct Ctx;
void *func_020124E4(struct Obj *p);
unsigned int func_02012138(const struct Ctx *p);
typedef unsigned int   u32;
struct Desc;
struct S0201235C;
int func_02158344(int a0);
void func_0217F3C4(Ov018Obj *p, int a);
int func_0217F40C(Ov018Obj *p);
void func_0217F318(Ov018Obj *p);
struct Desc *func_02158768(int a0, int a1, int a2, int a3);
int func_021589D0(int a0);
void func_02159058(int a, int b, int c, int d, u16 e);
void func_02012374(struct Evt *evt, struct Evt **out);
void func_0217FE38(int v, Ov018Outer *c);
int func_0217CA84(void *a, int b);
void func_0201235C(struct S0201235C *o, u32 *out);

int func_02182AA4(void *a, int *state, Ov018Outer *c)
{
    void *sub;
    int v;
    void *w;

    sub = func_020124E4(a);
    v = func_02158344((int)((void *)func_02012138(sub)));
    switch (*state) {
    case 0:
        func_0217F3C4(&c->obj, c->f9C);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C(&c->obj) == 1) {
            (*state)++;
        }
        break;
    case 2:
        func_0217F318(&c->obj);
        w = func_02158768((int)sub, 0xAFD, 0, 4);
        func_02159058(func_021589D0((int)w), 0x23F, 1, 0, 0);
        func_02012374(a, w);
        (*state)++;
        break;
    case 3:
        *state = 4;
        break;
    case 4:
        func_0217FE38(v, c);
        func_0201235C(a, (u32 *)func_0217CA84(sub, 0));
        return 0;
    }
    return 0;
}
