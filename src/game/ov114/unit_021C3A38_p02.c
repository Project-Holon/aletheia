/*
 * file:     unit_021C3A38_p02.c
 * unit:     yes
 * function: func_021C4E68, func_021C4E7C, func_021C5430
 * address:  0x021C4E68
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
 *   gsimalloc                       0x0217eab0 arm
 *   ghiDoReceive                    0x021c04d4 arm  ov114
 *   ghiFreeTempBuffer               0x021c4e68 arm  ov114
 *   ghiAppendDataToBuffer           0x021bfcec arm  ov114
 *   ghiDecryptReceivedData          0x021c0378 arm  ov114
 *   strncmp                         0x020949f4 arm
 *   strstr                          0x02094b20 arm
 *   memmove                         0x02092364 arm
 *   ghiResetBuffer                  0x021c00fc arm  ov114
 *   ghiCallProgressCallback         0x021c02c8 arm  ov114
 *   strlen                          0x0209477c arm
 *   OS_SPrintf                      0x02084f40 arm
 *   goastrdup                       0x0217f1e0 arm
 *   atoi                            0x020964e0 arm
 *   ghiProcessIncomingFileData      0x021c4c50 arm  ov114
 *   GOAGetLastError                 0x0217ed54 arm
 *   g_021CF194                      0x021cf194 data
 *   g_021CF2BC                      0x021cf2bc data
 *   g_021CF2C0                      0x021cf2c0 data
 *   g_021CF2C8                      0x021cf2c8 data
 *   __ctype_mapC                    0x020a61dc data a2
 *   g_021CF2D4                      0x021cf2d4 data
 *   g_021CF2E4                      0x021cf2e4 data
 *   g_021CE0B8                      0x021ce0b8 data
 *   @13998                          0x021ce0b8 data
 *   g_021CF2F4                      0x021cf2f4 data
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_021C04D4  0x021C04D4  arm  ov114
 *   func_021BFCEC  0x021BFCEC  arm  ov114
 *   func_021C0378  0x021C0378  arm  ov114
 *   func_021C4C50  0x021C4C50  arm  ov114
 *   g_021CF310     0x021CF310  data
 *   g_021CF320     0x021CF320  data
 */
#define ISSPACE(c) (((unsigned)(c) < 0x80u) ? (__ctype_mapC[c] & 0x100) : 0)
#define ISSPACE2(c) (((unsigned)(c) < 0x80u) ? (__ctype_mapC[c] & 0x100) : 0)
struct GHIBuffer_021C5430;
struct GHIConnection_021C5430;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct GHIBuffer_021C4E7C {
    void *connection;
    char *data;
    int size;
    int length;
    int position;
    int fixed;
    int dontFree;
    int readOnly;
    int pad;
} GHIBuffer_021C4E7C;

typedef struct GHIEncryptor {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int pad[8];
} GHIEncryptor;

typedef struct GHIPostingState {
    int f[8];
} GHIPostingState;

typedef struct GHIConnection_021C4E7C {
    int inUse;
    int request;
    int uniqueID;
    int type;
    int state;
    char *URL;
    char *serverAddress;
    unsigned int serverIP;
    u16 serverPort;
    char *requestPath;
    int protocol;
    char *sendHeaders;
    void *saveFile;
    char *saveFileName;
    int blocking;
    int persistConnection;
    int result;
    void *progressCallback;
    void *completedCallback;
    void *callbackParam;
    int socket;
    int socketError;
    GHIBuffer_021C4E7C sendBuffer;
    GHIBuffer_021C4E7C encodeBuffer;
    GHIBuffer_021C4E7C recvBuffer;
    GHIBuffer_021C4E7C decodeBuffer;
    GHIBuffer_021C4E7C getFileBuffer;
    int userBufferSupplied;
    int statusMajorVersion;
    int statusMinorVersion;
    int statusCode;
    int statusStringIndex;
    int headerStringIndex;
    int completed;
    int fileBytesReceived;
    int totalSize;
    char *redirectURL;
    int redirectCount;
    int chunkedTransfer;
    char chunkHeader[11];
    int chunkHeaderLen;
    int chunkBytesLeft;
    int chunkReadingState;
    int processing;
    int connectionClosed;
    int throttle;
    unsigned int lastThrottleRecv;
    void *post;
    GHIPostingState postingState;
    unsigned int maxRecvTime;
    char *proxyOverrideServer;
    u16 proxyOverridePort;
    GHIEncryptor encryptor;
    void *handle;
    unsigned int receiveFileIdleTime;
} GHIConnection_021C4E7C;

typedef struct {
    void *connection;
    char *data;
    int size;
    int len;
    int pos;
    char pad14[0x10];
} GHIBuffer_021C5430;

typedef struct {
    char pad000[0x40];
    int result;                 /* 0x040 */
    char pad044[0x5C];
    GHIBuffer_021C5430 recvBuffer;       /* 0x0A0 */
    GHIBuffer_021C5430 decodeBuffer;     /* 0x0C4 */
    char pad0E8[0x3C];
    int completed;              /* 0x124 */
    int fileBytesReceived;      /* 0x128 */
    int totalSize;              /* 0x12C */
    char pad130[0x58];
    unsigned int maxRecvTime;   /* 0x188 */
    char pad18C[0x0C];
    void *encryptEngine;        /* 0x198 */
    char pad19C[0x0C];
    int sessionEstablished;     /* 0x1A8 */
    char pad1AC[0x24];
    unsigned int lastReceiveTime; /* 0x1D0 */
} GHIConnection_021C5430;

extern void func_0217EAE0(int);
extern int strncmp(const char *p1, const char *p2, unsigned long n);
extern char *strstr(const char *haystack, const char *needle);
extern unsigned long strlen(const char *p);
extern void *gsimalloc(unsigned long size);
extern int ghiDoReceive(GHIConnection_021C4E7C *connection, char *buffer, int *bufferLen);
extern void ghiFreeTempBuffer(char *buffer);
extern int ghiAppendDataToBuffer(GHIBuffer_021C4E7C *buffer, char *data, int dataLen);
extern int ghiDecryptReceivedData(GHIConnection_021C4E7C *connection);
extern void *memmove(void *dst, const void *src, unsigned long n);
extern void ghiResetBuffer(GHIBuffer_021C4E7C *buffer);
extern void ghiCallProgressCallback(GHIConnection_021C4E7C *connection, char *buffer, int bufferLen);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern char *goastrdup(char *src);
extern int atoi(const char *p);
extern int ghiProcessIncomingFileData(GHIConnection_021C4E7C *connection, char *data, int len);
extern int GOAGetLastError(int socket);
extern unsigned int func_0217F264(void);
extern void *func_0217EAB0(unsigned long size);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_021C04D4(struct GHIConnection_021C5430 *connection, char *buffer, int *bufferLen);
extern int func_021BFCEC(struct GHIBuffer_021C5430 *buffer, char *data, int dataLen);
extern int func_021C0378(struct GHIConnection_021C5430 *connection);
extern int func_021C4C50(struct GHIConnection_021C5430 *connection, char *data, int len);
void func_021C4E68(int a);
void func_021C4E7C(GHIConnection_021C4E7C *connection);
void func_021C5430(GHIConnection_021C5430 *connection);
extern char g_021CF194[];
extern char g_021CF2BC[];
extern char g_021CF2C0[];
extern char g_021CF2C8[];
extern u16 __ctype_mapC[];
extern char g_021CF2D4[];
extern char g_021CF2E4[];
extern char g_021CE0B8[];
extern char g_021CF2F4[];
extern char g_021CF310[];
extern char g_021CF320[];


/*
 * Null-guarded release through the ov009 helper at 0x0217EAE0.
 */
void func_021C4E68(int a)
{
    if (a == 0)
        return;
    func_0217EAE0(a);
}


/*
 * sdk:      ghiDoReceivingHeaders (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * notes:    every byte and all 48 relocations resolve (the last is the
 *           vendor template @13998, declared in symbols:).  The second isspace loop (after the header-value scan) is the
 *           short-circuit `(c < 0 || c >= 0x80) ? 0 : table` form, not the unsigned
 *           fold the first loop uses.
 */
void func_021C4E7C(GHIConnection_021C4E7C *connection)
{
    int result;
    int hasHeaders;
    char *headers;
    char *endOfHeaders;
    int bufferLen;
    char *buffer;
    char *fileStart;
    int fileLength;
    char *contentLength;
    char *location;
    char *end;
    int nMaxLen;

    nMaxLen = 0x1000;
    hasHeaders = 1;
    buffer = gsimalloc(nMaxLen);
    if (buffer == 0) {
        connection->completed = 1;
        connection->result = 1;
        return;
    }
    bufferLen = nMaxLen;
    result = ghiDoReceive(connection, buffer, &bufferLen);
    if (result == 3) {
        ghiFreeTempBuffer(buffer);
        return;
    }
    if (result == 1) {
        ghiFreeTempBuffer(buffer);
        return;
    }
    if (result == 0) {
        if (connection->encryptor.f4 != 0 && connection->encryptor.f14 == 1) {
            if (ghiAppendDataToBuffer(&connection->decodeBuffer, buffer, bufferLen) == 0) {
                ghiFreeTempBuffer(buffer);
                return;
            }
            if (ghiDecryptReceivedData(connection) == 0) {
                connection->completed = 1;
                connection->result = 0x11;
                ghiFreeTempBuffer(buffer);
                return;
            }
        } else {
            if (ghiAppendDataToBuffer(&connection->recvBuffer, buffer, bufferLen) == 0) {
                ghiFreeTempBuffer(buffer);
                return;
            }
        }
    }

    headers = connection->recvBuffer.data + connection->headerStringIndex;
    if (connection->statusCode / 100 == 1 &&
        (strncmp(headers, g_021CF194, 2) == 0 ||
         strncmp(headers, g_021CF2BC, 2) == 0)) {
        endOfHeaders = headers;
        hasHeaders = 0;
    } else {
        endOfHeaders = strstr(headers, g_021CF2C0);
    }
    if (endOfHeaders == 0)
        endOfHeaders = strstr(headers, g_021CF2BC);
    if (endOfHeaders != 0) {
        if (hasHeaders == 1)
            endOfHeaders += 2;
        *endOfHeaders = 0;

        fileStart = endOfHeaders + 2;
        fileLength = connection->recvBuffer.length - (fileStart - connection->recvBuffer.data);
        connection->recvBuffer.position = connection->recvBuffer.length =
            endOfHeaders - connection->recvBuffer.data + 1;

        if (connection->statusCode / 100 == 1) {
            if (fileLength != 0) {
                memmove(connection->recvBuffer.data, fileStart, fileLength + 1);
                connection->recvBuffer.length = fileLength;
            } else {
                ghiResetBuffer(&connection->recvBuffer);
            }
            if (connection->postingState.f[6] != 0) {
                connection->postingState.f[6] = 0;
                connection->state = 6;
                ghiCallProgressCallback(connection, 0, 0);
            }
            connection->state = 8;
            ghiCallProgressCallback(connection, 0, 0);
            ghiFreeTempBuffer(buffer);
            return;
        }

        result = 0;
        if (connection->statusCode / 100 == 3) {
            if (connection->redirectCount > 10) {
                connection->completed = 1;
                connection->result = 0xb;
                ghiFreeTempBuffer(buffer);
                return;
            }
            location = strstr(headers, g_021CF2C8);
            if (location != 0) {
                location += 9;
                while (ISSPACE(*location))
                    location++;
                end = location;
                while (*end != 0 && !(((*end) < 0 || (*end) >= 0x80) ? 0 : (__ctype_mapC[*end] & 0x100)))
                    end++;
                *end = 0;
                if (*location == '/') {
                    connection->redirectURL = gsimalloc(strlen(connection->serverAddress) + 14 + strlen(location));
                    if (connection->redirectURL == 0) {
                        connection->completed = 1;
                        connection->result = 1;
                    }
                    OS_SPrintf(connection->redirectURL, g_021CF2D4,
                               connection->serverAddress, connection->serverPort, location);
                } else {
                    connection->redirectURL = goastrdup(location);
                    if (connection->redirectURL == 0) {
                        connection->completed = 1;
                        connection->result = 1;
                    }
                }
                ghiFreeTempBuffer(buffer);
                return;
            }
        }

        contentLength = strstr(headers, g_021CF2E4);
        if (contentLength != 0) {
            char *pEnd;
            char *pStart;
            char szMaxSize[11] = "2147483647";
            int len;

            pStart = contentLength + 0x10;
            pEnd = pStart;
            len = strlen(szMaxSize);
            while (pEnd && *pEnd && *pEnd != '\n' && *pEnd != '\r' && *pEnd != ' ')
                pEnd++;
            if (pEnd - pStart > len) {
                connection->completed = 1;
                connection->result = 0x10;
                ghiFreeTempBuffer(buffer);
                return;
            }
            if (len == pEnd - pStart && strncmp(pStart, szMaxSize, pEnd - pStart) >= 0) {
                connection->completed = 1;
                connection->result = 0x10;
                ghiFreeTempBuffer(buffer);
                return;
            }
            connection->totalSize = atoi(pStart);
        }

        connection->chunkedTransfer = (strstr(headers, g_021CF2F4) != 0) ? 1 : 0;
        if (connection->chunkedTransfer) {
            connection->chunkHeader[0] = 0;
            connection->chunkHeaderLen = 0;
            connection->chunkBytesLeft = 0;
            connection->chunkReadingState = 0;
        }
        if (connection->type == 3 || connection->type == 4) {
            connection->completed = 1;
            ghiFreeTempBuffer(buffer);
            return;
        }

        connection->state = 0xa;
        if (contentLength != 0 && connection->totalSize == 0) {
            connection->completed = 1;
            ghiFreeTempBuffer(buffer);
            return;
        }
        if (fileLength > 0)
            ghiProcessIncomingFileData(connection, fileStart, fileLength);
    } else if (result == 2) {
        connection->completed = 1;
        connection->result = 7;
        connection->socketError = GOAGetLastError(connection->socket);
    }
    ghiFreeTempBuffer(buffer);
}


/*
 * sdk:      ghiDoReceivingFile (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void func_021C5430(GHIConnection_021C5430 *connection)
{
    int result;
    unsigned int start_time;
    unsigned int running_time;
    int bufferLen;
    char *buffer;
    int decryptedLen;

    start_time = func_0217F264();
    running_time = 0;
    bufferLen = 0;

    buffer = func_0217EAB0(0x2000);
    if (buffer == 0)
    {
        connection->completed = 1;
        connection->result = 1;
        return;
    }

    func_0217D254(8, (char *)3, 0x10, g_021CF310);

    while (!connection->completed && running_time < connection->maxRecvTime)
    {
        bufferLen = 0x2000;
        result = func_021C04D4((struct GHIConnection_021C5430 *)connection, buffer, &bufferLen);
        if (result == 1)
        {
            func_021C4E68((int)buffer);
            if (connection->lastReceiveTime == 0)
            {
                connection->lastReceiveTime = func_0217F264();
                return;
            }
            if (func_0217F264() - connection->lastReceiveTime < 30000)
                return;
            func_0217D254(8, 0, 1, g_021CF320, func_0217F264() - connection->lastReceiveTime);
            connection->lastReceiveTime = 0;
            connection->completed = 1;
            connection->result = 0x13;
            return;
        }
        connection->lastReceiveTime = 0;

        if (result == 3)
        {
            func_021C4E68((int)buffer);
            return;
        }
        if (result == 2)
        {
            connection->completed = 1;
            if (connection->totalSize > 0 && connection->fileBytesReceived < connection->totalSize)
                connection->result = 0xF;
            func_021C4E68((int)buffer);
            return;
        }

        if (connection->encryptEngine != 0 && connection->sessionEstablished == 1)
        {
            if (!func_021BFCEC((struct GHIBuffer_021C5430 *)(&connection->decodeBuffer), buffer, bufferLen))
            {
                func_021C4E68((int)buffer);
                return;
            }
            connection->recvBuffer.len = connection->recvBuffer.pos;
            if (!func_021C0378((struct GHIConnection_021C5430 *)connection))
            {
                connection->completed = 1;
                connection->result = 0x11;
                func_021C4E68((int)buffer);
                return;
            }
            decryptedLen = connection->recvBuffer.len - connection->recvBuffer.pos;
            if (decryptedLen != 0)
            {
                if (!func_021C4C50((struct GHIConnection_021C5430 *)connection, connection->recvBuffer.data + connection->recvBuffer.pos, decryptedLen))
                {
                    func_021C4E68((int)buffer);
                    return;
                }
            }
        }
        else
        {
            if (!func_021C4C50((struct GHIConnection_021C5430 *)connection, buffer, bufferLen))
            {
                func_021C4E68((int)buffer);
                return;
            }
        }

        running_time = func_0217F264() - start_time;
    }

    func_021C4E68((int)buffer);
}
