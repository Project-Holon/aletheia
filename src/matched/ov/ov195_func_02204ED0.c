/*
 * function: func_02204ED0
 * address:  0x02204ED0
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf of the func_022040E0 dependency tree: when the scene object sits in
 * state word +0x30 == 0, play cue 0x3f2 and move it to state 2.
 *
 * symbols:
 *   func_02005D90  0x02005D90  thumb
 */
extern void func_02005D90(int, int);

void func_02204ED0(int a, int *p)
{
    if (p[0xc] == 0) {
        func_02005D90(0x3f2, 0xffff);
        p[0xc] = 2;
    }
}
