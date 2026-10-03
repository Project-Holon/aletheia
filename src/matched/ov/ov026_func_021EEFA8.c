/*
 * function: func_021EEFA8
 * address:  0x021EEFA8
 * packet:   pkt_ov026_021EEFA8
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEFA8  0x021EEFA8  thumb  ov026
 *   func_021EF614  0x021EF614  thumb  ov026
 *   func_021EF664  0x021EF664  thumb  ov026
 *   func_021EF830  0x021EF830  thumb  ov026
 *   func_02014A10  0x02014A10  thumb
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A2108  0x021A2108  thumb  ov021
 *   func_021A25BC  0x021A25BC  thumb  ov021
 *   func_021A2160  0x021A2160  thumb  ov021
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_021A223C  0x021A223C  thumb  ov021
 *   func_021A23B0  0x021A23B0  thumb  ov021
 */

typedef unsigned short u16;
typedef signed short   s16;

extern s16 *func_021A21B8(int);
extern void func_021A2108(int, int, int);
extern void func_021A25BC(int, int);
extern void func_021A2160(int, int, int);
extern void func_021A232C(int, int, int, int, int);
extern int func_021A223C(int, int);
extern int func_021A23B0(int);
typedef unsigned int   u32;
extern u16 func_02014A10(u32 i);
extern void func_021EF614(int, u16 *, int, int);
extern void func_021EF664(int, s16 *, int, int);
extern void func_021EF830(int, s16 *);

int func_021EEFA8(int a, int b, int c)
{
    s16 *p;
    int t;
    int u;

    p = func_021A21B8(a);
    switch (p[0]) {
    case 0:
        func_021A2108(a, 0x3E, func_02014A10(7));
        p[1] = 0x5A;
        p[0] = p[0] + 1;
        break;
    case 1:
        p[1] = p[1] - 1;
        if (p[1] <= 0) {
            func_021EF614(a, (u16 *)p, b, 1);
            p[7] = 0x78;
            p[1] = 8;
            p[0] = p[0] + 1;
        }
        break;
    case 2:
        p[1] = p[1] - 1;
        if (p[1] == 0) {
            func_021A25BC(a, 0x690);
            func_021A2160(a, 1, 0);
            func_021A232C(a, 9, 0x7F80, 10, b);
        }
        t = func_021A223C(a, c);
        u = func_021A23B0(a);
        if (t == 1 && u == 1 && p[1] <= 0) {
            return 1;
        }
        break;
    }
    func_021EF664(a, p, b, 0);
    func_021EF830(a, p);
    return 0;
}
