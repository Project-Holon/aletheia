/*
 * function: IRCBATTLEMATCH_StepOpenQuitConfirm
 * address: 0x021B9EA4
 * packet: pkt_ov100_021B9EA4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gIrcBattleMatchMsgQuitConfirm 0x021BB65C data a4
 *   func_02049B40 0x02049B40 arm
 *   IRCBATTLEMATCH_PrintMainMessage 0x021BA3A4 thumb ov100
 *   IRCBATTLEMATCH_OpenQuitMenu 0x021BA1D0 thumb ov100
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepWaitQuitChoice 0x021B9E48 thumb ov100
 */
#include "../include/Obj00060.h"
struct Word { int x; };
extern const struct Word gIrcBattleMatchMsgQuitConfirm;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void IRCBATTLEMATCH_PrintMainMessage(struct Word *,int);
extern void IRCBATTLEMATCH_OpenQuitMenu(int);
extern void GF_FONT_SetDefaultTextColor(void);
typedef unsigned char  u8;
extern void IRCBATTLEMATCH_SetStep(u8 *p, u32 v);
extern void IRCBATTLEMATCH_StepWaitQuitChoice(int a);
void IRCBATTLEMATCH_StepOpenQuitConfirm(int a) {
 struct Word x=gIrcBattleMatchMsgQuitConfirm;
 int v=((struct Obj00060 *)a)->fCB0;
 func_02049B40(23,5,4,0x180,32,((struct Obj00060 *)a)->f278);
 IRCBATTLEMATCH_PrintMainMessage(&x,a);
 ((struct Obj00060 *)a)->fCB0=v;
 IRCBATTLEMATCH_OpenQuitMenu(a);
 GF_FONT_SetDefaultTextColor();
 IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StepWaitQuitChoice);
}
