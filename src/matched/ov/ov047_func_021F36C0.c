/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov047_021F36C0
 * region:   ov047
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 */

extern int func_02188C80(int a);
extern int func_02188C84(int a);
extern int func_02188CB4(int a);
extern int func_02189764(int a, int b, int c, int d);
extern int *func_021897BC(int a, int b);
extern int func_021A3074(int a);
extern unsigned int func_020120F4(unsigned int);
extern unsigned int func_02012EC4(unsigned int);
extern void *func_0200B3A4(unsigned int, unsigned int);

void func_021F36C0(int a)
{
    int *p;

    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(a))), 0x1f);
    func_02189764(a, 1, func_02188C84(a), 0x14);
    p = func_021897BC(a, 1);
    p[0] = func_02188CB4(a);
    p[1] = func_021A3074(p[0]);
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
}
