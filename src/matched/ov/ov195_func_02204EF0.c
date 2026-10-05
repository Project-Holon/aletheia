/*
 * function: func_02204EF0
 * address:  0x02204EF0
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Leaf of the func_022040E0 dependency tree: true when the scene object's
 * state word +0x30 is 2.  Unlabelled in the listing (a leaf that saves no
 * lr), so region-qualified.
 */
int func_02204EF0(int a, int *p)
{
    return p[0xc] == 2;
}
