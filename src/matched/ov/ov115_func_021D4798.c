/*
 * function: WIFILOGIN_DISP_StepOpenCardMenu
 * address: 0x021D4798
 * packet: pkt_ov115_021D4798
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   WIFILOGIN_MSG_IsPrintDone 0x021D5C70 thumb ov115
 *   WIFILOGIN_COMMON_SetStateHandler 0x021D426C thumb ov115
 *   WIFILOGIN_MSG_OpenTask 0x021D5D5C thumb ov115
 *   WIFILOGIN_DISP_StepCardMenu 0x021D4708 thumb ov115
 *   WIFILOGIN_MSG_CloseMessage 0x021D5D3C thumb ov115
 */
#include "../include/Obj10330.h"
#include "../include/Obj22592.h"
typedef unsigned char u8; typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void); extern int WIFILOGIN_MSG_IsPrintDone(int); extern void WIFILOGIN_COMMON_SetStateHandler(u8 *,u32); extern void *WIFILOGIN_MSG_OpenTask(u8 *,int,int,int);
extern void WIFILOGIN_DISP_StepCardMenu(u8 *); extern void WIFILOGIN_MSG_CloseMessage(int);
void WIFILOGIN_DISP_StepOpenCardMenu(u8 *p) { ((struct Obj10330 *)p)->f30=WIFILOGIN_MSG_OpenTask(*(u8 * *)&((struct Obj10330 *)p)->f38,1,!((struct Obj22592 *)(*(u8 * *)&((struct Obj10330 *)p)->f40))->f4,1); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCardMenu);  }
