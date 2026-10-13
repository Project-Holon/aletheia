/*
 * file:     sakerequest.c
 * unit:     yes
 * function: sakeiInitRequest, sakeiFreeRequest, sakeiCheckHttpResult, sakeiCheckSakeResult, sakeiSoapCallback, sakeiSetupRequest, sakeiExecuteRequest, sakeiStartRequest
 * address:  0x021DD56C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * GameSpy Sake client (libdwcgssake, object sakerequest.o): generic request
 * handling shared by every request kind.  A request is created from the sake
 * state (sakeiInitRequest), gets its SAKERequestInfo table (sakeiStartRequest), builds
 * the SOAP envelope (sakeiSetupRequest), is sent (sakeiExecuteRequest) and finishes in
 * sakeiSoapCallback, which maps the HTTP and Sake results, lets the kind parse the
 * response, calls the user callback and frees the request.
 *
 * symbols:
 *   OS_SNPrintf  0x02084F80  arm arm9
 *   gsXmlCloseWriter  0x02181DE8  arm ov009
 *   gsXmlCreateStreamWriter  0x021819B0  arm ov009
 *   gsXmlFreeWriter  0x02181D84  arm ov009
 *   gsXmlMoveToNext  0x021834E8  arm ov009
 *   gsXmlMoveToStart  0x021834D0  arm ov009
 *   gsXmlReadChildAsStringNT  0x0218372C  arm ov009
 *   gsXmlWriteCloseTag  0x02182A2C  arm ov009
 *   gsXmlWriteIntElement  0x02182CF0  arm ov009
 *   gsXmlWriteOpenTag  0x021829AC  arm ov009
 *   gsXmlWriteStringElement  0x02182AC0  arm ov009
 *   gsiExecuteSoap  0x0217FD7C  arm ov009
 *   gsifree  0x0217EAE0  arm ov009
 *   gsimalloc  0x0217EAB0  arm ov009
 *   memset  0x020923B0  arm
 *   strcmp  0x020948E0  arm
 *   sResultSuccess  0x021E3730  data
 *   sResultSecretKeyInvalid  0x021E3738  data
 *   sResultServiceDisabled  0x021E374C  data
 *   sResultDatabaseUnavailable  0x021E375C  data
 *   sResultLoginTicketInvalid  0x021E3770  data
 *   sResultLoginTicketExpired  0x021E3784  data
 *   sResultTableNotFound  0x021E3798  data
 *   sResultRecordNotFound  0x021E37A8  data
 *   sResultFieldNotFound  0x021E37B8  data
 *   sResultFieldTypeInvalid  0x021E37C8  data
 *   sResultNoPermission  0x021E37DC  data
 *   sResultRecordLimitReached  0x021E37EC  data
 *   sResultAlreadyRated  0x021E3800  data
 *   sResultNotRateable  0x021E3810  data
 *   sResultNotOwned  0x021E381C  data
 *   sResultFilterInvalid  0x021E3828  data
 *   sResultSortInvalid  0x021E3838  data
 *   sResultTargetFilterInvalid  0x021E3844  data
 *   sSoapNamespaces  0x021E370C  data
 *   sXmlNamespacePrefix  0x021E3858  data
 *   sTagGameid  0x021E385C  data
 *   sTagSecretKey  0x021E3864  data
 *   sTagLoginTicket  0x021E3870  data
 *   sServerUrlFormat  0x021E387C  data
 *   gDwcGdbStorageServerUrl  0x021E4C88  data
 */
#include "sake_types.h"

struct GSTask;

/* Only the field this file reads: the core task handle at +0x24. */
typedef struct GSSoapTask {
    unsigned char pad0[0x24];
    struct GSTask *coreTask;
} GSSoapTask;

typedef void (*GSSoapCallback)(int httpResult, void *requestData, void *responseData, void *userData);

extern void *gsimalloc(unsigned long size);
extern void gsifree(void *ptr);
extern void *memset(void *dst, int val, unsigned long n);
extern int strcmp(const char *a, const char *b);
extern int OS_SNPrintf(char *dst, unsigned long len, const char *fmt, ...);
extern int gsXmlMoveToStart(void *stream);
extern int gsXmlMoveToNext(void *stream, char *matchtag);
extern int gsXmlReadChildAsStringNT(void *stream, char *matchtag, char *valueOut, int maxLen);
extern void *gsXmlCreateStreamWriter(const char **namespaces, int count);
extern int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteIntElement(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int gsXmlWriteStringElement(void *stream, char *namespaceName, char *tag, char *value);
extern void gsXmlFreeWriter(void *stream);
extern int gsXmlCloseWriter(void *stream);
extern GSSoapTask *gsiExecuteSoap(char *url, char *service, void *soap, GSSoapCallback callback, void *userData);

SAKERequestInternal *sakeiInitRequest(SAKEInternal *sake, int type, void *input, SAKERequestCallback callback, void *userData);
void sakeiFreeRequest(SAKERequestInternal *request);
int sakeiCheckHttpResult(int httpResult);
int sakeiCheckSakeResult(const char *resultString);
void sakeiSoapCallback(int httpResult, void *requestData, void *responseData, void *userData);
int sakeiSetupRequest(SAKERequestInternal *request);
void sakeiExecuteRequest(SAKERequestInternal *request);
int sakeiStartRequest(SAKERequestInternal *request, SAKERequestInfo *info);

extern char sResultSuccess[];
extern char sResultSecretKeyInvalid[];
extern char sResultServiceDisabled[];
extern char sResultDatabaseUnavailable[];
extern char sResultLoginTicketInvalid[];
extern char sResultLoginTicketExpired[];
extern char sResultTableNotFound[];
extern char sResultRecordNotFound[];
extern char sResultFieldNotFound[];
extern char sResultFieldTypeInvalid[];
extern char sResultNoPermission[];
extern char sResultRecordLimitReached[];
extern char sResultAlreadyRated[];
extern char sResultNotRateable[];
extern char sResultNotOwned[];
extern char sResultFilterInvalid[];
extern char sResultSortInvalid[];
extern char sResultTargetFilterInvalid[];
extern char *sSoapNamespaces[1];
extern char sXmlNamespacePrefix[];
extern char sTagGameid[];
extern char sTagSecretKey[];
extern char sTagLoginTicket[];
extern char gDwcGdbStorageServerUrl[128];
extern char sServerUrlFormat[];

SAKERequestInternal *sakeiInitRequest(SAKEInternal *sake, int type, void *input, SAKERequestCallback callback, void *userData)
{
    SAKERequestInternal *request;

    sake->mStartRequestResult = SAKEStartRequestResult_SUCCESS;
    if (input == 0) {
        sake->mStartRequestResult = SAKEStartRequestResult_BAD_INPUT;
        return 0;
    }
    if (sake->mStartedUp == 0 || sake->mProfileSet == 0) {
        sake->mStartRequestResult = SAKEStartRequestResult_NOT_AUTHENTICATED;
        return 0;
    }
    request = (SAKERequestInternal *)gsimalloc(sizeof(SAKERequestInternal));
    if (request == 0) {
        sake->mStartRequestResult = SAKEStartRequestResult_OUT_OF_MEMORY;
        return 0;
    }
    memset(request, 0, sizeof(SAKERequestInternal));
    request->mSake = sake;
    request->mType = type;
    request->mInput = input;
    request->mCallback = callback;
    request->mUserData = userData;
    return request;
}

void sakeiFreeRequest(SAKERequestInternal *request)
{
    gsifree(request);
}

/* Maps an HTTP result to a SAKERequestResult. */
int sakeiCheckHttpResult(int httpResult)
{
    switch (httpResult) {
    case 0:
        return SAKERequestResult_SUCCESS;
    case 1:
        return SAKERequestResult_OUT_OF_MEMORY;
    case 0x12:
        return SAKERequestResult_REQUEST_CANCELLED;
    default:
        return SAKERequestResult_CONNECTION_ERROR;
    }
}

/*
 * Maps the result string of a Sake response to a SAKERequestResult: a chain
 * of string compares against the known names, and UNKNOWN_ERROR if none
 * matches.  Results 3 to 6 have no string; they come from the transport.
 */
int sakeiCheckSakeResult(const char *resultString)
{
    if (strcmp(resultString, sResultSuccess) == 0)
        return SAKERequestResult_SUCCESS;
    if (strcmp(resultString, sResultSecretKeyInvalid) == 0)
        return SAKERequestResult_SECRET_KEY_INVALID;
    if (strcmp(resultString, sResultServiceDisabled) == 0)
        return SAKERequestResult_SERVICE_DISABLED;
    if (strcmp(resultString, sResultDatabaseUnavailable) == 0)
        return SAKERequestResult_DATABASE_UNAVAILABLE;
    if (strcmp(resultString, sResultLoginTicketInvalid) == 0)
        return SAKERequestResult_LOGIN_TICKET_INVALID;
    if (strcmp(resultString, sResultLoginTicketExpired) == 0)
        return SAKERequestResult_LOGIN_TICKET_EXPIRED;
    if (strcmp(resultString, sResultTableNotFound) == 0)
        return SAKERequestResult_TABLE_NOT_FOUND;
    if (strcmp(resultString, sResultRecordNotFound) == 0)
        return SAKERequestResult_RECORD_NOT_FOUND;
    if (strcmp(resultString, sResultFieldNotFound) == 0)
        return SAKERequestResult_FIELD_NOT_FOUND;
    if (strcmp(resultString, sResultFieldTypeInvalid) == 0)
        return SAKERequestResult_FIELD_TYPE_INVALID;
    if (strcmp(resultString, sResultNoPermission) == 0)
        return SAKERequestResult_NO_PERMISSION;
    if (strcmp(resultString, sResultRecordLimitReached) == 0)
        return SAKERequestResult_RECORD_LIMIT_REACHED;
    if (strcmp(resultString, sResultAlreadyRated) == 0)
        return SAKERequestResult_ALREADY_RATED;
    if (strcmp(resultString, sResultNotRateable) == 0)
        return SAKERequestResult_NOT_RATEABLE;
    if (strcmp(resultString, sResultNotOwned) == 0)
        return SAKERequestResult_NOT_OWNED;
    if (strcmp(resultString, sResultFilterInvalid) == 0)
        return SAKERequestResult_FILTER_INVALID;
    if (strcmp(resultString, sResultSortInvalid) == 0)
        return SAKERequestResult_SORT_INVALID;
    return strcmp(resultString, sResultTargetFilterInvalid) == 0 ? SAKERequestResult_TARGET_FILTER_INVALID : SAKERequestResult_UNKNOWN_ERROR;
}

/*
 * SOAP completion callback: parses the response header, lets the request kind
 * decode its output, then reports to the user callback and releases the
 * request and its output.
 */
void sakeiSoapCallback(int httpResult, void *requestData, void *responseData, void *userData)
{
    SAKERequestInternal *request;
    void *output;
    int result;
    char resultString[32];

    request = (SAKERequestInternal *)userData;
    output = 0;
    if (!request || !request->mSake || !request->mInfo)
        return;
    result = sakeiCheckHttpResult(httpResult);
    if (result == SAKERequestResult_SUCCESS) {
        if (!gsXmlMoveToStart(responseData) || !gsXmlMoveToNext(responseData, request->mInfo->mResponseTag) ||
            !gsXmlReadChildAsStringNT(responseData, request->mInfo->mResultTag, resultString, 32)) {
            result = SAKERequestResult_MALFORMED_RESPONSE;
        } else {
            result = sakeiCheckSakeResult(resultString);
            if (result == SAKERequestResult_SUCCESS && request->mInfo->mOutputSize) {
                request->mOutput = gsimalloc(request->mInfo->mOutputSize);
                if (request->mOutput) {
                    request->mSoapResponse = responseData;
                    result = request->mInfo->mProcessSoapResponseFunc(request);
                    if (result == SAKERequestResult_SUCCESS)
                        output = request->mOutput;
                } else {
                    result = SAKERequestResult_OUT_OF_MEMORY;
                }
            }
        }
    }
    if (request->mCallback)
        request->mCallback(request->mSake, request, result, request->mInput, output, request->mUserData);
    if (request->mInfo->mFreeDataFunc)
        request->mInfo->mFreeDataFunc(request);
    gsifree(request->mOutput);
    request->mOutput = 0;
    sakeiFreeRequest(request);
}

/*
 * Builds the SOAP request: the common elements (game id, secret key, login
 * ticket) go in around the request kind's own fill function.  On failure the
 * writer is freed and the kind's free function is called.
 */
int sakeiSetupRequest(SAKERequestInternal *request)
{
    SAKERequestInfo *info = request->mInfo;
    int result;

    result = info->mValidateInputFunc(request);
    if (result != 0)
        return result;
    request->mSoapRequest = gsXmlCreateStreamWriter((const char **)sSoapNamespaces, 1);
    if (request->mSoapRequest == 0)
        return SAKEStartRequestResult_OUT_OF_MEMORY;
    gsXmlWriteOpenTag(request->mSoapRequest, sXmlNamespacePrefix, request->mInfo->mFuncName);
    gsXmlWriteIntElement(request->mSoapRequest, sXmlNamespacePrefix, sTagGameid, request->mSake->mGameId);
    gsXmlWriteStringElement(request->mSoapRequest, sXmlNamespacePrefix, sTagSecretKey, request->mSake->mSecretKey);
    gsXmlWriteStringElement(request->mSoapRequest, sXmlNamespacePrefix, sTagLoginTicket, request->mSake->mLoginTicket);
    result = info->mFillSoapRequestFunc(request);
    if (result != 0) {
        gsXmlFreeWriter(request->mSoapRequest);
        request->mSoapRequest = 0;
        if (info->mFreeDataFunc != 0)
            info->mFreeDataFunc(request);
        return result;
    }
    gsXmlWriteCloseTag(request->mSoapRequest, sXmlNamespacePrefix, request->mInfo->mFuncName);
    gsXmlCloseWriter(request->mSoapRequest);
    return 0;
}

/* Sends the SOAP request; the server URL is built once from the game name. */
void sakeiExecuteRequest(SAKERequestInternal *request)
{
    GSSoapTask *soapTask;

    if (!gDwcGdbStorageServerUrl[0])
        OS_SNPrintf(gDwcGdbStorageServerUrl, 128, sServerUrlFormat, request->mSake->mGameName);
    soapTask = gsiExecuteSoap(gDwcGdbStorageServerUrl, request->mInfo->mSoapAction, request->mSoapRequest, sakeiSoapCallback, request);
    if (soapTask)
        request->mInfo->mSoapTask = soapTask->coreTask;
    else
        request->mInfo->mSoapTask = 0;
}

/* Common tail of every start function: attach the info table, build and send. */
int sakeiStartRequest(SAKERequestInternal *request, SAKERequestInfo *info)
{
    int result;

    request->mInfo = info;
    result = sakeiSetupRequest(request);
    if (result)
        return result;
    sakeiExecuteRequest(request);
    return 0;
}
