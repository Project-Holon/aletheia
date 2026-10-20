#ifndef GAME_OV175_AUTHSERVICE_H
#define GAME_OV175_AUTHSERVICE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of authservice.c, prototypes copied from their definitions. */

#include "../ov175/auth_types.h"

int wsiServiceAvailable(void);
char *wsGetServiceUrl(void);
void wsLoginRemoteAuthCallback(int theResult, void *theRequestXml, void *theResponseXml, void *theRequestData);
int wsLoginRemoteAuth(int partnerCode, int namespaceId, char *authtoken, char *partnerChallenge, WSLoginCallback userCallback, void *userData);
unsigned int wsiToNetworkOrder(unsigned int num);
int wsLoginCertIsValid(GSLoginCertificate *cert);
int wsLoginCertWriteXML(GSLoginCertificate *cert, char *aNamespace, void *writer);
int wsLoginCertReadXML(GSLoginCertificate *cert, void *reader);
/* END mkheaders: generated region */

#endif
