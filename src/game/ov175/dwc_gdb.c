/*
 * file:     dwc_gdb.c
 * unit:     yes
 * function: DWC_GdbInitialize, DWC_GdbCancelRequest, DWC_GdbShutdown, DWCi_GdbCleanupRootCAList, DWC_GdbProcess, DWC_GdbGetState, DWC_GdbGetAsyncResult, DWC_GdbCreateRecordAsync, DWC_GdbUpdateRecordAsync, DWC_GdbGetMyRecordsAsync, DWC_GdbGetRecordsAsync, DWCi_GdbPrintf, DWCi_GdbCheckStateForAsyncProcess, DWCi_GdbShutdownGsCore, DWCi_GdbSakeRequestCallback, DWCi_GdbStartupResultToError, DWCi_GdbStartRequestResultToError, DWCi_GdbGetStartRequestErrorCode, DWCi_GdbHandleStartupResult, DWCi_GdbHandleStartRequestResult, DWCi_GdbRequestResultToAsyncResult, DWCi_GdbGetRequestResultErrorCode, DWCi_GdbHandleRequestResult, DWCi_GdbSetAsyncStatus, DWCi_GdbSwitchWork, DWCi_GdbSetUseSSL
 * address:  0x021E10CC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWC game database wrapper (libdwcgdb, object dwc_gdb.o) over the Sake record
 * store. One request runs at a time: the wrapper keeps its state, the kind of
 * request and the caller's output pointers in DWCiGdbEntity, starts the request
 * through the Sake client and turns the Sake result into DWC error codes.
 *
 * symbols:
 *   DWC_GHTTPCleanupRootCAList  0x021BF540  arm ov114
 *   DWC_GHTTPSetRootCAList  0x021BF520  arm ov114
 *   DWC_GetLastError  0x02059E18  arm
 *   DWC_InitGHTTP  0x021BF558  arm ov114
 *   DWC_ProcessGHTTP  0x021BF5B8  arm ov114
 *   DWC_ShutdownGHTTP  0x021BF57C  arm ov114
 *   DWCi_GetLoginTicket  0x0216AAE0  arm ov009
 *   DWCi_IsError  0x02059F38  arm
 *   DWCi_SetError  0x02059F54  arm
 *   OS_SNPrintf  0x02084F80  arm arm9
 *   OS_VSNPrintf  0x02084FA8  arm
 *   sakeStartup  0x021DD1EC  arm  ov175
 *   sakeShutdown  0x021DD250  arm  ov175
 *   sakeSetGame  0x021DD25C  arm  ov175
 *   sakeSetProfile  0x021DD290  arm  ov175
 *   sakeGetStartRequestResult  0x021DD2CC  arm  ov175
 *   sakeCreateRecord  0x021DD358  arm  ov175
 *   sakeUpdateRecord  0x021DD380  arm  ov175
 *   sakeGetMyRecords  0x021DD3A8  arm  ov175
 *   sakeGetSpecificRecords  0x021DD3D0  arm  ov175
 *   sakeSetFileDownloadURL  0x021DD3F8  arm  ov175
 *   sakeGetFileDownloadURL  0x021DD420  arm  ov175
 *   sakeSetFileUploadURL  0x021DD4B0  arm  ov175
 *   sakeGetFileUploadURL  0x021DD4D8  arm  ov175
 *   sakeCancelRequest  0x021DD560  arm  ov175
 *   g_021AE01C  0x021AE01C  data
 *   g_021AE11C  0x021AE11C  data
 *   sDwcGdbProcessNames  0x021E44D4  data
 *   sDwcGdbLoginTicketFailed  0x021E450C  data
 *   sDwcGdbSakeStartupFailed  0x021E452C  data
 *   sDwcGdbNotInAsyncProcess  0x021E4548  data
 *   sDwcGdbCancelGhttp  0x021E4560  data
 *   sDwcGdbIllegalProcess  0x021E457C  data
 *   sDwcGdbNotInitialized  0x021E4594  data
 *   sDwcGdbInAsyncProcess  0x021E45A8  data
 *   sDwcGdbCreateRecordFailed  0x021E45BC  data
 *   sDwcGdbUpdateRecordFailed  0x021E45DC  data
 *   sDwcGdbGetMyRecordsFailed  0x021E45FC  data
 *   sDwcGdbGetSpecificRecordsFailed  0x021E461C  data
 *   sDwcGdbPrintfPrefix  0x021E4640  data
 *   sDwcGdbInDwcError  0x021E464C  data
 *   sDwcGdbInCancelProcess  0x021E4660  data
 *   sDwcGdbCreateRecordDoneFormat  0x021E4674  data
 *   sDwcGdbDeleteRecordDoneFormat  0x021E46A0  data
 *   sDwcGdbUpdateRecordDoneFormat  0x021E46BC  data
 *   sDwcGdbRecordNumFormat  0x021E46E8  data
 *   sDwcGdbGetRecordLimitDoneFormat  0x021E4700  data
 *   sDwcGdbRateRecordDoneFormat  0x021E472C  data
 *   sDwcGdbOneRecordFormat  0x021E4754  data
 *   sDwcGdbNoRecordFormat  0x021E4768  data
 *   sDwcGdbGetRecordCountDoneFormat  0x021E477C  data
 *   sDwcGdbCanceledFormat  0x021E478C  data
 *   sDwcGdbFailedFormat  0x021E47A0  data
 *   sDwcGdbErrorFormat  0x021E47B0  data
 *   sDwcGdbAsyncResultFormat  0x021E47C4  data
 *   sDwcGdbStorageUrlFormatSecure2  0x021E47DC  data
 *   sDwcGdbUploadUrlFormatSecure2  0x021E4830  data
 *   sDwcGdbDownloadUrlFormatSecure2  0x021E4878  data
 *   sDwcGdbStorageUrlFormatSecure  0x021E48C4  data
 *   sDwcGdbUploadUrlFormatSecure  0x021E4914  data
 *   sDwcGdbDownloadUrlFormatSecure  0x021E495C  data
 *   gDwcGdbStorageServerUrl  0x021E4C88  data
 *   gDwcGdbEntity  0x021E5334  data
 *   ghttpCancelRequest  0x021C22A4  arm ov114
 *   ghttpGetState  0x021C22D4  arm ov114
 *   gsCoreInitialize  0x0217CA40  arm ov009
 *   gsCoreIsShutdown  0x0217CE1C  arm ov009
 *   gsCoreShutdown  0x0217CD94  arm ov009
 *   gsCoreThink  0x0217CCCC  arm ov009
 */
#include "gdb_types.h"

#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
typedef char *va_list;

extern int DWCi_GetLoginTicket(char *loginTicket);
extern void DWCi_SetError(int error, int errorCode);
extern int DWCi_IsError(void);
extern int DWC_GetLastError(int *errorCode);
extern void gsCoreInitialize(void);
extern void gsCoreThink(unsigned int theMS);
extern void gsCoreShutdown(void);
extern int gsCoreIsShutdown(void);
extern int DWC_InitGHTTP(void *theParam);
extern int DWC_ShutdownGHTTP(void);
extern int DWC_ProcessGHTTP(void);
extern int DWC_GHTTPSetRootCAList(const char *url);
extern int DWC_GHTTPCleanupRootCAList(const char *url);
extern int ghttpGetState(int request);
extern void ghttpCancelRequest(int request);
extern int OS_SNPrintf(char *dst, unsigned long len, const char *fmt, ...);
extern int OS_VSNPrintf(char *dst, unsigned int len, char *format, void *vlist);

extern int sakeStartup(SAKEInternal **sakePtr);
extern void sakeShutdown(SAKEInternal *sake);
extern void sakeSetGame(SAKEInternal *sake, const char *gameName, int gameId, const char *secretKey);
extern void sakeSetProfile(SAKEInternal *sake, int profileId, const char *loginTicket);
extern int sakeGetStartRequestResult(SAKEInternal *sake);
extern SAKERequestInternal *sakeCreateRecord(SAKEInternal *sake, void *input, SAKERequestCallback callback, void *userData);
extern SAKERequestInternal *sakeUpdateRecord(SAKEInternal *sake, void *input, SAKERequestCallback callback, void *userData);
extern SAKERequestInternal *sakeGetMyRecords(SAKEInternal *sake, void *input, SAKERequestCallback callback, void *userData);
extern SAKERequestInternal *sakeGetSpecificRecords(SAKEInternal *sake, void *input, SAKERequestCallback callback, void *userData);
extern int sakeSetFileDownloadURL(SAKEInternal *sake, const char *url);
extern int sakeGetFileDownloadURL(SAKEInternal *sake, int fileId, char *url);
extern int sakeSetFileUploadURL(SAKEInternal *sake, const char *url);
extern int sakeGetFileUploadURL(SAKEInternal *sake, char *url);
extern int sakeCancelRequest(SAKEInternal *sake, SAKERequestInternal *request);

int DWC_GdbInitialize(int game_id, DWCstAccUserData *userdata, int ssl_type);
int DWC_GdbCancelRequest(void);
int DWC_GdbShutdown(void);
void DWCi_GdbCleanupRootCAList(void);
void DWC_GdbProcess(void);
int DWC_GdbGetState(void);
int DWC_GdbGetAsyncResult(void);
int DWC_GdbCreateRecordAsync(char *gdb_name, SAKEField *fields, int field_num, int *record_id);
int DWC_GdbUpdateRecordAsync(char *gdb_name, int record_id, SAKEField *fields, int field_num);
int DWC_GdbGetMyRecordsAsync(char *gdb_name, char **field_names, int field_num, DWCGdbGetRecordsCallback callback,
                  void *user_param);
int DWC_GdbGetRecordsAsync(char *gdb_name, int *record_ids, int record_num, char **field_names, int field_num,
                  DWCGdbGetRecordsCallback callback, void *user_param);
void DWCi_GdbPrintf(int line, char *fmt, ...);
int DWCi_GdbCheckStateForAsyncProcess(int *result);
void DWCi_GdbShutdownGsCore(void);
void DWCi_GdbSakeRequestCallback(SAKEInternal *sake, SAKERequestInternal *request, int result, void *inputData,
                   void *outputData, void *userData);
int DWCi_GdbStartupResultToError(int startupResult, int *dwcError);
int DWCi_GdbStartRequestResultToError(int startRequestResult, int *dwcError);
int DWCi_GdbGetStartRequestErrorCode(int source, int error);
int DWCi_GdbHandleStartupResult(int startupResult);
int DWCi_GdbHandleStartRequestResult(int source, int startRequestResult);
int DWCi_GdbRequestResultToAsyncResult(int requestResult, int *dwcError);
int DWCi_GdbGetRequestResultErrorCode(int process, int asyncResult);
int DWCi_GdbHandleRequestResult(int process, int requestResult);
void DWCi_GdbSetAsyncStatus(unsigned int process);
void DWCi_GdbSwitchWork(void);
void DWCi_GdbSetUseSSL(int ssl_type);

extern DWCiGdbEntity gDwcGdbEntity;
extern char sDwcGdbLoginTicketFailed[];
extern char sDwcGdbSakeStartupFailed[];
extern char g_021AE01C[];
extern char g_021AE11C[];
extern char sDwcGdbNotInAsyncProcess[];
extern char sDwcGdbCancelGhttp[];
extern char sDwcGdbIllegalProcess[];
extern char sDwcGdbNotInitialized[];
extern char sDwcGdbInAsyncProcess[];
extern char gDwcGdbStorageServerUrl[];
extern char sDwcGdbCreateRecordFailed[];
extern char sDwcGdbUpdateRecordFailed[];
extern char sDwcGdbGetMyRecordsFailed[];
extern char sDwcGdbGetSpecificRecordsFailed[];
extern char sDwcGdbPrintfPrefix[];
extern char sDwcGdbInDwcError[];
extern char sDwcGdbInCancelProcess[];
extern char *sDwcGdbProcessNames[];
extern char sDwcGdbCreateRecordDoneFormat[];
extern char sDwcGdbDeleteRecordDoneFormat[];
extern char sDwcGdbUpdateRecordDoneFormat[];
extern char sDwcGdbRecordNumFormat[];
extern char sDwcGdbGetRecordLimitDoneFormat[];
extern char sDwcGdbRateRecordDoneFormat[];
extern char sDwcGdbOneRecordFormat[];
extern char sDwcGdbNoRecordFormat[];
extern char sDwcGdbGetRecordCountDoneFormat[];
extern char sDwcGdbCanceledFormat[];
extern char sDwcGdbFailedFormat[];
extern char sDwcGdbErrorFormat[];
extern char sDwcGdbAsyncResultFormat[];
extern char sDwcGdbStorageUrlFormatSecure2[];
extern char sDwcGdbUploadUrlFormatSecure2[];
extern char sDwcGdbDownloadUrlFormatSecure2[];
extern char sDwcGdbStorageUrlFormatSecure[];
extern char sDwcGdbUploadUrlFormatSecure[];
extern char sDwcGdbDownloadUrlFormatSecure[];

/*
 * DWC_GdbInitialize: starts the Sake client for the game with the account's
 * GameSpy profile and login ticket, sets the server URLs and starts GHTTP.
 */
int DWC_GdbInitialize(int game_id, DWCstAccUserData *userdata, int ssl_type)
{
    char loginTicket[25];
    int result;

    if (gDwcGdbEntity.state != DWC_GDB_STATE_NOT_INITIALIZED)
        return DWC_GDB_ERROR_ALREADY_INITIALIZED;
    if (!DWCi_GetLoginTicket(loginTicket)) {
        DWCi_GdbPrintf(0x11A, sDwcGdbLoginTicketFailed);
        DWCi_SetError(8, DWCi_GdbGetStartRequestErrorCode(1, DWC_GDB_ERROR_LOGIN_TICKET));
        return DWC_GDB_ERROR_LOGIN_TICKET;
    }
    gsCoreInitialize();
    result = sakeStartup(&gDwcGdbEntity.sake);
    if (result != 0) {
        DWCi_GdbPrintf(0x127, sDwcGdbSakeStartupFailed, result);
        DWCi_GdbShutdownGsCore();
        return DWCi_GdbHandleStartupResult(result);
    }
    sakeSetGame(gDwcGdbEntity.sake, g_021AE01C, game_id, g_021AE11C);
    sakeSetProfile(gDwcGdbEntity.sake, userdata->gs_profile_id, loginTicket);
    DWCi_GdbSetUseSSL(ssl_type);
    DWC_InitGHTTP(0);
    gDwcGdbEntity.state = DWC_GDB_STATE_IDLE;
    gDwcGdbEntity.result = 0;
    gDwcGdbEntity.process = DWC_GDB_PROCESS_NONE;
    gDwcGdbEntity.currentWork = 0;
    return DWC_GDB_ERROR_NONE;
}

/*
 * DWC_GdbCancelRequest: asks the running request to stop.  The result arrives
 * through the Sake callback with the canceled code.
 *
 * Every Sake process has its own case: with the cases merged the compiler
 * builds a different switch tree.
 */
int DWC_GdbCancelRequest(void)
{
    if (gDwcGdbEntity.state != DWC_GDB_STATE_IN_ASYNC_PROCESS) {
        DWCi_GdbPrintf(0x14F, sDwcGdbNotInAsyncProcess);
        return DWC_GDB_ERROR_ILLEGAL;
    }
    gDwcGdbEntity.state = DWC_GDB_STATE_IN_CANCEL_PROCESS;
    switch (gDwcGdbEntity.process) {
    case DWC_GDB_PROCESS_CREATE_RECORD:
        sakeCancelRequest(gDwcGdbEntity.sake, gDwcGdbEntity.work[gDwcGdbEntity.currentWork].sake.request);
        break;
    case DWC_GDB_PROCESS_DELETE_RECORD:
        sakeCancelRequest(gDwcGdbEntity.sake, gDwcGdbEntity.work[gDwcGdbEntity.currentWork].sake.request);
        break;
    case DWC_GDB_PROCESS_UPDATE_RECORD:
        sakeCancelRequest(gDwcGdbEntity.sake, gDwcGdbEntity.work[gDwcGdbEntity.currentWork].sake.request);
        break;
    case DWC_GDB_PROCESS_GET_MY_RECORDS:
        sakeCancelRequest(gDwcGdbEntity.sake, gDwcGdbEntity.work[gDwcGdbEntity.currentWork].sake.request);
        break;
    case DWC_GDB_PROCESS_GET_RECORD_LIMIT:
        sakeCancelRequest(gDwcGdbEntity.sake, gDwcGdbEntity.work[gDwcGdbEntity.currentWork].sake.request);
        break;
    case DWC_GDB_PROCESS_GET_RECORDS:
        sakeCancelRequest(gDwcGdbEntity.sake, gDwcGdbEntity.work[gDwcGdbEntity.currentWork].sake.request);
        break;
    case DWC_GDB_PROCESS_RATE_RECORD:
        sakeCancelRequest(gDwcGdbEntity.sake, gDwcGdbEntity.work[gDwcGdbEntity.currentWork].sake.request);
        break;
    case DWC_GDB_PROCESS_SEARCH_RECORDS:
        sakeCancelRequest(gDwcGdbEntity.sake, gDwcGdbEntity.work[gDwcGdbEntity.currentWork].sake.request);
        break;
    case DWC_GDB_PROCESS_GET_RANDOM_RECORD:
        sakeCancelRequest(gDwcGdbEntity.sake, gDwcGdbEntity.work[gDwcGdbEntity.currentWork].sake.request);
        break;
    case DWC_GDB_PROCESS_GET_RECORD_COUNT:
        sakeCancelRequest(gDwcGdbEntity.sake, gDwcGdbEntity.work[gDwcGdbEntity.currentWork].sake.request);
        break;
    case DWC_GDB_PROCESS_DOWNLOAD_FILE:
        DWCi_GdbPrintf(0x181, sDwcGdbCancelGhttp, ghttpGetState(gDwcGdbEntity.work[gDwcGdbEntity.currentWork].downloadFile.ghttpRequest));
        ghttpCancelRequest(gDwcGdbEntity.work[gDwcGdbEntity.currentWork].downloadFile.ghttpRequest);
        break;
    case DWC_GDB_PROCESS_UPLOAD_FILE:
        /* The cast through a pointer keeps the element address and the field offset apart (mla, then ldr). */
        DWCi_GdbPrintf(0x188, sDwcGdbCancelGhttp, ghttpGetState(((DWCiGdbWork *)gDwcGdbEntity.work)[gDwcGdbEntity.currentWork].uploadFile.ghttpRequest));
        ghttpCancelRequest(((DWCiGdbWork *)gDwcGdbEntity.work)[gDwcGdbEntity.currentWork].uploadFile.ghttpRequest);
        break;
    default:
        DWCi_GdbPrintf(0x18F, sDwcGdbIllegalProcess, gDwcGdbEntity.process);
        break;
    }
    return DWC_GDB_ERROR_NONE;
}

/* DWC_GdbShutdown: drops the root CA lists, stops GHTTP and the Sake client and shuts the core down. */
int DWC_GdbShutdown(void)
{
    if (gDwcGdbEntity.state == DWC_GDB_STATE_NOT_INITIALIZED) {
        DWCi_GdbPrintf(0x1a6, sDwcGdbNotInitialized);
        return DWC_GDB_ERROR_NOT_INITIALIZED;
    }
    if (gDwcGdbEntity.state == DWC_GDB_STATE_IN_ASYNC_PROCESS) {
        DWCi_GdbPrintf(0x1ab, sDwcGdbInAsyncProcess);
        return DWC_GDB_ERROR_IN_ASYNC_PROCESS;
    }
    DWCi_GdbCleanupRootCAList();
    gDwcGdbEntity.state = DWC_GDB_STATE_NOT_INITIALIZED;
    DWC_ShutdownGHTTP();
    sakeShutdown(gDwcGdbEntity.sake);
    DWCi_GdbShutdownGsCore();
    return DWC_GDB_ERROR_NONE;
}

/* DWCi_GdbCleanupRootCAList: releases the root CA lists of the storage, upload and download server URLs. */
void DWCi_GdbCleanupRootCAList(void)
{
    char upload_url[128];
    char download_url[128];

    DWC_GHTTPCleanupRootCAList(gDwcGdbStorageServerUrl);
    sakeGetFileUploadURL(gDwcGdbEntity.sake, upload_url);
    DWC_GHTTPCleanupRootCAList(upload_url);
    sakeGetFileDownloadURL(gDwcGdbEntity.sake, 1, download_url);
    DWC_GHTTPCleanupRootCAList(download_url);
}

/* DWC_GdbProcess: runs the GameSpy core unless it is shut down, then GHTTP. */
void DWC_GdbProcess(void)
{
    if (gsCoreIsShutdown() != 2)
        gsCoreThink(0);
    DWC_ProcessGHTTP();
}

/* DWC_GdbGetState: the state, or the error state when DWC is in an error. */
int DWC_GdbGetState(void)
{
    if (DWCi_IsError())
        return DWC_GDB_STATE_ERROR;
    return gDwcGdbEntity.state;
}

/* DWC_GdbGetAsyncResult: the result of the last request. */
int DWC_GdbGetAsyncResult(void)
{
    return gDwcGdbEntity.result;
}

/* DWC_GdbCreateRecordAsync: starts a CreateRecord request; the record id is written when it finishes. */
int DWC_GdbCreateRecordAsync(char *gdb_name, SAKEField *fields, int field_num, int *record_id)
{
    int result;
    SAKERequestInternal *request;
    DWCiGdbWork *work;

    if (DWCi_GdbCheckStateForAsyncProcess(&result) != 0) {
        return result;
    }
    DWCi_GdbSwitchWork();
    work = &gDwcGdbEntity.work[gDwcGdbEntity.currentWork];
    work->createRecord.input.mTableId = gdb_name;
    work->createRecord.input.mFields = fields;
    work->createRecord.input.mNumFields = field_num;
    work->createRecord.recordIdOut = record_id;
    request = sakeCreateRecord(gDwcGdbEntity.sake, &work->createRecord.input, DWCi_GdbSakeRequestCallback, 0);
    if (request == 0) {
        int sake_result = sakeGetStartRequestResult(gDwcGdbEntity.sake);
        DWCi_GdbPrintf(0x22f, sDwcGdbCreateRecordFailed, sake_result);
        return DWCi_GdbHandleStartRequestResult(DWC_GDB_PROCESS_CREATE_RECORD, sake_result);
    }
    gDwcGdbEntity.work[gDwcGdbEntity.currentWork].sake.request = request;
    DWCi_GdbSetAsyncStatus(DWC_GDB_PROCESS_CREATE_RECORD);
    return DWC_GDB_ERROR_NONE;
}

/* DWC_GdbUpdateRecordAsync: starts an UpdateRecord request. */
int DWC_GdbUpdateRecordAsync(char *gdb_name, int record_id, SAKEField *fields, int field_num)
{
    int result;
    SAKERequestInternal *request;
    DWCiGdbWork *work;

    if (DWCi_GdbCheckStateForAsyncProcess(&result) != 0) {
        return result;
    }
    DWCi_GdbSwitchWork();
    work = &gDwcGdbEntity.work[gDwcGdbEntity.currentWork];
    work->updateRecord.input.mTableId = gdb_name;
    work->updateRecord.input.mRecordId = record_id;
    work->updateRecord.input.mFields = fields;
    work->updateRecord.input.mNumFields = field_num;
    request = sakeUpdateRecord(gDwcGdbEntity.sake, &work->updateRecord.input, DWCi_GdbSakeRequestCallback, 0);
    if (request == 0) {
        int sake_result = sakeGetStartRequestResult(gDwcGdbEntity.sake);
        DWCi_GdbPrintf(0x29c, sDwcGdbUpdateRecordFailed, sake_result);
        return DWCi_GdbHandleStartRequestResult(DWC_GDB_PROCESS_UPDATE_RECORD, sake_result);
    }
    gDwcGdbEntity.work[gDwcGdbEntity.currentWork].sake.request = request;
    DWCi_GdbSetAsyncStatus(DWC_GDB_PROCESS_UPDATE_RECORD);
    return DWC_GDB_ERROR_NONE;
}

/* DWC_GdbGetMyRecordsAsync: starts a GetMyRecords request; the callback gets the records. */
int DWC_GdbGetMyRecordsAsync(char *gdb_name, char **field_names, int field_num, DWCGdbGetRecordsCallback callback,
                  void *user_param)
{
    int result;
    SAKERequestInternal *request;
    DWCiGdbWork *work;

    if (DWCi_GdbCheckStateForAsyncProcess(&result) != 0) {
        return result;
    }
    DWCi_GdbSwitchWork();
    work = &gDwcGdbEntity.work[gDwcGdbEntity.currentWork];
    work->getMyRecords.input.mTableId = gdb_name;
    work->getMyRecords.input.mFieldNames = field_names;
    work->getMyRecords.input.mNumFields = field_num;
    work->getMyRecords.callback = callback;
    request = sakeGetMyRecords(gDwcGdbEntity.sake, &work->getMyRecords.input, DWCi_GdbSakeRequestCallback, user_param);
    if (request == 0) {
        int sake_result = sakeGetStartRequestResult(gDwcGdbEntity.sake);
        DWCi_GdbPrintf(0x35b, sDwcGdbGetMyRecordsFailed, sake_result);
        return DWCi_GdbHandleStartRequestResult(DWC_GDB_PROCESS_GET_MY_RECORDS, sake_result);
    }
    gDwcGdbEntity.work[gDwcGdbEntity.currentWork].sake.request = request;
    DWCi_GdbSetAsyncStatus(DWC_GDB_PROCESS_GET_MY_RECORDS);
    return DWC_GDB_ERROR_NONE;
}

/* DWC_GdbGetRecordsAsync: starts a GetSpecificRecords request for the given record ids. */
int DWC_GdbGetRecordsAsync(char *gdb_name, int *record_ids, int record_num, char **field_names, int field_num,
                  DWCGdbGetRecordsCallback callback, void *user_param)
{
    int result;
    SAKERequestInternal *request;
    DWCiGdbWork *work;

    if (DWCi_GdbCheckStateForAsyncProcess(&result) != 0) {
        return result;
    }
    DWCi_GdbSwitchWork();
    work = &gDwcGdbEntity.work[gDwcGdbEntity.currentWork];
    work->getRecords.input.mTableId = gdb_name;
    work->getRecords.input.mRecordIds = record_ids;
    work->getRecords.input.mNumRecordIds = record_num;
    work->getRecords.input.mFieldNames = field_names;
    work->getRecords.input.mNumFields = field_num;
    work->getRecords.callback = callback;
    request = sakeGetSpecificRecords(gDwcGdbEntity.sake, &work->getRecords.input, DWCi_GdbSakeRequestCallback, user_param);
    if (request == 0) {
        int sake_result = sakeGetStartRequestResult(gDwcGdbEntity.sake);
        DWCi_GdbPrintf(0x3ca, sDwcGdbGetSpecificRecordsFailed, sake_result);
        return DWCi_GdbHandleStartRequestResult(DWC_GDB_PROCESS_GET_RECORDS, sake_result);
    }
    gDwcGdbEntity.work[gDwcGdbEntity.currentWork].sake.request = request;
    DWCi_GdbSetAsyncStatus(DWC_GDB_PROCESS_GET_RECORDS);
    return DWC_GDB_ERROR_NONE;
}

/* DWCi_GdbPrintf: debug print with the "Gdb[line]> " prefix; the output goes into a local buffer only. */
void DWCi_GdbPrintf(int line, char *fmt, ...)
{
    char str_buf[256];
    int str_len;
    va_list args;

    str_len = OS_SNPrintf(str_buf, 256, sDwcGdbPrintfPrefix, line);
    va_start(args, fmt);
    OS_VSNPrintf(str_buf + str_len, 256 - str_len, fmt, args);
}

/* DWCi_GdbCheckStateForAsyncProcess: nonzero, with the error in *result, when a new request cannot start now. */
int DWCi_GdbCheckStateForAsyncProcess(int *result)
{
    if (DWCi_IsError()) {
        DWCi_GdbPrintf(0x568, sDwcGdbInDwcError, DWC_GetLastError(0));
        if (result != 0) {
            *result = DWC_GDB_ERROR_IN_DWC_ERROR;
        }
        return 1;
    }
    switch (gDwcGdbEntity.state) {
    case DWC_GDB_STATE_NOT_INITIALIZED:
        DWCi_GdbPrintf(0x570, sDwcGdbNotInitialized);
        if (result != 0) {
            *result = DWC_GDB_ERROR_NOT_INITIALIZED;
        }
        return 1;
    case DWC_GDB_STATE_IN_ASYNC_PROCESS:
        DWCi_GdbPrintf(0x575, sDwcGdbInAsyncProcess);
        if (result != 0) {
            *result = DWC_GDB_ERROR_IN_ASYNC_PROCESS;
        }
        return 1;
    case DWC_GDB_STATE_IN_CANCEL_PROCESS:
        DWCi_GdbPrintf(0x57a, sDwcGdbInCancelProcess);
        if (result != 0) {
            *result = DWC_GDB_ERROR_IN_CANCEL_PROCESS;
        }
        return 1;
    }
    return 0;
}

/* DWCi_GdbShutdownGsCore: shuts the GameSpy core down and runs it until it is stopped. */
void DWCi_GdbShutdownGsCore(void)
{
    gsCoreShutdown();
    gsCoreThink(0);
    if (gsCoreIsShutdown() != 2)
        gsCoreThink(0);
}

/*
 * DWCi_GdbSakeRequestCallback: Sake callback of every request.  Stores the
 * result, returns to the idle state and hands the output to the caller (the
 * record id, the limits, the count or the callback).
 */
void DWCi_GdbSakeRequestCallback(SAKEInternal *sake, SAKERequestInternal *request, int result, void *inputData,
                   void *outputData, void *userData)
{
    DWCGdbProcess process = gDwcGdbEntity.process;

    if (gDwcGdbEntity.state != DWC_GDB_STATE_IN_ASYNC_PROCESS && gDwcGdbEntity.state != DWC_GDB_STATE_IN_CANCEL_PROCESS)
        return;
    if (result == 0) {
        gDwcGdbEntity.result = DWC_GDB_ASYNC_RESULT_SUCCESS;
        gDwcGdbEntity.state = DWC_GDB_STATE_IDLE;
        gDwcGdbEntity.process = DWC_GDB_PROCESS_NONE;
        switch (process) {
        case DWC_GDB_PROCESS_CREATE_RECORD: {
            DWCiGdbWork *work = &gDwcGdbEntity.work[gDwcGdbEntity.currentWork];

            *work->createRecord.recordIdOut = ((SAKECreateRecordOutput *)outputData)->mRecordId;
            DWCi_GdbPrintf(0x5af, sDwcGdbCreateRecordDoneFormat, sDwcGdbProcessNames[process], work->createRecord.input.mTableId,
                          work->createRecord.input.mNumFields, *work->createRecord.recordIdOut);
            break;
        }
        case DWC_GDB_PROCESS_DELETE_RECORD: {
            DWCiGdbWork *work = &gDwcGdbEntity.work[gDwcGdbEntity.currentWork];

            DWCi_GdbPrintf(0x5b8, sDwcGdbDeleteRecordDoneFormat, sDwcGdbProcessNames[process], work->deleteRecord.input.mTableId,
                          work->deleteRecord.input.mRecordId);
            break;
        }
        case DWC_GDB_PROCESS_UPDATE_RECORD: {
            DWCiGdbWork *work = &gDwcGdbEntity.work[gDwcGdbEntity.currentWork];

            DWCi_GdbPrintf(0x5c2, sDwcGdbUpdateRecordDoneFormat, sDwcGdbProcessNames[process], work->updateRecord.input.mTableId,
                          work->updateRecord.input.mRecordId, work->updateRecord.input.mNumFields);
            break;
        }
        case DWC_GDB_PROCESS_GET_MY_RECORDS: {
            DWCiGdbWork *work = &gDwcGdbEntity.work[gDwcGdbEntity.currentWork];
            SAKERecordsOutput *output = outputData;

            DWCi_GdbPrintf(0x5cb, sDwcGdbRecordNumFormat, sDwcGdbProcessNames[process], output->mNumRecords);
            work->getMyRecords.callback(output->mNumRecords, output->mRecords, userData);
            break;
        }
        case DWC_GDB_PROCESS_GET_RECORD_LIMIT: {
            DWCiGdbWork *work = &gDwcGdbEntity.work[gDwcGdbEntity.currentWork];
            DWCiGdbRecordLimitOutput *output = outputData;

            *work->getRecordLimit.limitNumOut = output->mLimitNum;
            *work->getRecordLimit.ownedNumOut = output->mOwnedNum;
            DWCi_GdbPrintf(0x5d8, sDwcGdbGetRecordLimitDoneFormat, sDwcGdbProcessNames[process], work->getRecordLimit.mTableId,
                          *work->getRecordLimit.limitNumOut, *work->getRecordLimit.ownedNumOut);
            break;
        }
        case DWC_GDB_PROCESS_GET_RECORDS: {
            DWCiGdbWork *work = &gDwcGdbEntity.work[gDwcGdbEntity.currentWork];
            SAKERecordsOutput *output = outputData;

            DWCi_GdbPrintf(0x5e1, sDwcGdbRecordNumFormat, sDwcGdbProcessNames[process], output->mNumRecords);
            work->getRecords.callback(output->mNumRecords, output->mRecords, userData);
            break;
        }
        case DWC_GDB_PROCESS_RATE_RECORD: {
            DWCiGdbWork *work = &gDwcGdbEntity.work[gDwcGdbEntity.currentWork];

            DWCi_GdbPrintf(0x5ec, sDwcGdbRateRecordDoneFormat, sDwcGdbProcessNames[process], work->rateRecord.mTableId,
                          work->rateRecord.mRecordId, work->rateRecord.mRating);
            break;
        }
        case DWC_GDB_PROCESS_SEARCH_RECORDS: {
            DWCiGdbWork *work = &gDwcGdbEntity.work[gDwcGdbEntity.currentWork];
            SAKERecordsOutput *output = outputData;

            DWCi_GdbPrintf(0x5f5, sDwcGdbRecordNumFormat, sDwcGdbProcessNames[process], output->mNumRecords);
            work->searchRecords.callback(output->mNumRecords, output->mRecords, userData);
            break;
        }
        case DWC_GDB_PROCESS_GET_RANDOM_RECORD: {
            DWCiGdbWork *work = &gDwcGdbEntity.work[gDwcGdbEntity.currentWork];
            SAKEGetRandomRecordOutput *output = outputData;

            if (output->mRecord != 0) {
                DWCi_GdbPrintf(0x5ff, sDwcGdbOneRecordFormat, sDwcGdbProcessNames[process]);
                work->getRandomRecord.callback(1, &output->mRecord, userData);
            } else {
                DWCi_GdbPrintf(0x604, sDwcGdbNoRecordFormat, sDwcGdbProcessNames[process]);
                work->getRandomRecord.callback(0, 0, userData);
            }
            break;
        }
        case DWC_GDB_PROCESS_GET_RECORD_COUNT: {
            DWCiGdbWork *work = &gDwcGdbEntity.work[gDwcGdbEntity.currentWork];

            *work->getRecordCount.countOut = ((DWCiGdbRecordCountOutput *)outputData)->mCount;
            DWCi_GdbPrintf(0x60d, sDwcGdbGetRecordCountDoneFormat, sDwcGdbProcessNames[process], *work->getRecordCount.countOut);
            break;
        }
        default:
            DWCi_GdbPrintf(0x613, sDwcGdbIllegalProcess, process);
            break;
        }
    } else if (result == SAKERequestResult_REQUEST_CANCELLED) {
        DWCi_GdbPrintf(0x61a, sDwcGdbCanceledFormat, sDwcGdbProcessNames[gDwcGdbEntity.process], result);
        gDwcGdbEntity.result = DWC_GDB_ASYNC_RESULT_CANCELED;
        gDwcGdbEntity.state = DWC_GDB_STATE_IDLE;
        gDwcGdbEntity.process = DWC_GDB_PROCESS_NONE;
    } else {
        DWCi_GdbPrintf(0x621, sDwcGdbFailedFormat, sDwcGdbProcessNames[gDwcGdbEntity.process], result);
        gDwcGdbEntity.result = DWCi_GdbHandleRequestResult(gDwcGdbEntity.process, result);
        gDwcGdbEntity.state = DWC_GDB_STATE_IDLE;
        gDwcGdbEntity.process = DWC_GDB_PROCESS_NONE;
    }
}

/*
 * DWCi_GdbStartupResultToError: ARM jump-table selector over the Sake startup
 * result (0 success, 1 not available, 2 core shutdown, 3 out of memory); the
 * DWC error class goes to *dwcError.
 */
int DWCi_GdbStartupResultToError(int startupResult, int *dwcError)
{
    switch (startupResult) {
    case 0:
        *dwcError = 0;
        return DWC_GDB_ERROR_NONE;
    case 1:
        *dwcError = 8;
        return DWC_GDB_ERROR_NOT_AVAILABLE;
    case 2:
        *dwcError = 8;
        return DWC_GDB_ERROR_CORE_SHUTDOWN;
    case 3:
        *dwcError = 9;
        return DWC_GDB_ERROR_OUT_OF_MEMORY;
    }
    return DWC_GDB_ERROR_ILLEGAL;
}

/*
 * DWCi_GdbStartRequestResultToError: translates a SAKEStartRequestResult; the
 * DWC error class is parked at 0x13 up front, success clears it and out of
 * memory sets 9.
 */
int DWCi_GdbStartRequestResultToError(int startRequestResult, int *dwcError)
{
    *dwcError = 0x13;
    switch (startRequestResult) {
    case SAKEStartRequestResult_SUCCESS:
        *dwcError = 0;
        return DWC_GDB_ERROR_NONE;
    case SAKEStartRequestResult_NOT_AUTHENTICATED:
        return DWC_GDB_ERROR_NOT_AUTHENTICATED;
    case SAKEStartRequestResult_OUT_OF_MEMORY:
        *dwcError = 9;
        return DWC_GDB_ERROR_OUT_OF_MEMORY;
    case SAKEStartRequestResult_BAD_INPUT:
        return DWC_GDB_ERROR_BAD_INPUT;
    case SAKEStartRequestResult_BAD_TABLEID:
        return DWC_GDB_ERROR_BAD_TABLE_ID;
    case SAKEStartRequestResult_BAD_FIELDS:
        return DWC_GDB_ERROR_BAD_FIELDS;
    case SAKEStartRequestResult_NO_FIELDS:
        return DWC_GDB_ERROR_NO_FIELDS;
    case SAKEStartRequestResult_BAD_FIELD_NAME:
        return DWC_GDB_ERROR_BAD_FIELD_NAME;
    case SAKEStartRequestResult_BAD_FIELD_TYPE:
        return DWC_GDB_ERROR_BAD_FIELD_TYPE;
    case SAKEStartRequestResult_BAD_FIELD_VALUE:
        return DWC_GDB_ERROR_BAD_FIELD_VALUE;
    case SAKEStartRequestResult_BAD_OFFSET:
        return DWC_GDB_ERROR_BAD_OFFSET;
    case SAKEStartRequestResult_BAD_MAX:
        return DWC_GDB_ERROR_BAD_MAX;
    case SAKEStartRequestResult_BAD_RECORDIDS:
        return DWC_GDB_ERROR_BAD_RECORD_IDS;
    case SAKEStartRequestResult_BAD_NUM_RECORDIDS:
        return DWC_GDB_ERROR_BAD_NUM_RECORD_IDS;
    case 14:
        return DWC_GDB_ERROR_ILLEGAL;
    default:
        return DWC_GDB_ERROR_ILLEGAL;
    }
}

/* DWCi_GdbGetStartRequestErrorCode: the DWC error code -40000 - (source * 100 + error). */
int DWCi_GdbGetStartRequestErrorCode(int source, int error)
{
    return -40000 - (source * 100 + error);
}

/* DWCi_GdbHandleStartupResult: logs and posts the DWC error for a failed Sake startup. */
int DWCi_GdbHandleStartupResult(int startupResult)
{
    int dwcError;
    int error = DWCi_GdbStartupResultToError(startupResult, &dwcError);

    if (error != 0) {
        DWCi_GdbPrintf(0x6db, sDwcGdbErrorFormat, error);
        DWCi_SetError(dwcError, DWCi_GdbGetStartRequestErrorCode(1, error));
    }
    return error;
}

/* DWCi_GdbHandleStartRequestResult: logs and posts the DWC error for a request that did not start. */
int DWCi_GdbHandleStartRequestResult(int source, int startRequestResult)
{
    int dwcError;
    int error = DWCi_GdbStartRequestResultToError(startRequestResult, &dwcError);

    if (error != 0) {
        DWCi_GdbPrintf(0x6ec, sDwcGdbErrorFormat, error);
        DWCi_SetError(dwcError, DWCi_GdbGetStartRequestErrorCode(source, error));
    }
    return error;
}

/*
 * DWCi_GdbRequestResultToAsyncResult: translates a SAKERequestResult into a
 * DWCGdbAsyncResult.  The DWC error class is parked at 0x13 up front; success
 * clears it and out of memory sets 9.  Result 23 is written before 22, and the
 * default repeats the code of 22 in its own block, as in the image.
 */
int DWCi_GdbRequestResultToAsyncResult(int requestResult, int *dwcError)
{
    *dwcError = 0x13;
    switch (requestResult) {
    case SAKERequestResult_SUCCESS:
        *dwcError = 0;
        return DWC_GDB_ASYNC_RESULT_SUCCESS;
    case SAKERequestResult_SECRET_KEY_INVALID:
        return DWC_GDB_ASYNC_RESULT_SECRET_KEY_INVALID;
    case SAKERequestResult_SERVICE_DISABLED:
        return DWC_GDB_ASYNC_RESULT_SERVICE_DISABLED;
    case SAKERequestResult_CONNECTION_TIMEOUT:
        return DWC_GDB_ASYNC_RESULT_CONNECTION_TIMEOUT;
    case SAKERequestResult_CONNECTION_ERROR:
        return DWC_GDB_ASYNC_RESULT_CONNECTION_ERROR;
    case SAKERequestResult_MALFORMED_RESPONSE:
        return DWC_GDB_ASYNC_RESULT_MALFORMED_RESPONSE;
    case SAKERequestResult_OUT_OF_MEMORY:
        *dwcError = 9;
        return DWC_GDB_ASYNC_RESULT_OUT_OF_MEMORY;
    case SAKERequestResult_DATABASE_UNAVAILABLE:
        return DWC_GDB_ASYNC_RESULT_DATABASE_UNAVAILABLE;
    case SAKERequestResult_LOGIN_TICKET_INVALID:
        return DWC_GDB_ASYNC_RESULT_LOGIN_TICKET_INVALID;
    case SAKERequestResult_LOGIN_TICKET_EXPIRED:
        return DWC_GDB_ASYNC_RESULT_LOGIN_TICKET_EXPIRED;
    case SAKERequestResult_TABLE_NOT_FOUND:
        return DWC_GDB_ASYNC_RESULT_TABLE_NOT_FOUND;
    case SAKERequestResult_RECORD_NOT_FOUND:
        return DWC_GDB_ASYNC_RESULT_RECORD_NOT_FOUND;
    case SAKERequestResult_FIELD_NOT_FOUND:
        return DWC_GDB_ASYNC_RESULT_FIELD_NOT_FOUND;
    case SAKERequestResult_FIELD_TYPE_INVALID:
        return DWC_GDB_ASYNC_RESULT_FIELD_TYPE_INVALID;
    case SAKERequestResult_NO_PERMISSION:
        return DWC_GDB_ASYNC_RESULT_NO_PERMISSION;
    case SAKERequestResult_RECORD_LIMIT_REACHED:
        return DWC_GDB_ASYNC_RESULT_RECORD_LIMIT_REACHED;
    case SAKERequestResult_ALREADY_RATED:
        return DWC_GDB_ASYNC_RESULT_ALREADY_RATED;
    case SAKERequestResult_NOT_RATEABLE:
        return DWC_GDB_ASYNC_RESULT_NOT_RATEABLE;
    case SAKERequestResult_NOT_OWNED:
        return DWC_GDB_ASYNC_RESULT_NOT_OWNED;
    case SAKERequestResult_FILTER_INVALID:
        return DWC_GDB_ASYNC_RESULT_FILTER_INVALID;
    case SAKERequestResult_SORT_INVALID:
        return DWC_GDB_ASYNC_RESULT_SORT_INVALID;
    case SAKERequestResult_TARGET_FILTER_INVALID:
        return DWC_GDB_ASYNC_RESULT_TARGET_FILTER_INVALID;
    case SAKERequestResult_REQUEST_CANCELLED:
        return DWC_GDB_ASYNC_RESULT_CANCELED;
    case SAKERequestResult_UNKNOWN_ERROR:
        return DWC_GDB_ASYNC_RESULT_UNKNOWN_ERROR;
    default:
        return DWC_GDB_ASYNC_RESULT_UNKNOWN_ERROR;
    }
}

/*
 * DWCi_GdbGetRequestResultErrorCode: the DWC error code
 * -40000 - (process * 100 + asyncResult + 50).
 */
int DWCi_GdbGetRequestResultErrorCode(int process, int asyncResult)
{
    return -40000 - (process * 100 + asyncResult + 50);
}

/* DWCi_GdbHandleRequestResult: translates a failed request result, logs it and posts the DWC error. */
int DWCi_GdbHandleRequestResult(int process, int requestResult)
{
    int error_code;
    int dwc_error;
    int retval;

    retval = DWCi_GdbRequestResultToAsyncResult(requestResult, &dwc_error);
    if (retval != DWC_GDB_ASYNC_RESULT_SUCCESS) {
        DWCi_GdbPrintf(0x75b, sDwcGdbAsyncResultFormat, retval);
        error_code = DWCi_GdbGetRequestResultErrorCode(process, retval);
        DWCi_SetError(dwc_error, error_code);
    }
    return retval;
}

/* DWCi_GdbSetAsyncStatus: enters the async state for the given kind of request, with no result yet. */
void DWCi_GdbSetAsyncStatus(unsigned int process)
{
    gDwcGdbEntity.state = DWC_GDB_STATE_IN_ASYNC_PROCESS;
    gDwcGdbEntity.process = process;
    gDwcGdbEntity.result = 0;
}

/* DWCi_GdbSwitchWork: flips to the other work slot. */
void DWCi_GdbSwitchWork(void)
{
    if (gDwcGdbEntity.currentWork == 0)
        gDwcGdbEntity.currentWork = 1;
    else
        gDwcGdbEntity.currentWork = 0;
}

/*
 * DWCi_GdbSetUseSSL: builds the storage, upload and download server URLs for
 * the wanted server set and registers their root CA lists.  The default is the
 * secure server; 1 selects the secure2 server.  The storage URL is kept in
 * data; the Sake client keeps copies of the file URLs.
 */
void DWCi_GdbSetUseSSL(int ssl_type)
{
    char upload_url[128];
    char download_url[128];

    switch (ssl_type) {
    case 1:
        OS_SNPrintf(gDwcGdbStorageServerUrl, 128, sDwcGdbStorageUrlFormatSecure2, g_021AE01C);
        DWC_GHTTPSetRootCAList(gDwcGdbStorageServerUrl);
        OS_SNPrintf(upload_url, 128, sDwcGdbUploadUrlFormatSecure2, g_021AE01C);
        DWC_GHTTPSetRootCAList(upload_url);
        OS_SNPrintf(download_url, 128, sDwcGdbDownloadUrlFormatSecure2, g_021AE01C);
        DWC_GHTTPSetRootCAList(download_url);
        break;
    case 0:
    default:
        OS_SNPrintf(gDwcGdbStorageServerUrl, 128, sDwcGdbStorageUrlFormatSecure, g_021AE01C);
        DWC_GHTTPSetRootCAList(gDwcGdbStorageServerUrl);
        OS_SNPrintf(upload_url, 128, sDwcGdbUploadUrlFormatSecure, g_021AE01C);
        DWC_GHTTPSetRootCAList(upload_url);
        OS_SNPrintf(download_url, 128, sDwcGdbDownloadUrlFormatSecure, g_021AE01C);
        DWC_GHTTPSetRootCAList(download_url);
        break;
    }
    sakeSetFileUploadURL(gDwcGdbEntity.sake, upload_url);
    sakeSetFileDownloadURL(gDwcGdbEntity.sake, download_url);
}
