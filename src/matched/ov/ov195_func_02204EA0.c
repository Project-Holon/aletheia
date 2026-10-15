/*
 * function: SHINKA_DEMO_IsBgmState1
 * address:  0x02204EA0
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Leaf of the SHINKA_DEMO_Main dependency tree: true when the scene object's
 * state word +0x30 is 1.  Unlabelled in the listing (a leaf that saves no
 * lr), so region-qualified.
 */
int SHINKA_DEMO_IsBgmState1(int a, int *p)
{
    return p[0xc] == 1;
}
