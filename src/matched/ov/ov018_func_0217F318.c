/*
 * function: func_0217F318
 * address:  0x0217F318
 * packet:   pkt_ov018_0217F318
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0217F390  0x0217F390  thumb
 *   func_0217F58C  0x0217F58C  thumb
 *   func_0217F45C  0x0217F45C  thumb
 *   func_02190E40  0x02190E40  thumb  ov021
 *   func_021904C8  0x021904C8  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
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

void func_0217F390(Ov018Obj *p);
void func_0217F58C(Ov018Obj *p);
void func_0217F45C(Ov018Obj *p);
typedef unsigned int   u32;
int func_02190E40(u32 a);
struct Rec;
void func_021904C8(struct Rec *a0);
struct U16Vec;
struct WordSet;
void func_02045808(struct U16Vec *vec);
u32 func_0201ED04(struct WordSet *p);

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
