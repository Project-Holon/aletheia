/*
 * function: EGG_DEMO_MAIN_PushBgm
 * address:  0x021F5FDC
 * packet:   pkt_021F5FDC
 * region:   ov215
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_USE_SetBgmPaused 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 */

extern void GFL_USE_SetBgmPaused(void *p);
extern int GFL_USE_PushBgm(void);

void EGG_DEMO_MAIN_PushBgm(void *a0, void *a1)
{
    GFL_USE_SetBgmPaused((void *)1);
    GFL_USE_PushBgm();
}