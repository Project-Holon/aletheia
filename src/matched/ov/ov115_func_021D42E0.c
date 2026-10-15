/*
 * function: WIFILOGIN_DISP_StepCancelOnReady
 * address: 0x021D42E0
 * packet: pkt_ov115_021D42E0
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
 *   WIFILOGIN_COMMON_IsCancelInput 0x021D4240 thumb ov115
 *   WIFILOGIN_DISP_StepCallSync 0x021D4AB0 thumb ov115
 */
#include "../include/Obj22585.h"
typedef unsigned char u8; typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void); extern int WIFILOGIN_MSG_IsPrintDone(int); extern void WIFILOGIN_COMMON_SetStateHandler(u8 *,u32); extern void *WIFILOGIN_MSG_OpenTask(u8 *,int,int,int);
extern int WIFILOGIN_COMMON_IsCancelInput(u8 *); extern void WIFILOGIN_DISP_StepCallSync(u8 *);
void WIFILOGIN_DISP_StepCancelOnReady(u8 *p) { if(WIPE_SYS_EndCheck() && WIFILOGIN_MSG_IsPrintDone(((struct Obj22585 *)p)->f38) && WIFILOGIN_COMMON_IsCancelInput(p)) WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCallSync); }
