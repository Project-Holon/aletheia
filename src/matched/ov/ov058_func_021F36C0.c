/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov058_021F36C0
 * region:   ov058
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021F38F4  0x021F38F4  thumb  ov058
 *   d_021F3B60  0x021F3B60  data  ov058  a4
 */

typedef unsigned short u16;

extern int func_02188C84(int a);
extern int func_02188D2C(int a);
extern int func_02188C80(int a);
extern int func_020120F4(int a);
extern int func_02012EC4(int a);
extern void func_02189764(int a, int b, int c, int d);
extern void *func_021897BC(int a, int b);
extern void func_021BE760(int a, void *b, int c);
extern void func_021F38F4(void *a, int b);
extern char d_021F3B60[];

void func_021F36C0(int a)
{
    int r4;
    void *r6;

    func_02188C84(a);
    r4 = func_02188D2C(a);
    func_02012EC4(func_020120F4(func_02188C80(a)));
    func_02189764(a, 1, func_02188C84(a), 0x20);
    r6 = func_021897BC(a, 1);
    func_021BE760(r4, d_021F3B60, 0);
    func_021F38F4(r6, a);
}
