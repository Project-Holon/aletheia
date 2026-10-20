#ifndef GAME_OV009_GPIBUFFER_H
#define GAME_OV009_GPIBUFFER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gpibuffer.c, prototypes copied from their definitions. */

#include "../ov009/gpi_types.h"

int gpiAppendCharToBuffer(void **connection, GPIBuffer *buffer, int c);
int gpiAppendStringToBufferLen(void **connection, GPIBuffer *buffer, const char *src, int n);
int gpiAppendStringToBuffer(void **connection, GPIBuffer *buffer, const char *string);
int gpiAppendIntToBuffer(void **connection, GPIBuffer *buffer, int value);
int gpiSendData(int *connection, int sock, char *buffer, int bufferLen, int *closed, int *sent, char *id);
int gpiSendOrBufferChar(void **connection, GPIPeer *peer, char c);
int gpiSendOrBufferStringLenToPeer(void **connection, GPIPeer *peer, char *string, int stringLen);
int gpiSendOrBufferString(void **connection, GPIPeer *peer, char *string);
int gpiRecvToBuffer(void **connection, int sock, GPIBuffer *inputBuffer, int *bytesRead, int *connClosed, char *id);
int gpiSendFromBuffer(void **connection, int sock, GPIBuffer *outputBuffer, int *connClosed, int clipSentData, char *id);
int gpiSendBufferToPeer(GPIConnection **connection, unsigned int ip, unsigned short port, GPIBuffer *outputBuffer, int *closed, int clipSentData);
int gpiReadMessageFromBuffer(void **connection, GPIBuffer *inputBuffer, char **message, int *type, int *plen);
int gpiClipBufferToPosition(void **unused, GPIBuffer *buffer);
/* END mkheaders: generated region */

#endif
