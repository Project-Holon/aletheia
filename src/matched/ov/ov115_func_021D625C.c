/*
 * function: WIFILOGIN_MSG_StepWaitExit
 * address: 0x021D625C
 * packet: pkt_ov115_021D625C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFILOGIN_MSG_RunStep 0x021D6134 thumb ov115
 *   WIFILOGIN_MSG_StepMessage2 0x021D6274 thumb ov115
 */
#include "../include/Obj22608.h"
typedef unsigned char u8;typedef unsigned int u32;
extern void WIFILOGIN_MSG_RunStep(void *a0, int a1, int a2);
extern void WIFILOGIN_MSG_StepMessage2(u8 *);
void WIFILOGIN_MSG_StepWaitExit(u8 *p) { if(((struct Obj22608 *)p)->f18)WIFILOGIN_MSG_RunStep(p,(int)WIFILOGIN_MSG_StepMessage2,0x1d8); }
