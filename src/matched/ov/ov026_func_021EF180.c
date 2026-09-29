/*
 * function: func_021EF180
 * address:  0x021EF180
 * packet:   pkt_ov026_021EF180
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A223C  0x021A223C  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A21BC  0x021A21BC  thumb  ov021
 *   func_021EF664  0x021EF664  thumb  ov026
 *   func_021EF830  0x021EF830  thumb  ov026
 */

extern int func_021A21B8(int);
extern int func_021A223C(int, int);
extern int func_021A23B0(int);
extern int func_021A21BC(int);
extern void func_021EF664(int, int, int, int);
extern void func_021EF830(int, int);

int func_021EF180(int a, int b, int c)
{
    int x;
    int y;
    int t;

    x = func_021A21B8(a);
    y = func_021A223C(a, c);
    t = (b != 0) ? func_021A23B0(a) : 1;
    if (t != 0 && y != 0 && func_021A21BC(a) == 0) {
        return 1;
    }
    func_021EF664(a, x, b, 1);
    func_021EF830(a, x);
    return 0;
}
