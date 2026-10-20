#ifndef GAME_OV114_DPW_TR_H
#define GAME_OV114_DPW_TR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dpw_tr.c, prototypes copied from their definitions. */

struct DpwTrSearchKey;
typedef struct DpwTrSearchKey DpwTrSearchKey;

#include "../types.h"

void DPW_TR_Init(unsigned int profileId, unsigned int friendKeyLo, unsigned int friendKeyHi, int serverType);
void DPW_TR_Main(void);
void DPW_TR_End(void);
int DPW_TR_IsAsyncEnd(void);
int DPW_TR_GetAsyncResult(void);
void DPW_TR_UploadAsync(const void *tradeData, const void *wantedData, int wantedLen);
void DPW_TR_GetUploadResultAsync(void);
void DPW_TR_DownloadAsync(u8 *resultBuf);
void DPW_TR_ReturnAsync(u8 *resultBuf);
void DPW_TR_DeleteAsync(void);
void DPW_TR_UploadFinishAsync(void);
void DPW_TR_CancelAsync(void);
void DPW_TR_DownloadMatchDataAsync(const DpwTrSearchKey *searchKey, int searchCount, u8 *resultBuf);
void DPW_TR_DownloadMatchDataRawAsync(const void *searchData, u8 *resultBuf);
void DPW_TR_TradeAsync(unsigned uploadFlag, const void *tradeData, u8 *resultBuf, const void *wantedData, unsigned wantedLen);
void DPW_TR_TradeFinishAsync(void);
void DPW_TR_GetServerStateAsync(void);
void DPW_TR_SetProfileAsync(unsigned char *profile, u8 *resultBuf);
int DPW_TR_ConvertDwcError(u32 dwcErrorType);
/* END mkheaders: generated region */

#endif
