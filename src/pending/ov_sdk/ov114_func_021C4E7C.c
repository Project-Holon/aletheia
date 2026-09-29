/*
 * function: ghiDoReceivingHeaders
 * address:  0x021C4E7C
 * packet:   pkt_ov114_021C4E7C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      ghiDoReceivingHeaders (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * symbols:
 *   gsimalloc                       0x0217eab0 arm
 *   ghiDoReceive                    0x021c04d4 arm
 *   ghiFreeTempBuffer               0x021c4e68 arm
 *   ghiAppendDataToBuffer           0x021bfcec arm
 *   ghiDecryptReceivedData          0x021c0378 arm
 *   strncmp                         0x020949f4 arm
 *   strstr                          0x02094b20 arm
 *   memmove                         0x02092364 arm
 *   ghiResetBuffer                  0x021c00fc arm
 *   ghiCallProgressCallback         0x021c02c8 arm
 *   strlen                          0x0209477c arm
 *   OS_SPrintf                      0x02084f40 arm
 *   goastrdup                       0x0217f1e0 arm
 *   atoi                            0x020964e0 arm
 *   ghiProcessIncomingFileData      0x021c4c50 arm
 *   GOAGetLastError                 0x0217ed54 arm
 *   g_021CF194                      0x021cf194 data
 *   g_021CF2BC                      0x021cf2bc data
 *   g_021CF2C0                      0x021cf2c0 data
 *   g_021CF2C8                      0x021cf2c8 data
 *   __ctype_mapC                    0x020a61dc data a2
 *   g_021CF2D4                      0x021cf2d4 data
 *   g_021CF2E4                      0x021cf2e4 data
 *   g_021CE0B8                      0x021ce0b8 data
 *   g_021CF2F4                      0x021cf2f4 data
 *
 * blocker:  codegen -- full header state machine reconstructed from the
 *           listing; parked for a DIFF pass. The vendor object carries an
 *           unrecognised compiler stamp (4.0.0.1025, same as the
 *           already-EXACT siblings ghiDoConnecting/ghiDoReceivingFile, so
 *           1.1p1 is still the right pin). Not yet iterated against --diff.
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct GHIBuffer {
    void *f0;
    char *f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
} GHIBuffer;

typedef struct GHIConnection {
    char pad000[0x0c];
    int f00C;                    /* 0x0c */
    char pad010[0x04];
    int state;                   /* 0x10 */
    char pad014[0x04];
    char *host;                  /* 0x18 */
    char pad01c[0x04];
    u16 port;                    /* 0x20 */
    char pad022[0x1e];
    int result;                  /* 0x40 */
    char pad044[0x0c];
    int socket;                  /* 0x50 */
    int socketError;             /* 0x54 */
    char pad058[0x48];
    GHIBuffer headerBuffer;      /* 0xa0 */
    GHIBuffer decryptBuffer;     /* 0xc4 */
    char pad0e8[0x30];
    int fileLength;              /* 0x118 */
    char pad11c[0x04];
    int headerOffset;            /* 0x120 */
    int completed;               /* 0x124 */
    char pad128[0x04];
    int contentLength;           /* 0x12c */
    char *location;              /* 0x130 */
    int status;                  /* 0x134 */
    int hasHeaders;              /* 0x138 */
    u8 flag13c;                  /* 0x13c */
    char pad13d[0x0b];
    int f148;                    /* 0x148 */
    int f14c;                    /* 0x14c */
    int f150;                    /* 0x150 */
    char pad154[0x2c];
    int f180;                    /* 0x180 */
    char pad184[0x14];
    int f198;                    /* 0x198 */
    char pad19c[0x0c];
    int f1a8;                    /* 0x1a8 */
} GHIConnection;

extern void *gsimalloc(unsigned long size);
extern int ghiDoReceive(GHIConnection *connection, char *buffer, int *bufferLen);
extern void ghiFreeTempBuffer(char *buffer);
extern int ghiAppendDataToBuffer(GHIBuffer *buffer, char *data, int dataLen);
extern int ghiDecryptReceivedData(GHIConnection *connection);
extern int strncmp(const char *p1, const char *p2, unsigned long n);
extern char *strstr(const char *haystack, const char *needle);
extern void *memmove(void *dst, const void *src, unsigned long n);
extern void ghiResetBuffer(GHIBuffer *buffer);
extern void ghiCallProgressCallback(GHIConnection *connection, char *buffer, int bufferLen);
extern unsigned long strlen(const char *p);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern char *goastrdup(char *src);
extern int atoi(const char *p);
extern int ghiProcessIncomingFileData(GHIConnection *connection, char *data, int len);
extern int GOAGetLastError(void);

extern char g_021CF194[];
extern char g_021CF2BC[];
extern char g_021CF2C0[];
extern char g_021CF2C8[];
extern u16 __ctype_mapC[];
extern char g_021CF2D4[];
extern char g_021CF2E4[];
extern char g_021CE0B8[];
extern char g_021CF2F4[];

#define ISSPACE(c) ((((c) & 0x80) == 0) && ((__ctype_mapC[(u8)(c)] & 0x100) != 0))

void ghiDoReceivingHeaders(GHIConnection *connection)
{
    int nMaxLen;
    char *pEnd;
    char *pStart;
    char szMaxSize[11];
    int len;
    char *end;
    char *location;
    char *contentLength;
    int fileLength;
    char *fileStart;
    char *buffer;
    int bufferLen;
    char *endOfHeaders;
    char *headers;
    int hasHeaders;
    int result;
    char c;

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
    if (result != 0)
        goto L_4f90;

    if (connection->f198 != 0 && connection->f1a8 == 1) {
        if (ghiAppendDataToBuffer(&connection->decryptBuffer, buffer, bufferLen) != 0) {
            if (ghiDecryptReceivedData(connection) != 0)
                goto L_4f90;
            connection->completed = 1;
            connection->result = 0x11;
            goto L_4f80;
        }
    } else if (ghiAppendDataToBuffer(&connection->headerBuffer, buffer, bufferLen) != 0) {
        goto L_4f90;
    }

L_4f80:
    ghiFreeTempBuffer(buffer);
    return;

L_4f90:
    if (connection->fileLength / 100 != 1)
        goto L_4ff4;
    headers = connection->headerBuffer.f4 + connection->headerOffset;
    if (strncmp(headers, g_021CF194, 2) == 0 || strncmp(headers, g_021CF2BC, 2) == 0) {
        endOfHeaders = headers;
        hasHeaders = 0;
        goto L_5000;
    }

L_4ff4:
    headers = connection->headerBuffer.f4 + connection->headerOffset;
    end = strstr(headers, g_021CF2C0);
    if (end == 0) {
        end = strstr(headers, g_021CF2BC);
        if (end == 0)
            goto L_53d4;
    }

L_5000:
    if (hasHeaders == 1)
        end = end + 2;
    *end = 0;

    fileLength = connection->fileLength;
    fileStart = end + 2;
    len = end - connection->headerBuffer.f4 + 1;
    connection->headerBuffer.fC = len;
    connection->headerBuffer.f10 = len;
    fileLength = connection->headerBuffer.f10 - (fileStart - connection->headerBuffer.f4);
    if (connection->fileLength / 100 == 1) {
        if (fileLength != 0) {
            memmove(connection->headerBuffer.f4, fileStart, fileLength + 1);
            connection->headerBuffer.fC = fileLength;
        } else {
            ghiResetBuffer(&connection->headerBuffer);
        }
        if (connection->f180 != 0) {
            connection->f180 = 0;
            connection->state = 6;
            ghiCallProgressCallback(connection, 0, 0);
        }
        connection->state = 8;
        ghiCallProgressCallback(connection, 0, 0);
        ghiFreeTempBuffer(buffer);
        return;
    }

    result = 0;
    if (connection->fileLength / 100 == 3) {
        if (connection->status > 0xa) {
            connection->completed = 1;
            connection->result = 0xb;
            ghiFreeTempBuffer(buffer);
            return;
        }
        headers = connection->headerBuffer.f4 + connection->headerOffset;
        location = strstr(headers, g_021CF2C8);
        if (location == 0)
            goto L_5230;
        location = location + 9;
        while (ISSPACE(*location))
            location++;
        pEnd = location;
        while (*pEnd != 0 && !ISSPACE(*pEnd))
            pEnd++;
        *pEnd = 0;
        if (*location == '/') {
            len = strlen(connection->host);
            len = len + 14 + strlen(location);
            connection->location = gsimalloc(len);
            if (connection->location == 0) {
                connection->completed = 1;
                connection->result = 1;
            }
            OS_SPrintf(connection->location, g_021CF2D4, connection->host,
                       connection->port, location);
        } else {
            connection->location = goastrdup(location);
            if (connection->location == 0) {
                connection->completed = 1;
                connection->result = 1;
            }
        }
        ghiFreeTempBuffer(buffer);
        return;
    }

L_5230:
    headers = connection->headerBuffer.f4 + connection->headerOffset;
    contentLength = strstr(headers, g_021CF2E4);
    if (contentLength != 0) {
        memmove(szMaxSize, g_021CE0B8, 11);
        pStart = contentLength + 0x10;
        len = strlen(szMaxSize);
        end = pStart;
        while (*end != 0 && *end != '\n' && *end != '\r' && *end != ' ')
            end++;
        if (end - pStart > len) {
            connection->completed = 1;
            connection->result = 0x10;
            ghiFreeTempBuffer(buffer);
            return;
        }
        if (end - pStart == len && strncmp(pStart, szMaxSize, len) >= 0) {
            connection->completed = 1;
            connection->result = 0x10;
            ghiFreeTempBuffer(buffer);
            return;
        }
        connection->contentLength = atoi(pStart);
    }

L_5328:
    hasHeaders = strstr(headers, g_021CF2F4) != 0;
    connection->hasHeaders = hasHeaders;
    if (hasHeaders) {
        connection->flag13c = 0;
        connection->f148 = 0;
        connection->f14c = 0;
        connection->f150 = 0;
    }
    if (connection->f00C == 3 || connection->f00C == 4) {
        connection->completed = 1;
        ghiFreeTempBuffer(buffer);
        return;
    }

    connection->state = 0xa;
    if (contentLength != 0 && connection->contentLength == 0) {
        connection->completed = 1;
        ghiFreeTempBuffer(buffer);
        return;
    }
    if (fileLength > 0)
        ghiProcessIncomingFileData(connection, fileStart, fileLength);

L_53f8:
    ghiFreeTempBuffer(buffer);
    return;

L_53d4:
    if (result == 2) {
        connection->completed = 1;
        connection->result = 7;
        connection->socketError = GOAGetLastError();
    }
    goto L_53f8;
}
