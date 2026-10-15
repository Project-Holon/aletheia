/*
 * function: SHINKA_DEMO_VIEW_IsEvolveReady
 * address:  0x0220606C
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Getter for the +0x34 word of the ov195 scene object (unlabelled leaf).
 */
int SHINKA_DEMO_VIEW_IsEvolveReady(int *p)
{
    return p[13];
}
