/*
 * function: func_0217F2B4
 * address:  0x0217F2B4
 * packet:   pkt_ov018_0217F2B4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_0201EC74  0x0201EC74  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_021904B0  0x021904B0  thumb  ov021
 */

typedef unsigned char u8;

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
    u8 f28;
} Ov018Obj;

extern void *func_0201210C(void *p);
extern void *func_02188C54(unsigned char *p);
extern void *func_0201EC74(int a, int b, int heap);
extern void *func_020457B0(int n, int heap);
extern void *func_021904B0(void *a, int b);

void func_0217F2B4(Ov018Obj *p, void *a)
{
    void *r;

    r = func_02188C54(func_0201210C(a));
    if (p->f00 == 0) {
        p->f00 = func_0201EC74(6, 0x20, 4);
        p->f04 = func_020457B0(0x1F0, 4);
        p->f08 = func_020457B0(0x1D0, 4);
        p->f0C = func_021904B0(r, 0x44);
        p->f10 = func_021904B0(r, 0x42);
        p->f14 = func_021904B0(r, 0x43);
        p->f24 = r;
        p->f28 = 0;
    }
}
