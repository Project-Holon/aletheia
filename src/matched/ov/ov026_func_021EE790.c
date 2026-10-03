/*
 * function: func_021EE790
 * address:  0x021EE790
 * packet:   pkt_ov026_021EE790
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EE790 0x021EE790 thumb ov026
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A223C 0x021A223C thumb ov021
 *   func_021A232C 0x021A232C thumb ov021
 *   func_021A2108 0x021A2108 thumb ov021
 *   func_021A25BC 0x021A25BC thumb ov021
 *   func_021A23B0 0x021A23B0 thumb ov021
 *   func_021A244C 0x021A244C thumb ov021
 *   func_021A2564 0x021A2564 thumb ov021
 *   func_02014A10 0x02014A10 thumb
 */

extern int *func_021A21B8(int);
extern int func_021A223C(int, int);
extern void func_021A232C(int, int, int, int, int);
extern void func_021A2108(int, int, int);
extern void func_021A25BC(int, int);
extern int func_021A23B0(int);
extern void func_021A244C(int, int *, int *);
extern void func_021A2564(int, int, int);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 func_02014A10(u32 i);

int func_021EE790(int a, int b, int c)
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
            func_021A232C(a, 8, 0x7F5F, 0x5A, b);
            func_021A2108(a, 0x3E, func_02014A10(2));
            func_021A25BC(a, 0x691);
        }
    } else if (func_021A23B0(a) != 0 && t != 0) {
        return 1;
    }
    func_021A244C(a, &x, &y);
    func_021A2564(a, x, y);
    return 0;
}
