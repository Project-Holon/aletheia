/*
 * function: SHINKA_DEMO_VIEW_RequestStart
 * address:  0x02206044
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Setter for the +0x1c flag word of the ov195 scene object driven by
 * SHINKA_DEMO_Main.  Unlabelled in the listing (a leaf that saves no lr, so it
 * prints inside a .word run); region-qualified because ov094 overlaps.
 */
void SHINKA_DEMO_VIEW_RequestStart(int *p)
{
    p[7] = 1;
}
