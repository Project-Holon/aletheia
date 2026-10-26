#ifndef GAME_OV116_WIFI_BSUBWAY_H
#define GAME_OV116_WIFI_BSUBWAY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wifi_bsubway.c, prototypes copied from their definitions. */

struct MyStatus;
struct WifiBsubwayStatus;

#include "../types.h"

int WIFI_BSUBWAY_Create(void *task,int unused,u8 *parent);
int WIFI_BSUBWAY_Step(void *unusedA,int *state,int unusedB,u8 *work);
int WIFI_BSUBWAY_Delete(void *unusedA, int unusedB, int unusedC, u8 *work);
int WIFI_BSUBWAY_IsTransferReady(unsigned char *work,int state);
void WIFI_BSUBWAY_ClearTrainers(void *trainers);
void WIFI_BSUBWAY_StartRoomRequest(unsigned char *trainers,unsigned char *async,unsigned short roomNumber);
int WIFI_BSUBWAY_FinishRoomRequest(unsigned char *trainers,unsigned char *async);
void WIFI_BSUBWAY_StartPlayerDownload(unsigned char *trainers,unsigned char *async,unsigned short playerIndex);
int WIFI_BSUBWAY_FinishPlayerDownload(unsigned char *trainers,unsigned char *async);
u16 WIFI_BSUBWAY_GetRoomNumber(u8 *trainers);
u16 WIFI_BSUBWAY_GetPlayerIndex(u8 *trainers);
u16 WIFI_BSUBWAY_GetDownloadResult(u8 *trainers);
int WIFI_BSUBWAY_GetTransferState(unsigned char *trainers);
void WIFI_BSUBWAY_NormalizeTrainers(u8 *trainers);
void WIFI_BSUBWAY_SaveTrainers(u8 *trainers, void *save);
void WIFI_BSUBWAY_SaveHistory(unsigned char *trainers,void *save);
void WIFI_BSUBWAY_StatusInit(unsigned char *status,int heapId);
void WIFI_BSUBWAY_StatusDelete(unsigned char *status);
void WIFI_BSUBWAY_StatusSetMessage(u8 *status, void *saveControl, int msgId);
int WIFI_BSUBWAY_StatusCheckMessage(u8 *status,unsigned heapId);
void WIFI_BSUBWAY_StartProfileUpload(u8 *status,void *saveControl,u8 *async);
int WIFI_BSUBWAY_FinishProfileUpload(unsigned char *status,unsigned char *async);
void WIFI_BSUBWAY_BuildProfile(u8 *profileRecord, void *saveControl, const struct MyStatus *trainer);
void WIFI_BSUBWAY_OnHttpError(void *arg, u32 errorCode, u32 errorType, int dwcError);
void WIFI_BSUBWAY_StartHttpRequest(u8 *status, u8 *async, u8 *unusedA, int heapId);
int WIFI_BSUBWAY_PollHttpRequest(u8 *status, u8 *async, int quiet);
void WIFI_BSUBWAY_ReadRecordUnits(struct WifiBsubwayStatus *status,unsigned int index);
void WIFI_BSUBWAY_AbortHttpRequest(u8 *status);
void WIFI_BSUBWAY_StartUploadPlayer(u8 *status, u8 *async);
int WIFI_BSUBWAY_IsUploadDone(void *unused, u8 *async);
void WIFI_BSUBWAY_AsyncInit(void *async);
void WIFI_BSUBWAY_AsyncReset(u8 *async);
int WIFI_BSUBWAY_PollAsync(u8 *async,int *outResult);
int WIFI_BSUBWAY_AsyncHasError(u8 *async);
int WIFI_BSUBWAY_GetErrorState(int *async);
int WIFI_BSUBWAY_CheckFatalError(int *async);
void WIFI_BSUBWAY_SetDownloadResult(u8 *async, u32 state);
void WIFI_BSUBWAY_SetHttpError(u8 *async, u32 httpCode);
void WIFI_BSUBWAY_ResetUpload(u8 *async);
void WIFI_BSUBWAY_TickUploadTimeout(u8 *async);
void WIFI_BSUBWAY_OpenCodeIn(u8 *work,int heapId);
/* END mkheaders: generated region */

#endif
