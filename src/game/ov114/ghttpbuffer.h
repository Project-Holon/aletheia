#ifndef GAME_OV114_GHTTPBUFFER_H
#define GAME_OV114_GHTTPBUFFER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ghttpbuffer.c, prototypes copied from their definitions. */

#include "../ov114/ghttp_types.h"

int ghiResizeBuffer(GHIBuffer *buffer, int sizeIncrement);
int ghiInitBuffer(GHIConnection *connection, GHIBuffer *buffer, int initialSize, int sizeIncrement);
int ghiInitFixedBuffer(GHIConnection *connection, GHIBuffer *buffer, char *data, int size);
void ghiFreeBuffer(GHIBuffer *buffer);
int ghiAppendDataToBuffer(GHIBuffer *buffer, char *data, int dataLen);
int ghiEncryptDataToBuffer(GHIBuffer *buffer, const char *data, int dataLen);
int ghiAppendHeaderToBuffer(GHIBuffer *buffer, char *name, char *value);
int ghiAppendCharToBuffer(GHIBuffer *buffer, int ch);
int ghiAppendIntToBuffer(GHIBuffer *buffer, int i);
void ghiResetBuffer(GHIBuffer *buffer);
int ghiSendBufferedData(GHIConnection *connection);
/* END mkheaders: generated region */

#endif
