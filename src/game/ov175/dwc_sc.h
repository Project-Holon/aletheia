#ifndef GAME_OV175_DWC_SC_H
#define GAME_OV175_DWC_SC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_sc.c, prototypes copied from their definitions. */

#include "../ov175/sc_types.h"
#include "../ov175/auth_types.h"

int DWC_ScInitialize(int theGameId, int sslType);
int DWC_ScShutdown(void);
void DWCi_ScCleanupRootCAList(void);
int DWC_ScProcess(void);
int DWC_ScCreateSessionAsync(DWCScCallback callback, unsigned int timeoutMs, void *userData);
void DWCi_ScCreateSessionCallback(SCInterface *theInterface, int theHttpResult, int theResult, void *theUserData);
int DWC_ScSetReportIntentionAsync(int isAuthoritative, DWCScCallback callback, unsigned int timeoutMs, void *userData);
void DWCi_ScSetReportIntentionCallback(SCInterface *theInterface, int theHttpResult, int theResult, void *theUserData);
int DWC_ScSubmitReportAsync(SCIReport *report, int isAuthoritative, DWCScCallback callback, unsigned int timeoutMs, void *userData);
void DWCi_ScSubmitReportCallback(SCInterface *theInterface, int theHttpResult, int theResult, void *theUserData);
int DWC_ScSetSessionId(const char *sessionId);
unsigned char *DWC_ScGetSessionId(void);
unsigned char *DWC_ScGetConnectionId(void);
int DWC_ScCreateReport(unsigned int headerVersion, unsigned int playerCount, unsigned int teamCount, SCIReport **reportOut);
int DWC_ScReportBeginGlobalData(SCIReport *report);
int DWC_ScReportBeginPlayerData(SCIReport *report);
int DWC_ScReportBeginTeamData(SCIReport *report);
int DWC_ScReportBeginNewPlayer(SCIReport *report);
int DWC_ScReportSetPlayerData(SCIReport *report, unsigned int playerIndex, unsigned char *playerConnectionId, unsigned int playerTeamId, int playerResult, GSLoginCertificate *certificate, unsigned char *authHash);
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
/* END mkheaders: generated region */

#endif
