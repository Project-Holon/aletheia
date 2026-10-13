/*
 * function: IRCBATTLEMATCH_StepRedrawWaitMenu
 * address: 0x021BACC8
 * packet: pkt_ov100_021BACC8
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRCBATTLEMATCH_FreeMessageWindows 0x021BA5F4 thumb ov100
 *   IRCBATTLEMATCH_PrintMainMessage 0x021BA3A4 thumb ov100
 *   IRCBATTLEMATCH_OpenWaitMenu 0x021BA290 thumb ov100
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepWaitSession 0x021BB270 thumb ov100
 */
#include "../include/Obj10217.h"
struct Word { int x; };
extern void IRCBATTLEMATCH_FreeMessageWindows(unsigned a);
extern void IRCBATTLEMATCH_PrintMainMessage(struct Word *,int);
extern void IRCBATTLEMATCH_OpenWaitMenu(int,int);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void IRCBATTLEMATCH_SetStep(u8 *p, u32 v);
extern void IRCBATTLEMATCH_StepWaitSession(int p);
void IRCBATTLEMATCH_StepRedrawWaitMenu(int a) {
 struct Word x;
 IRCBATTLEMATCH_FreeMessageWindows(a);
 x.x=((struct Obj10217 *)a)->fCB0;
 IRCBATTLEMATCH_PrintMainMessage(&x,a);
 if(((struct Obj10217 *)a)->f24C==9 && ((struct Obj10217 *)a)->fCE8>0) {
  IRCBATTLEMATCH_OpenWaitMenu(a,1);
  IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StepWaitSession);
  return;
 }
 IRCBATTLEMATCH_OpenWaitMenu(a,0);
 IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StepWaitSession);
}
