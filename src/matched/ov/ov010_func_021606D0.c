/*
 * function: func_021606D0
 * address:  0x021606D0
 * packet:   pkt_ov010_021606D0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled thunk: tail-calls func_0216060C with its second argument.
 *
 * symbols:
 *   func_0216060C  0x0216060C  thumb  ov010
 */

extern void func_0216060C();

void func_021606D0(int a, int b)
{
    func_0216060C(b);
}
