/*
 * function: WIFILOGIN_DISP_StepCheckSave
 * address: 0x021D4430
 * packet: pkt_ov115_021D4430
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFILOGIN_MSG_IsPrintDone 0x021D5C70 thumb ov115
 *   DWC_RAP_IsUserDataChanged 0x02156C84 thumb ov009
 *   WIFILOGIN_MSG_SetMessage 0x021D5C24 thumb ov115
 *   WIFILOGIN_COMMON_SetStateHandler 0x021D426C thumb ov115
 *   WIFILOGIN_DISP_StepStartSave 0x021D43F4 thumb ov115
 *   WIFILOGIN_DISP_StepWaitLogin 0x021D4360 thumb ov115
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int WIFILOGIN_MSG_IsPrintDone(u8 *p);
extern unsigned char DWC_RAP_IsUserDataChanged(void);
extern void WIFILOGIN_MSG_SetMessage(void *,int);
extern void WIFILOGIN_COMMON_SetStateHandler(u8 *,u32);
extern void WIFILOGIN_DISP_StepStartSave(u8 *);
extern void WIFILOGIN_DISP_StepWaitLogin(u8 *);
#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
void WIFILOGIN_DISP_StepCheckSave(u8 *p) {
 if(WIFILOGIN_MSG_IsPrintDone((u8 *)W(0x38))) { if(DWC_RAP_IsUserDataChanged() && !W(0x24) && *(int *)(P(0x40)+0x14)!=2) { WIFILOGIN_MSG_SetMessage((void *)W(0x38),30); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepStartSave); } else { WIFILOGIN_DISP_StepWaitLogin(p); } }
}
