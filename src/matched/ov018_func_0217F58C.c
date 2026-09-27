/*
 * function: func_0217F58C
 * address:  0x0217F58C
 * packet:   pkt_ov018_0217F58C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02190728  0x02190728  thumb  ov021
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

void func_02190728(void *);

void func_0217F58C(Ov018Obj *p)
{
    if (p->f20 != 0) {
        func_02190728(p->f20);
        p->f20 = 0;
    }
}
