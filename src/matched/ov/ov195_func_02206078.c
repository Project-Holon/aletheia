/*
 * function: SHINKA_DEMO_VIEW_TrySecondForm
 * address:  0x02206078
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Leaf of the SHINKA_DEMO_Main dependency tree: on a positive SHINKA_DEMO_VIEW_IsMenuReady
 * probe it sets the +0x40 word and the +0x14 state word of the scene object
 * and notifies SHINKA_DEMO_VIEW_ShowMenu; returns 1, else 0.
 *
 * symbols:
 *   SHINKA_DEMO_VIEW_IsMenuReady  0x0220673C  thumb
 *   SHINKA_DEMO_VIEW_ShowMenu  0x02206750  thumb
 */
int SHINKA_DEMO_VIEW_TrySecondForm(int *p)
{
    int SHINKA_DEMO_VIEW_IsMenuReady(int *);
    void SHINKA_DEMO_VIEW_ShowMenu(int *);

    if (SHINKA_DEMO_VIEW_IsMenuReady(p) != 0) {
        p[0x10] = 1;
        p[5] = 0xc;
        SHINKA_DEMO_VIEW_ShowMenu(p);
        return 1;
    }
    return 0;
}
