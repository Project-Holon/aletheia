#ifndef GAME_OV175_SAKEMAIN_H
#define GAME_OV175_SAKEMAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sakemain.c, prototypes copied from their definitions. */

#include "../ov175/sake_types.h"

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
/* END mkheaders: generated region */

#endif
