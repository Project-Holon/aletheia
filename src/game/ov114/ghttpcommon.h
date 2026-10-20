#ifndef GAME_OV114_GHTTPCOMMON_H
#define GAME_OV114_GHTTPCOMMON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ghttpcommon.c, prototypes copied from their definitions. */

#include "../ov114/ghttp_types.h"

int ghiDecryptReceivedData(GHIConnection *connection);
int ghiDoReceive(GHIConnection *connection, char *buffer, int *bufferLen);
int ghiDoSend(GHIConnection *connection, char *buffer, int len);
int ghiTrySendThenBuffer(GHIConnection *connection, char *buffer, int len);
/* END mkheaders: generated region */

#endif
