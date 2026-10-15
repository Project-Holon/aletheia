/*
 * function: WIFILOGIN_DISP_StepWaitLogin
 * address: 0x021D4360
 * packet: pkt_ov115_021D4360
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x0203C600 has no outside code witness; the integrator owns it.
 * blocker: 0x0203C600 ARM verified EXACT in ov099_func_021BEB68.c.
 *   extern char *d_021469DC;
 *   extern void GFL_NET_STATE_WifiLoginMain(void);
 *   int GFL_NET_STATE_IsWifiLoginState(void) {
 *       return *(void **)(d_021469DC + 8) == (void *)GFL_NET_STATE_WifiLoginMain;
 *   }
 *   symbols: d_021469DC 0x021469DC data; GFL_NET_STATE_WifiLoginMain 0x0203C0F4 arm.
 * symbols:
 *   GFL_NET_STATE_IsWifiLoginState 0x0203C600 arm
 *   WIFILOGIN_MSG_CloseMessage 0x021D5D3C thumb ov115
 *   WIFILOGIN_MSG_RedrawWindow 0x021D5C94 thumb ov115
 *   WIFILOGIN_MSG_PrintMessage 0x021D5ED8 thumb ov115
 *   APP_ENV_IsRunOnTwl 0x0202EB0C thumb
 *   WIFILOGIN_COMMON_SetStateHandler 0x021D426C thumb ov115
 *   WIFILOGIN_DISP_StepCancel 0x021D4310 thumb ov115
 *   WIFILOGIN_DISP_StepBeginToken 0x021D4BB4 thumb ov115
 *   WIFILOGIN_DISP_StepCallSync 0x021D4AB0 thumb ov115
 *   WIFILOGIN_DISP_HandleNetError 0x021D4644 thumb ov115
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GFL_NET_STATE_IsWifiLoginState(void);
extern void WIFILOGIN_MSG_CloseMessage(u8 *p);
extern void WIFILOGIN_MSG_RedrawWindow(u8 *p);
extern void WIFILOGIN_MSG_PrintMessage(u8 *p, u32 n);
extern u32 APP_ENV_IsRunOnTwl(void);
extern void WIFILOGIN_COMMON_SetStateHandler(u8 *,u32);
extern void WIFILOGIN_DISP_StepCancel(u8 *);
extern void WIFILOGIN_DISP_StepBeginToken(u8 *);
extern void WIFILOGIN_DISP_StepCallSync(unsigned char *a);
extern int WIFILOGIN_DISP_HandleNetError(u8 *);
#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
void WIFILOGIN_DISP_StepWaitLogin(u8 *p) {
 if(GFL_NET_STATE_IsWifiLoginState()) { if(W(0x20)) { WIFILOGIN_MSG_CloseMessage((u8 *)W(0x38)); WIFILOGIN_MSG_RedrawWindow((u8 *)W(0x38)); if(APP_ENV_IsRunOnTwl()) WIFILOGIN_MSG_PrintMessage((u8 *)W(0x38),44); else WIFILOGIN_MSG_PrintMessage((u8 *)W(0x38),19); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCancel); } else if(*(int *)(P(0x40)+0x10)) { WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepBeginToken); } else { WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCallSync); } } else WIFILOGIN_DISP_HandleNetError(p);
}
