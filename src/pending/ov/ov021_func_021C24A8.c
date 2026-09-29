/*
 * function: func_021C24A8
 * address:  0x021C24A8
 * packet:   pkt_ov021_021C24A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  ABS32 func_021C24BC (pool word 0x021C24BD) has no witness: the
 *           callee is an unlabelled leaf (see ov021_func_021C24BC DIFF note),
 *           so sole-ref/code refuses it. Verdict MATCH*; 72-byte extent
 *           includes that leaf.
 * symbols:
 *   func_020515CC  0x020515CC  arm
 *   func_021C24BC  0x021C24BC  thumb  ov021
 */

void func_021C24BC(char *p);
void func_020515CC(int a, int b, void *c, int d);

void func_021C24A8(char *p, int k)
{
    func_020515CC(*(int *)(p + 0x58), k, func_021C24BC, 0);
}
