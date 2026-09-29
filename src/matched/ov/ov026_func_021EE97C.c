/*
 * function: func_021EE97C
 * address:  0x021EE97C
 * packet:   pkt_ov026_021EE97C
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EE97C 0x021EE97C thumb ov026
 *   func_021A2630 0x021A2630 thumb ov021
 *   func_021A2638 0x021A2638 thumb ov021
 *   func_021A2640 0x021A2640 thumb ov021
 *   func_021A26C4 0x021A26C4 thumb ov021
 *   func_021A21E0 0x021A21E0 thumb ov021
 *   func_0204B908 0x0204B908 arm
 */

typedef signed short s16;

typedef struct {
    s16 x;
    s16 y;
} Pt;

extern int *func_021A2630(int);
extern int func_021A2638(int);
extern void func_021A2640(int, Pt *);
extern void func_021A26C4(int, Pt *);
extern void func_021A21E0(int);
extern void func_0204B908(int, int);

void func_021EE97C(int a)
{
    int *p;
    int h;
    Pt pt;

    p = func_021A2630(a);
    h = func_021A2638(a);
    func_021A2640(a, &pt);
    switch (p[3]) {
    case 0:
        pt.x = pt.x + (s16)p[4];
        pt.y = pt.y + (s16)p[2];
        p[0] = p[0] + 2;
        if (p[0] > p[1]) {
            if (p[5] < 7) {
                p[3] = 2;
            } else {
                p[3] = 1;
                p[0] = 4;
                func_0204B908(h, 3);
            }
        }
        func_021A26C4(a, &pt);
        break;
    case 1:
        h = p[0];
        p[0] = h - 1;
        if (h <= 0) {
            p[3] = 2;
        }
        break;
    case 2:
        func_021A21E0(a);
        break;
    }
}
