/*
 * function: func_02181DD4
 * address:  0x02181DD4
 * packet:   pkt_ov018_02181DD4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0217F3C4  0x0217F3C4  thumb
 *   func_0217F40C  0x0217F40C  thumb
 *   func_0217F318  0x0217F318  thumb
 *   func_02158768  0x02158768  thumb  ov010
 *   func_021589D0  0x021589D0  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_020307B0  0x020307B0  arm
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
    void *f30;
} Ov018Obj;

typedef unsigned short u16;
typedef unsigned int   u32;
struct Evt;
struct Obj;
struct WordSet;
void *func_020124E4(struct Obj *p);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0217F3C4(Ov018Obj *p, int a);
int func_0217F40C(Ov018Obj *p);
void func_0217F318(Ov018Obj *p);
struct Desc;
struct Desc *func_02158768(int a0, int a1, int a2, int a3);
int func_021589D0(int a0);
void func_02159058(int a, int b, int c, int d, u16 e);
void func_02012374(struct Evt *evt, struct Evt **out);
void func_020307B0(void *);

int func_02181DD4(void *a, int *state, Ov018Obj *c)
{
    void *sub;
    void *w;

    sub = func_020124E4(a);
    switch (*state) {
    case 0:
        func_0201F02C(c->f00, 0, c->f30);
        func_0217F3C4(c, 0x1C);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C(c) == 1) {
            (*state)++;
        }
        break;
    case 2:
        func_0217F318(c);
        w = func_02158768((int)sub, 0xAFD, 0, 4);
        func_02159058(func_021589D0((int)w), 0x1C, 1, 0, 0);
        func_02012374(a, w);
        (*state)++;
        break;
    case 3:
        *state = 4;
        break;
    case 4:
        func_020307B0(c->f30);
        return 1;
    }
    return 0;
}
