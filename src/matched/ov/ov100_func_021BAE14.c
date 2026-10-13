/*
 * function: IRCBATTLEMATCH_StepRestoreWaitMenu
 * address: 0x021BAE14
 * packet: pkt_ov100_021BAE14
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRCBATTLEMATCH_PrintMainMessage 0x021BA3A4 thumb ov100
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepWaitSession 0x021BB270 thumb ov100
 *   IRCBATTLEMATCH_OpenWaitMenu 0x021BA290 thumb ov100
 */
#include "../include/Obj10218.h"
struct Word { int x; };
extern void IRCBATTLEMATCH_PrintMainMessage(struct Word *,int);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void IRCBATTLEMATCH_SetStep(u8 *p, u32 v);
extern void IRCBATTLEMATCH_StepWaitSession(int p);
extern void IRCBATTLEMATCH_OpenWaitMenu(int,int);
void IRCBATTLEMATCH_StepRestoreWaitMenu(int a) {
 struct Word x;
 x.x=((struct Obj10218 *)a)->fCB0;
 IRCBATTLEMATCH_PrintMainMessage(&x,a);
 IRCBATTLEMATCH_SetStep((u8 *)a,(u32)IRCBATTLEMATCH_StepWaitSession);
 if(((struct Obj10218 *)a)->f24C==9 && ((struct Obj10218 *)a)->fCE8>0) { IRCBATTLEMATCH_OpenWaitMenu(a,1); return; }
 IRCBATTLEMATCH_OpenWaitMenu(a,0);
}
