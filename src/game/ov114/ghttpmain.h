#ifndef GAME_OV114_GHTTPMAIN_H
#define GAME_OV114_GHTTPMAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ghttpmain.c, prototypes copied from their definitions. */

#include "../ov114/ghttp_types.h"

void ghiHandleStatus(GHIConnection *connection);
int ghiProcessConnection(GHIConnection *connection);
void ghttpStartup(void);
void ghttpCleanup(void);
int ghttpGetExA(const char *URL, const char *headers, char *buffer, int bufferSize, GHIPost *post, int throttle, int blocking, GHTTPProgressCallbackFn progressCallback, GHTTPCompletedCallbackFn completedCallback, void *param);
void ghttpThink(void);
int ghttpRequestThink(int request);
void ghttpCancelRequest(int request);
int ghttpGetState(int request);
void ghttpSetMaxRecvTime(int request, unsigned int maxRecvTime);
GHIPost *ghttpNewPost(void);
void ghttpPostSetAutoFree(GHIPost *post, GHTTPBool autoFree);
void ghttpFreePostAndUpdateConnection(int request, GHIPost *post);
int ghttpPostAddXml(GHIPost *post, void *xml);
int ghttpSetRootCAList(char *url, void *theRootCAList);
int ghttpCleanupRootCAList(char *url);
/* END mkheaders: generated region */

#endif
