/*
 * function: WIFILOGIN_MSG_StepMessage
 * address: 0x021D61B8
 * packet: pkt_ov115_021D61B8
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFILOGIN_MSG_SetMessage 0x021D5C24 thumb ov115
 *   WIFILOGIN_MSG_RunStep 0x021D6134 thumb ov115
 *   WIFILOGIN_MSG_StepWaitMessage 0x021D61D8 thumb ov115
 */
#include "../include/Obj22606.h"
typedef unsigned char u8;typedef unsigned int u32;
extern void WIFILOGIN_MSG_SetMessage(void *,int);
extern void WIFILOGIN_MSG_RunStep(void *a0, int a1, int a2);
extern void WIFILOGIN_MSG_StepWaitMessage(u8 *);
void WIFILOGIN_MSG_StepMessage(u8 *p) { WIFILOGIN_MSG_SetMessage(((struct Obj22606 *)p)->f8,26);WIFILOGIN_MSG_RunStep(p,(int)WIFILOGIN_MSG_StepWaitMessage,0x194); }
