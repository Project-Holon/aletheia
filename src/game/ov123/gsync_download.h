#ifndef GAME_OV123_GSYNC_DOWNLOAD_H
#define GAME_OV123_GSYNC_DOWNLOAD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gsync_download.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov123/gsync_download_types.h"

void GSYNC_DOWNLOAD_SetRequestMode(int reason, int err, int serverError);
GsyncDownloadWork *GSYNC_DOWNLOAD_AllocWork(int heap, int fileBufferSize);
void GSYNC_DOWNLOAD_FreeWork(GsyncDownloadWork *work);
void *GSYNC_DOWNLOAD_GetFileBuffer(GsyncDownloadWork *work);
int GSYNC_DOWNLOAD_CleanupAsync(void *arg, u32 errorCode, u32 errorType, int dwcError);
int GSYNC_DOWNLOAD_InitAsync(GsyncDownloadWork *work);
int GSYNC_DOWNLOAD_ClearResult(GsyncDownloadWork *work);
int GSYNC_DOWNLOAD_Reset(GsyncDownloadWork *work);
int GSYNC_DOWNLOAD_SetAttr(GsyncDownloadWork *work, void *attrName, int attrValue);
void GSYNC_DOWNLOAD_IsBusy(GsyncDownloadWork *work);
int GSYNC_DOWNLOAD_CancelAsync(GsyncDownloadWork *work);
int GSYNC_DOWNLOAD_GetFileListAsync(GsyncDownloadWork *work);
int GSYNC_DOWNLOAD_GetFileAsync(GsyncDownloadWork *work);
int GSYNC_DOWNLOAD_CleanupOnce(GsyncDownloadWork *work);
void GSYNC_DOWNLOAD_Process(GsyncDownloadWork *work);
unsigned int GSYNC_DOWNLOAD_GetFileSize(GsyncDownloadWork *work);
/* END mkheaders: generated region */

#endif
