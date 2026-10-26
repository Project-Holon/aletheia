#ifndef GAME_OV115_WIFILOGIN_MESSAGE_H
#define GAME_OV115_WIFILOGIN_MESSAGE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wifilogin_message.c, prototypes copied from their definitions. */

struct MsgBank;

#include "../types.h"
#include "../ov175/wifibattlematch_net_types.h"

u8 *WIFILOGIN_MSG_Create(u32 heap, u32 bank, u32 mode);
void WIFILOGIN_MSG_Run(u8 *p);
void WIFILOGIN_MSG_Delete(u8 *p);
void WIFILOGIN_MSG_Draw(void *p, int b);
void WIFILOGIN_MSG_DrawWindow(char *p, struct MsgBank *a, int b);
void WIFILOGIN_MSG_SetMessage(void *p, int b);
void WIFILOGIN_MSG_SetMessageWithIcon(u8 *p, struct MsgBank *a, int b);
int WIFILOGIN_MSG_IsPrintDone(u8 *p);
void WIFILOGIN_MSG_RedrawWindow(u8 *p);
void WIFILOGIN_MSG_ShowMessage(u8 *p, u32 n);
void WIFILOGIN_MSG_CloseMessage(u8 *p);
void *WIFILOGIN_MSG_OpenTask(u8 *p, int mode, int flag, int selected);
void WIFILOGIN_MSG_CloseTask(u8 *p);
void WIFILOGIN_MSG_UpdateTask(u8 *p);
int WIFILOGIN_MSG_IsTaskFinish(u8 *p);
u8 WIFILOGIN_MSG_GetTaskCursor(u8 *p);
void WIFILOGIN_MSG_PrintMessage(u8 *p,u32 n);
void WIFILOGIN_MSG_RedrawBorder(u8 *p);
u32 WIFILOGIN_MSG_GetFrameIdA(u32 a);
u32 WIFILOGIN_MSG_GetFrameIdB(u32 a);
void *WIFILOGIN_MSG_CreateYesNo(u8 *p, int mode, int n);
int WIFILOGIN_MSG_CreateWork(void *ctx,int unused,u8 *q);
int WIFILOGIN_MSG_DeleteWork(void *a,int b,u8 *c,u8 *p);
int WIFILOGIN_MSG_Update(int a,int b,int c,u8 *p);
void WIFILOGIN_MSG_SetStepHandler(u8 *p, void (*v)(u8 *));
void WIFILOGIN_MSG_RunStep(void *p, StepFn fn, int line);
int WIFILOGIN_MSG_CallStep(u8 *p);
void WIFILOGIN_MSG_StepWipe(u8 *p);
void WIFILOGIN_MSG_StepWaitWipe(u8 *p);
void WIFILOGIN_MSG_StepMessage(u8 *p);
void WIFILOGIN_MSG_StepWaitMessage(u8 *p);
void WIFILOGIN_MSG_StepExit(u8 *p);
void WIFILOGIN_MSG_StepWaitExit(u8 *p);
void WIFILOGIN_MSG_StepMessage2(u8 *p);
void WIFILOGIN_MSG_StepWaitMessage2(u8 *p);
void WIFILOGIN_MSG_StepWipe2(u8 *p);
void WIFILOGIN_MSG_StepFinish(u8 *p);
void WIFILOGIN_MSG_SetExitFlag(void *userArg);
/* END mkheaders: generated region */

#endif
