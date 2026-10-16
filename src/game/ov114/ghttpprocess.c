/*
 * file:     ghttpprocess.c
 * unit:     yes
 * function: ghiParseURL, ghiDoSocketInit, ghiDoHostLookup, ghiDoLookupPending, ghiDoConnecting, ghiDoSecuringSession, ghiDoSendingRequest, ghiDoPosting, ghiDoWaiting, ghiParseStatus, ghiDoReceivingStatus, ghiDeliverIncomingFileData, ghiParseChunkSize, ghiAppendToChunkHeaderBuffer, ghiProcessIncomingFileData, ghiFreeTempBuffer, ghiDoReceivingHeaders, ghiDoReceivingFile
 * address:  0x021C3A38
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
 *   strncmp  0x020949F4  arm
 *   strcspn  0x02094A60  arm
 *   strchr  0x02094A28  arm
 *   atoi  0x020964E0  arm
 *   goastrdup  0x0217F1E0  arm   ov009
 *   sGhttpHttp2     0x021CEFDC  data
 *   sGhttpHttps3     0x021CEFE4  data
 *   sGhttpUrlServerTerminators     0x021CEFF0  data
 *   sGhttpRootPath     0x021CEFF4  data
 *   gsDebugFormat  0x0217D254  arm   ov009
 *   ghiCallProgressCallback  0x021C02C8  arm   ov114
 *   SocketStartUp  0x0217F25C  arm   ov009
 *   ghttpSetRequestEncryptionEngine  0x021C109C  arm   ov114
 *   sGhttpSocketInitialization     0x021CEFF8  data
 *   sGhttpEncryptionEngineNotSetFor     0x021CF010  data
 *   sGhttpEncryptionEngineSetForUnsecured     0x021CF050  data
 *   sGhttpInitializingSslEngine     0x021CF090  data
 *   sGhttpFailedToInitializeSslEngine     0x021CF0AC  data
 *   inet_addr  0x0217ED38  arm   ov009
 *   gsiStartResolvingHostname  0x0217F150  arm   ov009
 *   sGhttpHostLookup     0x021CF0D0  data  ov114
 *   sGhttpThreadCreationFailed     0x021CF0E0  data  ov114
 *   gGhttpProxyServer     0x021D3B2C  data  ov114
 *   gsiGetResolvedIP  0x0217F1CC  arm   ov009
 *   sGhttpErrorResolvingHostname     0x021CF0F8  data  ov114
 *   sGhttpDnsLookupComplete     0x021CF114  data  ov114
 *   socket  0x0217EB18  arm  ov009
 *   GOAGetLastError  0x0217ED54  arm  ov009
 *   SetSockBlocking  0x0217EE50  arm  ov009
 *   SetReceiveBufferSize  0x0217EF00  arm  ov009
 *   func_0217EC08  0x0217EC08  arm  ov009
 *   GSISocketSelect  0x0217ED64  arm  ov009
 *   sGhttpConnecting     0x021CF12C  data
 *   gGhttpThrottleBufferSize     0x021CE5B0  data
 *   gGhttpProxyPort     0x021D3B28  data
 *   ghiSendBufferedData  0x021C011C  arm  ov114
 *   ghiResetBuffer  0x021C00FC  arm  ov114
 *   ghiDoReceive  0x021C04D4  arm  ov114
 *   ghiAppendDataToBuffer  0x021BFCEC  arm  ov114
 *   ghiDecryptReceivedData  0x021C0378  arm  ov114
 *   sGhttpSecuringSession     0x021CF138  data
 *   ghiAppendHeaderToBuffer  0x021BFF7C  arm  ov114
 *   ghiAppendCharToBuffer  0x021C0004  arm  ov114
 *   ghiAppendIntToBuffer  0x021C00C0  arm  ov114
 *   strstr  0x02094B20  arm
 *   OS_SPrintf  0x02084F40  arm
 *   ghiPostGetContentType  0x021C25C8  arm  ov114
 *   ghiEncryptDataToBuffer  0x021BFDEC  arm  ov114
 *   sGhttpSendingRequest     0x021CF14C  data
 *   sGhttpPost     0x021CF160  data
 *   sGhttpHead     0x021CF168  data
 *   sGhttpGet     0x021CF170  data
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
 *   ghiPostDoPosting  0x021C3834  arm   ov114
 *   ghiPostCleanupState  0x021C2BB0  arm   ov114
 *   ghiCallPostCallback  0x021C0318  arm   ov114
 *   sGhttpPosting     0x021CF1F8  data  ov114
 *   sGhttpWaiting     0x021CF204  data  ov114
 *   STD_TSScanf  0x0208CF34  arm
 *   sGhttpHttp4   0x021CF210  data
 *   gCtypeMap   0x020A61DC  data
 *   sGhttpReceivingStatus     0x021CF220  data
 *   sGhttpGotHttpContinue     0x021CF234  data
 *   sGhttpChunkSizeFormat   0x021CF248  data
 *   memcpy  0x02092344  arm
 *   sGhttpReadingFooter     0x021CF24C  data
 *   sGhttpReadingByteChunk     0x021CF25C  data
 *   sGhttpReadBytesOfChunk     0x021CF274  data
 *   sGhttpReadChunkFooter     0x021CF28C  data
 *   sGhttpFinishedReadingChunks     0x021CF2A0  data
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
 *   sGhttpDoubleLf                      0x021cf2bc data
 *   sGhttpDoubleCrLf                      0x021cf2c0 data
 *   sGhttpLocation                      0x021cf2c8 data
 *   __ctype_mapC                    0x020a61dc data a2
 *   sGhttpHttp5                      0x021cf2d4 data
 *   sGhttpContentLength2                      0x021cf2e4 data
 *   sGhttpMaxContentLength                      0x021ce0b8 data
 *   sGhttpTransferEncodingChunked                      0x021cf2f4 data
 *   current_time  0x0217F264  arm  ov009
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   sGhttpReceivingFile     0x021CF310  data
 *   sGhttpReceiveFileIdleTimeout     0x021CF320  data
 *   gsifree  0x0217EAE0  arm  ov009
 *   @13998                          0x021ce0b8 data
 */
#include "ghttp_types.h"

#define SOC_HTONS(x) ((u16)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))
#define ISSPACE(c) (((unsigned)(c) < 0x80u) ? (__ctype_mapC[c] & 0x100) : 0)
struct GSIResolveHostnameInfo;

typedef struct {
    u8 len;
    u8 family;
    u16 port;
    u32 addr;
} SOCSockAddrIn;

extern int strcspn(const u8 *s, const u8 *reject);
extern char *goastrdup(char *);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern void ghiCallProgressCallback(GHIConnection *, char *, int);
extern void SocketStartUp();
extern int ghttpSetRequestEncryptionEngine(int, int);
extern int inet_addr(int a);
extern int gsiStartResolvingHostname(char *hostname, struct GSIResolveHostnameInfo **handle);
extern int gsiGetResolvedIP(int *p);
extern int socket(int pf, int type, int protocol);
extern int GOAGetLastError(int socket);
extern int SetSockBlocking(int sock, int isblocking);
extern int SetReceiveBufferSize(int sock, int size);
extern int func_0217EC08(int sock, void *addr, int len);
extern int GSISocketSelect(int theSocket, int *theReadFlag, int *theWriteFlag, int *theExceptFlag);
extern int ghiSendBufferedData(struct GHIConnection *connection);
extern void ghiResetBuffer(GHIBuffer *buffer);
extern int ghiDoReceive(struct GHIConnection *connection, char *buffer, int *bufferLen);
extern int ghiAppendDataToBuffer(struct GHIBuffer *buffer, char *data, int dataLen);
extern int ghiDecryptReceivedData(struct GHIConnection *connection);
extern int ghiAppendHeaderToBuffer(GHIBuffer *buffer, const char *name, const char *value);
extern int ghiAppendCharToBuffer(GHIBuffer *buffer, int ch);
extern int ghiAppendIntToBuffer(GHIBuffer *buffer, int i);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern char *ghiPostGetContentType(GHIConnection *connection);
extern int ghiEncryptDataToBuffer(struct GHIBuffer *buffer, const char *data, int dataLen);
extern int ghiPostDoPosting(GHIConnection *);
extern void ghiPostCleanupState(GHIConnection *);
extern void ghiCallPostCallback(GHIConnection *);
extern int STD_TSScanf(char *src, char *fmt, ...);
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern void gsifree(void *);
extern void *gsimalloc(unsigned long size);
extern int ghiProcessIncomingFileData(GHIConnection *connection, char *data, int len);
extern unsigned int current_time(void);
extern void *gsimalloc(unsigned long size);
GHTTPBool ghiParseURL(GHIConnection *connection);
void ghiDoSocketInit(GHIConnection *connection);
void ghiDoHostLookup(GHIConnection *connection);
void ghiDoLookupPending(GHIConnection *connection);
void ghiDoConnecting(GHIConnection *connection);
void ghiDoSecuringSession(GHIConnection *connection);
void ghiDoSendingRequest(GHIConnection *connection);
void ghiDoPosting(GHIConnection *connection);
void ghiDoWaiting(GHIConnection *connection);
int ghiParseStatus(GHIConnection *connection);
void ghiDoReceivingStatus(GHIConnection *connection);
int ghiDeliverIncomingFileData(GHIConnection *connection, char *data, int len);
int ghiParseChunkSize(GHIConnection *connection);
void ghiAppendToChunkHeaderBuffer(GHIConnection *connection, char *data, int len);
void ghiFreeTempBuffer(void *memory);
void ghiDoReceivingHeaders(GHIConnection *connection);
void ghiDoReceivingFile(GHIConnection *connection);
extern char sGhttpHttp2[];
extern char sGhttpHttps3[];
extern char sGhttpUrlServerTerminators[];
extern char sGhttpRootPath[];
extern char sGhttpSocketInitialization[];
extern char sGhttpEncryptionEngineNotSetFor[];
extern char sGhttpEncryptionEngineSetForUnsecured[];
extern char sGhttpInitializingSslEngine[];
extern char sGhttpFailedToInitializeSslEngine[];
extern char sGhttpHostLookup[];
extern char sGhttpThreadCreationFailed[];
extern char *gGhttpProxyServer;
extern char sGhttpErrorResolvingHostname[];
extern char sGhttpDnsLookupComplete[];
extern char sGhttpConnecting[];
extern int gGhttpThrottleBufferSize;
extern u16 gGhttpProxyPort;
extern char sGhttpSecuringSession[];
extern char sGhttpSendingRequest[];
extern char sGhttpPost[];
extern char sGhttpHead[];
extern char sGhttpGet[];
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
extern char sGhttpPosting[];
extern char sGhttpWaiting[];
extern char sGhttpHttp4[];
extern const unsigned short gCtypeMap[];
extern char sGhttpReceivingStatus[];
extern char sGhttpGotHttpContinue[];
extern char sGhttpChunkSizeFormat[];
extern char sGhttpReadingFooter[];
extern char sGhttpReadingByteChunk[];
extern char sGhttpReadBytesOfChunk[];
extern char sGhttpReadChunkFooter[];
extern char sGhttpFinishedReadingChunks[];
extern char sGhttpDoubleLf[];
extern char sGhttpDoubleCrLf[];
extern char sGhttpLocation[];
extern u16 __ctype_mapC[];
extern char sGhttpHttp5[];
extern char sGhttpContentLength2[];
extern char sGhttpMaxContentLength[];
extern char sGhttpTransferEncodingChunked[];
extern char sGhttpReceivingFile[];
extern char sGhttpReceiveFileIdleTimeout[];





extern unsigned long strlen(const char *p);
extern int strncmp(const char *s1, const char *s2, unsigned int n);
extern char *strchr(const char *, int);
extern char *strstr(const char *s, const char *find);
extern int atoi(const char *s);
extern void *memmove(void *dst, const void *src, unsigned long n);
/*
 * sdk:      ghiParseURL (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
GHTTPBool ghiParseURL(GHIConnection *connection)
{
    char *URL;
    int nIndex;
    char tempChar;
    char *p;
    char *path;

    if (connection == 0)
        return GHTTPFalse;
    URL = connection->URL;
    if (URL == 0)
        return GHTTPFalse;
    if (strncmp((const char *)URL, (const char *)sGhttpHttp2, 7) == 0) {
        connection->protocol = 0;
        URL += 7;
    } else if (strncmp((const char *)URL, (const char *)sGhttpHttps3, 8) == 0) {
        connection->protocol = 1;
        URL += 8;
    } else {
        return GHTTPFalse;
    }
    nIndex = strcspn((const u8 *)URL, (const u8 *)sGhttpUrlServerTerminators);
    tempChar = URL[nIndex];
    URL[nIndex] = 0;
    connection->serverAddress = goastrdup(URL);
    if (connection->serverAddress == 0)
        return GHTTPFalse;
    URL[nIndex] = tempChar;
    URL += nIndex;
    if (*URL == ':') {
        URL++;
        connection->serverPort = (unsigned short)atoi((const char *)URL);
        if (connection->serverPort == 0)
            return GHTTPFalse;
        while (*++URL != 0 && *URL != '/')
            ;
    } else if (connection->protocol == 1) {
        connection->serverPort = 443;
    } else {
        connection->serverPort = 80;
    }
    if (*URL == 0)
        URL = sGhttpRootPath;
    path = goastrdup(URL);
    connection->requestPath = path;
    while ((p = strchr(path, ' ')) != 0) {
        *p = '+';
        path = connection->requestPath;
    }
    if (path == 0)
        return GHTTPFalse;
    return GHTTPTrue;
}





/*
 * sdk:      ghiDoSocketInit (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void ghiDoSocketInit(GHIConnection *connection)
{
    int aResult;

    gsDebugFormat(8, (char *)3, 16, sGhttpSocketInitialization);
    ghiCallProgressCallback(connection, 0, 0);
    SocketStartUp();
    if (ghiParseURL(connection) == GHTTPFalse) {
        connection->completed = 1;
        connection->result = 3;
        return;
    }
    if (connection->protocol == 1 && connection->encryptor.engine == 0) {
        gsDebugFormat(8, 0, 2, sGhttpEncryptionEngineNotSetFor);
        ghttpSetRequestEncryptionEngine(connection->request, 5);
    } else if (connection->protocol != 1 && connection->encryptor.engine != 0) {
        ghttpSetRequestEncryptionEngine(connection->request, 0);
        gsDebugFormat(8, 0, 2, sGhttpEncryptionEngineSetForUnsecured);
    }
    if (connection->protocol == 1 && connection->encryptor.field_08 == 0) {
        gsDebugFormat(8, (char *)3, 15, sGhttpInitializingSslEngine);
        aResult = connection->encryptor.initFunc(connection, &connection->encryptor);
        if (aResult == 3) {
            gsDebugFormat(8, (char *)3, 2, sGhttpFailedToInitializeSslEngine);
            connection->completed = 1;
            connection->result = 17;
            return;
        }
    }
    connection->state = 1;
    ghiCallProgressCallback(connection, 0, 0);
}





/*
 * sdk:      ghiDoHostLookup (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void ghiDoHostLookup(GHIConnection *connection)
{
    char *server;

    if (connection->handle != 0) {
        connection->state = 2;
        ghiCallProgressCallback(connection, 0, 0);
        return;
    }
    gsDebugFormat(8, (char *)3, 16, sGhttpHostLookup);
    server = connection->proxyOverrideServer;
    if (server == 0) {
        server = gGhttpProxyServer;
        if (server == 0)
            server = connection->serverAddress;
    }
    connection->serverIP = inet_addr((int)server);
    if (connection->serverIP == (unsigned int)-1) {
        if (gsiStartResolvingHostname(server, (struct GSIResolveHostnameInfo **)(&connection->handle)) == -1) {
            gsDebugFormat(8, (char *)3, 1, sGhttpThreadCreationFailed);
            connection->handle = 0;
            connection->completed = 1;
            connection->result = 4;
            return;
        }
    }
    if (connection->serverIP == (unsigned int)-1) {
        connection->state = 2;
        ghiCallProgressCallback(connection, 0, 0);
        return;
    }
    connection->state = 3;
    ghiCallProgressCallback(connection, 0, 0);
}





/*
 * sdk:      ghiDoLookupPending (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void ghiDoLookupPending(GHIConnection *connection)
{
    connection->serverIP = gsiGetResolvedIP(connection->handle);
    if (connection->serverIP == (unsigned int)-1) {
        gsDebugFormat(8, (char *)3, 1, sGhttpErrorResolvingHostname);
        connection->handle = 0;
        connection->completed = 1;
        connection->result = 4;
        return;
    }
    if (connection->serverIP == 0) {
        connection->state = 2;
        ghiCallProgressCallback(connection, 0, 0);
        return;
    }
    connection->handle = 0;
    gsDebugFormat(8, (char *)3, 16, sGhttpDnsLookupComplete);
    connection->state = 3;
    ghiCallProgressCallback(connection, 0, 0);
}





/*
 * sdk:      ghiDoConnecting (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void ghiDoConnecting(GHIConnection *connection)
{
    int rcode;
    int socketError;
    SOCSockAddrIn address;
    int writeFlag;
    int exceptFlag;

    gsDebugFormat(8, (char *)3, 0x10, sGhttpConnecting);

    if (connection->socket == -1)
    {
        connection->socket = socket(2, 1, 0);
        if (connection->socket == -1)
        {
            connection->completed = 1;
            connection->result = 5;
            connection->socketError = GOAGetLastError(connection->socket);
            return;
        }
        if (!SetSockBlocking(connection->socket, 0))
        {
            connection->completed = 1;
            connection->result = 5;
            connection->socketError = GOAGetLastError(connection->socket);
            return;
        }
        if (connection->throttle)
            SetReceiveBufferSize(connection->socket, gGhttpThrottleBufferSize);

        if (connection->encryptor.engine == 4)
        {
            if (connection->encryptor.startFunc(connection, &connection->encryptor) == 3)
            {
                connection->completed = 1;
                connection->result = 0x11;
                return;
            }
            connection->encryptor.engine = 0;
        }

        {
            u32 *addressWords = (u32 *)&address;
            addressWords[0] = 0;
            addressWords[1] = 0;
        }
        address.family = 2;
        if (connection->proxyOverrideServer)
            address.port = SOC_HTONS(connection->proxyOverridePort);
        else if (gGhttpProxyServer)
            address.port = SOC_HTONS(gGhttpProxyPort);
        else
            address.port = SOC_HTONS(connection->serverPort);
        address.addr = connection->serverIP;

        rcode = func_0217EC08(connection->socket, &address, sizeof(address));
        if (rcode == -1)
        {
            socketError = GOAGetLastError(connection->socket);
            if (socketError != -6 && socketError != -26 && socketError != -76)
            {
                connection->completed = 1;
                connection->result = 6;
                connection->socketError = socketError;
                return;
            }
        }
    }

    rcode = GSISocketSelect(connection->socket, 0, &writeFlag, &exceptFlag);
    if (rcode == -1 || (rcode == 1 && exceptFlag))
    {
        connection->completed = 1;
        connection->result = 6;
        if (rcode == -1)
            connection->socketError = GOAGetLastError(connection->socket);
        else
            connection->socketError = 0;
        return;
    }

    if (rcode == 1 && writeFlag)
    {
        if (connection->encryptor.engine == 0)
            connection->state = 5;
        else
            connection->state = 4;
        ghiCallProgressCallback(connection, 0, 0);
    }
}




/*
 * sdk:      ghiDoSecuringSession (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void ghiDoSecuringSession(GHIConnection *connection)
{
    int bufferLen;
    char buffer[1025];
    int result;

    if (!connection->encryptor.initialized)
    {
        gsDebugFormat(8, (char *)3, 0x10, sGhttpSecuringSession);
        if (connection->encryptor.startFunc != 0)
        {
            if (connection->encryptor.startFunc(connection, &connection->encryptor) == 3)
            {
                connection->completed = 1;
                connection->result = 0x11;
                return;
            }
        }
        if (connection->encryptor.sessionEstablished)
        {
            connection->state = 5;
            ghiCallProgressCallback(connection, 0, 0);
            return;
        }
    }

    if (connection->encryptor.handshaking)
    {
        if (connection->encryptor.startFunc != 0)
        {
            if (connection->encryptor.startFunc(connection, &connection->encryptor) == 3)
            {
                connection->completed = 1;
                connection->result = 0x11;
                return;
            }
        }
        if (!connection->encryptor.sessionEstablished)
            return;
        connection->state = 5;
        ghiCallProgressCallback(connection, 0, 0);
        return;
    }

    if (connection->sendBuffer.pos < connection->sendBuffer.len)
    {
        if (!ghiSendBufferedData(connection))
            return;
        if (connection->sendBuffer.pos < connection->sendBuffer.len)
            return;
        ghiResetBuffer(&connection->sendBuffer);
    }

    bufferLen = sizeof(buffer);
    result = ghiDoReceive(connection, buffer, &bufferLen);
    if (result == 2 || result == 3)
    {
        connection->completed = 1;
        connection->result = 0x11;
        return;
    }
    if (result != 0)
        return;
    if (!ghiAppendDataToBuffer(&connection->decodeBuffer, buffer, bufferLen))
        return;
    if (!ghiDecryptReceivedData(connection))
    {
        connection->completed = 1;
        connection->result = 0x11;
        return;
    }
    if (!connection->encryptor.sessionEstablished)
        return;
    connection->state = 5;
    ghiCallProgressCallback(connection, 0, 0);
}




/*
 * sdk:      ghiDoSendingRequest (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void ghiDoSendingRequest(GHIConnection *connection)
{
    char buf[16];
    GHIBuffer *writeBuffer;
    char *requestType;

    gsDebugFormat(8, (char *)3, 0x10, sGhttpSendingRequest);

    if (connection->sendBuffer.len == 0)
    {
        if (connection->encryptor.engine == 0 || !connection->encryptor.encryptOnBuffer)
            writeBuffer = &connection->sendBuffer;
        else
            writeBuffer = &connection->encodeBuffer;

        if (connection->post != 0 && !connection->postingState.field_1C)
            requestType = sGhttpPost;
        else if (connection->type == 3)
            requestType = sGhttpHead;
        else
            requestType = sGhttpGet;
        ghiAppendDataToBuffer(writeBuffer, requestType, 0);

        if (connection->proxyOverrideServer != 0 || gGhttpProxyServer != 0)
            ghiAppendDataToBuffer(writeBuffer, connection->URL, 0);
        else
            ghiAppendDataToBuffer(writeBuffer, connection->requestPath, 0);
        ghiAppendDataToBuffer(writeBuffer, sGhttpHttp3, 0);

        if (connection->serverPort == 80)
        {
            ghiAppendHeaderToBuffer(writeBuffer, sGhttpHost, connection->serverAddress);
        }
        else
        {
            ghiAppendDataToBuffer(writeBuffer, sGhttpHost2, 0);
            ghiAppendDataToBuffer(writeBuffer, connection->serverAddress, 0);
            ghiAppendCharToBuffer(writeBuffer, ':');
            ghiAppendIntToBuffer(writeBuffer, connection->serverPort);
            ghiAppendDataToBuffer(writeBuffer, sGhttpLineEndProcess, 2);
        }

        if (connection->sendHeaders == 0 || strstr(connection->sendHeaders, sGhttpUserAgent) == 0)
            ghiAppendHeaderToBuffer(writeBuffer, sGhttpUserAgent, sGhttpGamespyhttp);

        if (connection->persistConnection)
            ghiAppendHeaderToBuffer(writeBuffer, sGhttpConnection, sGhttpKeepAlive);
        else
            ghiAppendHeaderToBuffer(writeBuffer, sGhttpConnection, sGhttpClose);

        if (connection->post != 0 && !connection->postingState.field_1C)
        {
            OS_SPrintf(buf, sGhttpIntFormatProcess, connection->postingState.totalBytes);
            ghiAppendHeaderToBuffer(writeBuffer, sGhttpContentLength, buf);
            ghiAppendHeaderToBuffer(writeBuffer, sGhttpContentType, ghiPostGetContentType(connection));
        }

        if (connection->sendHeaders != 0)
            ghiAppendDataToBuffer(writeBuffer, connection->sendHeaders, 0);
        ghiAppendDataToBuffer(writeBuffer, sGhttpLineEndProcess, 2);

        if (connection->encryptor.engine != 0 && connection->encryptor.encryptOnBuffer == 1)
        {
            if (!ghiEncryptDataToBuffer(&connection->sendBuffer, writeBuffer->data, writeBuffer->len))
            {
                connection->completed = 1;
                connection->result = 0x11;
                return;
            }
            ghiResetBuffer(writeBuffer);
        }
    }

    if (!ghiSendBufferedData(connection))
        return;
    if (connection->sendBuffer.pos < connection->sendBuffer.len)
        return;
    ghiResetBuffer(&connection->sendBuffer);

    if (connection->post != 0 && !connection->postingState.field_1C)
        connection->state = 6;
    else
        connection->state = 7;
    ghiCallProgressCallback(connection, 0, 0);
}




/*
 * sdk:      ghiDoPosting (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void ghiDoPosting(GHIConnection *connection)
{
    int result;
    int oldBytesPosted;
    int rcode;
    int readFlag;

    gsDebugFormat(8, (char *)3, 16, sGhttpPosting);
    oldBytesPosted = connection->postingState.bytesPosted;
    result = ghiPostDoPosting(connection);
    if (result == 0) {
        readFlag = 0;
        ghiPostCleanupState(connection);
        rcode = GSISocketSelect(connection->socket, &readFlag, 0, 0);
        if (rcode != 1)
            return;
        if (readFlag == 0)
            return;
        connection->state = 8;
        ghiCallProgressCallback(connection, 0, 0);
        return;
    }
    if (result == 3) {
        connection->postingState.waitPostContinue = 0;
        return;
    }
    if (oldBytesPosted != connection->postingState.bytesPosted)
        ghiCallPostCallback(connection);
    if (result != 1)
        return;
    ghiPostCleanupState(connection);
    connection->postingState.field_1C = 1;
    connection->state = 7;
    ghiCallProgressCallback(connection, 0, 0);
}



/*
 * sdk:      ghiDoWaiting (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void ghiDoWaiting(GHIConnection *connection)
{
    int rcode;
    int readFlag;
    int exceptFlag;

    gsDebugFormat(8, (char *)3, 16, sGhttpWaiting);
    rcode = GSISocketSelect(connection->socket, &readFlag, 0, &exceptFlag);
    if (rcode == -1 || (rcode == 1 && exceptFlag)) {
        connection->completed = 1;
        connection->result = 5;
        if (rcode == -1)
            connection->socketError = GOAGetLastError(connection->socket);
        else
            connection->socketError = 0;
        return;
    }
    if (rcode != 1)
        return;
    if (readFlag == 0)
        return;
    connection->state = 8;
    ghiCallProgressCallback(connection, 0, 0);
}



static inline int isspace(int c) { return ((c < 0 || c >= 0x80) ? 0 : (gCtypeMap[c] & 0x100)); }



/*
 * sdk:      ghiParseStatus (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
int ghiParseStatus(GHIConnection *connection)
{
    int majorVersion;
    int minorVersion;
    int statusCode;
    int statusStringIndex;
    int rcode;
    char c;

    rcode = STD_TSScanf(connection->recvBuffer.data, sGhttpHttp4, &majorVersion, &minorVersion,
                        &statusCode, &statusStringIndex);
    if (rcode != 3 || majorVersion < 1 || statusCode < 100 || statusCode >= 600) {
        connection->completed = 1;
        connection->result = 7;
        return 0;
    }
    while ((c = connection->recvBuffer.data[statusStringIndex]) != 0 && isspace(c))
        statusStringIndex++;
    connection->statusMajorVersion = majorVersion;
    connection->statusMinorVersion = minorVersion;
    connection->statusCode = statusCode;
    connection->statusStringIndex = statusStringIndex;
    return 1;
}



/*
 * sdk:      ghiDoReceivingStatus (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void ghiDoReceivingStatus(GHIConnection *connection)
{
    char buffer[1024];
    int bufferLen;
    int result;
    char *endOfStatus;
    int statusLength;

    gsDebugFormat(8, (char *)3, 0x10, sGhttpReceivingStatus);

    bufferLen = sizeof(buffer);
    result = ghiDoReceive(connection, buffer, &bufferLen);
    if (result == 3 || result == 1)
        return;

    if (result == 0)
    {
        if (connection->encryptor.engine != 0 && connection->encryptor.encryptOnBuffer == 1)
        {
            if (!ghiAppendDataToBuffer(&connection->decodeBuffer, buffer, bufferLen))
                return;
            if (!ghiDecryptReceivedData(connection))
            {
                connection->completed = 1;
                connection->result = 0x11;
                return;
            }
        }
        else
        {
            if (!ghiAppendDataToBuffer(&connection->recvBuffer, buffer, bufferLen))
                return;
        }
    }

    endOfStatus = strstr(connection->recvBuffer.data, sGhttpLineEndProcess);
    if (endOfStatus != 0)
    {
        *endOfStatus = '\0';
        statusLength = endOfStatus - connection->recvBuffer.data;

        if (!ghiParseStatus(connection))
            return;

        connection->headerStringIndex = statusLength + 2;

        if (connection->statusCode == 100 && connection->postingState.waitPostContinue)
        {
            connection->postingState.waitPostContinue = 0;
            ghiResetBuffer(&connection->recvBuffer);
            connection->state = 6;
            ghiCallProgressCallback(connection, 0, 0);
            gsDebugFormat(8, 0, 0x10, sGhttpGotHttpContinue);
        }
        else
        {
            connection->state = 9;
            ghiCallProgressCallback(connection, 0, 0);
        }
    }
    else if (result == 2)
    {
        connection->completed = 1;
        connection->result = 7;
        connection->socketError = GOAGetLastError(connection->socket);
    }
}



/*
 * sdk:      ghiDeliverIncomingFileData (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
int ghiDeliverIncomingFileData(GHIConnection *connection, char *data, int len)
{
    char *buffer = 0;
    int bufferLen = 0;

    connection->fileBytesReceived += len;
    if (connection->fileBytesReceived == connection->totalSize || connection->connectionClosed != 0)
        connection->completed = 1;

    if (connection->type == 0) {
        if (ghiAppendDataToBuffer(&connection->getFileBuffer, data, len) == 0)
            return 0;
        buffer = connection->getFileBuffer.data;
        bufferLen = connection->getFileBuffer.len;
    } else if (connection->type == 1) {
        if (len != 0) {
            connection->completed = 1;
            connection->result = 13;
            return 0;
        }
        buffer = data;
        bufferLen = len;
    } else if (connection->type == 2) {
        buffer = data;
        bufferLen = len;
    }
    ghiCallProgressCallback(connection, buffer, bufferLen);
    return 1;
}



/*
 * sdk:      ghiParseChunkSize (ghttpprocess.o)
 */
int ghiParseChunkSize(GHIConnection *connection)
{
    int num;
    if (STD_TSScanf(connection->chunkHeader, sGhttpChunkSizeFormat, &num) != 1)
        return -1;
    return num;
}



/*
 * sdk:      ghiAppendToChunkHeaderBuffer (ghttpprocess.o)
 */
void ghiAppendToChunkHeaderBuffer(GHIConnection *connection, char *data, int len)
{
    int copyLen;
    if (len == 0 || connection->chunkHeaderLen >= 10)
        return;
    copyLen = 10 - connection->chunkHeaderLen;
    if (copyLen >= len)
        copyLen = len;
    memcpy(connection->chunkHeader + connection->chunkHeaderLen, data, copyLen);
    connection->chunkHeaderLen += copyLen;
    connection->chunkHeader[connection->chunkHeaderLen] = 0;
}



int ghiProcessIncomingFileData(GHIConnection *connection, char *data, int len)
{
    char *endOfHeader;
    char *endOfFooter;
    int toWrite;

    if (connection->chunkedTransfer)
    {
        while (len > 0)
        {
            if (connection->chunkReadingState == 0)
            {
                endOfHeader = strchr(data, '\n');
                if (endOfHeader != 0)
                {
                    ghiAppendToChunkHeaderBuffer(connection, data, endOfHeader - data);
                    endOfHeader++;
                    len -= endOfHeader - data;
                    data = endOfHeader;
                    connection->chunkBytesLeft = ghiParseChunkSize(connection);
                    if (connection->chunkBytesLeft == -1)
                    {
                        connection->completed = 1;
                        connection->result = 7;
                        return 0;
                    }
                    if (connection->chunkBytesLeft == 0)
                    {
                        connection->chunkReadingState = 3;
                        gsDebugFormat(8, 0, 0x20, sGhttpReadingFooter);
                    }
                    else
                    {
                        connection->chunkReadingState = 1;
                        gsDebugFormat(8, 0, 0x20, sGhttpReadingByteChunk, connection->chunkBytesLeft);
                    }
                }
                else
                {
                    ghiAppendToChunkHeaderBuffer(connection, data, len);
                    return 1;
                }
            }
            else if (connection->chunkReadingState == 1)
            {
                toWrite = connection->chunkBytesLeft;
                if (toWrite >= len)
                    toWrite = len;
                gsDebugFormat(8, 0, 0x20, sGhttpReadBytesOfChunk, toWrite);
                if (!ghiDeliverIncomingFileData(connection, data, toWrite))
                    return 0;
                data += toWrite;
                len -= toWrite;
                connection->chunkBytesLeft -= toWrite;
                if (connection->chunkBytesLeft == 0)
                    connection->chunkReadingState = 2;
            }
            else if (connection->chunkReadingState == 2)
            {
                endOfFooter = strchr(data, '\n');
                if (endOfFooter == 0)
                    return 1;
                endOfFooter++;
                len -= endOfFooter - data;
                data = endOfFooter;
                connection->chunkHeader[0] = '\0';
                connection->chunkHeaderLen = 0;
                connection->chunkBytesLeft = 0;
                connection->chunkReadingState = 0;
                gsDebugFormat(8, 0, 0x20, sGhttpReadChunkFooter);
            }
            else if (connection->chunkReadingState == 3)
            {
                connection->completed = 1;
                gsDebugFormat(8, 0, 0x20, sGhttpFinishedReadingChunks);
                return 1;
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
    return ghiDeliverIncomingFileData(connection, data, len);
}



/*
 * sdk:      ghiFreeTempBuffer (ghttpprocess.o)
 *
 * Null-guarded release of a temporary receive buffer.
 */
void ghiFreeTempBuffer(void *memory)
{
    if (memory == 0)
        return;
    gsifree(memory);
}



/*
 * sdk:      ghiDoReceivingHeaders (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * The second isspace loop (after the header-value scan) is the short-circuit
 * form `(c < 0 || c >= 0x80) ? 0 : table`, not the unsigned fold the first
 * loop uses.
 */
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
        if (connection->encryptor.engine != 0 && connection->encryptor.encryptOnBuffer == 1) {
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
        fileLength = connection->recvBuffer.len - (fileStart - connection->recvBuffer.data);
        connection->recvBuffer.pos = connection->recvBuffer.len =
            endOfHeaders - connection->recvBuffer.data + 1;

        if (connection->statusCode / 100 == 1) {
            if (fileLength != 0) {
                memmove(connection->recvBuffer.data, fileStart, fileLength + 1);
                connection->recvBuffer.len = fileLength;
            } else {
                ghiResetBuffer(&connection->recvBuffer);
            }
            if (connection->postingState.waitPostContinue != 0) {
                connection->postingState.waitPostContinue = 0;
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



/*
 * sdk:      ghiDoReceivingFile (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void ghiDoReceivingFile(GHIConnection *connection)
{
    int result;
    unsigned int startTime;
    unsigned int runningTime;
    int bufferLen;
    char *buffer;
    int decryptedLen;

    startTime = current_time();
    runningTime = 0;
    bufferLen = 0;

    buffer = gsimalloc(0x2000);
    if (buffer == 0)
    {
        connection->completed = 1;
        connection->result = 1;
        return;
    }

    gsDebugFormat(8, (char *)3, 0x10, sGhttpReceivingFile);

    while (!connection->completed && runningTime < connection->maxRecvTime)
    {
        bufferLen = 0x2000;
        result = ghiDoReceive(connection, buffer, &bufferLen);
        if (result == 1)
        {
            ghiFreeTempBuffer(buffer);
            if (connection->receiveFileIdleTime == 0)
            {
                connection->receiveFileIdleTime = current_time();
                return;
            }
            if (current_time() - connection->receiveFileIdleTime < 30000)
                return;
            gsDebugFormat(8, 0, 1, sGhttpReceiveFileIdleTimeout, current_time() - connection->receiveFileIdleTime);
            connection->receiveFileIdleTime = 0;
            connection->completed = 1;
            connection->result = 0x13;
            return;
        }
        connection->receiveFileIdleTime = 0;

        if (result == 3)
        {
            ghiFreeTempBuffer(buffer);
            return;
        }
        if (result == 2)
        {
            connection->completed = 1;
            if (connection->totalSize > 0 && connection->fileBytesReceived < connection->totalSize)
                connection->result = 0xF;
            ghiFreeTempBuffer(buffer);
            return;
        }

        if (connection->encryptor.engine != 0 && connection->encryptor.encryptOnBuffer == 1)
        {
            if (!ghiAppendDataToBuffer(&connection->decodeBuffer, buffer, bufferLen))
            {
                ghiFreeTempBuffer(buffer);
                return;
            }
            connection->recvBuffer.len = connection->recvBuffer.pos;
            if (!ghiDecryptReceivedData(connection))
            {
                connection->completed = 1;
                connection->result = 0x11;
                ghiFreeTempBuffer(buffer);
                return;
            }
            decryptedLen = connection->recvBuffer.len - connection->recvBuffer.pos;
            if (decryptedLen != 0)
            {
                if (!ghiProcessIncomingFileData(connection, connection->recvBuffer.data + connection->recvBuffer.pos, decryptedLen))
                {
                    ghiFreeTempBuffer(buffer);
                    return;
                }
            }
        }
        else
        {
            if (!ghiProcessIncomingFileData(connection, buffer, bufferLen))
            {
                ghiFreeTempBuffer(buffer);
                return;
            }
        }

        runningTime = current_time() - startTime;
    }

    ghiFreeTempBuffer(buffer);
}
