/*
 * function: IRCBATTLEMATCH_StepWaitTimeout
 * address: 0x021B99F4
 * packet: pkt_ov100_021B99F4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_Exit 0x0203CEAC arm
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepWaitTouchThenExit 0x021B99D4 thumb ov100
 */
#include "../include/Obj22073.h"
extern int GFL_NET_Exit(int);
extern void IRCBATTLEMATCH_SetStep(unsigned char *,unsigned);
extern void IRCBATTLEMATCH_StepWaitTouchThenExit(unsigned char *a);
void IRCBATTLEMATCH_StepWaitTimeout(unsigned a)
{
 if(++((struct Obj22073 *)a)->fCAC>60) {
  GFL_NET_Exit(0);
  IRCBATTLEMATCH_SetStep((unsigned char *)a,(unsigned)IRCBATTLEMATCH_StepWaitTouchThenExit);
 }
}
