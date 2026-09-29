/*
 * function: func_021BCAB0
 * address:  0x021BCAB0
 * packet:   pkt_ov021_021BCAB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD118  0x021BD118  thumb  ov021
 *   func_02013E4C  0x02013E4C  thumb
 *   func_021BC5BC  0x021BC5BC  thumb  ov021
 *   func_021BCB48  0x021BCB48  thumb  ov021
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb
 *   func_0215841C  0x0215841C  thumb
 *   func_021583EC  0x021583EC  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F158  0x0201F158  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_020458F8  0x020458F8  arm
 */

extern int func_021BD118(int a);
extern unsigned int func_02013E4C(void);
extern void func_021BC5BC(int a);
extern int func_021BCB48(int a, int b);
extern void func_02012138(int a);
extern int func_02158344(void);
extern int func_0215841C(int a);
extern int func_021583EC(int a, int b);
extern int func_02045EC0(int a, int b);
extern void func_02045CAC(int a, int b, int c);
extern void func_0201F02C(int a, int b, int c);
extern void func_0201F158(int a, int b, int c);
extern void func_0201F250(int a, int b, int c);
extern void func_02045808(int a);
extern unsigned char func_020458F8(int a);

void func_021BCAB0(int *p)
{
    int r6, r7;
    unsigned int r4;

    r6 = func_021BD118((int)p);
    r4 = func_02013E4C();
    if (r4 >= 0x75) {
        r4 = 0;
    }
    if (r4 == 0) {
        func_021BC5BC((int)p);
        return;
    }
    if (func_021BCB48((int)p, r6) != 0) {
        func_02012138(p[0]);
        func_02158344();
        r7 = func_021583EC(p[1], func_0215841C(p[1]));
        r6 = func_02045EC0(p[5], 3);
        func_02045CAC(p[5], r4, p[7]);
        func_0201F02C(p[2], 0, r7);
        func_0201F158(p[2], 1, r4);
        func_0201F250(p[2], p[7], r6);
        func_02045808(r6);
    } else {
        func_02045CAC(p[5], r4, p[7]);
    }
    *((unsigned char *)p + 0x20) = func_020458F8(p[7]);
}
