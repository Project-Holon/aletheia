/*
 * function: func_021C7CF4
 * address:  0x021C7CF4
 * packet:   pkt_021C7CF4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *
 * Forwarding tail call: only the first argument is passed; the callee's
 * remaining argument register is a leftover (see
 * docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 */

void func_021B9934(int);

void func_021C7CF4(int *p)
{
    func_021B9934(p[2]);
}
