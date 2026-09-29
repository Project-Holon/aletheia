/*
 * function: func_021791EC
 * address:  0x021791EC
 * packet:   pkt_ov014_021791EC
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: sets state 1 by tail-calling func_02178138.  Used as the
 * callback of func_021791F8's call to func_02090DEC.
 *
 * symbols:
 *   func_02178138  0x02178138  thumb  ov014
 */

extern void func_02178138(int state);

void func_021791EC(void)
{
    func_02178138(1);
}
