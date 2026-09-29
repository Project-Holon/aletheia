/*
 * function: func_021EF1C4
 * address:  0x021EF1C4
 * packet:   pkt_ov025_021EF1C4
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021A2630  0x021A2630  thumb  ov021
 *   func_021A2638  0x021A2638  thumb  ov021
 *   func_021A2640  0x021A2640  thumb  ov021
 *   func_021A2654  0x021A2654  thumb  ov021
 *   func_021A26C4  0x021A26C4  thumb  ov021
 *   func_021A21E0  0x021A21E0  thumb  ov021
 *   func_0204B908  0x0204B908  arm
 *   func_0204B918  0x0204B918  arm
 */

typedef unsigned short u16;
typedef signed short   s16;

typedef struct {
    s16 x;
    s16 y;
} Pt;

extern int *func_021A2630(int);
extern int func_021A2638(int);
extern void func_021A2640(int, Pt *);
extern void func_021A2654(int, Pt *);
extern void func_021A26C4(int, Pt *);
extern void func_021A21E0(int);
extern void func_0204B908(int, u16);
extern int func_0204B918(int);

void func_021EF1C4(int a)
{
    int *p;
    int h;
    Pt pt;

    p = func_021A2630(a);
    h = func_021A2638(a);
    func_021A2640(a, &pt);
    switch (p[3]) {
    case 0:
        if (++p[0] > p[1]) {
            p[3] = 1;
            p[0] = (p[6] % 4) * 2 + 8;
            p[4] = 2;
            p[2] = 2;
            func_0204B908(h, func_0204B918(h) + 3);
            return;
        }
        pt.x = pt.x + (s16)p[4];
        pt.y = pt.y + (s16)p[2];
        func_021A2654(a, &pt);
        break;
    case 1:
        pt.x = pt.x + (s16)p[4];
        if (p[0] % 2 == 0) {
            pt.y = pt.y + (s16)p[2];
        } else {
            pt.y = pt.y - (s16)p[2];
        }
        if (p[0] % 4 == 0) {
            if (p[2] - 1 >= 0) {
                p[2] = p[2] - 1;
            }
            if (p[4] - 1 >= 0) {
                p[4] = p[4] - 1;
            }
        }
        func_021A26C4(a, &pt);
        if (p[0]-- <= 0) {
            p[3] = 2;
        }
        break;
    case 2:
        func_021A21E0(a);
        break;
    }
}
