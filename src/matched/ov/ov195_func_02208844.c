/*
 * function: SHINKA_DEMO_EFFECT_AdvanceState
 * address:  0x02208844
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Flag bump on the ov195 scene object (+8 == 1 -> 2); unlabelled leaf.
 */
void SHINKA_DEMO_EFFECT_AdvanceState(int *p)
{
    if (p[2] == 1)
        p[2] = 2;
}
