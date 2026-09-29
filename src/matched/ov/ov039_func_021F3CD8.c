/*
 * function: func_021F3CD8
 * address:  0x021F3CD8
 * packet:   pkt_ov039_021F3CD8
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897BC 0x021897BC thumb
 *   func_02188C80 0x02188C80 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012A30 0x02012A30 thumb
 *   func_02028B50 0x02028B50 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_021897A0 0x021897A0 thumb
 *   func_021BE418 0x021BE418 thumb ov021
 */

extern int func_02188D2C(int);
extern int *func_021897BC(int, int);
extern int func_02188C80(int);
extern int func_020120F4(int);
extern int func_02012A30(int);
extern void func_02028B50(int, int);
extern void func_02030EAC(int);
extern void func_021897A0(int, int);
extern void func_021BE418(int, int);

void func_021F3CD8(int a)
{
    int r6 = func_02188D2C(a);
    int *r4 = func_021897BC(a, 1);

    func_02028B50(func_02012A30(func_020120F4(func_02188C80(a))), 0x68A);
    func_02030EAC(*r4);
    func_021897A0(a, 1);
    func_021BE418(r6, 0);
}
