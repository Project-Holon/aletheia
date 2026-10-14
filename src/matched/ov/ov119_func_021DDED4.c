/*
 * function: POKETRADE_NEGO_StepConfirmMenuChoice
 * address: 0x021DDED4
 * packet: pkt_ov119_021DDED4
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
 *   POKETRADE_NEGO_StepShowWaitMessageA 0x021DDE4C thumb ov119
 *   POKETRADE_NEGO_StepShowWaitMessageB 0x021DDE90 thumb ov119
 */
#include "../include/Obj00001.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void POKETRADE_SAVE_CloseTaskMenu(char *p);
extern void POKETRADE_SAVE_CloseMessageWindowClear(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepShowWaitMessageA(unsigned char *p);
extern void POKETRADE_NEGO_StepShowWaitMessageB(unsigned char *p);

void POKETRADE_NEGO_StepConfirmMenuChoice(unsigned char *p)
{
    int v; if(APP_TASKMENU_IsFinish((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C))==0)return;v=APP_TASKMENU_GetCursorPos((const u8 *)(*(int *)&((struct Obj00001 *)p)->f64C));POKETRADE_SAVE_CloseTaskMenu((char *)p);POKETRADE_SAVE_CloseMessageWindowClear((char *)p);*(int *)&((struct Obj00001 *)p)->f64C=0;switch(v){case 0:POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepShowWaitMessageA);return;case 1:POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepShowWaitMessageB);return;}
}
