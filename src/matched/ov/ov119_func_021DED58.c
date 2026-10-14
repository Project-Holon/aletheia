/*
 * function: POKETRADE_NEGO_StepWaitWipeToBrowse
 * address:  0x021DED58
 * packet:   pkt_ov119_021DED58
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_NEGO_StepBuildBrowseScene  0x021DECA0  thumb  ov119
 */

extern unsigned WIPE_SYS_EndCheck(void);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void POKETRADE_NEGO_StepBuildBrowseScene(char *p);

void POKETRADE_NEGO_StepWaitWipeToBrowse(void *p)
{
    if (WIPE_SYS_EndCheck() != 0) {
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepBuildBrowseScene);
    }
}
