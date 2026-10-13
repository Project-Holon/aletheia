/*
 * function: IRCBATTLEMATCH_StepOpenErrorConfirm
 * address: 0x021BB058
 * packet: pkt_ov100_021BB058
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gIrcBattleMatchMsgErrorConfirm 0x021BB668 data a4
 *   func_02049B40 0x02049B40 arm
 *   IRCBATTLEMATCH_PrintMainMessage 0x021BA3A4 thumb ov100
 *   IRCBATTLEMATCH_OpenQuitMenu 0x021BA1D0 thumb ov100
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepWaitErrorChoice 0x021BAFFC thumb ov100
 */
#include "../include/Obj00060.h"
struct Word { int x; };
extern const struct Word gIrcBattleMatchMsgErrorConfirm;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void IRCBATTLEMATCH_PrintMainMessage(struct Word *,int);
typedef unsigned char  u8;
extern void IRCBATTLEMATCH_OpenQuitMenu(int);
extern void GF_FONT_SetDefaultTextColor(void);
extern void BUTTON_MAN_Delete(void *p);
extern void IRCBATTLEMATCH_SetStep(u8 *p, u32 v);
extern void IRCBATTLEMATCH_StepWaitErrorChoice(int a);
void IRCBATTLEMATCH_StepOpenErrorConfirm(int a) {
 struct Word x=gIrcBattleMatchMsgErrorConfirm;
 int v=((struct Obj00060 *)a)->fCB0;
 func_02049B40(23,5,4,0x180,32,((struct Obj00060 *)a)->f278);
 IRCBATTLEMATCH_PrintMainMessage(&x,a);
 ((struct Obj00060 *)a)->fCB0=v;
 IRCBATTLEMATCH_OpenQuitMenu(a);
 GF_FONT_SetDefaultTextColor();
 if(((struct Obj00060 *)a)->fCA4!=0) BUTTON_MAN_Delete((void *)(((struct Obj00060 *)a)->fCA4));
 ((struct Obj00060 *)a)->fCA4=0;
 IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StepWaitErrorChoice);
}
