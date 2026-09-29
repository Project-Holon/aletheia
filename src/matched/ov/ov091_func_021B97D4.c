/*
 * unit:     yes
 * function: func_021B97D4, func_021B9804
 * address:  0x021B97D4
 * packet:   pkt_ov091_021B97D4
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_021B9804 is an unlabelled tail-call stub inside the extent.
 *
 * symbols:
 *   func_021BBBD8  0x021BBBD8  thumb  ov091
 *   func_021BBBE4  0x021BBBE4  thumb  ov091
 *   func_021BBBA0  0x021BBBA0  thumb  ov091
 *   func_021BBB40  0x021BBB40  thumb  ov091
 */

typedef unsigned char u8;

extern void func_021BBBD8(int unused, int *q);
extern int func_021BBBE4(u8 *p, int *q);
extern void func_021BBBA0(int unused, int *q);
extern void func_021BBB40(u8 *p, int *q);

#define W(o) (*(int *)(p + (o)))

void func_021B97D4(u8 *p)
{
    int r;

    func_021BBBD8((int)p, (int *)W(0x154));
    r = func_021BBBE4(p, (int *)W(0x154));
    if (r != 0x17) {
        ((void (*)(u8 *, int))W(0x14c))(p, r);
        func_021BBBA0((int)p, (int *)W(0x154));
    }
}

void func_021B9804(u8 *p, int a1)
{
    p[0xc] = 9;
    W(0x14c) = a1;
    func_021BBB40(p, (int *)W(0x154));
}
