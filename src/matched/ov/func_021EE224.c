/*
 * function: func_021EE224
 * address:  0x021EE224
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02025774  0x02025774  thumb  ov170
 *
 * Forward the i-th entry word plus the third argument.
 */

extern void func_02025774(int, int);

void func_021EE224(char *p, int i, int v)
{
    func_02025774(*(int *)(p + i * 8 + 4), v);
}

