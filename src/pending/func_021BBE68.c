/*
 * function: func_021BBE68
 * address:  0x021BBE68
 * packet:   pkt_021BBE68
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_0202822C  0x0202822C  thumb
 *
 * blocker: Target 0x0202822C has no witness outside this range (no label with an outside branch). Byte-correct.
 */

void func_0202822C(int);

void func_021BBE68(int x)
{
    if (x != 0)
        func_0202822C(x);
}
