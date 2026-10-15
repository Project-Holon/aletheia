/*
 * function: POKETRADE_NEGO_StepWaitMessageThenContinue
 * address: 0x021DF3E4
 * packet: pkt_ov119_021DF3E4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepRebuildBrowseScene 0x021DBBD0 thumb ov119
 */
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void POKETRADE_PROC_StepRebuildBrowseScene(char *p);
void POKETRADE_NEGO_StepWaitMessageThenContinue(void *p)
{
    GFL_NET_HANDLE_GetCurrentHandle();
    if (POKETRADE_SAVE_IsMessagePrintDone(p)) {
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepRebuildBrowseScene);
    }
}
