/*
 * function: func_0217DFD0
 * address:  0x0217DFD0
 * packet:   pkt_0217DFD0
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E8738  0x021E8738  thumb  ov177
 */

extern void func_021E8738(int *p, int a, int b, int c);

void func_0217DFD0(int *p, int a, int b)
{
    func_021E8738((int *)(*(int *)((char *)p + 0x18)), *(int *)p, a, b);
}
