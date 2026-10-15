/*
 * function: SHINKA_DEMO_VIEW_RequestFadeOut
 * address:  0x02206064
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Setter for the +0x30 flag word of the ov195 scene object (unlabelled leaf).
 */
void SHINKA_DEMO_VIEW_RequestFadeOut(int *p)
{
    p[12] = 1;
}
