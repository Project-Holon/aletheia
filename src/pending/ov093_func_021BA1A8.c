/*
 * function: func_021BA1A8
 * address:  0x021BA1A8
 * packet:   pkt_021BA1A8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_02013158  0x02013158  thumb
 *
 * blocker: target 0x02013158 has no `func_`/`sub_` label and no outside
 * branch, so the pool relocation cannot be witnessed.  All bytes correct.
 */

void func_02013158(int *);

void func_021BA1A8(int **p)
{
    func_02013158(*p);
}
