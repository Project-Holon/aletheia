/*
 * function: WIFILOGIN_DISP_Update
 * address: 0x021D4CE4
 * packet: pkt_ov115_021D4CE4
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
 *   WIFILOGIN_DISP_Draw 0x021D4DF4 thumb ov115
 *   WIFILOGIN_MSG_Run 0x021D5A88 thumb ov115
 *   WIFILOGIN_MSG_UpdateTask 0x021D5E48 thumb ov115
 */
#include "../include/Obj06414.h"
typedef unsigned char u8; typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void); extern int WIFILOGIN_MSG_IsPrintDone(int); extern void WIFILOGIN_COMMON_SetStateHandler(u8 *,u32); extern void *WIFILOGIN_MSG_OpenTask(u8 *,int,int,int);
extern void WIFILOGIN_DISP_Draw(u8 *p); extern void WIFILOGIN_MSG_Run(void *); extern void WIFILOGIN_MSG_UpdateTask(void *);
int WIFILOGIN_DISP_Update(int a,int b,int c,u8 *p) { int r=1; void (*cb)(u8 *); WIFILOGIN_DISP_Draw(((struct Obj06414 *)p)->f34); WIFILOGIN_MSG_Run(((struct Obj06414 *)p)->f38); cb=*(void (**)(u8 *))p; if(cb) { cb(p); r=0; } if(((struct Obj06414 *)p)->f30) WIFILOGIN_MSG_UpdateTask(((struct Obj06414 *)p)->f30); return r; }
