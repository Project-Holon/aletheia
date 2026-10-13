/*
 * function: IRCBATTLEMATCH_StepWaitTouchThenCancel
 * address: 0x021BAEB4
 * packet: pkt_ov100_021BAEB4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: caller uses r0 after BLX; extern return retains that live value.
 * symbols:
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   IRCBATTLEMATCH_AbortSession 0x021B95C0 thumb ov100
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StartExitWipe 0x021B96B8 thumb ov100
 */
#include "../include/Obj22086.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int TOUCHPANEL_GetTrg(void);
extern int IRCBATTLEMATCH_AbortSession(u8 *p);
extern void IRCBATTLEMATCH_SetStep(u8 *,u32);
extern void IRCBATTLEMATCH_StartExitWipe(u8 *a);
void IRCBATTLEMATCH_StepWaitTouchThenCancel(int p) {
    if(TOUCHPANEL_GetTrg()!=0) {
        IRCBATTLEMATCH_AbortSession((u8 *)p);
        *(int *)(((struct Obj22086 *)p)->f244+0x1c)=13;
        IRCBATTLEMATCH_SetStep((u8 *)p,(u32)IRCBATTLEMATCH_StartExitWipe);
    }
}
