/*
 * function: func_0217F528
 * address:  0x0217F528
 * packet:   pkt_ov018_0217F528
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02034714  0x02034714  arm
 *   func_02190708  0x02190708  thumb  ov021
 *   d_02183B2C     0x02183B2C  data
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
} Ov018Obj;

typedef unsigned short u16;

extern unsigned char d_02183B2C[];

void func_0201210C(int);
void func_02034714(void *, int, void *);
void *func_02190708(void *, void *, u16, u16, u16, u16);

void func_0217F528(Ov018Obj *p, int a, int b, int c, int d, int e)
{
    func_0201210C(a);
    if (p->f20 != 0) {
        func_02034714(d_02183B2C, 0, d_02183B2C);
    }
    p->f20 = func_02190708(p->f24, p->f0C, b, c, d, e);
}
