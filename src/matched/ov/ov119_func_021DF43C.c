/*
 * function: POKETRADE_NEGO_StepFinalAgreeMenuChoice
 * address: 0x021DF43C
 * packet: pkt_ov119_021DF43C
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
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepBeginFinalReady 0x021DF404 thumb ov119
 *   POKETRADE_NEGO_StepWaitMessageThenContinue 0x021DF3E4 thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void POKETRADE_SAVE_CloseTaskMenu(char *p);
extern void POKETRADE_SAVE_CloseMessageWindowClear(char *p);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void POKETRADE_NEGO_StepBeginFinalReady(char *p);
extern void POKETRADE_NEGO_StepWaitMessageThenContinue(void *);
void POKETRADE_NEGO_StepFinalAgreeMenuChoice(void *p)
{
    int v;
    if (!APP_TASKMENU_IsFinish((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C))) return;
    v=APP_TASKMENU_GetCursorPos((const u8 *)(*(int *)&((struct Obj00001 *)p)->f64C));
    POKETRADE_SAVE_CloseTaskMenu(p);
    POKETRADE_SAVE_CloseMessageWindowClear(p);
    *(int *)&((struct Obj00001 *)p)->f64C=0;
    if (v==0) {POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepBeginFinalReady);return;}
    POKETRADE_SAVE_CloseMessageWindowClear(p);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepWaitMessageThenContinue);
}
