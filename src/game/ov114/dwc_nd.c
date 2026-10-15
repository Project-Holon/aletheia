/*
 * file:     dwc_nd.c
 * unit:     yes
 * function: DWCi_NdAlloc, DWCi_NdFree, DWCi_NdCleanupCallback, DWCi_SVLTokenWaitThread, func_021C58C8, DWC_NdInitAsync, DWC_NdProcess, DWC_NdCleanupAsync, DWC_NdSetAttr, DWC_NdGetFileListAsync, DWC_NdGetFileAsync, DWC_NdCancelAsync, DWC_NdGetProgress
 * address:  0x021C569C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_JoinThread  0x02085710  arm
 *   OS_LockMutex  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   gDwcNdState     0x021D3B68  data ov114
 *   gDwcNdMutex     0x021D3B84  data ov114
 *   DWC_SVLProcess  0x02168040  arm  ov009
 *   strlen         0x0209477C  arm
 *   OS_SNPrintf  0x02084F80  arm
 *   DWC_Base64Encode  0x02059B40  arm
 *   DWCi_NdStartup  0x021C6348  arm  ov114
 *   func_02059E18  0x02059E18  arm
 *   func_02059F54  0x02059F54  arm
 *   OS_Sleep  0x02085A38  arm
 *   DWCi_NdSetError  0x021C659C  arm  ov114
 *   OS_UnlockMutex 0x02086078  arm
 *   DWCi_IsError  0x02059F38  arm
 *   OS_InitMutex  0x02086004  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   strncpy        0x02094860  arm
 *   DWC_SVLGetTokenAsync  0x02167FA8  arm
 *   OS_CreateThread  0x020853C0  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   sDwcNdServiceLocatorPort     0x021CF370  data
 *   DWCi_NdCleanupAsync  0x021C651C  arm  ov114
 *   DWCi_NdSetAttr  0x021C5F90  arm  ov114
 *   MI_CpuFill8    0x02082BCC  arm
 *   DWCi_NdGetFileListAsync  0x021C7124  arm  ov114
 *   DWCi_NdGetFileAsync  0x021C73C0  arm  ov114
 *   DWCi_NdCancelAsync  0x021C666C  arm  ov114
 *   DWCi_NdGetProgress  0x021C757C  arm  ov114
 *   DWC_AllocEx  0x0205A17C  arm  arm9
 *   @16277         0x021CF348  data
 *   @16278         0x021CF35C  data
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "dwc_nd_types.h"

struct DWCNdFileInfo;

extern void *DWC_AllocEx(int name, unsigned long size, int align);
extern void DWC_Free(int name, void *ptr, unsigned long size);
void OS_JoinThread(void *thread);
void OS_LockMutex(void *mutex);
void OS_UnlockMutex(void *mutex);
extern int DWC_SVLProcess(void);
extern int OS_SNPrintf(char *dst, u32 len, const char *fmt, ...);
extern int DWC_Base64Encode(char *src, u32 srclen, char *dst, u32 dstlen);
extern int DWCi_NdStartup(void *(*alloc)(unsigned long, int), void (*free)(void *), char *url,
                         char *token, char *gameCode, char *password,
                         void (*callback)(int, int, int));
extern int func_02059E18(int *errorCode);
extern void func_02059F54(int error, int errorCode);
extern void OS_Sleep(u32 msec);
extern void DWCi_NdSetError(int error, int serverError);
extern int DWCi_IsError(void);
extern void OS_InitMutex(void *mutex);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern char *strncpy(char *dst, const char *src, unsigned long n);
extern int DWC_SVLGetTokenAsync(char *serviceName, DWCSvlResult *result);
extern void OS_CreateThread(void *thread, void (*func)(void *), void *arg, void *stack,
                          unsigned long stackSize, unsigned long prio);
extern void OS_WakeupThreadDirect(void *thread);
extern void DWCi_NdCleanupAsync(void (*callback)(void));
extern int DWCi_NdSetAttr(char *attr1, char *attr2, char *attr3);
extern int DWCi_NdGetFileListAsync(void *fileList, int offset, int num);
extern int DWCi_NdGetFileAsync(struct DWCNdFileInfo *fileInfo, char *buffer, unsigned int bufferSize, char *opt);
extern int DWCi_NdCancelAsync(void);
extern int DWCi_NdGetProgress(unsigned long *received, unsigned long *contentLength);
void *DWCi_NdAlloc(unsigned long size, int align);
void DWCi_NdFree(void *ptr);
void DWCi_NdCleanupCallback(void);
void func_021C58C8(int reason, int error, int serverError);
int DWC_NdInitAsync(NdCallback callback, char *gameCode, char *password);
void DWC_NdProcess(void);
int DWC_NdCleanupAsync(void);
int DWC_NdSetAttr(char *attr1, char *attr2, char *attr3);
int DWC_NdGetFileListAsync(void *fileList, unsigned int offset, unsigned int num);
int DWC_NdGetFileAsync(void *fileInfo, char *buffer, unsigned int size);
int DWC_NdCancelAsync(void);
int DWC_NdGetProgress(unsigned long *received, unsigned long *contentLength);
extern char sDwcNdServiceLocatorPort[];

/*
 * Allocator handed to the download library: aligned allocation from heap 10.
 */
void *DWCi_NdAlloc(unsigned long size, int align)
{
    return DWC_AllocEx(0xa, size, align);
}

/*
 * Free function handed to the download library: releases a heap 10 block.
 */
void DWCi_NdFree(void *ptr)
{
    DWC_Free(0xa, ptr, 0);
}

/*
 * Cleanup after the session ended: joins the token thread, frees the session block
 * and reports the cleanup reason.
 */
void DWCi_NdCleanupCallback(void)
{
    OS_JoinThread(gDwcNdState.param->thread);
    DWCi_NdFree(gDwcNdState.param);
    gDwcNdState.param = 0;
    OS_LockMutex(gDwcNdMutex);
    gDwcNdState.state = 3;
    gDwcNdState.reason = 4;
    OS_UnlockMutex(gDwcNdMutex);
}

/*
 * sdk:      DWCi_SVLTokenWaitThread (libdwcnd.TWL.HYB.a(dwc_nd.o))
 *
 * Polls the service locator (DWC_SVLProcess, ov009) until the token is ready, then builds
 * the download URL, decodes the token and starts the download server session.
 */
static void DWCi_SVLTokenWaitThread(void *arg)
{
    char url[256];
    char token[400];
    int errorCode;

    while (1) {
        switch (DWC_SVLProcess()) {
        case 3:
            if (strlen(gDwcNdState.param->svl.svlHost) + strlen("https:///download") > sizeof(url) - 1) {
                func_021C58C8(0, 8, -1);
                return;
            }
            OS_SNPrintf(url, sizeof(url), "https://%s/download", gDwcNdState.param->svl.svlHost);
            if (DWC_Base64Encode(gDwcNdState.param->svl.svlToken, strlen(gDwcNdState.param->svl.svlToken),
                              token, sizeof(token)) < 0) {
                func_021C58C8(0, 8, -1);
                return;
            }
            if (!DWCi_NdStartup(DWCi_NdAlloc, DWCi_NdFree, url, token, gDwcNdState.param->gameCode,
                               gDwcNdState.param->password, func_021C58C8)) {
                func_021C58C8(0, 8, -1);
                return;
            }
            gDwcNdState.param->status = 1;
            func_021C58C8(0, 0, -1);
            return;
        case 4:
            func_02059E18(&errorCode);
            func_02059F54(13, errorCode);
            func_021C58C8(0, 3, -1);
            return;
        case 5:
            func_021C58C8(0, 6, -1);
            return;
        }
        OS_Sleep(100);
    }
}

/*
 * Records the outcome (reason, error, server error) of the session for DWC_NdProcess.
 */
void func_021C58C8(int reason, int error, int serverError)
{
    if (error != 0)
        DWCi_NdSetError(error, serverError);
    OS_LockMutex(gDwcNdMutex);
    gDwcNdState.state = 3;
    gDwcNdState.reason = reason;
    gDwcNdState.error = error;
    gDwcNdState.serverError = serverError;
    if (error != 0)
        gDwcNdState.state = 4;
    OS_UnlockMutex(gDwcNdMutex);
}

/*
 * sdk:      DWC_NdInitAsync (libdwcnd.TWL.HYB.a(dwc_nd.o))
 */
int DWC_NdInitAsync(NdCallback callback, char *gameCode, char *password)
{
    if (DWCi_IsError())
        return 0;
    OS_InitMutex(gDwcNdMutex);
    OS_LockMutex(gDwcNdMutex);
    if (gDwcNdState.state != 0) {
        DWCi_NdSetError(2, 0);
        OS_UnlockMutex(gDwcNdMutex);
        return 0;
    }
    gDwcNdState.state = 2;
    OS_UnlockMutex(gDwcNdMutex);
    gDwcNdState.reason = 0;
    gDwcNdState.error = 0;
    gDwcNdState.serverError = 0;
    gDwcNdState.callback = callback;
    gDwcNdState.errorReported = 0;
    gDwcNdState.param = DWCi_NdAlloc(sizeof(NdParam), 0x20);
    if (gDwcNdState.param == 0) {
        DWCi_NdSetError(1, 0);
        return 0;
    }
    MI_CpuFill8(gDwcNdState.param, 0, sizeof(NdParam));
    gDwcNdState.param->status = 0;
    strncpy(gDwcNdState.param->gameCode, gameCode, 31);
    strncpy(gDwcNdState.param->password, password, 31);
    if (DWC_SVLGetTokenAsync(sDwcNdServiceLocatorPort, &gDwcNdState.param->svl) == 0) {
        DWCi_NdFree(gDwcNdState.param);
        gDwcNdState.param = 0;
        return 0;
    }
    OS_CreateThread(gDwcNdState.param->thread, DWCi_SVLTokenWaitThread, 0,
                  gDwcNdState.param->stack + sizeof(gDwcNdState.param->stack), 0x800, 0x10);
    OS_WakeupThreadDirect(gDwcNdState.param->thread);
    return 1;
}

/*
 * sdk:      DWC_NdProcess (libdwcnd.TWL.HYB.a dwc_nd.o)
 */
void DWC_NdProcess(void)
{
    int needCallback = 0;
    int needCleanUpCallback = 0;
    int reason;

    OS_LockMutex(gDwcNdMutex);
    reason = gDwcNdState.reason;
    if (reason == 0 && gDwcNdState.state == 4) {
        if (gDwcNdState.errorReported == 0) {
            needCallback = 1;
            gDwcNdState.errorReported = 1;
        }
    } else if ((unsigned int)(gDwcNdState.state - 3) <= 1) {
        needCallback = 1;
        gDwcNdState.state = 1;
    }
    if (reason == 4) {
        gDwcNdState.state = 0;
        gDwcNdState.reason = 0;
        needCleanUpCallback = 1;
    }
    OS_UnlockMutex(gDwcNdMutex);
    if (gDwcNdState.callback == 0)
        return;
    if (needCleanUpCallback) {
        gDwcNdState.callback(4, 0, -1);
    } else if (needCallback) {
        gDwcNdState.callback(gDwcNdState.reason, gDwcNdState.error, gDwcNdState.serverError);
    }
}

int DWC_NdCleanupAsync(void)
{
    if (gDwcNdState.state == 0)
        return 0;
    OS_LockMutex(gDwcNdMutex);
    if (gDwcNdState.state == 0) {
        OS_UnlockMutex(gDwcNdMutex);
        return 0;
    }
    gDwcNdState.state = 2;
    OS_UnlockMutex(gDwcNdMutex);
    if (gDwcNdState.param->status == 0)
        DWCi_NdCleanupCallback();
    else
        DWCi_NdCleanupAsync(DWCi_NdCleanupCallback);
    return 1;
}

/*
 * sdk:      DWC_NdSetAttr (libdwcnd.TWL.HYB.a dwc_nd.o)
 */
int DWC_NdSetAttr(char *attr1, char *attr2, char *attr3)
{
    if (DWCi_IsError())
        return 0;
    return DWCi_NdSetAttr(attr1, attr2, attr3);
}

/*
 * sdk:      DWC_NdGetFileListAsync (libdwcnd.TWL.HYB.a dwc_nd.o)
 */
int DWC_NdGetFileListAsync(void *fileList, unsigned int offset, unsigned int num)
{
    if (DWCi_IsError())
        return 0;
    OS_LockMutex(gDwcNdMutex);
    if (gDwcNdState.state != 1) {
        DWCi_NdSetError(2, 0);
        OS_UnlockMutex(gDwcNdMutex);
        return 0;
    }
    gDwcNdState.state = 2;
    OS_UnlockMutex(gDwcNdMutex);
    MI_CpuFill8(fileList, 0, num * 0xB0);
    if (DWCi_NdGetFileListAsync(fileList, offset, num))
        return 1;
    OS_LockMutex(gDwcNdMutex);
    gDwcNdState.state = 1;
    OS_UnlockMutex(gDwcNdMutex);
    return 0;
}

/*
 * sdk:      DWC_NdGetFileAsync (libdwcnd.TWL.HYB.a dwc_nd.o)
 */
int DWC_NdGetFileAsync(void *fileInfo, char *buffer, unsigned int size)
{
    if (DWCi_IsError())
        return 0;
    OS_LockMutex(gDwcNdMutex);
    if (gDwcNdState.state != 1) {
        DWCi_NdSetError(2, 0);
        OS_UnlockMutex(gDwcNdMutex);
        return 0;
    }
    gDwcNdState.state = 2;
    OS_UnlockMutex(gDwcNdMutex);
    if (DWCi_NdGetFileAsync(fileInfo, buffer, size, 0))
        return 1;
    OS_LockMutex(gDwcNdMutex);
    gDwcNdState.state = 1;
    OS_UnlockMutex(gDwcNdMutex);
    return 0;
}

/*
 * sdk:      DWC_NdCancelAsync (libdwcnd.TWL.HYB.a dwc_nd.o)
 */
int DWC_NdCancelAsync(void)
{
    if (DWCi_IsError())
        return 0;
    OS_LockMutex(gDwcNdMutex);
    if (gDwcNdState.state != 2) {
        OS_UnlockMutex(gDwcNdMutex);
        return 0;
    }
    OS_UnlockMutex(gDwcNdMutex);
    return DWCi_NdCancelAsync() != 0;
}

int DWC_NdGetProgress(unsigned long *received, unsigned long *contentLength)
{
    if (DWCi_IsError())
        return 0;
    OS_LockMutex(gDwcNdMutex);
    if (gDwcNdState.state != 2) {
        OS_UnlockMutex(gDwcNdMutex);
        return 0;
    }
    OS_UnlockMutex(gDwcNdMutex);
    return DWCi_NdGetProgress(received, contentLength);
}
