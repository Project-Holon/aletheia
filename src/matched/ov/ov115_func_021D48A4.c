/*
 * function: WIFILOGIN_DISP_StepCardMenu2
 * address: 0x021D48A4
 * packet: pkt_ov115_021D48A4
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFILOGIN_MSG_IsTaskFinish 0x021D5E6C thumb ov115
 *   WIFILOGIN_MSG_GetTaskCursor 0x021D5EA8 thumb ov115
 *   WIFILOGIN_MSG_CloseMessage 0x021D5D3C thumb ov115
 *   WIFILOGIN_MSG_PrintMessage 0x021D5ED8 thumb ov115
 *   WIFILOGIN_COMMON_SetStateHandler 0x021D426C thumb ov115
 *   WIFILOGIN_DISP_StepOpenCardMenu2 0x021D4878 thumb ov115
 *   WIFILOGIN_MSG_RedrawBorder 0x021D5F7C thumb ov115
 *   WIFILOGIN_MSG_ShowMessage 0x021D5CCC thumb ov115
 *   WIFILOGIN_DISP_StepCallSync 0x021D4AB0 thumb ov115
 *   WIFILOGIN_MSG_CloseTask 0x021D5E34 thumb ov115
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int WIFILOGIN_MSG_IsTaskFinish(u8 *p);
extern u8 WIFILOGIN_MSG_GetTaskCursor(u8 *p);
extern void WIFILOGIN_MSG_CloseMessage(u8 *p);
extern void WIFILOGIN_MSG_PrintMessage(u8 *p, u32 n);
extern void WIFILOGIN_COMMON_SetStateHandler(u8 *,u32);
extern void WIFILOGIN_DISP_StepOpenCardMenu2(u8 *);
extern void WIFILOGIN_MSG_RedrawBorder(u8 *p);
extern void WIFILOGIN_MSG_ShowMessage(u8 *p, u32 n);
extern void WIFILOGIN_DISP_StepCallSync(unsigned char *a);
extern void WIFILOGIN_MSG_CloseTask(u8 *p);
#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
void WIFILOGIN_DISP_StepCardMenu2(u8 *p) {
 if(WIFILOGIN_MSG_IsTaskFinish((u8 *)W(0x30))) { if(!WIFILOGIN_MSG_GetTaskCursor((u8 *)W(0x30))) { *(int *)(P(0x40)+0x1c)=0; WIFILOGIN_MSG_CloseMessage((u8 *)W(0x38)); WIFILOGIN_MSG_PrintMessage((u8 *)W(0x38),22); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepOpenCardMenu2); } else { *(int *)(P(0x40)+0x1c)=1; WIFILOGIN_MSG_RedrawBorder((u8 *)W(0x38)); if(!*(int *)(P(0x40)+4)) WIFILOGIN_MSG_ShowMessage((u8 *)W(0x38),35); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCallSync); } WIFILOGIN_MSG_CloseTask((u8 *)W(0x30)); W(0x30)=0; }
}
