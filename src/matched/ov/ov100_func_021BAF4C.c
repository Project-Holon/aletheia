/*
 * function: IRCBATTLEMATCH_StepOpenCancelConfirm
 * address: 0x021BAF4C
 * packet: pkt_ov100_021BAF4C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gIrcBattleMatchMsgCancelConfirmAlt 0x021BB688 data a4
 *   func_02049B40 0x02049B40 arm
 *   IRCBATTLEMATCH_PrintMainMessage 0x021BA3A4 thumb ov100
 *   IRCBATTLEMATCH_OpenQuitMenu 0x021BA1D0 thumb ov100
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepWaitCancelChoice 0x021BAE5C thumb ov100
 */
#include "../include/Obj00060.h"
struct Word { int x; };
extern const struct Word gIrcBattleMatchMsgCancelConfirmAlt;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void IRCBATTLEMATCH_PrintMainMessage(struct Word *,int);
extern void IRCBATTLEMATCH_OpenQuitMenu(int),GF_FONT_SetDefaultTextColor(void);
typedef unsigned char  u8;
extern void IRCBATTLEMATCH_SetStep(u8 *p, u32 v);
extern void IRCBATTLEMATCH_StepWaitCancelChoice(int a);
void IRCBATTLEMATCH_StepOpenCancelConfirm(int a) {
 struct Word x=gIrcBattleMatchMsgCancelConfirmAlt;
 int v=((struct Obj00060 *)a)->fCB0;
 func_02049B40(23,5,4,0x180,32,((struct Obj00060 *)a)->f278);
 IRCBATTLEMATCH_PrintMainMessage(&x,a);
 ((struct Obj00060 *)a)->fCB0=v;
 IRCBATTLEMATCH_OpenQuitMenu(a);
 GF_FONT_SetDefaultTextColor();
 IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StepWaitCancelChoice);
}
