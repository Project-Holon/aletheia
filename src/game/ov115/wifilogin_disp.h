#ifndef GAME_OV115_WIFILOGIN_DISP_H
#define GAME_OV115_WIFILOGIN_DISP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wifilogin_disp.c, prototypes copied from their definitions. */

#include "../types.h"

void WIFILOGIN_DISP_OpenProfileCard(u8 *p);
void WIFILOGIN_DISP_GetProfileSlot0(u8 *p);
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
int WIFILOGIN_DISP_Delete(u32 a,int b,int c,u8 *p);
u8 *WIFILOGIN_DISP_CreateDisplay(u16 heap, u32 mode, int reconnect);
void WIFILOGIN_DISP_Draw(u8 *p);
void WIFILOGIN_DISP_DeleteDisplay(u8 *p);
void WIFILOGIN_DISP_InitBgLayersA(u32 unused,unsigned long base);
void WIFILOGIN_DISP_InitBgLayersB(void *unused, unsigned long base);
void WIFILOGIN_DISP_InitBgLayersC(void *unused, unsigned long base);
void WIFILOGIN_DISP_InitBgLayersD(void *unused, unsigned long base);
void WIFILOGIN_DISP_LoadPalette(char *p);
void WIFILOGIN_DISP_UpdatePalette(void *unused, u8 *p);
void WIFILOGIN_DISP_CreateActors(u8 *p);
void WIFILOGIN_DISP_CreateUnit(u8 *p);
void WIFILOGIN_DISP_DrawActors(u8 *p);
void WIFILOGIN_DISP_DeleteActors(u8 *p);
void WIFILOGIN_DISP_ScanlineEffect(void *unused, u8 *p);
void WIFILOGIN_DISP_VBlank(void *task,u8 *p);
void WIFILOGIN_DISP_SetPaletteFlag(u8 *p);
void WIFILOGIN_DISP_SetupScreen(u8 *p);
/* END mkheaders: generated region */

#endif
