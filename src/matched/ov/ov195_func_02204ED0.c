/*
 * function: SHINKA_DEMO_PlayEvolutionBgm
 * address:  0x02204ED0
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf of the SHINKA_DEMO_Main dependency tree: when the scene object sits in
 * state word +0x30 == 0, play cue 0x3f2 and move it to state 2.
 *
 * symbols:
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 */
extern void GFL_USE_CancelChangeAndPlayBgm(int, int);

void SHINKA_DEMO_PlayEvolutionBgm(int a, int *p)
{
    if (p[0xc] == 0) {
        GFL_USE_CancelChangeAndPlayBgm(0x3f2, 0xffff);
        p[0xc] = 2;
    }
}
