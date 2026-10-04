/*
 * function: func_021B9020
 * address:  0x021B9020
 * packet:   pkt_ov091_021B9020
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B907C  0x021B907C  thumb  ov091
 *   func_021B90F8  0x021B90F8  thumb  ov091
 *   func_021B916C  0x021B916C  thumb  ov091
 *   func_021BBBD8  0x021BBBD8  thumb  ov091
 *   func_021BBBE4  0x021BBBE4  thumb  ov091
 */

typedef unsigned char u8;

extern void func_021B907C(u8 *p);
extern void func_021B90F8(u8 *p);
extern void func_021B916C(u8 *p);
extern void func_021BBBD8(int unused, int *q);
extern unsigned int func_021BBBE4(int a, unsigned char *b);

#define W(o) (*(int *)(p + (o)))

void func_021B9020(u8 *p)
{
    int r;

    switch (p[0xe]) {
    case 0:
        func_021B907C(p);
        p[0xe] = 1;
        break;
    case 1:
        func_021BBBD8((int)p, (int *)W(0x154));
        r = func_021BBBE4((int)p, (unsigned char *)((int *)W(0x154)));
        if (r != 0x17) {
            W(0x3c) = r;
            p[0xe] = 2;
        }
        if (*(u8 *)(W(0x280) + 0x63) == 1) {
            p[0xe] = 2;
        }
        break;
    case 2:
        func_021B90F8(p);
        func_021B916C(p);
        break;
    }
}
