/*
 * function: POKETRADE_PROC_StepSummaryMenuChoice
 * address: 0x021DB030
 * packet: pkt_ov119_021DB030
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the 0x1080 halfword is signed; u16 pools 0xffff, s16 derives -1 from zero.
 * symbols:
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   POKETRADE_SAVE_CloseTaskMenu 0x021E12F8 thumb ov119
 *   POKETRADE_SAVE_CloseMessageWindowClear 0x021E1098 thumb ov119
 *   POKETRADE_2D_UpdateVisibleColumns 0x021E4E64 thumb ov119
 *   POKETRADE_2D_SetupSubBlend 0x021E6700 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepSendStartRound 0x021DAFB8 thumb ov119
 *   POKETRADE_PROC_StepBrowseGrid 0x021DBE70 thumb ov119
 */
#include "../include/Obj00001.h"
typedef short s16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void POKETRADE_SAVE_CloseTaskMenu(char *p);
extern void POKETRADE_SAVE_CloseMessageWindowClear(char *p);
extern void POKETRADE_2D_UpdateVisibleColumns(int a, char *p, int b);
extern void POKETRADE_2D_SetupSubBlend(void *);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepSendStartRound(char *p);
extern void POKETRADE_PROC_StepBrowseGrid(char *p);
void POKETRADE_PROC_StepSummaryMenuChoice(char *p) {
 int v;
 if(APP_TASKMENU_IsFinish((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C))) {
  v=APP_TASKMENU_GetCursorPos((const u8 *)(*(int *)&((struct Obj00001 *)p)->f64C));POKETRADE_SAVE_CloseTaskMenu(p);*(int *)&((struct Obj00001 *)p)->f64C=0;
  switch(v) {
  case 0:POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendStartRound);return;
  case 1:POKETRADE_SAVE_CloseMessageWindowClear(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBrowseGrid);
   ((struct Obj00001 *)p)->f1080=-1;POKETRADE_2D_UpdateVisibleColumns(*(int *)&((struct Obj00001 *)p)->f828,p,0);POKETRADE_2D_SetupSubBlend(p);return;
  }
 }
}
