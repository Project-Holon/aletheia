/*
 * file:     intrude_subdisp_p13.c
 * unit:     yes
 * function: func_0217F318, func_0217F36C, func_0217F390, func_0217F3A4, func_0217F3C4
 * address:  0x0217F318
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
 *   func_0217F58C  0x0217F58C  thumb
 *   func_0217F45C  0x0217F45C  thumb
 *   func_02190E40  0x02190E40  thumb  ov021
 *   func_021904C8  0x021904C8  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0217F3E4  0x0217F3E4  thumb
 *   func_02190F64  0x02190F64  thumb  ov021
 *   func_02190EB8  0x02190EB8  thumb  ov021
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 */
struct Rec;
struct U16Vec;
struct WordSet;
struct Fx;
struct Obj2;
struct P;
struct MsgBank;
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

typedef unsigned int   u32;

typedef unsigned short u16;

void func_0217F58C(Ov018Obj *p);
void func_0217F45C(Ov018Obj *p);
int func_02190E40(u32 a);
u32 func_021904C8(struct Rec *a0);
void func_02045808(struct U16Vec *vec);
u32 func_0201ED04(struct WordSet *p);
void func_0217F3E4(Ov018Obj *p);
struct Obj2 *func_02190F64(struct Fx *a, u32 b);
void func_02190EB8(struct P *p, u32 b, u16 c, u32 d);
void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
void func_0201F250(struct WordSet *ws, void *dst, void *src);
void func_0217F318(Ov018Obj *p);
void func_0217F36C(Ov018Obj *p);
void func_0217F390(Ov018Obj *p);
void func_0217F3A4(Ov018Obj *p, void *a);
void func_0217F3C4(Ov018Obj *p, int a);


void func_0217F318(Ov018Obj *p)
{
    func_0217F390(p);
    func_0217F58C(p);
    func_0217F45C(p);
    if (p->f00 != 0) {
        if (p->f18 != 0) {
            func_02190E40((u32)p->f18);
            p->f18 = 0;
        }
        func_021904C8(p->f0C);
        func_021904C8(p->f10);
        func_021904C8(p->f14);
        func_02045808(p->f08);
        func_02045808(p->f04);
        func_0201ED04(p->f00);
        p->f00 = 0;
    }
}


void func_0217F36C(Ov018Obj *p)
{
    if (p->f18 != 0) {
        if (p->f28 == 1) {
            func_0217F3E4(p);
        }
    } else {
        p->f18 = func_02190F64(p->f24, (u32)p->f0C);
    }
}


void func_0217F390(Ov018Obj *p)
{
    if (p->f18 != 0) {
        func_02190E40((u32)p->f18);
        p->f18 = 0;
    }
}


void func_0217F3A4(Ov018Obj *p, void *a)
{
    func_0217F36C(p);
    func_02190EB8(p->f18, 0, 0, (u32)a);
    p->f28 = 1;
}


void func_0217F3C4(Ov018Obj *p, int a)
{
    func_02045CAC(p->f0C, a, p->f08);
    func_0201F250(p->f00, p->f04, p->f08);
    func_0217F3A4(p, p->f04);
}
