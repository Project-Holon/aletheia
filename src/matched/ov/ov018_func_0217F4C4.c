/*
 * function: func_0217F4C4
 * address:  0x0217F4C4
 * packet:   pkt_ov018_0217F4C4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021909BC  0x021909BC  thumb  ov021
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

void func_021909BC(void *);

void func_0217F4C4(Ov018Obj *p)
{
    if (p->f2C != 0) {
        func_021909BC(p->f2C);
        p->f2C = 0;
    }
}
