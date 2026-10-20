#ifndef GAME_OV175_SCIMAIN_H
#define GAME_OV175_SCIMAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scimain.c, prototypes copied from their definitions. */

#include "../ov175/sc_types.h"
#include "../ov175/auth_types.h"
#include "../ov175/auth_types.h"

int scInitialize(unsigned int theGameId, SCInterface **theInterfaceOut);
int scShutdown(SCInterface *theInterface);
int scThink(SCInterface *theInterface);
unsigned char *scGetSessionId(SCInterface *theInterface);
unsigned char *scGetConnectionId(SCInterface *theInterface);
int scSetSessionId(SCInterface *theInterface, const char *theSessionId);
int scCreateSession(SCInterface *theInterface, GSLoginCertificate *theCertificate, GSLoginCertificatePrivate *thePrivateData, SCWebCallback theCallback, int theTimeoutMs, void *theUserData);
int scSetReportIntention(SCInterface *theInterface, const char *theConnectionId, int isAuthoritative, GSLoginCertificate *theCertificate, GSLoginCertificatePrivate *thePrivateData, SCWebCallback theCallback, unsigned int theTimeoutMs, void *theUserData);
int scSubmitReport(SCInterface *theInterface, SCIReport *theReport, int isAuthoritative, GSLoginCertificate *theCertificate, GSLoginCertificatePrivate *thePrivateData, SCWebCallback theCallback, unsigned int theTimeoutMs, void *theUserData);
int scCreateReport(SCInterface *theInterface, unsigned int theHeaderVersion, unsigned int thePlayerCount, unsigned int theTeamCount, SCIReport **theReportOut);
int scReportBeginGlobalData(SCIReport *theReport);
int scReportBeginPlayerData(SCIReport *theReport);
int scReportBeginTeamData(SCIReport *theReport);
int scReportBeginNewPlayer(SCIReport *theReport);
int scReportEnd(SCIReport *theReport, int isAuthoritative, unsigned int theGameStatus);
int scReportSetPlayerData(SCIReport *theReport, unsigned int thePlayerIndex, unsigned char *thePlayerConnectionId, unsigned int thePlayerTeamId, int thePlayerResult, int thePlayerProfileId, GSLoginCertificate *theCertificate, unsigned char *theAuthHash);
int scReportAddIntValue(SCIReport *theReport, int theKey, int theValue);
int scReportAddByteValue(SCIReport *theReport, int theKey, int theValue);
int scDestroyReport(SCIReport *theReport);
char *scCleanupServiceUrl(void);
/* END mkheaders: generated region */

#endif
