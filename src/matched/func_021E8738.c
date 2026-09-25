/*
 * function: func_021E8738
 * address:  0x021E8738
 * packet:   pkt_021E8738
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045CAC  0x02045CAC  arm
 *   func_021E8754  0x021E8754  thumb  ov177
 */

extern void func_02045CAC(int, int, int);
extern void func_021E8754(int *, int);

void func_021E8738(int *p, int a, int b, int c)
{
    func_02045CAC(a, b, *(int *)((char *)p + 0x18));
    func_021E8754(p, c);
}
