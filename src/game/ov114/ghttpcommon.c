/*
 * file:     ghttpcommon.c
 * unit:     yes
 * function: ghiDecryptReceivedData, ghiDoReceive, ghiDoSend, ghiTrySendThenBuffer
 * address:  0x021C0378
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
 *   ghiResizeBuffer  0x021bfb90  arm   ov114
 *   gsDebugFormat  0x0217d254  arm   ov009
 *   ghiResetBuffer  0x021c00fc  arm   ov114
 *   memmove  0x02092364  arm
 *   sGhttpGhidecryptreceiveddataReadPastTheEnd     0x021ce5b4  data  ov114
 *   current_time                    0x0217f264 arm  ov009
 *   ghiEncryptorSslReceiveFunc                    0x021c1c80 arm  ov114
 *   recv                    0x0217ec4c arm  ov009
 *   GOAGetLastError                    0x0217ed54 arm  ov009
 *   gGhttpThrottle                       0x021ce5ac data
 *   sGhttpReceivedBytes                       0x021ce60c data
 *   ghiEncryptorSslSendFunc  0x021c1c78  arm  ov114
 *   send           0x0217ec90  arm  ov009
 *   GOAGetLastError 0x0217ed54 arm  ov009
 *   ghiEncryptDataToBuffer  0x021BFDEC arm ov114
 *   ghiSendBufferedData     0x021C011C arm ov114
 *   ghiResetBuffer          0x021C00FC arm ov114
 *   ghiDoSend               0x021C0684 arm ov114
 *   ghiAppendDataToBuffer   0x021BFCEC arm ov114
 */
#include "ghttp_types.h"


#include "ghttpbuffer.h"
#include "../ov009/gsdebug.h"
#include "../arm9/msl_string_mem.h"
#include "../ov009/gsplatformutil.h"
#include "ghttpEncryption.h"
#include "../ov009/gsplatformsocket.h"
extern int ghiDoSend(GHIConnection *connection, char *buffer, int len);
int ghiDecryptReceivedData(GHIConnection *connection);
int ghiDoReceive(GHIConnection *connection, char *buffer, int *bufferLen);
int ghiTrySendThenBuffer(GHIConnection *connection, char *buffer, int len);
extern char sGhttpGhidecryptreceiveddataReadPastTheEnd[];
extern GHIThrottle gGhttpThrottle;
extern char sGhttpReceivedBytes[];


/*
 * sdk:      ghiDecryptReceivedData (libdwcgsghttp.TWL.HYB.a ghttpcommon.o)
 */
int ghiDecryptReceivedData(GHIConnection *connection)
{
    int aResult;
    char *aReadPos;
    char *aWritePos;
    int aReadLen = 0;
    int aWriteLen = 0;
    int bytesToKeep;

    for (;;) {
        aReadPos = connection->decodeBuffer.data + connection->decodeBuffer.pos;
        aReadLen = connection->decodeBuffer.len - connection->decodeBuffer.pos;
        aWritePos = connection->recvBuffer.data + connection->recvBuffer.len;
        aWriteLen = connection->recvBuffer.size - connection->recvBuffer.len;
        aResult = connection->encryptor.decryptFunc(connection, &connection->encryptor,
                                          aReadPos, &aReadLen, aWritePos, &aWriteLen);
        if (aResult == 2) {
            if (ghiResizeBuffer(&connection->recvBuffer, connection->recvBuffer.sizeIncrement) == 0)
                return 0;
        } else if (aResult == 3) {
            return 0;
        }
        if (aResult == 2 && aWriteLen == 0)
            continue;
        if (aReadLen > connection->decodeBuffer.len) {
            gsDebugFormat((int)8, (int)4, 1, sGhttpGhidecryptreceiveddataReadPastTheEnd, aReadLen, connection->decodeBuffer.len);
            return 0;
        }
        connection->decodeBuffer.pos += aReadLen;
        connection->recvBuffer.len += aWriteLen;
        if (aWriteLen <= 0)
            break;
    }
    if (connection->decodeBuffer.pos > 0xff) {
        bytesToKeep = connection->decodeBuffer.len - connection->decodeBuffer.pos;
        if (bytesToKeep == 0) {
            ghiResetBuffer(&connection->decodeBuffer);
        } else {
            memmove(connection->decodeBuffer.data, connection->decodeBuffer.data + connection->decodeBuffer.pos, bytesToKeep);
            connection->decodeBuffer.pos = 0;
            connection->decodeBuffer.len = bytesToKeep;
        }
    }
    return 1;
}


/*
 * sdk:      ghiDoReceive (ghttpcommon.o)
 */
int ghiDoReceive(GHIConnection *connection, char *buffer, int *bufferLen)
{
    int rcode;
    int socketError;
    int len;

    len = *bufferLen - 1;

    if (connection->throttle) {
        unsigned int now = current_time();
        if (now < connection->lastThrottleRecv + gGhttpThrottle.timeDelay)
            return 1;
        connection->lastThrottleRecv = now;
        if (len >= gGhttpThrottle.bufferSize)
            len = gGhttpThrottle.bufferSize;
    }

    if (connection->encryptor.engine != 0 && connection->encryptor.sessionEstablished == 1 &&
        connection->encryptor.encryptOnSend == 1) {
        int result;
        int recvLength = len;
        result = ghiEncryptorSslReceiveFunc(connection, &connection->encryptor, buffer, &recvLength);
        if (result == 1) {
            if (recvLength == -1)
                return 1;
            rcode = recvLength;
        } else {
            connection->completed = 1;
            connection->result = 5;
            connection->socketError = 0;
            connection->connectionClosed = 1;
            return 3;
        }
    } else {
        rcode = recv(connection->socket, buffer, len, 0);
        if (rcode == -1) {
            socketError = GOAGetLastError(connection->socket);
            if (socketError == -56) {
                connection->connectionClosed = 1;
                return 2;
            }
            if (socketError == -6 || socketError == -26 || socketError == -76)
                return 1;
            connection->socketError = socketError;
            connection->completed = 1;
            connection->result = 5;
            connection->connectionClosed = 1;
            return 3;
        }
    }

    if (rcode == 0) {
        connection->connectionClosed = 1;
        return 2;
    }

    buffer[rcode] = 0;
    *bufferLen = rcode;
    gsDebugFormat(8, 0, 0x20, sGhttpReceivedBytes, rcode);
    return 0;
}


/*
 * sdk:      ghiDoSend (libdwcgsghttp.TWL.HYB.a ghttpcommon.o)
 */
int ghiDoSend(GHIConnection *connection, char *buffer, int len)
{
    int rcode;
    int bytesSent;
    int error;

    if (buffer == 0 || len == 0)
        return 0;
    if (connection->encryptor.engine != 0 && connection->encryptor.sessionEstablished == 1 && connection->encryptor.encryptOnSend == 1) {
        bytesSent = 0;
        if (ghiEncryptorSslSendFunc(connection, &connection->encryptor, buffer, len, &bytesSent) == 1) {
            rcode = bytesSent;
            if (rcode == -1)
                return -2;
        } else {
            connection->completed = 1;
            connection->result = 5;
            connection->socketError = 0;
            return -1;
        }
    } else {
        rcode = send(connection->socket, buffer, len, 0);
        if (rcode == -1) {
            error = GOAGetLastError(connection->socket);
            if (error == -6 || error == -26 || error == -76)
                return 0;
            connection->socketError = error;
            connection->completed = 1;
            connection->result = 5;
            return -1;
        }
    }
    if (connection->state == 6 && connection->postingState.waitPostContinue == 0)
        connection->postingState.bytesPosted += rcode;
    return rcode;
}


/*
 * sdk:      ghiTrySendThenBuffer (libdwcgsghttp.TWL.HYB.a(ghttpcommon.o))
 *
 * The -2 exit must be the else of a two-guard if/else whose then-arm is the
 * -1 guard, with the `rcode == len` test as a separate if after it: that
 * places the shared `return 2` block between the return 0 and the len test
 * and keeps the -1 guard a real bne instead of a predicated return.
 */
int ghiTrySendThenBuffer(GHIConnection *connection, char *buffer, int len)
{
    int rcode = 0;
    if (connection->encryptor.engine != 0 && connection->encryptor.sessionEstablished == 1 && connection->encryptor.encryptOnBuffer == 1)
    {
        if (ghiEncryptDataToBuffer(&connection->sendBuffer, buffer, len) == 0)
            return 0;
        if (ghiSendBufferedData(connection) == 0)
            return 0;
        if (connection->sendBuffer.pos < connection->sendBuffer.len)
            return 2;
        ghiResetBuffer(&connection->sendBuffer);
        return 1;
    }
    if (connection->sendBuffer.pos >= connection->sendBuffer.len)
    {
        rcode = ghiDoSend(connection, buffer, len);
        if (rcode != -2) {
            if (rcode == -1)
                return 0;
        } else {
            return 2;
        }
        if (rcode == len)
            return 1;
    }
    if (ghiAppendDataToBuffer(&connection->sendBuffer, buffer + rcode, len - rcode) == 0)
        return 0;
    return 2;
}
