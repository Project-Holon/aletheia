/*
 * file:     sakemain.c
 * unit:     yes
 * function: sakeStartup, sakeShutdown, sakeSetGame, sakeSetProfile, sakeGetStartRequestResult, sakeiRunRequest, sakeiCancelRequest, sakeCreateRecord, sakeUpdateRecord, sakeGetMyRecords, sakeGetSpecificRecords, sakeSetFileDownloadURL, sakeGetFileDownloadURL, sakeSetFileUploadURL, sakeGetFileUploadURL, sakeCancelRequest
 * address:  0x021DD1EC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * GameSpy Sake client (libdwcgssake, object sakemain.o): startup and shutdown,
 * game and profile setup, the public request entry points and the file
 * server URLs.
 *
 * symbols:
 *   OS_SNPrintf  0x02084F80  arm arm9
 *   gsCoreIsShutdown  0x0217CE1C  arm ov009
 *   gsiCoreCancelTask  0x0217CECC  arm ov009
 *   gsifree  0x0217EAE0  arm ov009
 *   gsimalloc  0x0217EAB0  arm ov009
 *   memset  0x020923B0  arm
 *   sakeiInitRequest  0x021DD56C  arm
 *   sakeiFreeRequest  0x021DD604  arm
 *   sakeiStartCreateRecordRequest  0x021DE024  arm
 *   sakeiStartUpdateRecordRequest  0x021DE0D4  arm
 *   sakeiStartGetMyRecordsRequest  0x021DEBE0  arm
 *   sakeiStartGetSpecificRecordsRequest  0x021DECE8  arm
 *   sFileDownloadUrlFormatOverride  0x021E363C  data
 *   sFileDownloadUrlFormatDefault  0x021E365C  data
 *   sFileUploadUrlFormatOverride  0x021E36B0  data
 *   sFileUploadUrlFormatDefault  0x021E36C4  data
 *   sFileDownloadUrlOverride  0x021E4B88  data
 *   sFileUploadUrlOverride  0x021E4C08  data
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "sake_types.h"

struct GSTask;

typedef enum SAKEStartupResult {
    SAKEStartupResult_SUCCESS = 0,
    SAKEStartupResult_NOT_AVAILABLE = 1,
    SAKEStartupResult_CORE_SHUTDOWN = 2,
    SAKEStartupResult_OUT_OF_MEMORY = 3
} SAKEStartupResult;

typedef enum SAKERequestType {
    SAKERequestType_CREATE_RECORD = 0,
    SAKERequestType_UPDATE_RECORD = 1,
    SAKERequestType_GET_MY_RECORDS = 4,
    SAKERequestType_GET_SPECIFIC_RECORDS = 5
} SAKERequestType;

extern int g_021ACEF8;
extern int gsCoreIsShutdown(void);
extern void *gsimalloc(unsigned long size);
extern void gsifree(void *ptr);
extern char *func_02094798(char *dst, const char *src);
extern int OS_SNPrintf(char *dst, unsigned long len, const char *fmt, ...);
extern void gsiCoreCancelTask(struct GSTask *theTask);
extern SAKERequestInternal *sakeiInitRequest(SAKEInternal *sake, int type, void *input, SAKERequestCallback callback, void *userData);
extern void sakeiFreeRequest(SAKERequestInternal *request);
extern int sakeiStartCreateRecordRequest(SAKERequestInternal *request);
extern int sakeiStartUpdateRecordRequest(SAKERequestInternal *request);
extern int sakeiStartGetMyRecordsRequest(SAKERequestInternal *request);
extern int sakeiStartGetSpecificRecordsRequest(SAKERequestInternal *request);
int sakeStartup(SAKEInternal **sakePtr);
void sakeShutdown(SAKEInternal *sake);
void sakeSetGame(SAKEInternal *sake, const char *gameName, int gameId, const char *secretKey);
void sakeSetProfile(SAKEInternal *sake, int profileId, const char *loginTicket);
int sakeGetStartRequestResult(SAKEInternal *sake);
SAKERequestInternal *sakeiRunRequest(SAKEInternal *sake, void *input, SAKERequestCallback callback, void *userData, int type, int (*startRequestFunc)(SAKERequestInternal *));
int sakeiCancelRequest(SAKEInternal *sake, SAKERequestInternal *request);
SAKERequestInternal *sakeCreateRecord(SAKEInternal *sake, void *input, SAKERequestCallback callback, void *userData);
SAKERequestInternal *sakeUpdateRecord(SAKEInternal *sake, void *input, SAKERequestCallback callback, void *userData);
SAKERequestInternal *sakeGetMyRecords(SAKEInternal *sake, void *input, SAKERequestCallback callback, void *userData);
SAKERequestInternal *sakeGetSpecificRecords(SAKEInternal *sake, void *input, SAKERequestCallback callback, void *userData);
int sakeSetFileDownloadURL(SAKEInternal *sake, const char *url);
int sakeGetFileDownloadURL(SAKEInternal *sake, int fileId, char *url);
int sakeSetFileUploadURL(SAKEInternal *sake, const char *url);
int sakeGetFileUploadURL(SAKEInternal *sake, char *url);
int sakeCancelRequest(SAKEInternal *sake, SAKERequestInternal *request);
extern char sFileDownloadUrlOverride[128];
extern char sFileUploadUrlOverride[128];
extern char sFileDownloadUrlFormatOverride[];
extern char sFileDownloadUrlFormatDefault[];
extern char sFileUploadUrlFormatOverride[];
extern char sFileUploadUrlFormatDefault[];

int sakeStartup(SAKEInternal **sakePtr)
{
    SAKEInternal *sake;

    if (g_021ACEF8 != 1)
        return SAKEStartupResult_NOT_AVAILABLE;
    if (gsCoreIsShutdown())
        return SAKEStartupResult_CORE_SHUTDOWN;
    sake = (SAKEInternal *)gsimalloc(sizeof(SAKEInternal));
    if (!sake)
        return SAKEStartupResult_OUT_OF_MEMORY;
    memset(sake, 0, sizeof(SAKEInternal));
    *sakePtr = sake;
    return SAKEStartupResult_SUCCESS;
}

void sakeShutdown(SAKEInternal *sake)
{
    gsifree(sake);
}

void sakeSetGame(SAKEInternal *sake, const char *gameName, int gameId, const char *secretKey)
{
    func_02094798(sake->mGameName, gameName);
    func_02094798(sake->mSecretKey, secretKey);
    sake->mGameId = gameId;
    sake->mStartedUp = 1;
}

/*
 * The 25-byte ticket copy is memcpy through string.h (a struct assignment
 * loads the byte pair in the converse order).  The ticket parameter is
 * const char * (DWARF: char *); with plain char * the copy compiles 4 bytes
 * longer.
 */
void sakeSetProfile(SAKEInternal *sake, int profileId, const char *loginTicket)
{
    sake->mProfileId = profileId;
    memcpy(sake->mLoginTicket, loginTicket, 25);
    sake->mProfileSet = 1;
}

int sakeGetStartRequestResult(SAKEInternal *sake)
{
    return sake->mStartRequestResult;
}

/*
 * Create the request, then let the request kind validate its input
 * (startRequestFunc); a failed start frees the request again and leaves the
 * reason in mStartRequestResult.
 */
SAKERequestInternal *sakeiRunRequest(SAKEInternal *sake, void *input, SAKERequestCallback callback, void *userData, int type, int (*startRequestFunc)(SAKERequestInternal *))
{
    SAKERequestInternal *request;

    request = sakeiInitRequest(sake, type, input, callback, userData);
    if (!request)
        return 0;
    sake->mStartRequestResult = startRequestFunc(request);
    if (sake->mStartRequestResult != 0) {
        sakeiFreeRequest(request);
        return 0;
    }
    return request;
}

/*
 * Returns 3 unless the sake object, the request, its info table and the SOAP
 * task handle in that table are all non-null; otherwise cancels the task and
 * returns 0.  One predicated cmpne chain, so the whole test is a single
 * short-circuit expression.
 */
int sakeiCancelRequest(SAKEInternal *sake, SAKERequestInternal *request)
{
    struct GSTask *task;

    if (sake && request && request->mInfo
        && (task = request->mInfo->mSoapTask) != 0) {
        gsiCoreCancelTask(task);
        return 0;
    }
    return 3;
}

SAKERequestInternal *sakeCreateRecord(SAKEInternal *sake, void *input, SAKERequestCallback callback, void *userData)
{
    return sakeiRunRequest(sake, input, callback, userData, SAKERequestType_CREATE_RECORD, sakeiStartCreateRecordRequest);
}

SAKERequestInternal *sakeUpdateRecord(SAKEInternal *sake, void *input, SAKERequestCallback callback, void *userData)
{
    return sakeiRunRequest(sake, input, callback, userData, SAKERequestType_UPDATE_RECORD, sakeiStartUpdateRecordRequest);
}

SAKERequestInternal *sakeGetMyRecords(SAKEInternal *sake, void *input, SAKERequestCallback callback, void *userData)
{
    return sakeiRunRequest(sake, input, callback, userData, SAKERequestType_GET_MY_RECORDS, sakeiStartGetMyRecordsRequest);
}

SAKERequestInternal *sakeGetSpecificRecords(SAKEInternal *sake, void *input, SAKERequestCallback callback, void *userData)
{
    return sakeiRunRequest(sake, input, callback, userData, SAKERequestType_GET_SPECIFIC_RECORDS, sakeiStartGetSpecificRecordsRequest);
}

/* Overrides the file download URL used by sakeGetFileDownloadURL (empty: default server). */
int sakeSetFileDownloadURL(SAKEInternal *sake, const char *url)
{
    if (sake == 0 || url == 0)
        return 0;
    func_02094798(sFileDownloadUrlOverride, url);
    return 1;
}

int sakeGetFileDownloadURL(SAKEInternal *sake, int fileId, char *url)
{
    int rcode;

    if (!sake || !url || !sake->mStartedUp || !sake->mProfileSet)
        return 0;
    if (sFileDownloadUrlOverride[0])
        rcode = OS_SNPrintf(url, 128, sFileDownloadUrlFormatOverride, sFileDownloadUrlOverride, fileId, sake->mGameId, sake->mProfileId);
    else
        rcode = OS_SNPrintf(url, 128, sFileDownloadUrlFormatDefault, sake->mGameName, fileId, sake->mGameId, sake->mProfileId);
    if (rcode < 0)
        return 0;
    return 1;
}

/* Overrides the file upload URL used by sakeGetFileUploadURL (empty: default server). */
int sakeSetFileUploadURL(SAKEInternal *sake, const char *url)
{
    if (sake == 0 || url == 0)
        return 0;
    func_02094798(sFileUploadUrlOverride, url);
    return 1;
}

int sakeGetFileUploadURL(SAKEInternal *sake, char *url)
{
    int rcode;

    if (!sake || !url || !sake->mStartedUp || !sake->mProfileSet)
        return 0;
    if (sFileUploadUrlOverride[0])
        rcode = OS_SNPrintf(url, 128, sFileUploadUrlFormatOverride, sFileUploadUrlOverride, sake->mGameId, sake->mProfileId);
    else
        rcode = OS_SNPrintf(url, 128, sFileUploadUrlFormatDefault, sake->mGameName, sake->mGameId, sake->mProfileId);
    if (rcode < 0)
        return 0;
    return 1;
}

int sakeCancelRequest(SAKEInternal *sake, SAKERequestInternal *request)
{
    return sakeiCancelRequest(sake, request);
}
