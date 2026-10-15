/*
 * function: WIFILOGIN_DISP_StepCheckAccount
 * address: 0x021D497C
 * packet: pkt_ov115_021D497C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: 0202EB44 leaves r0 live for this caller; entry p is forwarded.
 * 02009860 is bx lr; its unchanged entry pointer feeds both SDK readers.
 * callbacks: both zero-status arms use 42E0; mode2 and final else use 46CC;
 * missing profile uses 45D0, missing console uses 493C, mode1 uses 460C.
 * symbols:
 *   APP_ENV_InitParentalControl 0x0202EB44 thumb
 *   APP_ENV_IsEulaAgreed 0x0202EB4C thumb
 *   WIFILOGIN_MSG_CloseMessage 0x021D5D3C thumb ov115
 *   WIFILOGIN_MSG_PrintMessage 0x021D5ED8 thumb ov115
 *   WIFILOGIN_COMMON_SetStateHandler 0x021D426C thumb ov115
 *   WIFILOGIN_MSG_Draw 0x021D5B50 thumb ov115
 *   func_02009860 0x02009860 thumb
 *   DWC_CheckHasProfile 0x020597C8 arm
 *   DWC_CheckValidConsole 0x02059760 arm
 *   APP_ENV_IsRunOnTwl 0x0202EB0C thumb
 *   WIFILOGIN_DISP_StepCancelOnReady 0x021D42E0 thumb ov115
 *   WIFILOGIN_DISP_StepMenuAfterProfileError 0x021D46CC thumb ov115
 *   WIFILOGIN_DISP_StepConfirmProfile 0x021D45D0 thumb ov115
 *   WIFILOGIN_DISP_StepCancelWait 0x021D493C thumb ov115
 *   WIFILOGIN_DISP_StepConfirmConsole 0x021D460C thumb ov115
 */
#include "../include/Obj13850.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int APP_ENV_InitParentalControl(u8 *);
struct DWCstAccUserData;
extern u32 APP_ENV_IsEulaAgreed(void);
extern void WIFILOGIN_MSG_CloseMessage(u8 *p);
extern void WIFILOGIN_MSG_PrintMessage(u8 *,u32);
extern void WIFILOGIN_COMMON_SetStateHandler(u8 *,u32);
extern void WIFILOGIN_MSG_Draw(void *,int);
struct Sub020097BCObj;
extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);
extern int DWC_CheckHasProfile(struct DWCstAccUserData *userdata);
extern int DWC_CheckValidConsole(struct DWCstAccUserData *userdata);
extern u32 APP_ENV_IsRunOnTwl(void);
extern void WIFILOGIN_DISP_StepCancelOnReady(u8 *),WIFILOGIN_DISP_StepMenuAfterProfileError(u8 *),WIFILOGIN_DISP_StepConfirmProfile(u8 *);
extern void WIFILOGIN_DISP_StepCancelWait(u8 *),WIFILOGIN_DISP_StepConfirmConsole(u8 *);
#define P(k) (*(u8 **)(p+(k)))
void WIFILOGIN_DISP_StepCheckAccount(u8 *p)
{
    if(APP_ENV_InitParentalControl(p)==0) {
        WIFILOGIN_MSG_CloseMessage(P(0x38));
        WIFILOGIN_MSG_PrintMessage(P(0x38),39);
        *(int *)(P(0x40)+0x1c)=1;
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCancelOnReady);
        return;
    }
    if(APP_ENV_IsEulaAgreed()==0) {
        WIFILOGIN_MSG_CloseMessage(P(0x38));
        WIFILOGIN_MSG_PrintMessage(P(0x38),34);
        *(int *)(P(0x40)+0x1c)=1;
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCancelOnReady);
        return;
    }
    if(*(int *)(P(0x40)+0x14)==2) {
        WIFILOGIN_MSG_Draw(P(0x38),17);
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepMenuAfterProfileError);
        return;
    }
    if(DWC_CheckHasProfile((struct DWCstAccUserData *)func_02009860((struct Sub020097BCObj *)P(0x3c)))==0) {
        ((struct Obj13850 *)p)->f20=1;
        WIFILOGIN_MSG_CloseMessage(P(0x38));
        if(APP_ENV_IsRunOnTwl()==0) WIFILOGIN_MSG_PrintMessage(P(0x38),18);
        else WIFILOGIN_MSG_PrintMessage(P(0x38),43);
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepConfirmProfile);
        return;
    }
    if(DWC_CheckValidConsole((struct DWCstAccUserData *)func_02009860((struct Sub020097BCObj *)P(0x3c)))==0) {
        ((struct Obj13850 *)p)->f20=1;
        WIFILOGIN_MSG_CloseMessage(P(0x38));
        if(APP_ENV_IsRunOnTwl()==0) WIFILOGIN_MSG_PrintMessage(P(0x38),20);
        else WIFILOGIN_MSG_PrintMessage(P(0x38),45);
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepCancelWait);
        return;
    }
    if(*(int *)(P(0x40)+0x14)==1) {
        WIFILOGIN_MSG_CloseMessage(P(0x38));
        WIFILOGIN_MSG_PrintMessage(P(0x38),37);
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepConfirmConsole);
    } else {
        WIFILOGIN_MSG_Draw(P(0x38),17);
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepMenuAfterProfileError);
    }
}
