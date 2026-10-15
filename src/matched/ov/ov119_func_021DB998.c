/*
 * function: POKETRADE_PROC_StepWaitBrowseRelease
 * address: 0x021DB998
 * packet: pkt_ov119_021DB998
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepBrowseGrid 0x021DBE70 thumb ov119
 */
extern int TOUCHPANEL_GetCont(void);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void POKETRADE_PROC_StepBrowseGrid(char *p);
void POKETRADE_PROC_StepWaitBrowseRelease(char *p)
{
    if (TOUCHPANEL_GetCont() == 0)
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepBrowseGrid);
}
