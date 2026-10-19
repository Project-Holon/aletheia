/*
 * file:     ghttpbuffer.c
 * unit:     yes
 * function: ghiResizeBuffer, ghiInitBuffer, ghiInitFixedBuffer, ghiFreeBuffer, ghiAppendDataToBuffer, ghiEncryptDataToBuffer, ghiAppendHeaderToBuffer, ghiAppendCharToBuffer, ghiAppendIntToBuffer, ghiResetBuffer, ghiSendBufferedData
 * address:  0x021BFB90
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gsirealloc  0x0217EAC8 arm ov009
 *   gsifree                 0x0217EAE0  arm
 *   MSL_C_LIB_MemsetPtr                  0x020923B0  arm
 *   strlen           0x0209477c arm
 *   ghiResizeBuffer  0x021bfb90 arm  ov114
 *   memcpy           0x02092344 arm
 *   gsDebugFormat                    0x0217d254 arm  ov009
 *   sGhttpGhiencryptdatatobufferEncounteredUnhandledReturnCode                       0x021ce54c data ov114
 *   ghiAppendDataToBuffer  0x021BFCEC arm ov114
 *   sGhttpHeaderSeparator             0x021CE58C data
 *   sGhttpLineEndBuffer             0x021CE590 data
 *   OS_SPrintf             0x02084F40 arm
 *   sGhttpIntFormatBuffer             0x021CE594 data
 *   GSISocketSelect  0x0217ed64  arm  ov009
 *   GOAGetLastError  0x0217ed54  arm  ov009
 *   ghiDoSend    0x021c0684  arm  ov114
 */
#include "ghttp_types.h"


extern void *gsirealloc(void *ptr, unsigned long size);
extern void gsifree(void *ptr);
extern void *memcpy(void *, const void *, unsigned int);
extern void gsDebugFormat(int cat, int type, int level, char *fmt, ...);
extern int ghiAppendDataToBuffer(GHIBuffer *buffer, char *data, int dataLen);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern int GSISocketSelect(int, int *, int *, int *);
extern int GOAGetLastError(int);
extern int ghiDoSend(GHIConnection *, char *, int);
int ghiResizeBuffer(GHIBuffer *buffer, int sizeIncrement);
int ghiInitBuffer(GHIConnection *connection, GHIBuffer *buffer, int initialSize, int sizeIncrement);
int ghiInitFixedBuffer(GHIConnection *connection, GHIBuffer *buffer, char *data, int size);
void ghiFreeBuffer(GHIBuffer *buffer);
int ghiEncryptDataToBuffer(GHIBuffer *buffer, const char *data, int dataLen);
int ghiAppendHeaderToBuffer(GHIBuffer *buffer, char *name, char *value);
int ghiAppendCharToBuffer(GHIBuffer *buffer, int ch);
int ghiAppendIntToBuffer(GHIBuffer *buffer, int i);
void ghiResetBuffer(GHIBuffer *buffer);
int ghiSendBufferedData(GHIConnection *connection);
extern char sGhttpGhiencryptdatatobufferEncounteredUnhandledReturnCode[];
extern char sGhttpHeaderSeparator[];
extern char sGhttpLineEndBuffer[];
extern char sGhttpIntFormatBuffer[];


extern int strlen(unsigned char *s);
extern void *MSL_C_LIB_MemsetPtr(void *dest, int c, u32 n);
int ghiResizeBuffer(GHIBuffer *buffer, int sizeIncrement)
{
    int newSize;
    char *tempPtr;
    if (buffer == 0)
        return 0;
    if (sizeIncrement <= 0)
        return 0;
    newSize = buffer->size + sizeIncrement;
    tempPtr = gsirealloc(buffer->data, newSize);
    if (tempPtr == 0)
        return 0;
    buffer->data = tempPtr;
    buffer->size = newSize;
    return 1;
}


/*
 * sdk:      ghiInitBuffer (ghttpbuffer.o)
 */
int ghiInitBuffer(GHIConnection *connection, GHIBuffer *buffer, int initialSize, int sizeIncrement)
{
    if (connection == 0)
        return 0;
    if (buffer == 0)
        return 0;
    if (initialSize <= 0)
        return 0;
    if (sizeIncrement <= 0)
        return 0;
    buffer->connection = connection;
    buffer->data = 0;
    buffer->size = 0;
    buffer->len = 0;
    buffer->pos = 0;
    buffer->sizeIncrement = sizeIncrement;
    buffer->fixed = 0;
    buffer->dontFree = 0;
    buffer->readOnly = 0;
    if (ghiResizeBuffer(buffer, initialSize) == 0)
        return 0;
    *buffer->data = 0;
    return 1;
}


/*
 * sdk:      ghiInitFixedBuffer (ghttpbuffer.o)
 */
int ghiInitFixedBuffer(GHIConnection *connection, GHIBuffer *buffer, char *data, int size)
{
    if (connection == 0)
        return 0;
    if (buffer == 0)
        return 0;
    if (data == 0)
        return 0;
    if (size <= 0)
        return 0;
    buffer->connection = connection;
    buffer->data = data;
    buffer->size = size;
    buffer->len = 0;
    buffer->pos = 0;
    buffer->sizeIncrement = 0;
    buffer->fixed = 1;
    buffer->dontFree = 1;
    buffer->readOnly = 0;
    *data = 0;
    return 1;
}


void ghiFreeBuffer(GHIBuffer *buffer)
{
    if (buffer == 0 || buffer->data == 0)
        return;
    if (buffer->dontFree == 0)
        gsifree(buffer->data);
    MSL_C_LIB_MemsetPtr(buffer, 0, sizeof(GHIBuffer));
}


int ghiAppendDataToBuffer(GHIBuffer *buffer, char *data, int dataLen)
{
    int newLen;
    if (buffer == 0)
        return 0;
    if (data == 0)
        return 0;
    if (dataLen < 0)
        return 0;
    if (buffer->readOnly != 0)
        return 0;
    if (dataLen == 0)
        dataLen = strlen((unsigned char *)data);
    newLen = buffer->len + dataLen;
    while (newLen >= buffer->size) {
        if (buffer->fixed != 0) {
            buffer->connection->completed = 1;
            buffer->connection->result = 2;
            return 0;
        }
        if (ghiResizeBuffer(buffer, buffer->sizeIncrement) == 0) {
            buffer->connection->completed = 1;
            buffer->connection->result = 1;
            return 0;
        }
    }
    memcpy(buffer->data + buffer->len, data, dataLen);
    buffer->len = newLen;
    buffer->data[newLen] = 0;
    return 1;
}


/*
 * sdk:      ghiEncryptDataToBuffer (ghttpbuffer.o)
 */
int ghiEncryptDataToBuffer(GHIBuffer *buffer, const char *data, int dataLen)
{
    int result;
    int bufSpace = 0;
    int pos = 0;

    if (buffer == 0)
        return 0;
    if (data == 0)
        return 0;
    if (dataLen < 0)
        return 0;
    if (buffer->readOnly)
        return 0;

    if (buffer->connection->encryptor.engine == 0 ||
        buffer->connection->encryptor.sessionEstablished == 0)
        return ghiAppendDataToBuffer(buffer, (char *)data, dataLen);

    if (dataLen == 0)
        dataLen = strlen((unsigned char *)data);
    if (dataLen == 0)
        return 1;

    bufSpace = buffer->size - buffer->len;
    do {
        int fragmentLen = dataLen;
        if (fragmentLen >= 0x3f01)
            fragmentLen = 0x3f01;
        result = buffer->connection->encryptor.encryptFunc(
            buffer->connection, &buffer->connection->encryptor,
            data + pos, dataLen, buffer->data + buffer->len, &bufSpace);
        if (result == 2) {
            if (ghiResizeBuffer(buffer, buffer->sizeIncrement) == 0)
                return 0;
            bufSpace = buffer->size - buffer->len;
        } else if (result == 1) {
            pos += fragmentLen;
            buffer->len = buffer->size - bufSpace;
        } else {
            gsDebugFormat((int)8, (int)4, 2, sGhttpGhiencryptdatatobufferEncounteredUnhandledReturnCode, result);
            return 0;
        }
    } while (pos < dataLen);
    return 1;
}


int ghiAppendHeaderToBuffer(GHIBuffer *buffer, char *name, char *value)
{
    if (ghiAppendDataToBuffer(buffer, name, 0) == 0)
        return 0;
    if (ghiAppendDataToBuffer(buffer, sGhttpHeaderSeparator, 2) == 0)
        return 0;
    if (ghiAppendDataToBuffer(buffer, value, 0) == 0)
        return 0;
    if (ghiAppendDataToBuffer(buffer, sGhttpLineEndBuffer, 2) == 0)
        return 0;
    return 1;
}


/*
 * sdk:      ghiAppendCharToBuffer (ghttpbuffer.o)
 */
int ghiAppendCharToBuffer(GHIBuffer *buffer, int ch)
{
    if (buffer == 0)
        return 0;
    if (buffer->readOnly != 0)
        return 0;
    if (buffer->len + 1 >= buffer->size) {
        if (buffer->fixed != 0) {
            buffer->connection->completed = 1;
            buffer->connection->result = 2;
            return 0;
        }
        if (ghiResizeBuffer(buffer, buffer->sizeIncrement) != 0)
            goto append;
        buffer->connection->completed = 1;
        buffer->connection->result = 1;
        return 0;
    }
append:
    buffer->data[buffer->len] = ch;
    buffer->len++;
    buffer->data[buffer->len] = 0;
    return 1;
}


/*
 * sdk:      ghiAppendIntToBuffer (ghttpbuffer)
 */
int ghiAppendIntToBuffer(GHIBuffer *buffer, int i)
{
    char intValue[16];
    OS_SPrintf(intValue, sGhttpIntFormatBuffer, i);
    return ghiAppendDataToBuffer(buffer, intValue, 0);
}


void ghiResetBuffer(GHIBuffer *buffer)
{
    buffer->len = 0;
    buffer->pos = 0;
    if (buffer->readOnly == 0)
        buffer->data[0] = 0;
}


/*
 * sdk:      ghiSendBufferedData (libdwcgsghttp.TWL.HYB.a ghttpbuffer.o)
 *
 * The -2/-1 tail needs the goto spelling (return-1 label between the
 * return-0 and the loop continuation) to keep the returns unpredicated.
 */
int ghiSendBufferedData(GHIConnection *connection)
{
    int writeFlag;
    int exceptFlag;
    int rcode;

    for (;;) {
        if (connection->encryptor.engine == 0 || connection->encryptor.encryptOnBuffer == 1) {
            rcode = GSISocketSelect(connection->socket, 0, &writeFlag, &exceptFlag);
            if (rcode == -1 || (rcode == 1 && exceptFlag != 0)) {
                connection->completed = 1;
                connection->result = 5;
                connection->socketError = (rcode == -1) ? GOAGetLastError(connection->socket) : 0;
                return 0;
            }
            if (rcode < 1 || writeFlag == 0)
                return 1;
        }
        rcode = ghiDoSend(connection, connection->sendBuffer.data + connection->sendBuffer.pos, connection->sendBuffer.len - connection->sendBuffer.pos);
        if (rcode == -2)
            goto done;
        if (rcode != -1)
            goto cont;
        return 0;
    done:
        return 1;
    cont:
        connection->sendBuffer.pos += rcode;
        if (connection->sendBuffer.pos >= connection->sendBuffer.len)
            return 1;
    }
}
