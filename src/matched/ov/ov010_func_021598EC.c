/*
 * function: func_021598EC
 * address:  0x021598EC
 * packet:   pkt_ov010_021598EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_021B1BE8  0x021B1BE8  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_020288C4  0x020288C4  thumb
 *   func_0202972C  0x0202972C  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 */

extern int func_0215A5F4(int);
extern int func_0215A5DC(int);
extern int func_020120F4(int);
extern void func_021B1BE8(int);
extern int func_02012A30(int);
extern int func_020288C4(int);
extern int func_0202972C(int, int);
extern void func_0215897C(int, int);

int func_021598EC(int a, int b)
{
    int x = func_0215A5F4(b);
    int y = func_0215A5DC(b);
    int h = func_020120F4(y);
    int r = 0;
    func_021B1BE8(b);
    if (func_020288C4(func_02012A30(h))) {
        func_0215897C(x, func_0202972C(y, r));
        r = 1;
    }
    return r;
}
