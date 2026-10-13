/*
 * function: IRCBATTLEMATCH_StepWaitCancelChoice
 * address: 0x021BAE5C
 * packet: pkt_ov100_021BAE5C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   func_02041B6C 0x02041B6C arm
 *   IRCBATTLEMATCH_FreeMessageWindows 0x021BA5F4 thumb ov100
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepOpenWirelessWaitMenu 0x021BADFC thumb ov100
 *   IRCBATTLEMATCH_StepRestoreWaitMenu 0x021BAE14 thumb ov100
 */
#include "../include/Obj07965.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void func_02041B6C(u32 bit);
extern void IRCBATTLEMATCH_FreeMessageWindows(unsigned a);
extern void IRCBATTLEMATCH_SetStep(u8 *p, u32 v);
extern void IRCBATTLEMATCH_StepOpenWirelessWaitMenu(int p);
extern void IRCBATTLEMATCH_StepRestoreWaitMenu(int a);
void IRCBATTLEMATCH_StepWaitCancelChoice(int a) {
 if(APP_TASKMENU_IsFinish((struct TaskMenu *)(*(int *)&((struct Obj07965 *)a)->fCC0))!=0) {
  int v=APP_TASKMENU_GetCursorPos(*(const u8 * *)&((struct Obj07965 *)a)->fCC0);
  APP_TASKMENU_CloseMenu((struct TaskMenu *)(*(int *)&((struct Obj07965 *)a)->fCC0));
  *(int *)&((struct Obj07965 *)a)->fCC0=0;
  if(v==0) {
   IRCBATTLEMATCH_FreeMessageWindows(a); func_02041B6C(6); IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StepOpenWirelessWaitMenu); return;
  } else { IRCBATTLEMATCH_FreeMessageWindows(a); IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StepRestoreWaitMenu); }
 }
}
