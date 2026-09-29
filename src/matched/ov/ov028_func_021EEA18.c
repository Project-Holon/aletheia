/*
 * function: func_021EEA18
 * address:  0x021EEA18
 * packet:   pkt_ov028_021EEA18
 * region:   ov028
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEA18  0x021EEA18  thumb  ov028
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A2390  0x021A2390  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 *   func_021A21BC  0x021A21BC  thumb  ov021
 */

extern int *func_021A21B8(int);
extern void func_021A2390(int, int, int, int);
extern int func_021A23B0(int);
extern int func_021A21BC(int);

int func_021EEA18(int a, int b)
{
    int *p = func_021A21B8(a);
    int ok;

    if (p[1] == 0) {
        p[1] = p[1] - 1;
        func_021A2390(a, 0x7FDF, 0x3C, b);
    } else {
        if (b != 0) {
            ok = func_021A23B0(a);
        } else {
            ok = 1;
        }
        if (ok != 0 && func_021A21BC(a) == 0) {
            return 1;
        }
    }
    return 0;
}
