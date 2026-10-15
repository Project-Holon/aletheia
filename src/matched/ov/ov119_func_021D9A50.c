/*
 * function: POKETRADE_PROC_StepMainMenuChoice
 * address: 0x021D9A50
 * packet: pkt_ov119_021D9A50
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
 *   POKETRADE_PROC_ShowIntroMessage 0x021D9750 thumb ov119
 *   POKETRADE_PROC_StepAfterSummaryWipe 0x021D99F4 thumb ov119
 *   POKETRADE_PROC_StepSendNewRound 0x021DADAC thumb ov119
 *   WIPE_SYS_Start 0x0202208C thumb
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
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_ShowIntroMessage(char *p);
extern void POKETRADE_PROC_StepAfterSummaryWipe(char *p);
extern void POKETRADE_PROC_StepSendNewRound(void *);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
void POKETRADE_PROC_StepMainMenuChoice(char *p) { int v; if(APP_TASKMENU_IsFinish((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C))) {v=APP_TASKMENU_GetCursorPos((const u8 *)(*(int *)&((struct Obj00001 *)p)->f64C));POKETRADE_SAVE_CloseTaskMenu(p);POKETRADE_SAVE_CloseMessageWindowClear(p);*(int *)&((struct Obj00001 *)p)->f64C=0;switch(v) {case 0:POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_ShowIntroMessage);return;case 1:WIPE_SYS_Start((void *)3,0,0,0,6,1,((struct Obj00001 *)p)->f5F4);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepAfterSummaryWipe);return;case 2:POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendNewRound);return;} } }
