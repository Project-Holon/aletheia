/*
 * function: WIFILOGIN_MSG_StepMessage2
 * address: 0x021D6274
 * packet: pkt_ov115_021D6274
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFILOGIN_MSG_SetMessage 0x021D5C24 thumb ov115
 *   WIFILOGIN_MSG_RunStep 0x021D6134 thumb ov115
 *   WIFILOGIN_MSG_StepWaitMessage2 0x021D6294 thumb ov115
 */
#include "../include/Obj22609.h"
typedef unsigned char u8;typedef unsigned int u32;
extern void WIFILOGIN_MSG_SetMessage(void *,int);
extern void WIFILOGIN_MSG_RunStep(void *a0, int a1, int a2);
extern void WIFILOGIN_MSG_StepWaitMessage2(u8 *);
void WIFILOGIN_MSG_StepMessage2(u8 *p) { WIFILOGIN_MSG_SetMessage(((struct Obj22609 *)p)->f8,27);WIFILOGIN_MSG_RunStep(p,(int)WIFILOGIN_MSG_StepWaitMessage2,0x1e6); }
