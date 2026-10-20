#ifndef GAME_OV175_SCIWEBSERVICES_H
#define GAME_OV175_SCIWEBSERVICES_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sciwebservices.c, prototypes copied from their definitions. */

struct GHIPost;

#include "../ov175/sc_types.h"
#include "../ov175/sc_types.h"
#include "../ov175/auth_types.h"
#include "../ov175/auth_types.h"

int sciWsInit(SCWebServices *theWebServices, SCInterface *theInterface);
void sciWsDestroy(SCWebServices *theWebServices);
void sciWsThink(SCWebServices *theWebServices);
int sciWsCreateSession(SCWebServices *theWebServices, unsigned int theGameId, GSLoginCertificate *theCertificate, GSLoginCertificatePrivate *thePrivateData, SCWebCallback theCallback, int theTimeoutMs, void *theUserData);
void sciWsCreateSessionCallback(int theHttpResult, void *theRequestSoap, void *theResponseData, void *theUserData);
int sciWsSetReportIntention(SCWebServices *theWebServices, unsigned int theGameId, char *theSessionId, char *theConnectionId, int isAuthoritative, GSLoginCertificate *theCertificate, GSLoginCertificatePrivate *thePrivateData, SCWebCallback theCallback, unsigned int theTimeoutMs, void *theUserData);
void sciWsSetReportIntentionCallback(int theHttpResult, void *theRequestSoap, void *theResponseData, void *theUserData);
void sciWsSubmitReportCustom(struct GHIPost *thePost, void *theUserData);
int sciWsSubmitReport(SCWebServices *theWebServices, unsigned int theGameId, char *theSessionId, char *theConnectionId, SCIReport *theReport, int isAuthoritative, GSLoginCertificate *theCertificate, GSLoginCertificatePrivate *thePrivateData, SCWebCallback theCallback, unsigned int theTimeoutMs, void *theUserData);
void sciWsSubmitReportCallback(int theHttpResult, void *theRequestSoap, void *theResponseData, void *theUserData);
/* END mkheaders: generated region */

#endif
