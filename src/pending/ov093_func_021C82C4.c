/*
 * function: func_021C82C4
 * address:  0x021C82C4
 * packet:   pkt_021C82C4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_06898CF4  0x06898CF4  thumb  ov095
 *
 * blocker: target 0x06898CF4 is unlabelled in ov095 with no outside branch,
 * so the pool relocation has no witness.  All bytes correct.
 */

void func_06898CF4(int, int);

void func_021C82C4(int a, int b, int c)
{
    (void)a;
    func_06898CF4(b, c);
}
