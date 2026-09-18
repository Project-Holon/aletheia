/*
 * function: func_0202B42C
 * address:  0x0202B42C
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A bare tail-call thunk to func_0202B490.  The callee is an unlabelled leaf,
 * so its ISA has to be declared here; with `symbols:` absent the name
 * convention defaults it to ARM and the `matched` class refuses the EXACT
 * entry at 0x0202B490 on the ISA mismatch.
 *
 * symbols:
 *   func_0202B490  0x0202B490  thumb
 */

extern void func_0202B490(void);

void func_0202B42C(void)
{
    func_0202B490();
}
