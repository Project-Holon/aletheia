/*
 * file:     dwc_sc.c
 * unit:     yes
 * function: DWC_ScInitialize, DWC_ScShutdown, DWCi_ScCleanupRootCAList, DWC_ScProcess, DWC_ScCreateSessionAsync, DWCi_ScCreateSessionCallback, DWC_ScSetReportIntentionAsync, DWCi_ScSetReportIntentionCallback, DWC_ScSubmitReportAsync, DWCi_ScSubmitReportCallback, DWC_ScSetSessionId, DWC_ScGetSessionId, DWC_ScGetConnectionId, DWC_ScCreateReport, DWC_ScReportBeginGlobalData, DWC_ScReportBeginPlayerData, DWC_ScReportBeginTeamData, DWC_ScReportBeginNewPlayer, DWC_ScReportSetPlayerData, DWC_ScReportEnd, DWC_ScReportAddIntValue, DWC_ScReportAddByteValue, DWC_ScDestroyReport, DWC_ScGetLoginCertificate, DWCi_ScPrintf, DWCi_ScLoginCallback, DWCi_DWCScResultToDWCError, DWCi_ScGetRequestErrorCode, DWCi_HandleWSLoginError, DWCi_ScSetUseSSL
 * address:  0x021DEE3C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWC wrapper of the GameSpy Stats and Control client (libdwcsc, object dwc_sc.o):
 * logs in, starts the stats client and exposes the report calls (session, report
 * intention, match report, submit) with DWC error codes. The login certificate
 * and its private data live in this object's data.
 *
 * symbols:
 *   DWC_GHTTPCleanupRootCAList  0x021BF540  arm ov114
 *   DWC_GHTTPSetRootCAList  0x021BF520  arm ov114
 *   DWC_GetLastError  0x02059E18  arm arm9
 *   DWCi_GetAuthInfo  0x0216AA9C  arm ov009
 *   DWCi_HandleGHTTPError  0x021BF8C0  arm ov114
 *   DWCi_SetError  0x02059F54  arm arm9
 *   OS_SNPrintf  0x02084F80  arm arm9
 *   OS_Sleep  0x02085A38  arm arm9
 *   OS_VSNPrintf  0x02084FA8  arm
 *   scInitialize  0x021DF9D8  arm  ov175
 *   scThink  0x021DFA6C  arm
 *   scGetConnectionId  0x021DFAA0  arm  ov175
 *   scSetSessionId  0x021DFAA8  arm  ov175
 *   scSetReportIntention  0x021DFB18  arm  ov175
 *   scSubmitReport  0x021DFBB8  arm  ov175
 *   scCreateReport  0x021DFC8C  arm  ov175
 *   scReportBeginGlobalData  0x021DFCE8  arm
 *   scReportBeginPlayerData  0x021DFCF4  arm
 *   scReportBeginTeamData  0x021DFD00  arm
 *   scReportBeginNewPlayer  0x021DFD0C  arm
 *   scReportEnd  0x021DFD18  arm
 *   scReportSetPlayerData  0x021DFD24  arm
 *   scReportAddIntValue  0x021DFDFC  arm
 *   scReportAddByteValue  0x021DFE08  arm
 *   scDestroyReport  0x021DFE14  arm
 *   scCleanupServiceUrl  0x021DFE20  arm  ov175
 *   wsGetServiceUrl  0x021E22E4  arm  ov175
 *   wsLoginRemoteAuth  0x021E2510  arm  ov175
 *   g_021AE01C  0x021AE01C  data
 *   sDwcScLoginFailedFormat  0x021E3F48  data
 *   sDwcScPrintfPrefix  0x021E3F68  data
 *   sDwcScLoginHttpErrorFormat  0x021E3F74  data
 *   sDwcScLoginResultErrorFormat  0x021E3FA0  data
 *   sDwcScLoggedInFormat  0x021E3FCC  data
 *   sDwcScStatsUrlFormatSecure2  0x021E3FE8  data
 *   sDwcScAuthUrlFormatSecure2  0x021E4040  data
 *   sDwcScStatsUrlFormatSecure  0x021E408C  data
 *   sDwcScAuthUrlFormatSecure  0x021E40E4  data
 *   gDwcScControl  0x021E4D08  data
 *   gDwcScLoginPrivateData  0x021E4D1C  data
 *   gDwcScLoginCertificate  0x021E4F34  data
 *   gScStatsServiceUrl  0x021E52B4  data
 *   gWsAuthServiceUrl  0x021E53BC  data
 *   gsCoreInitialize  0x0217CA40  arm ov009
 *   gsCoreIsShutdown  0x0217CE1C  arm ov009
 *   gsCoreShutdown  0x0217CD94  arm ov009
 *   gsCoreThink  0x0217CCCC  arm ov009
 *   memcpy  0x02092344  arm
 *   scShutdown  0x021DFA3C  arm
 *   scGetSessionId  0x021DFA98  arm
 *   scCreateSession  0x021DFAB8  arm
 */
#include "sc_types.h"

#include "../sdk_stdarg.h"

/* Which DWC_Sc call an error came from (first argument of DWCi_ScGetRequestErrorCode). */
typedef enum DWCScErrorSource {
    DWCScErrorSource_LOGIN = 1,
    DWCScErrorSource_INITIALIZE = 2,
    DWCScErrorSource_SHUTDOWN = 3,
    DWCScErrorSource_PROCESS = 4,
    DWCScErrorSource_CREATE_SESSION = 5,
    DWCScErrorSource_SET_REPORT_INTENTION = 7,
    DWCScErrorSource_SET_SESSION_ID = 8,
    DWCScErrorSource_CREATE_REPORT = 9,
    DWCScErrorSource_REPORT_DATA = 10,
    DWCScErrorSource_SUBMIT_REPORT = 11,
    DWCScErrorSource_DESTROY_REPORT = 13
} DWCScErrorSource;

/* State of the DWC stats wrapper: the login progress, the client and the caller's three callbacks. */
typedef struct DWCScControl {
    int state;
    SCInterface *session;
    DWCScCallback createSessionCallback;
    DWCScCallback setReportIntentionCallback;
    DWCScCallback submitReportCallback;
} DWCScControl;

#include "../ov009/gscore.h"
#include "../ov009/dwc_login.h"
#include "../arm9/dwc_error.h"
#include "../arm9/os_thread.h"
#include "../arm9/os_printf.h"
#include "../ov114/dwc_ghttp.h"
typedef unsigned int size_t;
#include "../arm9/msl_string_mem.h"
#include "authservice.h"

int DWC_ScInitialize(int theGameId, int sslType);
int DWC_ScShutdown(void);
void DWCi_ScCleanupRootCAList(void);
int DWC_ScProcess(void);
int DWC_ScCreateSessionAsync(DWCScCallback callback, unsigned int timeoutMs, void *userData);
void DWCi_ScCreateSessionCallback(SCInterface *theInterface, int theHttpResult, int theResult, void *theUserData);
int DWC_ScSetReportIntentionAsync(int isAuthoritative, DWCScCallback callback, unsigned int timeoutMs, void *userData);
void DWCi_ScSetReportIntentionCallback(SCInterface *theInterface, int theHttpResult, int theResult, void *theUserData);
int DWC_ScSubmitReportAsync(SCIReport *report, int isAuthoritative, DWCScCallback callback, unsigned int timeoutMs,
                  void *userData);
void DWCi_ScSubmitReportCallback(SCInterface *theInterface, int theHttpResult, int theResult, void *theUserData);
int DWC_ScSetSessionId(const char *sessionId);
unsigned char *DWC_ScGetSessionId(void);
unsigned char *DWC_ScGetConnectionId(void);
int DWC_ScCreateReport(unsigned int headerVersion, unsigned int playerCount, unsigned int teamCount,
                  SCIReport **reportOut);
int DWC_ScReportBeginGlobalData(SCIReport *report);
int DWC_ScReportBeginPlayerData(SCIReport *report);
int DWC_ScReportBeginTeamData(SCIReport *report);
int DWC_ScReportBeginNewPlayer(SCIReport *report);
int DWC_ScReportSetPlayerData(SCIReport *report, unsigned int playerIndex, unsigned char *playerConnectionId,
                  unsigned int playerTeamId, int playerResult, GSLoginCertificate *certificate,
                  unsigned char *authHash);
int DWC_ScReportEnd(SCIReport *report, int isAuthoritative, unsigned int gameStatus);
int DWC_ScReportAddIntValue(SCIReport *report, int key, int value);
int DWC_ScReportAddByteValue(SCIReport *report, int key, int value);
int DWC_ScDestroyReport(SCIReport *report);
int DWC_ScGetLoginCertificate(GSLoginCertificate **certificateOut);
void DWCi_ScPrintf(int line, char *fmt, ...);
void DWCi_ScLoginCallback(int httpResult, WSLoginResponse *theResponse, void *theUserData);
int DWCi_DWCScResultToDWCError(int scResult);
int DWCi_ScGetRequestErrorCode(int source, int result);
int DWCi_HandleWSLoginError(int result);
void DWCi_ScSetUseSSL(int sslType);

extern DWCScControl gDwcScControl;
extern char sDwcScLoginFailedFormat[];
extern GSLoginCertificate gDwcScLoginCertificate;
extern GSLoginCertificatePrivate gDwcScLoginPrivateData;
extern char sDwcScPrintfPrefix[];
extern char sDwcScLoginHttpErrorFormat[];
extern char sDwcScLoginResultErrorFormat[];
extern char sDwcScLoggedInFormat[];
extern char gScStatsServiceUrl[];
extern char g_021AE01C[];
extern char sDwcScStatsUrlFormatSecure2[];
extern char gWsAuthServiceUrl[];
extern char sDwcScAuthUrlFormatSecure2[];
extern char sDwcScStatsUrlFormatSecure[];
extern char sDwcScAuthUrlFormatSecure[];

/* DWC_ScInitialize: logs in through the auth service, then starts the stats client for the game. */
int DWC_ScInitialize(int theGameId, int sslType)
{
    unsigned int gsResult;
    int result;
    char *authToken;
    char *partnerChallenge;

    gsCoreInitialize();
    DWCi_ScSetUseSSL(sslType);
    DWCi_GetAuthInfo(&authToken, &partnerChallenge);
    gDwcScControl.state = 0;
    result = wsLoginRemoteAuth(0, theGameId, authToken, partnerChallenge, DWCi_ScLoginCallback, 0);
    if (result != 0) {
        DWCi_ScPrintf(0x8e, sDwcScLoginFailedFormat, result);
        DWCi_SetError(0x14, DWCi_ScGetRequestErrorCode(DWCScErrorSource_LOGIN, 0));
        return 7;
    }
    while (gDwcScControl.state == 0) {
        OS_Sleep(10);
        gsCoreThink(0);
    }
    if (DWC_GetLastError(0) != 0)
        return 7;
    gsResult = scInitialize(theGameId, &gDwcScControl.session);
    if (gsResult != 0) {
        result = DWCi_DWCScResultToDWCError(gsResult);
        DWCi_SetError(result, DWCi_ScGetRequestErrorCode(DWCScErrorSource_INITIALIZE, gsResult));
    }
    return gsResult;
}

/* DWC_ScShutdown: shuts the stats client down, drops the root CA lists and runs the core until it is stopped. */
int DWC_ScShutdown(void)
{
    int result;

    result = scShutdown(gDwcScControl.session);
    if (result != 0)
        DWCi_SetError(DWCi_DWCScResultToDWCError(result), DWCi_ScGetRequestErrorCode(DWCScErrorSource_SHUTDOWN, result));
    DWCi_ScCleanupRootCAList();
    gsCoreShutdown();
    gsCoreThink(0);
    if (gsCoreIsShutdown() != 2)
        gsCoreThink(0);
    return result;
}

/* DWCi_ScCleanupRootCAList: releases the root CA list of the auth service URL and of the stats service URL. */
void DWCi_ScCleanupRootCAList(void)
{
    DWC_GHTTPCleanupRootCAList(wsGetServiceUrl());
    DWC_GHTTPCleanupRootCAList(scCleanupServiceUrl());
}

/*
 * DWC_ScProcess: runs the stats client once.  Same error post shape as the
 * report calls below, driven by the client in the control block.
 */
int DWC_ScProcess(void)
{
    int result = scThink(gDwcScControl.session);

    if (result != 0)
        DWCi_SetError(8, DWCi_ScGetRequestErrorCode(DWCScErrorSource_PROCESS, result));
    return result;
}

/*
 * DWC_ScCreateSessionAsync: stores the caller's callback and starts the
 * CreateSession call with the login certificate.
 */
int DWC_ScCreateSessionAsync(DWCScCallback callback, unsigned int timeoutMs, void *userData)
{
    int result;

    gDwcScControl.createSessionCallback = callback;
    result = scCreateSession(gDwcScControl.session, &gDwcScLoginCertificate, &gDwcScLoginPrivateData, DWCi_ScCreateSessionCallback, timeoutMs, userData);
    if (result != 0)
        DWCi_SetError(8, DWCi_ScGetRequestErrorCode(DWCScErrorSource_CREATE_SESSION, result));
    return result;
}

/* DWCi_ScCreateSessionCallback: passes the result and the caller's data on to the caller's callback. */
void DWCi_ScCreateSessionCallback(SCInterface *theInterface, int theHttpResult, int theResult, void *theUserData)
{
    gDwcScControl.createSessionCallback(theResult, theUserData);
}

/*
 * DWC_ScSetReportIntentionAsync: stores the caller's callback and starts the
 * SetReportIntention call with the login certificate.
 */
int DWC_ScSetReportIntentionAsync(int isAuthoritative, DWCScCallback callback, unsigned int timeoutMs, void *userData)
{
    int result;

    gDwcScControl.setReportIntentionCallback = callback;
    result = scSetReportIntention(gDwcScControl.session, 0, isAuthoritative, &gDwcScLoginCertificate, &gDwcScLoginPrivateData, DWCi_ScSetReportIntentionCallback,
                           timeoutMs, userData);
    if (result != 0)
        DWCi_SetError(8, DWCi_ScGetRequestErrorCode(DWCScErrorSource_SET_REPORT_INTENTION, result));
    return result;
}

/* DWCi_ScSetReportIntentionCallback: passes the result and the caller's data on to the caller's callback. */
void DWCi_ScSetReportIntentionCallback(SCInterface *theInterface, int theHttpResult, int theResult, void *theUserData)
{
    gDwcScControl.setReportIntentionCallback(theResult, theUserData);
}

/*
 * DWC_ScSubmitReportAsync: stores the caller's callback and starts the
 * SubmitReport call with the login certificate.
 */
int DWC_ScSubmitReportAsync(SCIReport *report, int isAuthoritative, DWCScCallback callback, unsigned int timeoutMs,
                  void *userData)
{
    int result;

    gDwcScControl.submitReportCallback = callback;
    result = scSubmitReport(gDwcScControl.session, report, isAuthoritative, &gDwcScLoginCertificate, &gDwcScLoginPrivateData, DWCi_ScSubmitReportCallback,
                           timeoutMs, userData);
    if (result != 0)
        DWCi_SetError(8, DWCi_ScGetRequestErrorCode(DWCScErrorSource_SUBMIT_REPORT, result));
    return result;
}

/* DWCi_ScSubmitReportCallback: passes the result and the caller's data on to the caller's callback. */
void DWCi_ScSubmitReportCallback(SCInterface *theInterface, int theHttpResult, int theResult, void *theUserData)
{
    gDwcScControl.submitReportCallback(theResult, theUserData);
}

/* DWC_ScSetSessionId: sets the session GUID of the stats client. */
int DWC_ScSetSessionId(const char *sessionId)
{
    int result = scSetSessionId(gDwcScControl.session, sessionId);

    if (result != 0)
        DWCi_SetError(8, DWCi_ScGetRequestErrorCode(DWCScErrorSource_SET_SESSION_ID, result));
    return result;
}

/* DWC_ScGetSessionId: the session GUID of the stats client. */
unsigned char *DWC_ScGetSessionId(void)
{
    return scGetSessionId(gDwcScControl.session);
}

/* DWC_ScGetConnectionId: the connection GUID of the stats client. */
unsigned char *DWC_ScGetConnectionId(void)
{
    return scGetConnectionId(gDwcScControl.session);
}

/* DWC_ScCreateReport: creates a match report for the session. */
int DWC_ScCreateReport(unsigned int headerVersion, unsigned int playerCount, unsigned int teamCount,
                  SCIReport **reportOut)
{
    int result;

    result = scCreateReport(gDwcScControl.session, headerVersion, playerCount, teamCount, reportOut);
    if (result != 0)
        DWCi_SetError(8, DWCi_ScGetRequestErrorCode(DWCScErrorSource_CREATE_REPORT, result));
    return result;
}

/* DWC_ScReportBeginGlobalData: starts the game section of the report. */
int DWC_ScReportBeginGlobalData(SCIReport *report)
{
    int result = scReportBeginGlobalData(report);

    if (result)
        DWCi_SetError(8, DWCi_ScGetRequestErrorCode(DWCScErrorSource_REPORT_DATA, result));
    return result;
}

/* DWC_ScReportBeginPlayerData: starts the player section of the report. */
int DWC_ScReportBeginPlayerData(SCIReport *report)
{
    int result = scReportBeginPlayerData(report);

    if (result)
        DWCi_SetError(8, DWCi_ScGetRequestErrorCode(DWCScErrorSource_REPORT_DATA, result));
    return result;
}

/* DWC_ScReportBeginTeamData: starts the team section of the report. */
int DWC_ScReportBeginTeamData(SCIReport *report)
{
    int result = scReportBeginTeamData(report);

    if (result)
        DWCi_SetError(8, DWCi_ScGetRequestErrorCode(DWCScErrorSource_REPORT_DATA, result));
    return result;
}

/* DWC_ScReportBeginNewPlayer: starts the next player entry of the report. */
int DWC_ScReportBeginNewPlayer(SCIReport *report)
{
    int result = scReportBeginNewPlayer(report);

    if (result)
        DWCi_SetError(8, DWCi_ScGetRequestErrorCode(DWCScErrorSource_REPORT_DATA, result));
    return result;
}

/*
 * DWC_ScReportSetPlayerData: records a player's connection id, team, result and
 * login certificate in the report.  The certificate's profile id goes along.
 */
int DWC_ScReportSetPlayerData(SCIReport *report, unsigned int playerIndex, unsigned char *playerConnectionId,
                  unsigned int playerTeamId, int playerResult, GSLoginCertificate *certificate,
                  unsigned char *authHash)
{
    int result = scReportSetPlayerData(report, playerIndex, playerConnectionId, playerTeamId, playerResult,
                               certificate->mProfileId, certificate, authHash);

    if (result != 0)
        DWCi_SetError(8, DWCi_ScGetRequestErrorCode(DWCScErrorSource_REPORT_DATA, result));
    return result;
}

/* DWC_ScReportEnd: closes the report with the game status. */
int DWC_ScReportEnd(SCIReport *report, int isAuthoritative, unsigned int gameStatus)
{
    int result = scReportEnd(report, isAuthoritative, gameStatus);

    if (result != 0)
        DWCi_SetError(DWCi_DWCScResultToDWCError(result), DWCi_ScGetRequestErrorCode(DWCScErrorSource_REPORT_DATA, result));
    return result;
}

/* DWC_ScReportAddIntValue: adds a key with an integer value to the current section. */
int DWC_ScReportAddIntValue(SCIReport *report, int key, int value)
{
    int result = scReportAddIntValue(report, key, value);

    if (result != 0)
        DWCi_SetError(DWCi_DWCScResultToDWCError(result), DWCi_ScGetRequestErrorCode(DWCScErrorSource_REPORT_DATA, result));
    return result;
}

/* DWC_ScReportAddByteValue: adds a key with a byte value to the current section. */
int DWC_ScReportAddByteValue(SCIReport *report, int key, int value)
{
    int result = scReportAddByteValue(report, key, value);

    if (result != 0)
        DWCi_SetError(DWCi_DWCScResultToDWCError(result), DWCi_ScGetRequestErrorCode(DWCScErrorSource_REPORT_DATA, result));
    return result;
}

/* DWC_ScDestroyReport: frees the report. */
int DWC_ScDestroyReport(SCIReport *report)
{
    int result = scDestroyReport(report);

    if (result != 0)
        DWCi_SetError(DWCi_DWCScResultToDWCError(result), DWCi_ScGetRequestErrorCode(DWCScErrorSource_DESTROY_REPORT, result));
    return result;
}

/* DWC_ScGetLoginCertificate: the certificate that the login produced. */
int DWC_ScGetLoginCertificate(GSLoginCertificate **certificateOut)
{
    *certificateOut = &gDwcScLoginCertificate;
    return 0;
}

/* DWCi_ScPrintf: debug print with the "Sc[line]> " prefix; the output goes into a local buffer only. */
void DWCi_ScPrintf(int line, char *fmt, ...)
{
    char strBuf[256];
    int strLen;
    va_list args;

    strLen = OS_SNPrintf(strBuf, 256, sDwcScPrintfPrefix, line);
    va_start(args, fmt);
    OS_VSNPrintf(strBuf + strLen, 256 - strLen, fmt, args);
}

/* DWCi_ScLoginCallback: keeps the certificate and private data of a successful login, or reports why it failed. */
void DWCi_ScLoginCallback(int httpResult, WSLoginResponse *theResponse, void *theUserData)
{
    if (httpResult != 0) {
        DWCi_ScPrintf(0x315, sDwcScLoginHttpErrorFormat, httpResult);
        if (httpResult == 1)
            DWCi_SetError(9, DWCi_ScGetRequestErrorCode(DWCScErrorSource_LOGIN, 5));
        else
            DWCi_SetError(0x14, DWCi_ScGetRequestErrorCode(DWCScErrorSource_LOGIN, 7));
        DWCi_HandleGHTTPError(httpResult);
    } else if (theResponse->mLoginResult != 0) {
        DWCi_ScPrintf(0x323, sDwcScLoginResultErrorFormat, theResponse->mLoginResult);
        DWCi_HandleWSLoginError(theResponse->mLoginResult);
    } else {
        memcpy(&gDwcScLoginCertificate, &theResponse->mCertificate, sizeof(GSLoginCertificate));
        memcpy(&gDwcScLoginPrivateData, &theResponse->mPrivateData, sizeof(GSLoginCertificatePrivate));
        DWCi_ScPrintf(0x32b, sDwcScLoggedInFormat, theResponse->mCertificate.mUniqueNick);
    }
    gDwcScControl.state = 1;
}

/*
 * DWCi_DWCScResultToDWCError: ARM jump-table selector over 0..14: only two
 * results carry a DWC error of their own (0 and 5), everything else is 0x14.
 */
int DWCi_DWCScResultToDWCError(int scResult)
{
    switch (scResult) {
    case 0:
        return 0;
    case 1:
    case 2:
    case 3:
    case 4:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
        break;
    case 5:
        return 9;
    }
    return 0x14;
}

/* DWCi_ScGetRequestErrorCode: the DWC error code -43000 - (source * 100 + result). */
int DWCi_ScGetRequestErrorCode(int source, int result)
{
    return -43000 - (source * 100 + result);
}

/*
 * DWCi_HandleWSLoginError: posts the DWC error for a login result: -43008 for
 * server codes and the failures of the request itself, -43006 (error 9) for
 * 104.  The switch has case 1 as well: it shifts the switch tree so that 105
 * is a lone node and 106..108 a linear range chain, as in the image.
 */
int DWCi_HandleWSLoginError(int result)
{
    int dwcError = 20;
    int errorCode = -43000;

    if (result == 0)
        return 0;
    switch (result) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7:
    case 100: case 101: case 102: case 103:
    case 105: case 106: case 107: case 108:
        errorCode -= 8;
        break;
    case 104:
        dwcError = 9;
        errorCode -= 6;
        break;
    default:
        errorCode -= 15;
        break;
    }
    DWCi_SetError(dwcError, errorCode);
    return result;
}

/*
 * DWCi_ScSetUseSSL: builds the two service URLs (stats and auth) for the
 * wanted server set and registers their root CA lists.  The default is the
 * secure server; 1 selects the secure2 server.
 */
void DWCi_ScSetUseSSL(int sslType)
{
    switch (sslType) {
    case 1:
        OS_SNPrintf(gScStatsServiceUrl, 128, sDwcScStatsUrlFormatSecure2, g_021AE01C);
        DWC_GHTTPSetRootCAList(gScStatsServiceUrl);
        OS_SNPrintf(gWsAuthServiceUrl, 128, sDwcScAuthUrlFormatSecure2, g_021AE01C);
        DWC_GHTTPSetRootCAList(gWsAuthServiceUrl);
        break;
    case 0:
    default:
        OS_SNPrintf(gScStatsServiceUrl, 128, sDwcScStatsUrlFormatSecure, g_021AE01C);
        DWC_GHTTPSetRootCAList(gScStatsServiceUrl);
        OS_SNPrintf(gWsAuthServiceUrl, 128, sDwcScAuthUrlFormatSecure, g_021AE01C);
        DWC_GHTTPSetRootCAList(gWsAuthServiceUrl);
        break;
    }
}
