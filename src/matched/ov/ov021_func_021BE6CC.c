/*
 * function: func_021BE6CC
 * address:  0x021BE6CC
 * packet:   pkt_ov021_021BE6CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE4C4  0x021BE4C4  thumb  ov021
 */

extern void *func_021BE4C4(int a, int b, int c);
extern void func_0204784C(void *a, int b, int *c);

void func_021BE6CC(int a, int b, int c, int d, int e)
{
    int t = e;

    func_0204784C(func_021BE4C4(a, b, c), d, &t);
}
