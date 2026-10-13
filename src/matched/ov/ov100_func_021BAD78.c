/*
 * function: IRCBATTLEMATCH_StepWaitErrorDialogClose
 * address: 0x021BAD78
 * packet: pkt_ov100_021BAD78
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   func_02041B6C 0x02041B6C arm
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepOpenErrorConfirm 0x021BB058 thumb ov100
 */
#include "../include/Obj07963.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void func_02041B6C(u32 bit);
extern void IRCBATTLEMATCH_SetStep(u8 *,unsigned);
extern void IRCBATTLEMATCH_StepOpenErrorConfirm(int a);
void IRCBATTLEMATCH_StepWaitErrorDialogClose(unsigned a)
{
 if(APP_TASKMENU_IsFinish((struct TaskMenu *)(*(int *)&((struct Obj07963 *)a)->fCC0))!=0) {
  APP_TASKMENU_GetCursorPos(*(const u8 * *)&((struct Obj07963 *)a)->fCC0);
  APP_TASKMENU_CloseMenu((struct TaskMenu *)(*(int *)&((struct Obj07963 *)a)->fCC0));
  *(unsigned *)&((struct Obj07963 *)a)->fCC0=0;
  func_02041B6C(6);
  IRCBATTLEMATCH_SetStep((u8 *)a,(unsigned)IRCBATTLEMATCH_StepOpenErrorConfirm);
 }
}
