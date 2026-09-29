/*
 * function: func_021C8BFC
 * address:  0x021C8BFC
 * packet:   pkt_ov021_021C8BFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C8D18  0x021C8D18  thumb  ov021
 *   func_021C8BC4  0x021C8BC4  thumb  ov021
 *   func_021A2F98  0x021A2F98  thumb  ov021
 *   func_021ACBC8  0x021ACBC8  thumb  ov021
 *   func_021C8E30  0x021C8E30  thumb  ov021
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_021C8D74  0x021C8D74  thumb  ov021
 *   func_021C8DC4  0x021C8DC4  thumb  ov021
 *   func_021C8DD4  0x021C8DD4  thumb  ov021
 *   func_021C8E5C  0x021C8E5C  thumb  ov021
 *   func_021C8D3C  0x021C8D3C  thumb  ov021
 *   func_021C8DE4  0x021C8DE4  thumb  ov021
 */

extern void func_021C8D18(int *p);
extern int func_021C8BC4();
extern int func_021A2F98(int a);
extern void func_021ACBC8(int a, int b);
extern void func_021C8E30(int *p);
extern int func_0216D454(int a);
extern void func_021C8D74(int *p);
extern void func_021C8DC4(int *p);
extern void func_021C8DD4(int *p);
extern void func_021C8E5C(int *p);
extern void func_021C8D3C(int *p);
extern void func_021C8DE4(int *p);

int func_021C8BFC(int a, int *st, int *p)
{
    switch (*st) {
    case 0:
        func_021C8D18(p);
        if (func_021C8BC4() == 0) {
            *st = 2;
        } else {
            func_021ACBC8(func_021A2F98(p[2]), 0);
            func_021C8E30(p);
            *st = 1;
        }
        break;
    case 1:
        func_021C8E30(p);
        if (func_0216D454(p[3])) {
            func_021C8D74(p);
            func_021C8DC4(p);
            func_021C8DD4(p);
            if (p[4] == 0 && p[5] == 0) {
                func_021C8E5C(p);
                *st = 2;
            } else {
                func_021C8D3C(p);
            }
        }
        break;
    case 2:
        func_021C8DE4(p);
        return 1;
    }
    return 0;
}
