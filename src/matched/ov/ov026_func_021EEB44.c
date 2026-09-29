/*
 * function: func_021EEB44
 * address:  0x021EEB44
 * packet:   pkt_ov026_021EEB44
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEB44  0x021EEB44  thumb  ov026
 *   func_021EEF0C  0x021EEF0C  thumb  ov026
 *   func_02014A10  0x02014A10  thumb
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A2108  0x021A2108  thumb  ov021
 *   func_021A2154  0x021A2154  thumb  ov021
 *   func_021A2130  0x021A2130  thumb  ov021
 *   func_021A25DC  0x021A25DC  thumb  ov021
 *   func_021A213C  0x021A213C  thumb  ov021
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_021A25BC  0x021A25BC  thumb  ov021
 *   func_021A2160  0x021A2160  thumb  ov021
 *   func_021A223C  0x021A223C  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 */

typedef signed short s16;

extern s16 *func_021A21B8(int);
extern void func_021A2108(int, int, int);
extern void func_021A2154(int, int, int);
extern void func_021A2130(int, int, int, int);
extern void func_021A25DC(int, int);
extern int func_021A213C(int);
extern void func_021A232C(int, int, int, int, int);
extern void func_021A25BC(int, int);
extern void func_021A2160(int, int, int);
extern int func_021A223C(int, int);
extern int func_021A23B0(int);
extern int func_02014A10(int);
extern void func_021EEF0C(int, s16 *);

int func_021EEB44(int a, int b, int c)
{
    s16 *p;
    int t;
    int u;

    p = func_021A21B8(a);
    switch (p[0]) {
    case 0:
        func_021A2108(a, 0x3E, func_02014A10(6));
        p[0] = p[0] + 1;
        p[1] = 0x5A;
        break;
    case 1:
        p[1] = p[1] - 1;
        if (p[1] < 0) {
            p[0] = p[0] + 1;
        }
        break;
    case 2:
        func_021A2154(a, 0x28C6, 8);
        p[1] = 0x10;
        p[0] = p[0] + 1;
        break;
    case 3:
        p[1] = p[1] - 1;
        if (p[1] < 0) {
            func_021A2130(a, 0x23DE, 4, 0x3C);
            func_021A25DC(a, 0x692);
            p[0] = p[0] + 1;
        }
        break;
    case 4:
        if (func_021A213C(a) == 0) {
            func_021A232C(a, 9, 0x7F80, 0x50, b);
            p[0] = p[0] + 1;
            p[1] = 0x30;
        }
        break;
    case 5:
        p[1] = p[1] - 1;
        if (p[1] == 0) {
            func_021A25BC(a, 0x690);
            func_021A2160(a, 1, 0);
        }
        t = func_021A223C(a, c);
        u = func_021A23B0(a);
        if (t != 0 && u != 0) {
            return 1;
        }
        break;
    }
    func_021EEF0C(a, p);
    return 0;
}
