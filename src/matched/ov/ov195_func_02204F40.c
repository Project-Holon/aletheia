/*
 * function: SHINKA_DEMO_PopBgm
 * address:  0x02204F40
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Leaf of the SHINKA_DEMO_Main dependency tree: when the scene object sits in
 * state 5 or in state 8/9, run the cue trio and drop it into state 4.
 *
 * symbols:
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   GFL_USE_SetBgmPaused  0x02005DE4  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 */
extern int GFL_USE_PopBgm(void);
typedef unsigned int   u32;
extern void GFL_USE_SetBgmPaused(void *p);
extern void GFL_USE_FadeInBgmFull(u32 a);

void SHINKA_DEMO_PopBgm(int a, int *p)
{
    int s = p[0xc];

    if (s == 5 || (unsigned)(s - 8) <= 1) {
        GFL_USE_PopBgm();
        GFL_USE_SetBgmPaused(0);
        GFL_USE_FadeInBgmFull(6);
        p[0xc] = 4;
    }
}
