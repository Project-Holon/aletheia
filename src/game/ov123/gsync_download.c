/*
 * file:     gsync_download.c
 * unit:     yes
 * function: GSYNC_DOWNLOAD_SetRequestMode, GSYNC_DOWNLOAD_AllocWork, GSYNC_DOWNLOAD_FreeWork, GSYNC_DOWNLOAD_GetFileBuffer, GSYNC_DOWNLOAD_CleanupAsync, GSYNC_DOWNLOAD_InitAsync, GSYNC_DOWNLOAD_ClearResult, GSYNC_DOWNLOAD_Reset, GSYNC_DOWNLOAD_SetAttr, GSYNC_DOWNLOAD_IsBusy, GSYNC_DOWNLOAD_CancelAsync, GSYNC_DOWNLOAD_GetFileListAsync, GSYNC_DOWNLOAD_GetFileAsync, GSYNC_DOWNLOAD_CleanupOnce, GSYNC_DOWNLOAD_Process, GSYNC_DOWNLOAD_GetFileSize
 * address:  0x021D5AC0
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from gsync_download.c, gsync_disp.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_NET_ERR_Halt 0x0200F7DC thumb
 *   GF_PANIC_Fail 0x02034714 arm
 *   sGsyncDownloadFileName 0x021DAA40 data ov123 a1
 *   sGsyncDownloadAssertText 0x021DAA54 data ov123 a1
 *   gGsyncDownloadWork 0x021DAC20 data ov123 a4
 *   DWC_RAP_SetErrorHookCallback 0x02156DE0 thumb ov009
 *   DWC_NdCleanupAsync 0x021C5B80 arm ov114
 *   DWC_NdInitAsync 0x021C5928 arm ov114
 *   sGsyncDownloadGameCode 0x021DAA58 data a1
 *   sGsyncDownloadPassword 0x021DAA60 data a1
 *   STD_TSNPrintf 0x0208D80C arm
 *   DWC_NdSetAttr 0x021C5C04 arm ov114
 *   sGsyncDownloadAttrFormat 0x021DAA74 data a1
 *   DWC_NdCancelAsync 0x021C5DB4 arm ov114
 *   DWC_NdGetFileListAsync 0x021C5C38 arm ov114
 *   DWC_NdGetFileAsync 0x021C5CFC arm ov114
 *   DWC_NdProcess  0x021C5AB8  arm  ov114
 */
#include "../ov114/dwci_nd_types.h"
#include "gsync_download_types.h"
#include "gsync_common_types.h"

#include "../arm9/gfl_heap_wrap.h"


#include "../arm9/net_err.h"

#include "../arm9/gf_panic.h"

#include "../ov009/dwc_rap.h"

#include "../ov114/dwc_nd.h"


#include "../arm9/std_sprintf.h"






void GSYNC_DOWNLOAD_SetRequestMode(void *unused, u32 err, int serverError);

GsyncDownloadWork *GSYNC_DOWNLOAD_AllocWork(int heap, int fileBufferSize);

void GSYNC_DOWNLOAD_FreeWork(GsyncDownloadWork *work);

void *GSYNC_DOWNLOAD_GetFileBuffer(GsyncDownloadWork *work);

int GSYNC_DOWNLOAD_CleanupAsync(GsyncDownloadWork *work);

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

extern char sGsyncDownloadFileName[];

extern char sGsyncDownloadAssertText[];

extern GsyncDownloadWork *gGsyncDownloadWork;

extern char sGsyncDownloadGameCode[];

extern char sGsyncDownloadPassword[];

extern const char sGsyncDownloadAttrFormat[];

/* Error codes the nd callback reports in its second argument. */
#define GSYNC_DOWNLOAD_ERR_FATAL 6

#define GSYNC_DOWNLOAD_ERR_NEEDS_RESET 8

static inline u32 filterCallbackError(u32 err)
{
    switch (err) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 7:
        break;
    case 3:
        return err;
    case GSYNC_DOWNLOAD_ERR_FATAL:
        gGsyncDownloadWork->errorFlag = 1;
        break;
    case GSYNC_DOWNLOAD_ERR_NEEDS_RESET:
        GFL_NET_ERR_Halt();
        break;
    }
    return err;
}

/* DWC nd completion callback: records that the request finished and how. */
void GSYNC_DOWNLOAD_SetRequestMode(void *unused, u32 err, int serverError)
{
    u32 result = filterCallbackError(err);
    gGsyncDownloadWork->requestDone = 1;
    gGsyncDownloadWork->callbackResult = result;
}

/* Allocates the work area and the file buffer (fileBufferSize bytes plus a 0x40 byte margin). */
GsyncDownloadWork *GSYNC_DOWNLOAD_AllocWork(int heap, int fileBufferSize)
{
    GsyncDownloadWork *work;
    work = (GsyncDownloadWork *)GFL_HEAP_Alloc(heap, sizeof(GsyncDownloadWork), 1, sGsyncDownloadFileName, 0x88);
    if (gGsyncDownloadWork)
        GF_PANIC_Fail(sGsyncDownloadAssertText, 0, sGsyncDownloadAssertText);
    gGsyncDownloadWork = work;
    work->fileBuffer = GFL_HEAP_Alloc(heap, fileBufferSize + 0x40, 0, sGsyncDownloadFileName, 0x8c);
    work->fileBufferSize = fileBufferSize;
    return work;
}

void GSYNC_DOWNLOAD_FreeWork(GsyncDownloadWork *work)
{
    if (gGsyncDownloadWork) {
        DWC_RAP_SetErrorHookCallback(0, 0);
        GFL_HEAP_Free(work->fileBuffer);
        GFL_HEAP_Free(work);
        gGsyncDownloadWork = 0;
    }
}

void *GSYNC_DOWNLOAD_GetFileBuffer(GsyncDownloadWork *work)
{
    return work->fileBuffer;
}

/* Error hook: starts the nd cleanup once; returns nonzero when no request is pending. */
int GSYNC_DOWNLOAD_CleanupAsync(GsyncDownloadWork *work)
{
    if (!work->cleanupStarted) {
        if (DWC_NdCleanupAsync())
            work->cleanupStarted = 1;
    }
    return work->requestDone == 0;
}

int GSYNC_DOWNLOAD_InitAsync(GsyncDownloadWork *work)
{
    work->requestDone = 0;
    if (!DWC_NdInitAsync((DWCNdCallback)((DWCNdCallback)GSYNC_DOWNLOAD_SetRequestMode), (char *)sGsyncDownloadGameCode, (char *)sGsyncDownloadPassword))
        return 0;
    DWC_RAP_SetErrorHookCallback((int (*)(u32, u32, u32, int))((sptr)GSYNC_DOWNLOAD_CleanupAsync), (sptr)work);
    return 1;
}

/* Nonzero when the last request finished without an error code. */
int GSYNC_DOWNLOAD_ClearResult(GsyncDownloadWork *work)
{
    if (gGsyncDownloadWork->requestDone) {
        if (!work->callbackResult)
            return 1;
    }
    return 0;
}

/* Nonzero when the download failed: timed out and cancel failed, or finished with an error code. */
int GSYNC_DOWNLOAD_Reset(GsyncDownloadWork *work)
{
    if (work->timedOut && work->errorFlag)
        return 1;
    if (gGsyncDownloadWork->requestDone && work->callbackResult)
        return 1;
    return 0;
}

int GSYNC_DOWNLOAD_SetAttr(GsyncDownloadWork *work, void *attrName, int attrValue)
{
    char valueText[20];
    int ok = 0;
    work->requestDone = 0;
    STD_TSNPrintf(valueText, 20, sGsyncDownloadAttrFormat, attrValue);
    if (DWC_NdSetAttr(attrName, valueText, (char *)sGsyncDownloadAssertText))
        ok = 1;
    return ok;
}

void GSYNC_DOWNLOAD_IsBusy(GsyncDownloadWork *work)
{
    work->timeoutFrames = 0;
    work->timedOut = 0;
}

/* Counts frames of a running request; after 3600 frames cancels it. Returns 0 once timed out. */
int GSYNC_DOWNLOAD_CancelAsync(GsyncDownloadWork *work)
{
    if (work->timedOut)
        return 0;
    if (work->timeoutFrames) {
        if (++work->timeoutFrames > 3600) {
            work->timedOut = 1;
            if (!DWC_NdCancelAsync())
                work->errorFlag = 1;
            return 0;
        }
    }
    return 1;
}

int GSYNC_DOWNLOAD_GetFileListAsync(GsyncDownloadWork *work)
{
    int ok = 1;
    work->requestDone = 0;
    work->timeoutFrames = 1;
    work->timedOut = 0;
    if (!DWC_NdGetFileListAsync(work, 0, 1))
        ok = 0;
    return ok;
}

int GSYNC_DOWNLOAD_GetFileAsync(GsyncDownloadWork *work)
{
    int ok = 1;
    work->requestDone = 0;
    work->timeoutFrames = 1;
    work->timedOut = 0;
    if (!DWC_NdGetFileAsync(work, work->fileBuffer, work->fileBufferSize + 0x40))
        ok = 0;
    return ok;
}

int GSYNC_DOWNLOAD_CleanupOnce(GsyncDownloadWork *work)
{
    int ok;
    if (!work->cleanupStarted) {
        ok = 0;
        work->requestDone = 0;
        if (!DWC_NdCleanupAsync())
            return ok;
    }
    return 1;
}

void GSYNC_DOWNLOAD_Process(GsyncDownloadWork *work)
{
    if (GSYNC_DOWNLOAD_CancelAsync(work) != 0)
        DWC_NdProcess();
}

/* Returns fileInfo.size (+0xAC) of the download work. Misnamed: still called GSYNC_DOWNLOAD_GetFileSize by gsync_state.c; rename to GSYNC_DOWNLOAD_GetFileSize with its callers. */
unsigned int GSYNC_DOWNLOAD_GetFileSize(GsyncDownloadWork *work){return work->fileInfo.size;}
