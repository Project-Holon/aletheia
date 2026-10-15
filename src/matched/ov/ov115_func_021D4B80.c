/*
 * unit: yes
 * function: WIFILOGIN_DISP_StepGetToken, WIFILOGIN_DISP_StepBeginToken
 * address: 0x021D4B80
 * packet: pkt_ov115_021D4B80
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFILOGIN_DISP_StepGetToken  0x021D4B80  thumb  ov115
 *   WIFILOGIN_DISP_HandleNetError 0x021D4644 thumb ov115
 *   DWC_SVLGetTokenAsync 0x02167FA8 arm ov009
 *   WIFILOGIN_COMMON_SetStateHandler 0x021D426C thumb ov115
 *   WIFILOGIN_DISP_StepPollToken 0x021D4BC4 thumb ov115
 *   d_021D65D0 0x021D65D0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int WIFILOGIN_DISP_HandleNetError(u8 *);
extern int DWC_SVLGetTokenAsync(char *svl, void *result);
extern void WIFILOGIN_COMMON_SetStateHandler(u8 *,u32);
extern void WIFILOGIN_DISP_StepPollToken(u8 *);
extern u8 d_021D65D0[];
#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
void WIFILOGIN_DISP_StepGetToken(u8 *p) {
 if(!WIFILOGIN_DISP_HandleNetError(p)) { if(DWC_SVLGetTokenAsync((char *)d_021D65D0,(void *)(*(int *)(P(0x40)+0x10)))) WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepPollToken); else WIFILOGIN_DISP_HandleNetError(p); }
}
void WIFILOGIN_DISP_StepBeginToken(u8 *p) { WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepGetToken); }
