/*
 * function: func_021EA5F0
 * address:  0x021EA5F0
 * packet:   pkt_ov093_021EA5F0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EA55C  0x021EA55C  thumb  ov093
 */
struct H;

extern void func_021EA55C(struct H *p, int a);

void func_021EA5F0(char *p, struct H *h)
{
    func_021EA55C(h, *(int *)(p + 0xac));
}
