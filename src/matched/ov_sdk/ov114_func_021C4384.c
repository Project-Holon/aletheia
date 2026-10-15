/*
 * function: ghiDoSendingRequest
 * address:  0x021C4384
 * packet:   pkt_ov114_021C4384
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiDoSendingRequest (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   ghiAppendDataToBuffer  0x021BFCEC  arm  ov114
 *   ghiAppendHeaderToBuffer  0x021BFF7C  arm  ov114
 *   ghiAppendCharToBuffer  0x021C0004  arm  ov114
 *   ghiAppendIntToBuffer  0x021C00C0  arm  ov114
 *   strstr  0x02094B20  arm
 *   OS_SPrintf  0x02084F40  arm
 *   ghiPostGetContentType  0x021C25C8  arm  ov114
 *   ghiEncryptDataToBuffer  0x021BFDEC  arm  ov114
 *   ghiResetBuffer  0x021C00FC  arm  ov114
 *   ghiSendBufferedData  0x021C011C  arm  ov114
 *   ghiCallProgressCallback  0x021C02C8  arm  ov114
 *   sGhttpSendingRequest     0x021CF14C  data
 *   sGhttpPost     0x021CF160  data
 *   sGhttpHead     0x021CF168  data
 *   sGhttpGet     0x021CF170  data
 *   gGhttpProxyServer     0x021D3B2C  data
 *   sGhttpHttp3     0x021CF178  data
 *   sGhttpHost     0x021CF184  data
 *   sGhttpHost2     0x021CF18C  data
 *   sGhttpLineEndProcess     0x021CF194  data
 *   sGhttpUserAgent     0x021CF198  data
 *   sGhttpGamespyhttp     0x021CF1A4  data
 *   sGhttpConnection     0x021CF1B4  data
 *   sGhttpKeepAlive     0x021CF1C0  data
 *   sGhttpClose     0x021CF1CC  data
 *   sGhttpIntFormatProcess     0x021CF1D4  data
 *   sGhttpContentLength     0x021CF1D8  data
 *   sGhttpContentType     0x021CF1E8  data
 */

typedef unsigned short u16;

typedef struct {
    void *connection;
    char *data;
    int size;
    int len;
    int pos;
    char pad14[0x10];
} GHIBuffer;

typedef struct {
    char pad000[0x0C];
    int type;                   /* 0x00C */
    int state;                  /* 0x010 */
    char *URL;                  /* 0x014 */
    char *serverAddress;        /* 0x018 */
    char pad01C[0x04];
    u16 serverPort;             /* 0x020 */
    char pad022[0x02];
    char *requestPath;          /* 0x024 */
    char pad028[0x04];
    char *sendHeaders;          /* 0x02C */
    char pad030[0x0C];
    int persistConnection;      /* 0x03C */
    int result;                 /* 0x040 */
    char pad044[0x14];
    GHIBuffer sendBuffer;       /* 0x058 */
    GHIBuffer encodeBuffer;     /* 0x07C */
    char pad0A0[0x84];
    int completed;              /* 0x124 */
    char pad128[0x3C];
    void *post;                 /* 0x164 */
    char pad168[0x0C];
    int totalBytes;             /* 0x174 */
    char pad178[0x0C];
    int postCompleted;          /* 0x184 */
    char pad188[0x04];
    char *proxyOverrideServer;  /* 0x18C */
    char pad190[0x08];
    void *encryptEngine;        /* 0x198 */
    char pad19C[0x0C];
    int sessionEstablished;     /* 0x1A8 */
} GHIConnection;

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
typedef unsigned char  u8;
struct Conn;
struct Ctx;
struct GHIBuffer;
struct GHIConnection;
extern int ghiAppendDataToBuffer(struct GHIBuffer *buffer, char *data, int dataLen);
extern int ghiAppendHeaderToBuffer(GHIBuffer *buffer, const char *name, const char *value);
extern int ghiAppendCharToBuffer(struct Ctx *ctx, int ch);
extern int ghiAppendIntToBuffer(GHIBuffer *buffer, int i);
extern u8 *strstr(const u8 *s1, const u8 *s2);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern char *ghiPostGetContentType(struct Conn *connection);
extern int ghiEncryptDataToBuffer(struct GHIBuffer *buffer, const char *data, int dataLen);
extern void ghiResetBuffer(GHIBuffer *buffer);
extern int ghiSendBufferedData(struct GHIConnection *connection);
extern void ghiCallProgressCallback(struct GHIConnection *connection, char *buffer, int bufferLen);
extern char sGhttpSendingRequest[];
extern char sGhttpPost[];
extern char sGhttpHead[];
extern char sGhttpGet[];
extern char *gGhttpProxyServer;
extern char sGhttpHttp3[];
extern char sGhttpHost[];
extern char sGhttpHost2[];
extern char sGhttpLineEndProcess[];
extern char sGhttpUserAgent[];
extern char sGhttpGamespyhttp[];
extern char sGhttpConnection[];
extern char sGhttpKeepAlive[];
extern char sGhttpClose[];
extern char sGhttpIntFormatProcess[];
extern char sGhttpContentLength[];
extern char sGhttpContentType[];

void ghiDoSendingRequest(GHIConnection *connection)
{
    char buf[16];
    GHIBuffer *writeBuffer;
    char *requestType;

    func_0217D254(8, (char *)3, 0x10, sGhttpSendingRequest);

    if (connection->sendBuffer.len == 0)
    {
        if (connection->encryptEngine == 0 || !connection->sessionEstablished)
            writeBuffer = &connection->sendBuffer;
        else
            writeBuffer = &connection->encodeBuffer;

        if (connection->post != 0 && !connection->postCompleted)
            requestType = sGhttpPost;
        else if (connection->type == 3)
            requestType = sGhttpHead;
        else
            requestType = sGhttpGet;
        ghiAppendDataToBuffer((struct GHIBuffer *)writeBuffer, requestType, 0);

        if (connection->proxyOverrideServer != 0 || gGhttpProxyServer != 0)
            ghiAppendDataToBuffer((struct GHIBuffer *)writeBuffer, connection->URL, 0);
        else
            ghiAppendDataToBuffer((struct GHIBuffer *)writeBuffer, connection->requestPath, 0);
        ghiAppendDataToBuffer((struct GHIBuffer *)writeBuffer, sGhttpHttp3, 0);

        if (connection->serverPort == 80)
        {
            ghiAppendHeaderToBuffer(writeBuffer, sGhttpHost, connection->serverAddress);
        }
        else
        {
            ghiAppendDataToBuffer((struct GHIBuffer *)writeBuffer, sGhttpHost2, 0);
            ghiAppendDataToBuffer((struct GHIBuffer *)writeBuffer, connection->serverAddress, 0);
            ghiAppendCharToBuffer((struct Ctx *)writeBuffer, ':');
            ghiAppendIntToBuffer(writeBuffer, connection->serverPort);
            ghiAppendDataToBuffer((struct GHIBuffer *)writeBuffer, sGhttpLineEndProcess, 2);
        }

        if (connection->sendHeaders == 0 || strstr((const u8 *)connection->sendHeaders, (const u8 *)sGhttpUserAgent) == 0)
            ghiAppendHeaderToBuffer(writeBuffer, sGhttpUserAgent, sGhttpGamespyhttp);

        if (connection->persistConnection)
            ghiAppendHeaderToBuffer(writeBuffer, sGhttpConnection, sGhttpKeepAlive);
        else
            ghiAppendHeaderToBuffer(writeBuffer, sGhttpConnection, sGhttpClose);

        if (connection->post != 0 && !connection->postCompleted)
        {
            OS_SPrintf(buf, sGhttpIntFormatProcess, connection->totalBytes);
            ghiAppendHeaderToBuffer(writeBuffer, sGhttpContentLength, buf);
            ghiAppendHeaderToBuffer(writeBuffer, sGhttpContentType, ghiPostGetContentType((struct Conn *)connection));
        }

        if (connection->sendHeaders != 0)
            ghiAppendDataToBuffer((struct GHIBuffer *)writeBuffer, connection->sendHeaders, 0);
        ghiAppendDataToBuffer((struct GHIBuffer *)writeBuffer, sGhttpLineEndProcess, 2);

        if (connection->encryptEngine != 0 && connection->sessionEstablished == 1)
        {
            if (!ghiEncryptDataToBuffer((struct GHIBuffer *)(&connection->sendBuffer), writeBuffer->data, writeBuffer->len))
            {
                connection->completed = 1;
                connection->result = 0x11;
                return;
            }
            ghiResetBuffer(writeBuffer);
        }
    }

    if (!ghiSendBufferedData((struct GHIConnection *)connection))
        return;
    if (connection->sendBuffer.pos < connection->sendBuffer.len)
        return;
    ghiResetBuffer(&connection->sendBuffer);

    if (connection->post != 0 && !connection->postCompleted)
        connection->state = 6;
    else
        connection->state = 7;
    ghiCallProgressCallback((struct GHIConnection *)connection, 0, 0);
}
