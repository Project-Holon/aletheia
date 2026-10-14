/*
 * function: POKETRADE_NEGO_StepOfferActionChoice
 * address: 0x021DE5C4
 * packet: pkt_ov119_021DE5C4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   POKETRADE_SAVE_CloseTaskMenu 0x021E12F8 thumb ov119
 *   POKETRADE_SAVE_CloseMessageWindowClear 0x021E1098 thumb ov119
 *   WIPE_SYS_Start 0x0202208C thumb
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   POKETRADE_NEGO_SetupWindowRegsOffers 0x021DEBD4 thumb ov119
 *   POKETRADE_PROC_ResetTouchbarBackButton 0x021D8980 thumb ov119
 *   func_021DD09C 0x021DD09C thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepBeginConfirm 0x021DE12C thumb ov119
 *   POKETRADE_NEGO_StepOpenSummaryFromBrowse 0x021DE518 thumb ov119
 *   POKETRADE_NEGO_StepBrowseOffersMain 0x021DEA24 thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void POKETRADE_SAVE_CloseTaskMenu(char *p);
extern void POKETRADE_SAVE_CloseMessageWindowClear(char *p);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern void POKETRADE_NEGO_SetupWindowRegsOffers(void *);
extern int POKETRADE_PROC_ResetTouchbarBackButton(char *p);
extern void func_021DD09C(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepBeginConfirm(char *p);
extern void POKETRADE_NEGO_StepOpenSummaryFromBrowse(void *);
extern void POKETRADE_NEGO_StepBrowseOffersMain(char *p);
void POKETRADE_NEGO_StepOfferActionChoice(char *p)
{
    int v;
    if(APP_TASKMENU_IsFinish((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C))) {
        v=APP_TASKMENU_GetCursorPos((const u8 *)(*(int *)&((struct Obj00001 *)p)->f64C));
        POKETRADE_SAVE_CloseTaskMenu(p); POKETRADE_SAVE_CloseMessageWindowClear(p);
        *(int *)&((struct Obj00001 *)p)->f64C=0;
        switch(v) {
        case 0: POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepBeginConfirm); return;
        case 1:
            WIPE_SYS_Start((void *)3,0,0,0,6,1,((struct Obj00001 *)p)->f5F4);
            TOUCHBAR_SetButtonEnabled((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),1,0);
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepOpenSummaryFromBrowse); return;
        case 2:
            POKETRADE_NEGO_SetupWindowRegsOffers(p); POKETRADE_PROC_ResetTouchbarBackButton(p); func_021DD09C(p);
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepBrowseOffersMain); return;
        }
    }
}
