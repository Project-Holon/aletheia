/*
 * function: func_021BC664
 * address:  0x021BC664
 * packet:   pkt_ov021_021BC664
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD090  0x021BD090  thumb  ov021
 *   func_021BD094  0x021BD094  thumb  ov021
 *   func_020493D4  0x020493D4  arm
 *   func_02030734  0x02030734  arm
 *   func_0204932C  0x0204932C  arm
 *   func_02062A98  0x02062A98  arm
 */

extern int func_021BD090(int a);
extern int func_021BD094(int a);
extern int func_020493D4(int a, int b);
extern int func_02030734(int a, int b, int c, int d, int e);
extern void func_0204932C(int a, int b, int c);
extern void func_02062A98(int a, int b);

typedef struct S {
    char pad[0x14c];
    int a;
    int b;
} S;

void func_021BC664(S *p)
{
    int r4, r6, h;

    r4 = func_021BD090((int)p);
    r6 = func_021BD094((int)p);
    h =func_02030734(r4, func_020493D4(r6, 1), 0, 0x021DE354, 0x2c8);
    p->a = h;
    func_0204932C(r6, 1, h);
    func_02062A98(p->a, (int)&p->b);
}
