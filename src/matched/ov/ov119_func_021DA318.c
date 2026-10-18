/*
 * function: POKETRADE_PROC_StepPeerSummaryMenu
 * address: 0x021DA318
 * packet: pkt_ov119_021DA318
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: keep=1 precedes choice=keep-2; a literal -1 initialized before
 * keep gave 14 entry-initialization bytes wrong with all later bytes equal.
 * initialization: 02035D20 writes both coordinates before return 1;
 * 021D9EBC's successful hit writes slot/column through 021E51A4.
 * return evidence: 02035C38/60 leave 020357A0/C0's u32 result in r0,
 * consumed here despite the legacy void forwarder declarations.
 * symbols:
 *   APP_TASKMENU_IsDecide 0x02027A20 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   UI_SetInputMode 0x020355D8 arm
 *   POKETRADE_PROC_ShowDragIcon 0x021D8C84 thumb ov119
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfPressing 0x021B6470 thumb ov067
 *   func_020355C4 0x020355C4 arm
 *   APP_TASKMENU_SetCursorActive 0x02027A08 thumb
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   POKETRADE_PROC_PollGridTouch 0x021D9EBC thumb ov119
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   POKETRADE_SAVE_CloseSummaryWindow 0x021E2484 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_ShowPeerSummary 0x021DA158 thumb ov119
 *   POKETRADE_PROC_UpdateDragIcon 0x021D8C0C thumb ov119
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   POKETRADE_PROC_UpdateDragState 0x021D8B54 thumb ov119
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   POKETRADE_PROC_LoadSlotMonAlt 0x021D8DD0 thumb ov119
 *   POKETRADE_PROC_IsTradeTargetValid 0x021DBD70 thumb ov119
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   POKETRADE_PROC_IsSelectedOfferSlot 0x021D9548 thumb ov119
 *   POKETRADE_NEGO_SetOfferMarkersState 0x021DF7AC thumb ov119
 *   POKETRADE_PROC_ShowCancelMessage 0x021DA0CC thumb ov119
 *   POKETRADE_PROC_CanTradeMon 0x021DD0CC thumb ov119
 *   POKETRADE_PROC_ShowSelectMessage 0x021DA110 thumb ov119
 *   POKETRADE_PROC_HideTouchbarButtons 0x021D9E54 thumb ov119
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   POKETRADE_NEGO_CanConfirmOffers 0x021DD2A8 thumb ov119
 *   POKETRADE_PROC_StepSendApplyAddOffer 0x021DA27C thumb ov119
 *   POKETRADE_PROC_StepSendAddOffer 0x021DA1DC thumb ov119
 *   POKETRADE_PROC_StepWaitTouchReleasePeer 0x021DA2F4 thumb ov119
 *   POKETRADE_PROC_UpdateTouchbarButtons 0x021DBB6C thumb ov119
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   POKETRADE_2D_DeleteMarkingIcon 0x021E5EF8 thumb ov119
 *   POKETRADE_2D_ClearSummaryBackground 0x021E4174 thumb ov119
 *   POKETRADE_SAVE_CloseTaskMenu 0x021E12F8 thumb ov119
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj04475.h"
typedef unsigned int u32;
typedef unsigned char u8;
struct TaskMenu;
struct S;
struct Obj;
extern unsigned APP_TASKMENU_IsDecide(char *p);
extern int TOUCHPANEL_GetTrg(void);
extern int TOUCHPANEL_GetCont(void);
extern u8 func_020355C4(void);
extern void UI_SetInputMode(u8),POKETRADE_PROC_ShowDragIcon(void *),TOUCHBAR_Update(struct S *);
extern int TOUCHBAR_GetPressedButtonIdIfPressing(u8 *),TOUCHBAR_GetPressedButtonIdIfDone(u8 *);
extern u32 APP_TASKMENU_SetCursorActive(struct TaskMenu *,u32),TOUCHPANEL_GetPointTrg(u32 *,u32 *),APP_TASKMENU_IsFinish(struct TaskMenu *);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *);
extern int POKETRADE_PROC_PollGridTouch(char *,int *,int *,int *,int *);
extern void GFL_USE_PlaySeDefaultVolume(u32),POKETRADE_SAVE_CloseSummaryWindow(char *,int),POKETRADE_PROC_SetStep(void *,int),POKETRADE_PROC_UpdateDragIcon(void *),POKETRADE_PROC_UpdateDragState(void *);
extern void *POKETRADE_PROC_LoadSlotMonAlt(void *a, int b, int c, char *p);
extern int POKETRADE_PROC_IsTradeTargetValid(char *,int,int);
extern int POKETRADE_PROC_IsHostSide(void *);
extern int POKETRADE_PROC_IsSelectedOfferSlot(char *,int,int);
extern int POKETRADE_PROC_CanTradeMon(char *,int);
extern int POKETRADE_NEGO_CanConfirmOffers(char *);
extern void POKETRADE_NEGO_SetOfferMarkersState(void *,int);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern void POKETRADE_PROC_UpdateTouchbarButtons(char *);
extern void CLACT_SetActorDrawEnable(struct Obj *,u32);
extern void POKETRADE_2D_DeleteMarkingIcon(void *);
extern void POKETRADE_2D_ClearSummaryBackground(char *p);
extern void POKETRADE_SAVE_CloseTaskMenu(char *p);
extern void func_02041B6C(u32);
extern void POKETRADE_PROC_ShowPeerSummary(char *p);
extern void POKETRADE_PROC_ShowCancelMessage(char *p);
extern void POKETRADE_PROC_ShowSelectMessage(char *p);
extern void POKETRADE_PROC_HideTouchbarButtons(char *p);
extern void POKETRADE_PROC_StepSendApplyAddOffer(char *p);
extern void POKETRADE_PROC_StepSendAddOffer(char *p);
extern void POKETRADE_PROC_StepWaitTouchReleasePeer(void *);
#define I(o) (*(int *)(p+(o)))
#define P(o) (*(void **)(p+(o)))
void POKETRADE_PROC_StepPeerSummaryMenu(char *p)
{
    u32 x,y;
    int slot,column;
    int changed=0;
    int keep=1;
    int choice=keep-2;
    int active=0;
    int n;
    if(!APP_TASKMENU_IsDecide(P(0x64c))) {
        n=TOUCHPANEL_GetTrg();
        if(n) UI_SetInputMode(keep);
        if(n) POKETRADE_PROC_ShowDragIcon(p);
        TOUCHBAR_Update(P(0x9c0));
        if(TOUCHBAR_GetPressedButtonIdIfPressing(P(0x9c0))==9 && func_020355C4()) APP_TASKMENU_SetCursorActive(P(0x64c),0);
        if(TOUCHBAR_GetPressedButtonIdIfDone(P(0x9c0))==9) {
            changed=1;
            ((struct Obj04475 *)p)->f10A0=1U-((struct Obj04475 *)p)->f10A0;
        }
        if(TOUCHPANEL_GetPointTrg(&x,&y)==1) {
            UI_SetInputMode(1);
            APP_TASKMENU_SetCursorActive(P(0x64c),0);
            if(POKETRADE_PROC_PollGridTouch(p,(int *)(p+0xf98),(int *)(p+0xf94),&slot,&column)) {
                I(0xf78)=column;
                I(0xf74)=slot;
                ((struct Obj04475 *)p)->fF54=x;
                ((struct Obj04475 *)p)->fF58=y;
                GFL_USE_PlaySeDefaultVolume(0x548);
                changed=1;
            } else if(y>=16 && y<144) active=1;
        }
        if(changed) {
            POKETRADE_SAVE_CloseSummaryWindow(p,1);
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_ShowPeerSummary);
            return;
        }
        POKETRADE_PROC_UpdateDragIcon(p);
        if(!active && !TOUCHPANEL_GetCont() && I(0xf34)) {
            if(I(0xf60) && I(0xf5c)) {
                GFL_USE_PlaySeDefaultVolume(0x72a);
                choice=0;
                active=1;
            } else POKETRADE_PROC_ShowDragIcon(p);
        }
        POKETRADE_PROC_UpdateDragState(p);
        POKETRADE_PROC_UpdateDragIcon(p);
    }
    if(APP_TASKMENU_IsFinish(P(0x64c))) {
        choice=APP_TASKMENU_GetCursorPos(P(0x64c));
        active=1;
    }
    if(active) {
        if(choice==0) {
            n=(int)POKETRADE_PROC_LoadSlotMonAlt((void *)I(0x828),I(0xf98),I(0xf94),p);
            if(POKETRADE_PROC_IsTradeTargetValid(p,I(0xf98),I(0xf94)) && POKETRADE_PROC_IsHostSide(p)) {
                I(0xf84)=I(0xf94);
                I(0xf88)=I(0xf98);
                POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendAddOffer);
            } else if(POKETRADE_PROC_IsSelectedOfferSlot(p,I(0xf98),I(0xf94))) {
                POKETRADE_NEGO_SetOfferMarkersState(p,1);
                POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_ShowCancelMessage);
            } else if(POKETRADE_PROC_CanTradeMon(p,n)) {
                POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_ShowSelectMessage);
                POKETRADE_NEGO_SetOfferMarkersState(p,1);
            } else if(!POKETRADE_PROC_IsHostSide(p)) {
                I(0xf84)=I(0xf94);
                I(0xf88)=I(0xf98);
                POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_HideTouchbarButtons);
                TOUCHBAR_SetButtonVisible((unsigned char *)I(0x9c0),7,0);
                TOUCHBAR_SetButtonVisible((unsigned char *)I(0x9c0),8,0);
                TOUCHBAR_SetButtonVisible((unsigned char *)I(0x9c0),9,0);
                keep=0;
            } else if(POKETRADE_NEGO_CanConfirmOffers(p) && !func_020355C4()) {
                I(0xf84)=I(0xf94);
                I(0xf88)=I(0xf98);
                POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendApplyAddOffer);
                TOUCHBAR_SetButtonVisible((unsigned char *)I(0x9c0),7,0);
                TOUCHBAR_SetButtonVisible((unsigned char *)I(0x9c0),8,0);
                TOUCHBAR_SetButtonVisible((unsigned char *)I(0x9c0),9,0);
                keep=0;
            } else {
                I(0xf84)=I(0xf94);
                I(0xf88)=I(0xf98);
                POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendAddOffer);
            }
        } else {
            POKETRADE_NEGO_SetOfferMarkersState(p,1);
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepWaitTouchReleasePeer);
        }
        I(0xf98)=-1;
        I(0xf94)=-1;
        if(keep) {
            POKETRADE_PROC_UpdateTouchbarButtons(p);
            CLACT_SetActorDrawEnable(P(0xf04),1);
        }
        POKETRADE_2D_DeleteMarkingIcon(p+0x950);
        POKETRADE_2D_DeleteMarkingIcon(p+0x964);
        POKETRADE_2D_DeleteMarkingIcon(p+0x978);
        POKETRADE_SAVE_CloseSummaryWindow(p,1);
        func_02041B6C(6);
        POKETRADE_2D_ClearSummaryBackground(p);
        POKETRADE_SAVE_CloseTaskMenu(p);
        P(0x64c)=0;
    }
    I(0xf34)=TOUCHPANEL_GetCont();
}
