/*
 * function: func_02208860
 * address:  0x02208860
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Camera-state predicate on the ov195 scene object's +8/+0xc words:
 * state 4 with +0xc <= 1, or state 5.  Unlabelled leaf.
 */
int func_02208860(int *p)
{
    if (p[2] == 4 && (unsigned)p[3] <= 1)
        return 1;
    if (p[2] == 5)
        return 1;
    return 0;
}
