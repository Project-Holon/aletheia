/*
 * function: ghiDoReceivingHeaders
 * address:  0x021C4E7C
 * packet:   pkt_ov114_021C4E7C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiDoReceivingHeaders (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * notes:    every byte and all 48 relocations resolve (the last is the
 *           vendor template @13998, declared in symbols:).  The second isspace loop (after the header-value scan) is the
 *           short-circuit `(c < 0 || c >= 0x80) ? 0 : table` form, not the unsigned
 *           fold the first loop uses.
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
 *   sGhttpLineEndProcess                      0x021cf194 data
 *   sGhttpDoubleLf                      0x021cf2bc data
 *   sGhttpDoubleCrLf                      0x021cf2c0 data
 *   sGhttpLocation                      0x021cf2c8 data
 *   __ctype_mapC                    0x020a61dc data a2
 *   sGhttpHttp5                      0x021cf2d4 data
 *   sGhttpContentLength2                      0x021cf2e4 data
 *   sGhttpMaxContentLength                      0x021ce0b8 data
 *   @13998                          0x021ce0b8 data
 *   sGhttpTransferEncodingChunked                      0x021cf2f4 data
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct GHIBuffer {
    void *connection;
    char *data;
    int size;
    int length;
    int position;
    int fixed;
    int dontFree;
    int readOnly;
    int pad;
} GHIBuffer;

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

typedef struct GHIConnection {
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
    GHIBuffer sendBuffer;
    GHIBuffer encodeBuffer;
    GHIBuffer recvBuffer;
    GHIBuffer decodeBuffer;
    GHIBuffer getFileBuffer;
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
} GHIConnection;

extern int strncmp(const char *p1, const char *p2, unsigned long n);
extern char *strstr(const char *haystack, const char *needle);
extern unsigned long strlen(const char *p);
extern void *gsimalloc(unsigned long size);
extern int ghiDoReceive(GHIConnection *connection, char *buffer, int *bufferLen);
extern void ghiFreeTempBuffer(char *buffer);
extern int ghiAppendDataToBuffer(GHIBuffer *buffer, char *data, int dataLen);
extern int ghiDecryptReceivedData(GHIConnection *connection);
extern void *memmove(void *dst, const void *src, unsigned long n);
extern void ghiResetBuffer(GHIBuffer *buffer);
extern void ghiCallProgressCallback(GHIConnection *connection, char *buffer, int bufferLen);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern char *goastrdup(char *src);
extern int atoi(const char *p);
extern int ghiProcessIncomingFileData(GHIConnection *connection, char *data, int len);
extern int GOAGetLastError(int socket);

extern char sGhttpLineEndProcess[];
extern char sGhttpDoubleLf[];
extern char sGhttpDoubleCrLf[];
extern char sGhttpLocation[];
extern u16 __ctype_mapC[];
extern char sGhttpHttp5[];
extern char sGhttpContentLength2[];
extern char sGhttpMaxContentLength[];
extern char sGhttpTransferEncodingChunked[];

#define ISSPACE(c) (((unsigned)(c) < 0x80u) ? (__ctype_mapC[c] & 0x100) : 0)
#define ISSPACE2(c) (((unsigned)(c) < 0x80u) ? (__ctype_mapC[c] & 0x100) : 0)

void ghiDoReceivingHeaders(GHIConnection *connection)
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
        (strncmp(headers, sGhttpLineEndProcess, 2) == 0 ||
         strncmp(headers, sGhttpDoubleLf, 2) == 0)) {
        endOfHeaders = headers;
        hasHeaders = 0;
    } else {
        endOfHeaders = strstr(headers, sGhttpDoubleCrLf);
    }
    if (endOfHeaders == 0)
        endOfHeaders = strstr(headers, sGhttpDoubleLf);
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
            location = strstr(headers, sGhttpLocation);
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
                    OS_SPrintf(connection->redirectURL, sGhttpHttp5,
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

        contentLength = strstr(headers, sGhttpContentLength2);
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

        connection->chunkedTransfer = (strstr(headers, sGhttpTransferEncodingChunked) != 0) ? 1 : 0;
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
