/*
 * function: WIFILOGIN_DISP_StepPollToken
 * address: 0x021D4BC4
 * packet: pkt_ov115_021D4BC4
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
 *   WIFILOGIN_DISP_HandleNetError 0x021D4644 thumb ov115
 *   DWC_SVLProcess 0x02168040 arm ov009
 *   WIFILOGIN_DISP_StepCallSync 0x021D4AB0 thumb ov115
 */
typedef unsigned char u8; typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void); extern int WIFILOGIN_MSG_IsPrintDone(int); extern void WIFILOGIN_COMMON_SetStateHandler(u8 *,u32); extern void *WIFILOGIN_MSG_OpenTask(u8 *,int,int,int);
extern int WIFILOGIN_DISP_HandleNetError(u8 *); extern int DWC_SVLProcess(void); extern void WIFILOGIN_DISP_StepCallSync(u8 *);
void WIFILOGIN_DISP_StepPollToken(u8 *p) { int x; if(!WIFILOGIN_DISP_HandleNetError(p)) { x=DWC_SVLProcess(); if(x==3) WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCallSync); else if(x==4 || x==0 || x==5) WIFILOGIN_DISP_HandleNetError(p); } }
