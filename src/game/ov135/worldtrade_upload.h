#ifndef GAME_OV135_WORLDTRADE_SERVER_H
#define GAME_OV135_WORLDTRADE_SERVER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of worldtrade_upload.c, prototypes copied from their definitions. */

#include "../ov135/worldtrade_types.h"
#include "../types.h"

int WORLDTRADE_SERVER_Init(WorldtradeWork *p);
int WORLDTRADE_SERVER_CallStateHandler(u8 *p);
int WORLDTRADE_SERVER_Exit(WorldtradeWork *p);
void WORLDTRADE_SERVER_SetupBgPlanes(void);
void WORLDTRADE_SERVER_ExitBgPlanes(void);
void WORLDTRADE_SERVER_LoadBgGraphics(WorldtradeWork *p);
void WORLDTRADE_SERVER_CreateWindows(WorldtradeWork *p);
void WORLDTRADE_SERVER_DeleteWindows(WorldtradeWork *p);
void WORLDTRADE_SERVER_CreateStrings(WorldtradeWork *p);
void WORLDTRADE_SERVER_DeleteStrings(WorldtradeWork *p);
int WORLDTRADE_SERVER_StartRequest(WorldtradeWork *p);
int WORLDTRADE_SERVER_SendUploadRequest(WorldtradeWork *p);
int WORLDTRADE_SERVER_PollUploadResponse(WorldtradeWork *p);
int WORLDTRADE_SERVER_StartNameCheck(u8 *p);
int WORLDTRADE_SERVER_WaitNameCheck(u8 *p);
int WORLDTRADE_SERVER_StartDataTransfer(WorldtradeWork *p);
int WORLDTRADE_SERVER_WaitUploadResult(WorldtradeWork *p);
int WORLDTRADE_SERVER_StartUploadFinish(WorldtradeWork *p);
int WORLDTRADE_SERVER_WaitUploadFinish(WorldtradeWork *p);
int WORLDTRADE_SERVER_StartDownload(WorldtradeWork *p);
int WORLDTRADE_SERVER_WaitDownload(WorldtradeWork *p);
int WORLDTRADE_SERVER_StartUploadFinishB(WorldtradeWork *p);
int WORLDTRADE_SERVER_WaitUploadFinishB(WorldtradeWork *p);
int WORLDTRADE_SERVER_StartTrade(WorldtradeWork *p);
int WORLDTRADE_SERVER_WaitTrade(WorldtradeWork *p);
int WORLDTRADE_SERVER_StartTradeFinish(WorldtradeWork *p);
int WORLDTRADE_SERVER_WaitTradeFinish(WorldtradeWork *p);
int WORLDTRADE_SERVER_StartReturn(WorldtradeWork *p);
int WORLDTRADE_SERVER_WaitReturn(WorldtradeWork *p);
int WORLDTRADE_SERVER_StateShowResultA(WorldtradeWork *p);
int WORLDTRADE_SERVER_StartDownloadB(WorldtradeWork *p);
int WORLDTRADE_SERVER_WaitDownloadB(WorldtradeWork *p);
void WORLDTRADE_SERVER_ShowResultByMode(WorldtradeWork *p);
void WORLDTRADE_SERVER_RecordTradeResult(WorldtradeWork *p, void *mon, WorldtradeEntry *ent, void *old);
int WORLDTRADE_SERVER_StartCancel(WorldtradeWork *p);
int WORLDTRADE_SERVER_WaitCancel(WorldtradeWork *p);
int WORLDTRADE_SERVER_StateStartWipeOutDisconnect(WorldtradeWork *p);
int WORLDTRADE_SERVER_StateFinishTrade(WorldtradeWork *p);
int WORLDTRADE_SERVER_StartDelete(WorldtradeWork *p);
int WORLDTRADE_SERVER_WaitDelete(WorldtradeWork *p);
int WORLDTRADE_SERVER_StateIdle(void);
int WORLDTRADE_SERVER_StateSetBusyMessage(WorldtradeWork *p);
int WORLDTRADE_SERVER_StateClearBusyMessage(WorldtradeWork *p);
int WORLDTRADE_SERVER_StatePrintMessage9(WorldtradeWork *p);
int WORLDTRADE_SERVER_StatePrintMessage10(WorldtradeWork *p);
int WORLDTRADE_SERVER_StateStartUploadFinishAsync(WorldtradeWork *p);
int WORLDTRADE_SERVER_StateWaitUploadFinishAsync(WorldtradeWork *p);
int WORLDTRADE_SERVER_StateShowRetryMessage(WorldtradeWork *p);
void WORLDTRADE_SERVER_GetErrorMessageId(WorldtradeWork *p);
int WORLDTRADE_SERVER_StateShowErrorMessage(WorldtradeWork *p);
int WORLDTRADE_SERVER_StateCheckAsyncEnd(WorldtradeWork *p);
int WORLDTRADE_SERVER_StateShowErrorMessageB(WorldtradeWork *p);
int WORLDTRADE_SERVER_StateOpenSavePrompt(WorldtradeWork *p);
int WORLDTRADE_SERVER_StartSave(WorldtradeWork *p);
int WORLDTRADE_SERVER_StateCountdown(WorldtradeWork *p);
int WORLDTRADE_SERVER_WaitSave(WorldtradeWork *p);
int WORLDTRADE_SERVER_StateSaveGame(WorldtradeWork *p);
int WORLDTRADE_SERVER_StartSaveB(WorldtradeWork *p);
int WORLDTRADE_SERVER_WaitSaveB(WorldtradeWork *p);
int WORLDTRADE_SERVER_StateStartWipeOutRestore(WorldtradeWork *p);
int WORLDTRADE_SERVER_StateWaitMessage(WorldtradeWork *p);
int WORLDTRADE_SERVER_StateWaitMessageOrTouch(WorldtradeWork *p);
/* END mkheaders: generated region */

#endif
