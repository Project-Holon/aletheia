/*
 * function: func_021EEDD8
 * address:  0x021EEDD8
 * packet:   pkt_ov026_021EEDD8
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EEDD8 0x021EEDD8 thumb ov026
 *   func_021A2630 0x021A2630 thumb ov021
 *   func_021A2638 0x021A2638 thumb ov021
 *   func_021A2640 0x021A2640 thumb ov021
 *   func_021A26C4 0x021A26C4 thumb ov021
 *   func_021A21E0 0x021A21E0 thumb ov021
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

void func_021EEDD8(int a)
{
    int *p;
    Pt pt;

    p = func_021A2630(a);
    func_021A2638(a);
    func_021A2640(a, &pt);
    switch (p[3]) {
    case 0:
        pt.x = pt.x + (s16)p[4];
        pt.y = pt.y + (s16)p[2];
        if (pt.y >= 0xC0) {
            p[3] = 1;
        }
        func_021A26C4(a, &pt);
        break;
    case 1:
        func_021A21E0(a);
        break;
    }
}
