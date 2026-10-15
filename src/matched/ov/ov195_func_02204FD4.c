/*
 * function: SHINKA_DEMO_PlayResultBgm
 * address:  0x02204FD4
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf of the SHINKA_DEMO_Main dependency tree: when the scene object sits in
 * state word +0x30 == 4, hand it to SHINKA_DEMO_PushBgm and play cue 0x515, then
 * park it in state 9.  First argument is forwarded untouched.
 *
 * symbols:
 *   SHINKA_DEMO_PushBgm  0x02204F24  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 */
extern void SHINKA_DEMO_PushBgm(int, int *);
extern void GFL_USE_CancelChangeAndPlayBgm(int, int);

void SHINKA_DEMO_PlayResultBgm(int a, int *p)
{
    if (p[0xc] == 4) {
        SHINKA_DEMO_PushBgm(a, p);
        GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
        p[0xc] = 9;
    }
}
