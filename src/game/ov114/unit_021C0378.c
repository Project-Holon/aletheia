/*
 * file:     unit_021C0378.c
 * unit:     yes
 * function: func_021C0378, func_021C04D4, func_021C0684, func_021C07B8
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
 *   func_021BFB90  0x021bfb90  arm   ov114
 *   func_0217D254  0x0217d254  arm   ov009
 *   func_021C00FC  0x021c00fc  arm   ov114
 *   func_02092364  0x02092364  arm
 *   g_021CE5B4     0x021ce5b4  data  ov114
 *   func_0217F264                    0x0217f264 arm  ov009
 *   func_021C1C80                    0x021c1c80 arm  ov114
 *   func_0217EC4C                    0x0217ec4c arm  ov009
 *   func_0217ED54                    0x0217ed54 arm  ov009
 *   g_021CE5AC                       0x021ce5ac data
 *   g_021CE60C                       0x021ce60c data
 *   func_021C1C78  0x021c1c78  arm  ov114
 *   send           0x0217ec90  arm  ov009
 *   GOAGetLastError 0x0217ed54 arm  ov009
 *   ghiEncryptDataToBuffer  0x021BFDEC arm ov114
 *   ghiSendBufferedData     0x021C011C arm ov114
 *   ghiResetBuffer          0x021C00FC arm ov114
 *   ghiDoSend               0x021C0684 arm ov114
 *   ghiAppendDataToBuffer   0x021BFCEC arm ov114
 */
#include "../../matched/include/G_GHIThrottle.h"

struct GHIConnection_021C0378;
typedef int (*GHIDecryptFunc)(struct GHIConnection_021C0378 *connection, void *encryptor,
                              char *readPos, int *readLen,
                              char *writePos, int *writeLen);

typedef struct GHIBuffer_021C0378 {
    struct GHIConnection_021C0378 *connection;
    char *data;
    int size;
    int len;
    int pos;
    int sizeIncrement;
    int fixed;
    int dontFree;
    int readOnly;
} GHIBuffer_021C0378;

typedef struct GHIConnection_021C0378 {
    char pad0[0xa0];
    GHIBuffer_021C0378 decodedBuffer;
    GHIBuffer_021C0378 recvBuffer;
    char pad1[0x194 - 0xe8];
    char encryptor[0x1c4 - 0x194];
    GHIDecryptFunc decryptFunc;
} GHIConnection_021C0378;

typedef struct GHIThrottle GHIThrottle;

typedef struct GHIConnection_021C04D4 {
    char pad0[0x40];
    int result;                 /* +0x040 */
    char pad44[0x50 - 0x44];
    int socket;                 /* +0x050 */
    int socketError;            /* +0x054 */
    char pad58[0x124 - 0x58];
    int completed;              /* +0x124 */
    char pad128[0x158 - 0x128];
    int connectionClosed;       /* +0x158 */
    int throttle;               /* +0x15c */
    unsigned int lastThrottleRecv; /* +0x160 */
    char pad164[0x194 - 0x164];
    char encryptor[4];          /* +0x194 */
    int engine;                 /* +0x198 */
    char pad19c[0x1a4 - 0x19c];
    int sessionEstablished;     /* +0x1a4 */
    char pad1a8[0x1ac - 0x1a8];
    int encryptOnSend;          /* +0x1ac */
} GHIConnection_021C04D4;

typedef struct GHIConnection_021C0684 {
    unsigned char pad0[0x10];
    int f10;
    unsigned char pad1[0x40 - 0x14];
    int f40;
    unsigned char pad2[0x50 - 0x44];
    int f50;
    int f54;
    unsigned char pad3[0x124 - 0x58];
    int f124;
    unsigned char pad4[0x170 - 0x128];
    int f170;
    unsigned char pad5[0x180 - 0x174];
    int f180;
    unsigned char pad6[0x194 - 0x184];
    int f194;
    int f198;
    unsigned char pad7[0x1a4 - 0x19c];
    int f1a4;
    unsigned char pad8[0x1ac - 0x1a8];
    int f1ac;
} GHIConnection_021C0684;

typedef struct {
    char pad0[4];
    char *data;
    int size;
    int length;
    int pos;
    char pad1[12];
    int fixed;
    char pad2[4];
} GHIBuffer_021C07B8;

typedef struct GHIConnection_021C07B8 {
    char pad0[0x58];
    GHIBuffer_021C07B8 sendBuffer;
    char pad1[0x118];
    int encrypt;
    char pad2[8];
    int encryptState;
    int encryptSent;
} GHIConnection_021C07B8;

extern int func_021BFB90(GHIBuffer_021C0378 *, int);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_021C00FC(GHIBuffer_021C0378 *);
extern void *func_02092364(void *, const void *, unsigned int);
extern unsigned int func_0217F264(void);
extern int func_021C1C80(void *connection, void *encryptor, char *buffer, int *bufferLen);
extern int func_0217EC4C(int sock, char *buf, int len, int flags);
extern int func_0217ED54(int sock);
extern int func_021C1C78(void *a0, void *a1, char *a2, int a3, int *a4);
extern int send(int, char *, int, int);
extern int GOAGetLastError(int);
extern int ghiEncryptDataToBuffer(GHIBuffer_021C07B8 *buffer, char *data, int dataLen);
extern int ghiSendBufferedData(GHIConnection_021C07B8 *connection);
extern void ghiResetBuffer(GHIBuffer_021C07B8 *buffer);
extern int ghiDoSend(GHIConnection_021C07B8 *connection, char *buffer, int len);
extern int ghiAppendDataToBuffer(GHIBuffer_021C07B8 *buffer, char *data, int dataLen);
int func_021C0378(GHIConnection_021C0378 *connection);
int func_021C04D4(GHIConnection_021C04D4 *connection, char *buffer, int *bufferLen);
int func_021C0684(GHIConnection_021C0684 *connection, char *buffer, int len);
int func_021C07B8(GHIConnection_021C07B8 *connection, char *buffer, int len);
extern char g_021CE5B4[];
extern struct GHIThrottle g_021CE5AC;
extern char g_021CE60C[];


/*
 * sdk:      ghiDecryptReceivedData (libdwcgsghttp.TWL.HYB.a ghttpcommon.o)
 */
int func_021C0378(GHIConnection_021C0378 *connection)
{
    int aResult;
    char *aReadPos;
    char *aWritePos;
    int aReadLen = 0;
    int aWriteLen = 0;
    int bytesToKeep;

    for (;;) {
        aReadPos = connection->recvBuffer.data + connection->recvBuffer.pos;
        aReadLen = connection->recvBuffer.len - connection->recvBuffer.pos;
        aWritePos = connection->decodedBuffer.data + connection->decodedBuffer.len;
        aWriteLen = connection->decodedBuffer.size - connection->decodedBuffer.len;
        aResult = connection->decryptFunc(connection, connection->encryptor,
                                          aReadPos, &aReadLen, aWritePos, &aWriteLen);
        if (aResult == 2) {
            if (func_021BFB90(&connection->decodedBuffer, connection->decodedBuffer.sizeIncrement) == 0)
                return 0;
        } else if (aResult == 3) {
            return 0;
        }
        if (aResult == 2 && aWriteLen == 0)
            continue;
        if (aReadLen > connection->recvBuffer.len) {
            func_0217D254(8, (char *)4, 1, g_021CE5B4, aReadLen, connection->recvBuffer.len);
            return 0;
        }
        connection->recvBuffer.pos += aReadLen;
        connection->decodedBuffer.len += aWriteLen;
        if (aWriteLen <= 0)
            break;
    }
    if (connection->recvBuffer.pos > 0xff) {
        bytesToKeep = connection->recvBuffer.len - connection->recvBuffer.pos;
        if (bytesToKeep == 0) {
            func_021C00FC(&connection->recvBuffer);
        } else {
            func_02092364(connection->recvBuffer.data, connection->recvBuffer.data + connection->recvBuffer.pos, bytesToKeep);
            connection->recvBuffer.pos = 0;
            connection->recvBuffer.len = bytesToKeep;
        }
    }
    return 1;
}


/*
 * sdk:      ghiDoReceive (ghttpcommon.o)
 */
int func_021C04D4(GHIConnection_021C04D4 *connection, char *buffer, int *bufferLen)
{
    int rcode;
    int socketError;
    int len;

    len = *bufferLen - 1;

    if (connection->throttle) {
        unsigned int now = func_0217F264();
        if (now < connection->lastThrottleRecv + g_021CE5AC.timeDelay)
            return 1;
        connection->lastThrottleRecv = now;
        if (len >= g_021CE5AC.bufferSize)
            len = g_021CE5AC.bufferSize;
    }

    if (connection->engine != 0 && connection->sessionEstablished == 1 &&
        connection->encryptOnSend == 1) {
        int result;
        int recvLength = len;
        result = func_021C1C80(connection, connection->encryptor, buffer, &recvLength);
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
        rcode = func_0217EC4C(connection->socket, buffer, len, 0);
        if (rcode == -1) {
            socketError = func_0217ED54(connection->socket);
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
    func_0217D254(8, 0, 0x20, g_021CE60C, rcode);
    return 0;
}


/*
 * sdk:      ghiDoSend (libdwcgsghttp.TWL.HYB.a ghttpcommon.o)
 */
int func_021C0684(GHIConnection_021C0684 *connection, char *buffer, int len)
{
    int rcode;
    int bytesSent;
    int error;

    if (buffer == 0 || len == 0)
        return 0;
    if (connection->f198 != 0 && connection->f1a4 == 1 && connection->f1ac == 1) {
        bytesSent = 0;
        if (func_021C1C78(connection, &connection->f194, buffer, len, &bytesSent) == 1) {
            rcode = bytesSent;
            if (rcode == -1)
                return -2;
        } else {
            connection->f124 = 1;
            connection->f40 = 5;
            connection->f54 = 0;
            return -1;
        }
    } else {
        rcode = send(connection->f50, buffer, len, 0);
        if (rcode == -1) {
            error = GOAGetLastError(connection->f50);
            if (error == -6 || error == -26 || error == -76)
                return 0;
            connection->f54 = error;
            connection->f124 = 1;
            connection->f40 = 5;
            return -1;
        }
    }
    if (connection->f10 == 6 && connection->f180 == 0)
        connection->f170 += rcode;
    return rcode;
}


/*
 * sdk:      ghiTrySendThenBuffer (libdwcgsghttp.TWL.HYB.a(ghttpcommon.o))
 *
 * The -2 exit must be the else of a two-guard if/else whose then-arm is the
 * -1 guard, with the `rcode == len` test as a separate if after it: that
 * places the shared `return 2` block between the return 0 and the len test
 * and keeps the -1 guard a real bne instead of a predicated return
 * (docs/idioms/a-bare-constant-return-guard-is-predicated-unless-its-exit-is-shared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov114_func_021C07B8.c \
 *     --func func_021C07B8 --addr 0x021C07B8 --region ov114 --arm --cc 1.1p1 --lang c99
 *   (--cc 1.2 is byte-identical)
 */
int func_021C07B8(GHIConnection_021C07B8 *connection, char *buffer, int len)
{
    int rcode = 0;
    if (connection->encrypt != 0 && connection->encryptState == 1 && connection->encryptSent == 1)
    {
        if (ghiEncryptDataToBuffer(&connection->sendBuffer, buffer, len) == 0)
            return 0;
        if (ghiSendBufferedData(connection) == 0)
            return 0;
        if (connection->sendBuffer.pos < connection->sendBuffer.length)
            return 2;
        ghiResetBuffer(&connection->sendBuffer);
        return 1;
    }
    if (connection->sendBuffer.pos >= connection->sendBuffer.length)
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
