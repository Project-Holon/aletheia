/*
 * function: POKETRADE_PROC_ShowPeerSummary
 * address: 0x021DA158
 * packet: pkt_ov119_021DA158
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_LoadSlotMon 0x021D8D4C thumb ov119
 *   POKETRADE_SAVE_CloseSummaryWindow 0x021E2484 thumb ov119
 *   POKETRADE_SAVE_DrawSummaryPage 0x021E1E00 thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   POKETRADE_PROC_RequestBoxRedraw 0x021D8B38 thumb ov119
 *   func_020307B0 0x020307B0 arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepPeerSummaryMenu 0x021DA318 thumb ov119
 */
#include "../include/Obj08052.h"

extern void *POKETRADE_PROC_LoadSlotMon(void **a, int b, int c, char *p);
typedef unsigned char  u8;
extern void POKETRADE_SAVE_CloseSummaryWindow(char *p, int a);
extern void POKETRADE_SAVE_DrawSummaryPage(char *p, int mode, void *mon);
extern u8 func_020355C4(void);
extern void POKETRADE_PROC_RequestBoxRedraw(char *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepPeerSummaryMenu(char *p);
void POKETRADE_PROC_ShowPeerSummary(char *p) {
    int v=(int)POKETRADE_PROC_LoadSlotMon(*(void ** *)&((struct Obj08052 *)p)->f828,((struct Obj08052 *)p)->fF98,((struct Obj08052 *)p)->fF94,p);
    POKETRADE_SAVE_CloseSummaryWindow(p,0);
    POKETRADE_SAVE_DrawSummaryPage(p,((struct Obj08052 *)p)->f10A0,(void *)v);
    if (func_020355C4()) POKETRADE_PROC_RequestBoxRedraw(p);
    func_020307B0((void *)v);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepPeerSummaryMenu);
}
