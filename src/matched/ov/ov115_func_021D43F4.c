/*
 * function: WIFILOGIN_DISP_StepStartSave
 * address: 0x021D43F4
 * packet: pkt_ov115_021D43F4
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
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   WIFILIST_GetGsProfileId 0x02009CC0 thumb
 *   func_02008540 0x02008540 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   WIFILOGIN_DISP_StepSaveResult 0x021D43CC thumb ov115
 */
#include "../include/Obj06413.h"
typedef unsigned char u8; typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void); extern int WIFILOGIN_MSG_IsPrintDone(int); extern void WIFILOGIN_COMMON_SetStateHandler(u8 *,u32); extern void *WIFILOGIN_MSG_OpenTask(u8 *,int,int,int);
extern u8 *GAME_DATA_GetMyStatus(void *); extern void *WIFILIST_GetGsProfileId(void *); extern void func_02008540(void *,void *); extern void GAME_DATA_SaveStart(u8 *); extern void WIFILOGIN_DISP_StepSaveResult(u8 *);
void WIFILOGIN_DISP_StepStartSave(u8 *p) { void *a; if(WIFILOGIN_MSG_IsPrintDone(((struct Obj06413 *)p)->f38)) { a=GAME_DATA_GetMyStatus(((struct Obj06413 *)p)->f44); func_02008540(a,WIFILIST_GetGsProfileId(((struct Obj06413 *)p)->f3C)); GAME_DATA_SaveStart(*(u8 * *)&((struct Obj06413 *)p)->f44); ((struct Obj06413 *)p)->f24=1; WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepSaveResult); } }
