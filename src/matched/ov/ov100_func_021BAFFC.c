/*
 * function: IRCBATTLEMATCH_StepWaitErrorChoice
 * address: 0x021BAFFC
 * packet: pkt_ov100_021BAFFC
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
 *   IRCBATTLEMATCH_AbortSession 0x021B95C0 thumb ov100
 *   IRCBATTLEMATCH_SetPaletteFade 0x021B967C thumb ov100
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StartExitWipe 0x021B96B8 thumb ov100
 *   IRCBATTLEMATCH_StepShowErrorMessage 0x021BAFCC thumb ov100
 */
#include "../include/Obj07966.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void func_02041B6C(u32 bit);
extern void IRCBATTLEMATCH_FreeMessageWindows(unsigned a);
extern int IRCBATTLEMATCH_AbortSession(u8 *p);
extern void IRCBATTLEMATCH_SetPaletteFade(int,int);
extern void IRCBATTLEMATCH_SetStep(u8 *p, u32 v);
extern void IRCBATTLEMATCH_StartExitWipe(u8 *a);
extern void IRCBATTLEMATCH_StepShowErrorMessage(int p);
void IRCBATTLEMATCH_StepWaitErrorChoice(int a) {
 if(APP_TASKMENU_IsFinish((struct TaskMenu *)(*(int *)&((struct Obj07966 *)a)->fCC0))!=0) {
  int v=APP_TASKMENU_GetCursorPos(*(const u8 * *)&((struct Obj07966 *)a)->fCC0);
  APP_TASKMENU_CloseMenu((struct TaskMenu *)(*(int *)&((struct Obj07966 *)a)->fCC0));
  *(int *)&((struct Obj07966 *)a)->fCC0=0;
  func_02041B6C(6);
  if(v==0) {
   IRCBATTLEMATCH_FreeMessageWindows(a); IRCBATTLEMATCH_AbortSession((u8 *)a); IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StartExitWipe);
  } else IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StepShowErrorMessage);
  IRCBATTLEMATCH_SetPaletteFade(a,0);
 }
}
