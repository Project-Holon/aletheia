/*
 * function: WIFILOGIN_MSG_Update
 * address: 0x021D6104
 * packet: pkt_ov115_021D6104
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFILOGIN_MSG_UpdateTask 0x021D5E48 thumb ov115
 *   WIFILOGIN_DISP_Draw 0x021D4DF4 thumb ov115
 *   WIFILOGIN_MSG_Run 0x021D5A88 thumb ov115
 *   WIFILOGIN_MSG_CallStep 0x021D613C thumb ov115
 */
#include "../include/Obj06415.h"
typedef unsigned char u8;typedef unsigned int u32;
extern void WIFILOGIN_MSG_UpdateTask(u8 *p);
extern void WIFILOGIN_DISP_Draw(u8 *p);
extern void WIFILOGIN_MSG_Run(u8 *p);extern int WIFILOGIN_MSG_CallStep(u8 *);
int WIFILOGIN_MSG_Update(int a,int b,int c,u8 *p) { int result;if(((struct Obj06415 *)p)->f0)WIFILOGIN_MSG_UpdateTask(((struct Obj06415 *)p)->f0);WIFILOGIN_DISP_Draw(((struct Obj06415 *)p)->f4);WIFILOGIN_MSG_Run(((struct Obj06415 *)p)->f8);result=0;if(WIFILOGIN_MSG_CallStep(p))result=1;return result; }
