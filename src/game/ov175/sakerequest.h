#ifndef GAME_OV175_SAKEREQUEST_H
#define GAME_OV175_SAKEREQUEST_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sakerequest.c, prototypes copied from their definitions. */

#include "../ov175/sake_types.h"
#include "../ov175/sake_types.h"
#include "../ov175/sake_types.h"

SAKERequestInternal *sakeiInitRequest(SAKEInternal *sake, int type, void *input, SAKERequestCallback callback, void *userData);
void sakeiFreeRequest(SAKERequestInternal *request);
int sakeiCheckHttpResult(int httpResult);
int sakeiCheckSakeResult(const char *resultString);
void sakeiSoapCallback(int httpResult, void *requestData, void *responseData, void *userData);
int sakeiSetupRequest(SAKERequestInternal *request);
void sakeiExecuteRequest(SAKERequestInternal *request);
int sakeiStartRequest(SAKERequestInternal *request, SAKERequestInfo *info);
/* END mkheaders: generated region */

#endif
