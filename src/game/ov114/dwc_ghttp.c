/*
 * file:     dwc_ghttp.c
 * unit:     yes
 * function: func_021BF520, DWC_GHTTPCleanupRootCAList, DWC_InitGHTTP, DWC_ShutdownGHTTP, DWC_ProcessGHTTP, GHTTPCompletedCallback, GHTTPProgressCallback, DWC_GetGHTTPDataEx, DWCi_GHTTPGetEx, DWC_CancelGHTTPRequest, DWCi_HandleGHTTPError, DWCi_AppendDWCGHTTPParam, DWCi_RemoveDWCGHTTPParamEntry, DWCi_FindDWCGHTTPParamEntryByReq, DWCi_RemoveAllDWCGHTTPParamEntry
 * address:  0x021BF520
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
 *   ghttpSetRootCAList  0x021C2344  arm  ov114
 *   ghttpCleanupRootCAList  0x021C2350  arm  ov114
 *   gDwcGhttpParamList  0x021D3B20  data
 *   ghttpStartup  0x021C1FF8  arm  ov114
 *   ghttpCleanup  0x021C204C  arm  ov114
 *   DWCi_RemoveAllDWCGHTTPParamEntry  0x021BFB20  arm  ov114
 *   ghttpThink  0x021C2270  arm  ov114
 *   DWCi_HandleGHTTPError  0x021BF8C0  arm  ov114
 *   DWC_Free       0x0205A1B0  arm
 *   DWCi_RemoveDWCGHTTPParamEntry  0x021BFA70  arm  ov114
 *   DWCi_GHTTPGetEx  0x021BF6EC  arm  ov114
 *   func_02059F54  0x02059F54  arm
 *   func_0205A16C  0x0205A16C  arm
 *   DWC_Alloc   0x0205A16C  arm
 *   func_0205A1B0  0x0205A1B0  arm
 *   ghttpGetExA  0x021C20A4  arm  ov114
 *   ghttpSetMaxRecvTime  0x021C22EC  arm  ov114
 *   ghttpCancelRequest  0x021C22A4  arm  ov114
 *   gDwcGhttpParamList    0x021D3B20  data  ov114
 *   sDwcGhttpRootCaList  0x021CE544  data
 *   DWCi_IsError  0x02059F38  arm  arm9
 */
#include "ghttp_types.h"
#include "dwc_ghttp_types.h"

extern int ghttpSetRootCAList(char *url, void *rootCAList);
extern int ghttpCleanupRootCAList(char *url);
extern void ghttpStartup(void);
extern void ghttpCleanup(void);
extern int DWCi_IsError(void);
extern void ghttpThink(void);
extern void DWCi_RemoveAllDWCGHTTPParamEntry(void);
extern void DWC_Free(int name, void *ptr, int size);
extern void ghttpCancelRequest(int request);
extern void ghttpSetMaxRecvTime(int request, unsigned int maxRecvTime);
extern void func_02059F54(int error, int errorCode);
extern void *DWC_Alloc(int name, unsigned long size);
extern int ghttpGetExA(const char *url, const char *headers, char *buffer, int bufferSize,
                         GHIPost *post, int throttle, int blocking,
                         GHTTPProgressCallbackFn progressCallback,
                         GHTTPCompletedCallbackFn completedCallback, void *param);

int func_021BF520(char *url);
int DWC_GHTTPCleanupRootCAList(char *url);
int DWC_InitGHTTP(void);
int DWC_ShutdownGHTTP(void);
int DWC_ProcessGHTTP(void);
int GHTTPCompletedCallback(int request, int result, char *buffer, int bufferLen, void *param);
void GHTTPProgressCallback(int request, int state, const char *buffer, int bufferLen, int bytesReceived, int totalSize, void *param);
int DWC_GetGHTTPDataEx(char *url, int bufferLen, int bufferClear, DWCGHTTPProgressCallback progressCallback, DWCGHTTPCompletedCallback completedCallback, void *param);
int DWCi_GHTTPGetEx(char *url, int bufferLen, int bufferClear, GHIPost **post, DWCGHTTPProgressCallback progressCallback, DWCGHTTPCompletedCallback completedCallback, void *param);
void DWC_CancelGHTTPRequest(int request);
int DWCi_HandleGHTTPError(int result);
DWCGHTTPParamEntry *DWCi_AppendDWCGHTTPParam(DWCGHTTPParam *param);
void DWCi_RemoveDWCGHTTPParamEntry(DWCGHTTPParamEntry *entry);
DWCGHTTPParamEntry *DWCi_FindDWCGHTTPParamEntryByReq(u32 request);

extern char sDwcGhttpRootCaList[];

/*
 * Sets the root CA list of `url` to the built-in table and reports whether exactly one entry was set.
 */
int func_021BF520(char *url)
{
    return ghttpSetRootCAList(url, sDwcGhttpRootCaList) == 1;
}

/*
 * Clears the root CA list of `url` and reports whether exactly one entry was removed.
 */
int DWC_GHTTPCleanupRootCAList(char *url)
{
    return ghttpCleanupRootCAList(url) == 1;
}

/*
 * Starts the ghttp client and counts one more user of it.
 */
int DWC_InitGHTTP(void)
{
    ghttpStartup();
    gDwcGhttpParamList.initCount++;
    return 1;
}

/*
 * sdk:      DWC_ShutdownGHTTP (dwc_ghttp.o)
 */
int DWC_ShutdownGHTTP(void)
{
    if (gDwcGhttpParamList.initCount <= 0) {
        return 1;
    }
    ghttpCleanup();
    if (--gDwcGhttpParamList.initCount == 0) {
        DWCi_RemoveAllDWCGHTTPParamEntry();
    }
    return 1;
}

int DWC_ProcessGHTTP(void)
{
    if (DWCi_IsError() != 0)
        return 0;
    ghttpThink();
    return 1;
}

/*
 * sdk:      GHTTPCompletedCallback (dwc_ghttp.o)
 */
int GHTTPCompletedCallback(int request, int result, char *buffer, int bufferLen, void *param)
{
    DWCGHTTPParamEntry *entry;
    DWCGHTTPCompletedCallback callback;
    int bufferClear;

    entry = param;
    callback = entry->param.completedCallback;
    bufferClear = entry->param.bufferClear;
    if (callback != 0) {
        if (result == 0) {
            callback(buffer, bufferLen, result, entry->param.param);
        } else if (result == 0x12) {
            callback(0, 0, result, entry->param.param);
        } else {
            DWCi_HandleGHTTPError(result);
            callback(0, 0, result, entry->param.param);
        }
    }
    if (result != 0 || bufferClear == 1) {
        if (entry == 0 || entry->buffer == 0) {
            bufferClear = 1;
        } else {
            DWC_Free(6, entry->buffer, 0);
        }
    }
    DWCi_RemoveDWCGHTTPParamEntry(entry);
    return bufferClear != 0;
}

/*
 * Progress callback handed to ghttp: forwards to the user callback stored in the entry.
 */
void GHTTPProgressCallback(int request, int state, const char *buffer, int bufferLen, int bytesReceived, int totalSize, void *param)
{
    DWCGHTTPParamEntry *entry = param;
    DWCGHTTPProgressCallback callback = entry->param.progressCallback;

    if (callback == 0) {
        return;
    }
    callback(state, buffer, bufferLen, bytesReceived, totalSize, entry->param.param);
}

/*
 * GetEx without a post body.
 */
int DWC_GetGHTTPDataEx(char *url, int bufferLen, int bufferClear, DWCGHTTPProgressCallback progressCallback, DWCGHTTPCompletedCallback completedCallback, void *param)
{
    return DWCi_GHTTPGetEx(url, bufferLen, bufferClear, 0, progressCallback, completedCallback, param);
}

/*
 * Starts a ghttp GET (or POST) request with a heap buffer of bufferLen bytes; returns the
 * request id or a negative error after reporting it through the completion callback.
 *
 * sdk:      DWCi_GHTTPGetEx (libdwcghttp.TWL.HYB.a(dwc_ghttp.o))
 */
int DWCi_GHTTPGetEx(char *url, int bufferLen, int bufferClear, GHIPost **post,
                  DWCGHTTPProgressCallback progressCallback, DWCGHTTPCompletedCallback completedCallback, void *param)
{
    char *buffer = 0;
    int request;
    DWCGHTTPParamEntry *entry;
    DWCGHTTPParam paramInstance;

    if (DWCi_IsError())
        return -1;
    paramInstance.param = param;
    paramInstance.completedCallback = completedCallback;
    paramInstance.progressCallback = progressCallback;
    paramInstance.bufferClear = bufferClear;
    entry = DWCi_AppendDWCGHTTPParam(&paramInstance);
    if (entry == 0) {
        DWCi_HandleGHTTPError(-5);
        completedCallback(0, 0, -5, param);
        return -5;
    }
    if (bufferLen > 0) {
        buffer = DWC_Alloc(6, bufferLen);
        if (buffer == 0) {
            DWCi_HandleGHTTPError(-5);
            completedCallback(0, 0, -5, param);
            DWCi_RemoveDWCGHTTPParamEntry(entry);
            return -5;
        }
        entry->buffer = buffer;
    }
    request = ghttpGetExA(url, 0, buffer, bufferLen, post == 0 ? 0 : *post, 0, 0,
                            progressCallback == 0 ? 0 : GHTTPProgressCallback, GHTTPCompletedCallback, entry);
    if (request < 0) {
        DWCi_HandleGHTTPError(request);
        completedCallback(0, 0, request, param);
        if (entry->buffer != 0)
            DWC_Free(6, entry->buffer, 0);
        DWCi_RemoveDWCGHTTPParamEntry(entry);
    }
    entry->request = request;
    ghttpSetMaxRecvTime(request, 1);
    return request;
}

/*
 * sdk:      DWC_CancelGHTTPRequest (dwc_ghttp.o)
 */
void DWC_CancelGHTTPRequest(int request)
{
    DWCGHTTPParamEntry *entry;

    ghttpCancelRequest(request);
    entry = DWCi_FindDWCGHTTPParamEntryByReq(request);
    if (entry == 0) {
        return;
    }
    if (entry->buffer != 0) {
        DWC_Free(6, entry->buffer, 0);
    }
    DWCi_RemoveDWCGHTTPParamEntry(entry);
}

/*
 * sdk:      DWCi_HandleGHTTPError (libdwcghttp.TWL.HYB.a(dwc_ghttp.o))
 */
int DWCi_HandleGHTTPError(int result)
{
    int errorCode;
    int dwcError;

    dwcError = 7;
    errorCode = -98000;
    if (result == 0)
        return 0;
    switch (result) {
    case -7:
        errorCode += -800;
        break;
    case -6:
        errorCode += -810;
        break;
    case -5:
        errorCode += -840;
        break;
    case -4:
    case -3:
    case -2:
        errorCode += -820;
        break;
    case -1:
        errorCode += -830;
        break;
    case 1:
    case 20:
        dwcError = 9;
        errorCode += -1;
        break;
    case 2:
        errorCode += -840;
        break;
    case 3:
        errorCode += -850;
        break;
    case 4:
        errorCode += -30;
        break;
    case 5:
        errorCode += -50;
        break;
    case 6:
    case 11:
    case 12:
        errorCode += -20;
        break;
    case 7:
        errorCode += -860;
        break;
    case 8:
    case 9:
    case 10:
        errorCode += -870;
        break;
    case 13:
    case 14:
        errorCode += -880;
        break;
    case 15:
        errorCode += -890;
        break;
    case 16:
        errorCode += -900;
        break;
    case 17:
        errorCode += -910;
        break;
    }
    func_02059F54(dwcError, errorCode);
    return result;
}

/*
 * Allocates a list entry for a copy of `param` and pushes it on the list head.
 */
DWCGHTTPParamEntry *DWCi_AppendDWCGHTTPParam(DWCGHTTPParam *param)
{
    DWCGHTTPParamEntry *entry;

    entry = DWC_Alloc(6, 0x20);
    if (entry == 0) {
        return 0;
    }
    entry->param = *param;
    entry->next = 0;
    entry->buffer = 0;
    if (gDwcGhttpParamList.head == 0) {
        gDwcGhttpParamList.head = entry;
        return entry;
    }
    entry->next = gDwcGhttpParamList.head;
    gDwcGhttpParamList.head = entry;
    return entry;
}

/*
 * Singly linked list removal.  The if/else with a lone `prev = cur` arm is
 * deliberate: it makes armcc if-convert that assignment to `movne` and
 * branch over the found arm, which is the only shape that reproduces the
 * original loop.  See
 * docs/idioms/a-lone-move-arm-if-converts-to-movne.md
 */
void DWCi_RemoveDWCGHTTPParamEntry(DWCGHTTPParamEntry *entry)
{
    DWCGHTTPParamEntry *prev = gDwcGhttpParamList.head;
    DWCGHTTPParamEntry *cur;
    if (prev == 0)
        return;
    if (prev == entry) {
        DWCGHTTPParamEntry *next = prev->next;
        DWC_Free(6, prev, 0);
        gDwcGhttpParamList.head = next;
        return;
    }
    cur = prev->next;
    if (cur == 0)
        return;
    for (;;) {
        if (cur != entry) {
            prev = cur;
        } else {
            DWCGHTTPParamEntry *found = prev->next;
            prev->next = found->next;
            DWC_Free(6, found, 0);
            return;
        }
        cur = cur->next;
        if (cur == 0)
            return;
    }
}

/*
 * Linear search of the list for the entry of `request`; NULL when absent.  The compound
 * condition and the named list pointer leave the single shared test block at 0x021bfb00
 * with the entry jumping to it; the list address is not folded into the pool word.
 */
DWCGHTTPParamEntry *DWCi_FindDWCGHTTPParamEntryByReq(u32 request)
{
    DWCGHTTPParamList *list = &gDwcGhttpParamList;
    DWCGHTTPParamEntry *entry = list->head;

    while (entry != 0 && (u32)entry->request != request)
        entry = entry->next;
    return entry;
}

/*
 * sdk:      DWCi_RemoveAllDWCGHTTPParamEntry (dwc_ghttp.o)
 */
void DWCi_RemoveAllDWCGHTTPParamEntry(void)
{
    DWCGHTTPParamEntry *cursor;
    DWCGHTTPParamEntry *target;

    cursor = gDwcGhttpParamList.head;
    while (cursor != 0) {
        target = cursor;
        cursor = cursor->next;
        if (target->buffer != 0) {
            DWC_Free(6, target->buffer, 0);
        }
        DWC_Free(6, target, 0);
    }
    gDwcGhttpParamList.head = 0;
}
