/*
 * function: POKETRADE_PROC_StepPeerSelectAction
 * address: 0x021DBDB4
 * packet: pkt_ov119_021DBDB4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_LoadSlotMonAlt 0x021D8DD0 thumb ov119
 *   POKETRADE_PROC_IsTradeTargetValid 0x021DBD70 thumb ov119
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepClearPeerSelection 0x021DB9B4 thumb ov119
 *   POKETRADE_NEGO_StepSendOfferRemoval 0x021DF708 thumb ov119
 *   POKETRADE_PROC_StepOpenPeerSummary 0x021DA640 thumb ov119
 *   POKE_TOOL_GetBoxValue 0x02017E88 thumb
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   POKETRADE_SAVE_CloseTaskMenu 0x021E12F8 thumb ov119
 *   POKETRADE_PROC_ShowDragIcon 0x021D8C84 thumb ov119
 */
#include "../include/Obj03774.h"
extern void *POKETRADE_PROC_LoadSlotMonAlt(void *a, int b, int c, char *p);extern int POKETRADE_PROC_IsTradeTargetValid(void *,int,int);extern void GFL_USE_PlaySeDefaultVolume(int);extern int POKETRADE_PROC_IsHostSide(void *);extern void POKETRADE_PROC_SetStep(void *,int);extern void POKETRADE_PROC_StepClearPeerSelection(void);extern void POKETRADE_NEGO_StepSendOfferRemoval(void);extern void POKETRADE_PROC_StepOpenPeerSummary(void);extern int POKE_TOOL_GetBoxValue(int,int,int);extern void TOUCHBAR_SetButtonVisible(int,int,int);extern void POKETRADE_SAVE_CloseTaskMenu(void *);extern void POKETRADE_PROC_ShowDragIcon(void *);
int POKETRADE_PROC_StepPeerSelectAction(char *p) {int e=(int)POKETRADE_PROC_LoadSlotMonAlt((void *)(((struct Obj03774 *)p)->f828),((struct Obj03774 *)p)->fF98,((struct Obj03774 *)p)->fF94,p);if(POKETRADE_PROC_IsTradeTargetValid(p,((struct Obj03774 *)p)->fF98,((struct Obj03774 *)p)->fF94)) {GFL_USE_PlaySeDefaultVolume(0x626);if(POKETRADE_PROC_IsHostSide(p)==0){POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepClearPeerSelection);return 1;}POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendOfferRemoval);return 1;}if(e && POKE_TOOL_GetBoxValue(e,0xa9,0)) {GFL_USE_PlaySeDefaultVolume(0x54b);TOUCHBAR_SetButtonVisible(((struct Obj03774 *)p)->f9C0,8,0);POKETRADE_SAVE_CloseTaskMenu(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepOpenPeerSummary);return 1;}POKETRADE_PROC_ShowDragIcon(p);((struct Obj03774 *)p)->fF98=-1;((struct Obj03774 *)p)->fF94=-1;return 0;}
