/*
 * function: func_0217F390
 * address:  0x0217F390
 * packet:   pkt_ov018_0217F390
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02190E40  0x02190E40  thumb  ov021
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

typedef unsigned int   u32;
int func_02190E40(u32 a);

void func_0217F390(Ov018Obj *p)
{
    if (p->f18 != 0) {
        func_02190E40((u32)p->f18);
        p->f18 = 0;
    }
}
