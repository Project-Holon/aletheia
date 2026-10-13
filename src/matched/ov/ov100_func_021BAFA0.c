/*
 * function: IRCBATTLEMATCH_StepCountdownThenExit
 * address: 0x021BAFA0
 * packet: pkt_ov100_021BAFA0
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRCBATTLEMATCH_FreeMessageWindows 0x021BA5F4 thumb ov100
 *   IRCBATTLEMATCH_AbortSession 0x021B95C0 thumb ov100
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StartExitWipe 0x021B96B8 thumb ov100
 */
#include "../include/Obj22087.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void IRCBATTLEMATCH_FreeMessageWindows(unsigned a);
extern int IRCBATTLEMATCH_AbortSession(u8 *p);
extern void IRCBATTLEMATCH_SetStep(u8 *,u32);
extern void IRCBATTLEMATCH_StartExitWipe(u8 *a);
void IRCBATTLEMATCH_StepCountdownThenExit(int p) {
    if(--((struct Obj22087 *)p)->fCAC==0) {
        IRCBATTLEMATCH_FreeMessageWindows(p);
        IRCBATTLEMATCH_AbortSession((u8 *)p);
        IRCBATTLEMATCH_SetStep((u8 *)p,(u32)IRCBATTLEMATCH_StartExitWipe);
    }
}
