/*
 * function: func_021F3A28
 * address:  0x021F3A28
 * packet:   pkt_ov043_021F3A28
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_021F3D78  0x021F3D78  thumb
 */

extern void *func_0201210C(void);
extern void *func_02188C80(void *p);
extern void *func_020120F4(void *p);
extern void *func_02012EC4(void *p);
extern void *func_0200B3A4(void *p, int n);
extern int  *func_021897BC(void *a, int b);
extern void *func_02188D2C(void *a);
extern void  func_021BE700(void *p, int i, int j, int k, int flag);
extern void *func_020122C0(void *p, int a, void (*cb)(void), int n);
extern void  func_021F3D78(void);

void func_021F3A28(void *a0, int a1)
{
    void *r6;
    int *r4;
    void *x;
    int d;

    r6 = func_0201210C();
    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(r6))), 7);
    r4 = func_021897BC(r6, 1);
    r4[5] = a1;
    if (a1) {
        r4[1] = 0x320000;
        r4[2] = 0x370000;
    } else {
        r4[1] = 0x370000;
        r4[2] = 0x320000;
        x = func_02188D2C(r6);
        func_021BE700(x, 0, 7, 1, 1);
        func_021BE700(x, 0, 7, 0, 0);
    }
    d = r4[2] - r4[1];
    if (d < 0) {
        d = -0x2000;
    } else {
        d = 0x2000;
    }
    r4[3] = d;
    func_020122C0(a0, 0, func_021F3D78, 0);
}
