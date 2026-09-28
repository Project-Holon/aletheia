/*
 * function: func_02204FA0
 * address:  0x02204FA0
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf of the func_022040E0 dependency tree: when the scene object sits in
 * state word +0x30 == 5, clear word +0x34, arm a 1-flag timer on it and move
 * to state 7.
 *
 * symbols:
 *   func_020063B4  0x020063B4  thumb
 */
extern int func_020063B4(unsigned char *, int *, int);

void func_02204FA0(int a, int *p)
{
    if (p[0xc] == 5) {
        p[0xd] = 0;
        func_020063B4((unsigned char *)0x519, &p[0xd], 1);
        p[0xc] = 7;
    }
}
