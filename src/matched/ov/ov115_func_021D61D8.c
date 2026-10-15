/*
 * function: WIFILOGIN_MSG_StepWaitMessage
 * address: 0x021D61D8
 * packet: pkt_ov115_021D61D8
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFILOGIN_MSG_IsPrintDone 0x021D5C70 thumb ov115
 *   WIFILOGIN_MSG_RunStep 0x021D6134 thumb ov115
 *   WIFILOGIN_MSG_StepExit 0x021D61FC thumb ov115
 */
#include "../include/Obj22607.h"
typedef unsigned char u8;typedef unsigned int u32;
extern int WIFILOGIN_MSG_IsPrintDone(u8 *p);extern void WIFILOGIN_MSG_RunStep(void *,void (*)(u8 *),int),WIFILOGIN_MSG_StepExit(u8 *);
void WIFILOGIN_MSG_StepWaitMessage(u8 *p) { if(WIFILOGIN_MSG_IsPrintDone(((struct Obj22607 *)p)->f8))WIFILOGIN_MSG_RunStep(p,WIFILOGIN_MSG_StepExit,0x1a2); }
