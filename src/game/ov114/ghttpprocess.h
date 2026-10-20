#ifndef GAME_OV114_GHTTPPROCESS_H
#define GAME_OV114_GHTTPPROCESS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ghttpprocess.c, prototypes copied from their definitions. */

#include "../ov114/ghttp_types.h"

GHTTPBool ghiParseURL(GHIConnection *connection);
void ghiDoSocketInit(GHIConnection *connection);
void ghiDoHostLookup(GHIConnection *connection);
void ghiDoLookupPending(GHIConnection *connection);
void ghiDoConnecting(GHIConnection *connection);
void ghiDoSecuringSession(GHIConnection *connection);
void ghiDoSendingRequest(GHIConnection *connection);
void ghiDoPosting(GHIConnection *connection);
void ghiDoWaiting(GHIConnection *connection);
int ghiParseStatus(GHIConnection *connection);
void ghiDoReceivingStatus(GHIConnection *connection);
int ghiDeliverIncomingFileData(GHIConnection *connection, char *data, int len);
int ghiParseChunkSize(GHIConnection *connection);
void ghiAppendToChunkHeaderBuffer(GHIConnection *connection, char *data, int len);
int ghiProcessIncomingFileData(GHIConnection *connection, char *data, int len);
void ghiFreeTempBuffer(void *memory);
void ghiDoReceivingHeaders(GHIConnection *connection);
void ghiDoReceivingFile(GHIConnection *connection);
/* END mkheaders: generated region */

#endif
