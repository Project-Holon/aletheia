/*
 * function: POKETRADE_NEGO_StepDeclineMenuChoice
 * address: 0x021DE988
 * packet: pkt_ov119_021DE988
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
 *   POKETRADE_PROC_ResetTouchbarBackButton 0x021D8980 thumb ov119
 *   POKETRADE_PROC_UpdatePickedIcon 0x021DD09C thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepBeginDeclineConfirm 0x021DE950 thumb ov119
 *   POKETRADE_NEGO_StepBrowseOffersMain 0x021DEA24 thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void POKETRADE_SAVE_CloseTaskMenu(char *p);
extern void POKETRADE_SAVE_CloseMessageWindowClear(char *p);
extern int POKETRADE_PROC_ResetTouchbarBackButton(char *p);
extern void POKETRADE_PROC_UpdatePickedIcon(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepBeginDeclineConfirm(char *p);
extern void POKETRADE_NEGO_StepBrowseOffersMain(char *p);
void POKETRADE_NEGO_StepDeclineMenuChoice(char *p)
{
    int v;
    if(APP_TASKMENU_IsFinish((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C))) {
        v=APP_TASKMENU_GetCursorPos((const u8 *)(*(int *)&((struct Obj00001 *)p)->f64C));
        POKETRADE_SAVE_CloseTaskMenu(p);
        POKETRADE_SAVE_CloseMessageWindowClear(p);
        *(int *)&((struct Obj00001 *)p)->f64C=0;
        if(v==0) {
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepBeginDeclineConfirm);
            return;
        }
        POKETRADE_SAVE_CloseMessageWindowClear(p);
        POKETRADE_PROC_ResetTouchbarBackButton(p);
        POKETRADE_PROC_UpdatePickedIcon(p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepBrowseOffersMain);
    }
}
