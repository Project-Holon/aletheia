/*
 * function: func_021EEFF0
 * address:  0x021EEFF0
 * packet:   pkt_ov025_021EEFF0
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEFF0 0x021EEFF0 thumb ov025
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A223C 0x021A223C thumb ov021
 *   func_021A232C 0x021A232C thumb ov021
 *   func_021A2108 0x021A2108 thumb ov021
 *   func_021A23B0 0x021A23B0 thumb ov021
 *   func_021A244C 0x021A244C thumb ov021
 *   func_021A2564 0x021A2564 thumb ov021
 *   func_02014A10 0x02014A10 thumb
 */

extern int *func_021A21B8(int);
extern int func_021A223C(int, int);
extern void func_021A232C(int, int, int, int, int);
extern void func_021A2108(int, int, int);
extern int func_021A23B0(int);
extern void func_021A244C(int, int *, int *);
extern void func_021A2564(int, int, int);
extern int func_02014A10(int);

int func_021EEFF0(int a, int b, int c)
{
    int *p;
    int t;
    int x;
    int y;

    p = func_021A21B8(a);
    t = func_021A223C(a, c);
    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0) {
            func_021A232C(a, 9, 0x7F80, 0x3C, b);
            func_021A2108(a, 0x3E, func_02014A10(5));
        }
    } else if (func_021A23B0(a) != 0 && t != 0) {
        return 1;
    }
    func_021A244C(a, &x, &y);
    func_021A2564(a, x, y);
    return 0;
}
