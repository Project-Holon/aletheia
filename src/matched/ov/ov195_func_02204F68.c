/*
 * function: SHINKA_DEMO_IsBgmState4
 * address:  0x02204F68
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Leaf of the SHINKA_DEMO_Main dependency tree: true when the scene object's
 * state word +0x30 is 4.  Unlabelled in the listing (a leaf that saves no
 * lr), so region-qualified.
 */
int SHINKA_DEMO_IsBgmState4(int a, int *p)
{
    return p[0xc] == 4;
}
