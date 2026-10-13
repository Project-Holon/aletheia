/*
 * function: IRCBATTLEMATCH_StepResumeWaiting
 * address: 0x021B9E14
 * packet: pkt_ov100_021B9E14
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRCBATTLEMATCH_FreeMessageWindows 0x021BA5F4 thumb ov100
 *   IRCBATTLEMATCH_PrintMainMessage 0x021BA3A4 thumb ov100
 *   IRCBATTLEMATCH_OpenWaitMenu 0x021BA290 thumb ov100
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepSendMode 0x021B9EF8 thumb ov100
 */
#include "../include/Obj00060.h"
struct Word { int x; };
extern void IRCBATTLEMATCH_FreeMessageWindows(unsigned);
extern void IRCBATTLEMATCH_PrintMainMessage(struct Word *,int);
extern void IRCBATTLEMATCH_OpenWaitMenu(int,int);
extern void IRCBATTLEMATCH_SetStep(unsigned char *,unsigned);
typedef unsigned char  u8;
extern void IRCBATTLEMATCH_StepSendMode(u8 *a);
void IRCBATTLEMATCH_StepResumeWaiting(unsigned a)
{
 struct Word x;
 IRCBATTLEMATCH_FreeMessageWindows(a);
 x.x=((struct Obj00060 *)a)->fCB0;
 IRCBATTLEMATCH_PrintMainMessage(&x,a);
 IRCBATTLEMATCH_OpenWaitMenu(a,0);
 IRCBATTLEMATCH_SetStep((unsigned char *)a,(unsigned)IRCBATTLEMATCH_StepSendMode);
}
