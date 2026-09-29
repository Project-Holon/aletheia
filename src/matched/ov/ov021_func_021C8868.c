/*
 * function: func_021C8868
 * address:  0x021C8868
 * packet:   pkt_ov021_021C8868
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012ED0  0x02012ED0  thumb
 *   func_02011330  0x02011330  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021C8738  0x021C8738  thumb  ov021
 */

extern void func_0215A5F4(int b);
extern void func_0215A5DC(int b);
extern void func_0201210C();
extern void func_02188C80();
extern void func_020120F4();
extern int *func_02012ED0();
extern int func_02011330(int a);
extern unsigned short *func_02159AE8(int a, int b);
extern int func_021C8738(int a, int k);

int func_021C8868(int a, int b)
{
    int *r4;
    int r7;
    unsigned short *r5;

    func_0215A5F4(b);
    func_0215A5DC(b);
    func_0201210C();
    func_02188C80();
    func_020120F4();
    r4 = func_02012ED0();
    r7 = func_02011330(a);
    r5 = func_02159AE8(a, b);
    *r5 = func_021C8738(*r4, r7);
    return 0;
}
