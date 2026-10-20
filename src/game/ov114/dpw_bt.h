#ifndef GAME_OV114_DPW_BT_H
#define GAME_OV114_DPW_BT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dpw_bt.c, prototypes copied from their definitions. */

#include "../types.h"

void DPW_BT_Init(unsigned profileId, unsigned friendKeyLo, unsigned friendKeyHi, unsigned serverType);
void DPW_BT_Main(void);
void DPW_BT_End(void);
int DPW_BT_IsAsyncEnd(void);
int DPW_BT_GetAsyncResult(void);
void DPW_BT_GetRoomNumAsync(unsigned rank);
void DPW_BT_DownloadPlayerAsync(unsigned rank, unsigned roomNo, u8 *resultBuf);
void DPW_BT_UploadPlayerAsync(u32 rank, u32 roomNo, u32 section, const void *playerData, const void *leaderData, u32 resultBuf);
void DPW_BT_CancelAsync(void);
void DPW_BT_GetServerStateAsync(void);
void DPW_BT_SetProfileAsync(unsigned char *profile, u8 *resultBuf);
int DPW_BT_ConvertDwcError(unsigned dwcErrorType);
/* END mkheaders: generated region */

#endif
