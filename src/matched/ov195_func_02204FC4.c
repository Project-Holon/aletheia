/*
 * function: func_02204FC4
 * address:  0x02204FC4
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf of the func_022040E0 dependency tree: true when the scene object's
 * state word +0x30 is 7 or 8.
 */
int func_02204FC4(int a, int *p)
{
    return p[0xc] == 7 || p[0xc] == 8;
}
