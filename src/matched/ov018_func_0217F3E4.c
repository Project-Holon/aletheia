/*
 * function: func_0217F3E4
 * address:  0x0217F3E4
 * packet:   pkt_ov018_0217F3E4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_02190F7C  0x02190F7C  thumb  ov021
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
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj;

extern unsigned char d_02183B2C[];

void func_02034714(void *, int, void *);
void func_02190F7C(void *);

void func_0217F3E4(Ov018Obj *p)
{
    if (p->f18 == 0) {
        func_02034714(d_02183B2C, 0, d_02183B2C);
    }
    func_02190F7C(p->f18);
    p->f28 = 0;
}
