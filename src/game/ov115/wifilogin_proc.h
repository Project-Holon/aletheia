#ifndef GAME_OV115_WIFILOGIN_PROC_H
#define GAME_OV115_WIFILOGIN_PROC_H

struct TcbTask;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wifilogin_proc.c, prototypes copied from their definitions. */

struct Proc;
struct WifiloginPalTask;

#include "../types.h"

void *WIFILOGIN_DISP_GetWifiUserData(u8 *p);
void *WIFILOGIN_DISP_GetDwcFriendDataSlot0(u8 *p);
void WIFILOGIN_DISP_CopyProfileSlot(int a,int b,u8 *p);
void WIFILOGIN_DISP_StepCancelOnReady(u8 *p);
void WIFILOGIN_DISP_StepCancel(u8 *p);
void WIFILOGIN_DISP_StepWaitLogin(u8 *p);
void WIFILOGIN_DISP_StepSaveResult(u8 *p);
void WIFILOGIN_DISP_StepStartSave(u8 *p);
void WIFILOGIN_DISP_StepCheckSave(u8 *p);
void WIFILOGIN_DISP_StartSession(u8 *p);
void WIFILOGIN_DISP_StepConfirmProfileResult(u8 *p);
void WIFILOGIN_DISP_StepConfirmConsoleResult(u8 *p);
void WIFILOGIN_DISP_StepConfirmProfile(u8 *p);
void WIFILOGIN_DISP_StepConfirmConsole(u8 *p);
int WIFILOGIN_DISP_HandleNetError(u8 *p);
void WIFILOGIN_DISP_StepMenuAfterProfileError(u8 *p);
void WIFILOGIN_DISP_StepCardMenu(u8 *p);
void WIFILOGIN_DISP_StepOpenCardMenu(u8 *p);
void WIFILOGIN_DISP_StepCardSelect(u8 *p);
void WIFILOGIN_DISP_StepOpenCardMenu2(u8 *p);
void WIFILOGIN_DISP_StepCardMenu2(u8 *p);
void WIFILOGIN_DISP_StepOpenCardMenu3(u8 *p);
void WIFILOGIN_DISP_StepCancelWait(u8 *p);
void WIFILOGIN_DISP_StepCheckAccount(u8 *p);
void WIFILOGIN_DISP_StepFinish(u8 *p);
void WIFILOGIN_DISP_StepCallSync(unsigned char *a);
void WIFILOGIN_DISP_StepStartWipe(u8 *p);
void WIFILOGIN_DISP_StepGetToken(u8 *p);
void WIFILOGIN_DISP_StepBeginToken(u8 *p);
void WIFILOGIN_DISP_StepPollToken(u8 *p);
int WIFILOGIN_DISP_Create(void *ctx,int unused,u8 *q);
int WIFILOGIN_DISP_Update(int a,int b,int c,u8 *p);
int WIFILOGIN_DISP_Delete(struct Proc *a,int b,int c,u8 *p);
/* END mkheaders: generated region */

#endif
