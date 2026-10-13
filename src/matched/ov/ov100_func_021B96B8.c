/*
 * function: IRCBATTLEMATCH_StartExitWipe
 * address: 0x021B96B8
 * packet: pkt_ov100_021B96B8
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepWipeEnd 0x021B95D8 thumb ov100
 */
#include "../include/Obj22065.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void IRCBATTLEMATCH_SetStep(u8 *,u32);
extern void IRCBATTLEMATCH_StepWipeEnd(u8 *);
void IRCBATTLEMATCH_StartExitWipe(u8 *a){WIPE_SYS_Start(0,0,0,0,6,1,((struct Obj22065 *)a)->f278);IRCBATTLEMATCH_SetStep(a,(u32)IRCBATTLEMATCH_StepWipeEnd);}
