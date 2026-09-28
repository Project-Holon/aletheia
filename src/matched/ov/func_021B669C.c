/*
 * function: func_021B669C
 * address:  0x021B669C
 * packet:   pkt_ov179_021B669C
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204A380  0x0204A380  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0207EB78  0x0207EB78  arm
 *   func_0207ECF0  0x0207ECF0  arm
 *   func_020307B0  0x020307B0  arm
 */

extern int func_0204A380(int, int, int, int);
extern void func_020862F0(int, int);
extern void func_0207EB78(int, int, int);
extern void func_0207ECF0(int, int, int);
extern void func_020307B0(int);

void func_021B669C(int a, int b, int c, int d, int e)
{
    int t = func_0204A380(a, b, 1, 0x807f);

    func_020862F0(t, d);
    if (e == 0) {
        func_0207EB78(t, c, d);
    } else {
        func_0207ECF0(t, c, d);
    }
    func_020307B0(t);
}