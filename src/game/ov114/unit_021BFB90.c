/*
 * file:     unit_021BFB90.c
 * unit:     yes
 * function: func_021BFB90, func_021BFBD0, func_021BFC54, func_021BFCB4, func_021BFCEC, func_021BFDEC, func_021BFF7C, func_021C0004, func_021C00C0, func_021C00FC, func_021C011C
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
 *   memset                  0x020923B0  arm
 *   strlen           0x0209477c arm
 *   ghiResizeBuffer  0x021bfb90 arm  ov114
 *   memcpy           0x02092344 arm
 *   func_0209477C                    0x0209477c arm
 *   func_0217D254                    0x0217d254 arm  ov009
 *   g_021CE54C                       0x021ce54c data ov114
 *   ghiAppendDataToBuffer  0x021BFCEC arm ov114
 *   g_021CE58C             0x021CE58C data
 *   g_021CE590             0x021CE590 data
 *   OS_SPrintf             0x02084F40 arm
 *   g_021CE594             0x021CE594 data
 *   GSISocketSelect  0x0217ed64  arm  ov009
 *   GOAGetLastError  0x0217ed54  arm  ov009
 *   func_021C0684    0x021c0684  arm  ov114
 */
#include "ghttp_types.h"


extern void *gsirealloc(void *ptr, unsigned long size);
extern void gsifree(void *ptr);
extern void *memset(void *dst, int c, unsigned int n);
extern unsigned int strlen(const char *);
extern void *memcpy(void *, const void *, unsigned int);
extern int func_0209477C(const u8 *s);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int ghiAppendDataToBuffer(GHIBuffer *buffer, char *data, int dataLen);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern int GSISocketSelect(int, int *, int *, int *);
extern int GOAGetLastError(int);
extern int func_021C0684(GHIConnection *, char *, int);
int func_021BFB90(GHIBuffer *buffer, int sizeIncrement);
int func_021BFBD0(unsigned int a0, unsigned int *a1, int a2, int a3);
int func_021BFC54(int a, int *out, char *buf, int n);
void ghiFreeBuffer(GHIBuffer *buffer);
int func_021BFCEC(GHIBuffer *buffer, char *data, int dataLen);
int func_021BFDEC(GHIBuffer *buffer, const char *data, int dataLen);
int func_021BFF7C(GHIBuffer *buffer, char *name, char *value);
int func_021C0004(GHIBuffer *ctx, int ch);
int func_021C00C0(GHIBuffer *buffer, int i);
void func_021C00FC(GHIBuffer *buffer);
int func_021C011C(GHIConnection *connection);
extern char g_021CE54C[];
extern char g_021CE58C[];
extern char g_021CE590[];
extern char g_021CE594[];


int func_021BFB90(GHIBuffer *buffer, int sizeIncrement)
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


int func_021BFBD0(unsigned int a0, unsigned int *a1, int a2, int a3)
{
    if (a0 == 0)
        return 0;
    if (a1 == 0)
        return 0;
    if (a2 <= 0)
        return 0;
    if (a3 <= 0)
        return 0;
    a1[0] = a0;
    a1[1] = 0;
    a1[2] = 0;
    a1[3] = 0;
    a1[4] = 0;
    a1[5] = (unsigned int)a3;
    a1[6] = 0;
    a1[7] = 0;
    a1[8] = 0;
    if (func_021BFB90((GHIBuffer *)a1, a2) == 0)
        return 0;
    *(char *)a1[1] = 0;
    return 1;
}


int func_021BFC54(int a, int *out, char *buf, int n)
{
    if (a == 0)
        return 0;
    if (out == 0)
        return 0;
    if (buf == 0)
        return 0;
    if (n <= 0)
        return 0;
    out[0] = a;
    out[1] = (int)buf;
    out[2] = n;
    out[3] = 0;
    out[4] = 0;
    out[5] = 0;
    out[6] = 1;
    out[7] = 1;
    out[8] = 0;
    *buf = 0;
    return 1;
}


void ghiFreeBuffer(GHIBuffer *buffer)
{
    if (buffer == 0 || buffer->data == 0)
        return;
    if (buffer->dontFree == 0)
        gsifree(buffer->data);
    memset(buffer, 0, sizeof(GHIBuffer));
}


int func_021BFCEC(GHIBuffer *buffer, char *data, int dataLen)
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
        dataLen = strlen(data);
    newLen = buffer->len + dataLen;
    while (newLen >= buffer->size) {
        if (buffer->fixed != 0) {
            buffer->connection->completed = 1;
            buffer->connection->result = 2;
            return 0;
        }
        if (func_021BFB90((GHIBuffer *)buffer, buffer->sizeIncrement) == 0) {
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
int func_021BFDEC(GHIBuffer *buffer, const char *data, int dataLen)
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
        return func_021BFCEC((GHIBuffer *)buffer, (char *)data, dataLen);

    if (dataLen == 0)
        dataLen = func_0209477C((const u8 *)data);
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
            if (func_021BFB90((GHIBuffer *)buffer, buffer->sizeIncrement) == 0)
                return 0;
            bufSpace = buffer->size - buffer->len;
        } else if (result == 1) {
            pos += fragmentLen;
            buffer->len = buffer->size - bufSpace;
        } else {
            func_0217D254(8, (char *)4, 2, g_021CE54C, result);
            return 0;
        }
    } while (pos < dataLen);
    return 1;
}


int func_021BFF7C(GHIBuffer *buffer, char *name, char *value)
{
    if (ghiAppendDataToBuffer(buffer, name, 0) == 0)
        return 0;
    if (ghiAppendDataToBuffer(buffer, g_021CE58C, 2) == 0)
        return 0;
    if (ghiAppendDataToBuffer(buffer, value, 0) == 0)
        return 0;
    if (ghiAppendDataToBuffer(buffer, g_021CE590, 2) == 0)
        return 0;
    return 1;
}


int func_021C0004(GHIBuffer *ctx, int ch)
{
    if (ctx == 0)
        return 0;
    if (ctx->readOnly != 0)
        return 0;
    if (ctx->len + 1 >= ctx->size) {
        if (ctx->fixed != 0) {
            ctx->connection->completed = 1;
            ctx->connection->result = 2;
            return 0;
        }
        if (func_021BFB90((GHIBuffer *)ctx, ctx->sizeIncrement) != 0)
            goto append;
        ctx->connection->completed = 1;
        ctx->connection->result = 1;
        return 0;
    }
append:
    ctx->data[ctx->len] = ch;
    ctx->len++;
    ctx->data[ctx->len] = 0;
    return 1;
}


/*
 * sdk:      ghiAppendIntToBuffer (ghttpbuffer)
 */
int func_021C00C0(GHIBuffer *buffer, int i)
{
    char intValue[16];
    OS_SPrintf(intValue, g_021CE594, i);
    return ghiAppendDataToBuffer(buffer, intValue, 0);
}


void func_021C00FC(GHIBuffer *buffer)
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
int func_021C011C(GHIConnection *connection)
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
        rcode = func_021C0684(connection, connection->sendBuffer.data + connection->sendBuffer.pos, connection->sendBuffer.len - connection->sendBuffer.pos);
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
