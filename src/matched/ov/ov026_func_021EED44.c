/*
 * function: func_021EED44
 * address:  0x021EED44
 * packet:   pkt_ov026_021EED44
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EED44 0x021EED44 thumb ov026
 *   func_021EEF0C 0x021EEF0C thumb ov026
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A223C 0x021A223C thumb ov021
 *   func_021A2390 0x021A2390 thumb ov021
 *   func_021A23B0 0x021A23B0 thumb ov021
 *   func_021A21BC 0x021A21BC thumb ov021
 */

typedef signed short s16;

extern s16 *func_021A21B8(int);
extern int func_021A223C(int, int);
extern void func_021A2390(int, int, int, int);
extern int func_021A23B0(int);
extern int func_021A21BC(int);
extern void func_021EEF0C(int, s16 *);

int func_021EED44(int a, int b, int c)
{
    s16 *p;
    int t;
    int ok;

    p = func_021A21B8(a);
    t = func_021A223C(a, c);
    if (p[1] > 0) {
        p[1] = p[1] - 1;
        if (p[1] == 0) {
            func_021A2390(a, 0x7FDF, 0x32, b);
        }
    } else {
        if (b != 0) {
            ok = func_021A23B0(a);
        } else {
            ok = 1;
        }
        if (ok != 0 && t != 0 && func_021A21BC(a) == 0) {
            return 1;
        }
    }
    func_021EEF0C(a, p);
    return 0;
}
