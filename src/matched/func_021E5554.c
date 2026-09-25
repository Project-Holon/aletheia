/*
 * function: func_021E5554
 * address:  0x021E5554
 * packet:   pkt_021E5554
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E5604  0x021E5604  thumb  ov177
 *   func_021E5670  0x021E5670  thumb  ov177
 */

extern void func_021E5604(int *);
extern void func_021E5670(int *);

void func_021E5554(int a, int *p)
{
    func_021E5604(p);
    func_021E5670((int *)((char *)p + 4));
}
