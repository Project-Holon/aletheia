/*
 * function: func_021B66E0
 * address:  0x021B66E0
 * packet:   pkt_ov101_021B66E0
 * region:   ov101
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   func_021B64F0  0x021B64F0  thumb  ov101
 */

extern void func_02082BCC(int, int, int);
extern int func_02030734(int, int, int, int, int);
extern void func_021B64F0(int, int, int, int, int);

void func_021B66E0(int a, int b, int c)
{
    int r7;

    func_02082BCC(a, 0, 0x34);
    r7 = 0x57b;
    *(int *)a = b;
    *(int *)(a + 0x28) = func_02030734(c, 0x2c, 0, 0x021B7524, r7);
    func_02082BCC(*(int *)(a + 0x28), 0, 0x2c);
    *(int *)(a + 0x2c) = func_02030734(c, 0x2c, 0, 0x021B7524, r7 + 2);
    func_02082BCC(*(int *)(a + 0x2c), 0, 0x2c);
    *(int *)(a + 0x30) = func_02030734(c, 0x2c, 0, 0x021B7524, r7 + 4);
    func_02082BCC(*(int *)(a + 0x30), 0, 0x2c);
    func_021B64F0(b, 0x1000, 0x021B741C, 4, a);
}
