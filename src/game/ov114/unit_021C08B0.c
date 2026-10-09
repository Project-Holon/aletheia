/*
 * file:     unit_021C08B0.c
 * unit:     yes
 * function: func_021C08B0, func_021C0998, ghiCloseConnection, ghiFreeConnectionData, ghiFreeConnection, func_021C0DA4, func_021C0DF8, func_021C0E58, func_021C0FB0, func_021C1020
 * address:  0x021C08B0
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
 *   gsirealloc         0x0217EAC8 arm ov009
 *   gsimalloc          0x0217EAB0 arm ov009
 *   gsifree            0x0217EAE0 arm ov009
 *   ghiConnectionsLen  0x021D3B30 data
 *   func_021C0370                    0x021c0370 arm  ov114
 *   func_021C0374                    0x021c0374 arm  ov114
 *   func_020923B0                    0x020923b0 arm
 *   func_021BFBD0                    0x021bfbd0 arm  ov114
 *   func_021C0D40                    0x021c0d40 arm  ov114
 *   g_021D3B30                       0x021d3b30 data
 *   ghiLock                     0x021C0370  arm
 *   gsDebugFormat               0x0217D254  arm
 *   gsiCancelResolvingHostname  0x0217F1C0  arm
 *   shutdown                    0x0217EB9C  arm
 *   closesocketsure             0x0217EB40  arm
 *   ghiUnlock                   0x021C0374  arm
 *   g_021CE620                  0x021CE620  data
 *   ghiFreeBuffer           0x021BFCB4  arm  ov114
 *   ghiPostCleanupState     0x021C2BB0  arm  ov114
 *   func_0217D254  0x0217d254  arm   ov009
 *   func_0217F1C0  0x0217f1c0  arm   ov009
 *   func_0217EB9C  0x0217eb9c  arm   ov009
 *   func_0217EB40  0x0217eb40  arm   ov009
 *   func_0217EAE0  0x0217eae0  arm   ov009
 *   func_021C00FC  0x021c00fc  arm   ov114
 *   func_020949F4  0x020949f4  arm
 *   g_021CE648     0x021ce648  data  ov114
 *   g_021CE660     0x021ce660  data
 *   strncmp                 0x020949F4  arm
 *   strcspn                 0x02094A60  arm
 *   goastrdup               0x0217F1E0  arm
 *   g_021CE66C              0x021CE66C  data
 *   g_021CE674              0x021CE674  data
 */
#include "ghttp_types.h"

typedef struct {
    int length;
    int numConnections;
    int nextUniqueID;
    GHIConnection **connections;
} GHIGlobals;

extern void *gsirealloc(void *ptr, unsigned long size);
extern void *gsimalloc(unsigned long size);
extern void gsifree(void *ptr);
extern void func_021C0370(void);
extern void func_021C0374(void);
extern void *func_020923B0(void *dst, int c, unsigned int n);
extern int func_021BFBD0(unsigned int a0, unsigned int *a1, int a2, int a3);
extern int func_021C0D40(GHIConnection *connection);
extern void ghiLock(void);
extern void gsDebugFormat(int cat, int type, unsigned int level, char *tokenStr);
extern void gsiCancelResolvingHostname(void *host);
extern int shutdown(int sock, int how);
extern int closesocketsure(int sock, int *notInCloseSocket);
extern void ghiUnlock(void);
extern void ghiFreeBuffer(GHIBuffer *buffer);
extern void ghiPostCleanupState(GHIConnection *connection);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_0217F1C0(void *);
extern int func_0217EB9C(int, int);
extern int func_0217EB40(int, int *);
extern void func_0217EAE0(void *);
extern void func_021C00FC(GHIBuffer *);
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern int strncmp(const char *s1, const char *s2, unsigned int n);
extern int strcspn(const char *s1, const char *s2);
extern char *goastrdup(char *src);
int func_021C08B0(void);
GHIConnection *func_021C0998(void);
int ghiCloseConnection(GHIConnection *connection);
int ghiFreeConnectionData(GHIConnection *connection);
int ghiFreeConnection(GHIConnection *connection);
GHIConnection *ghiRequestToConnection(int request);
void ghiEnumConnections(int (*callback)(GHIConnection *));
void func_021C0E58(GHIConnection *connection);
void ghiCleanupConnections(void);
char *ghiGetServerAddressFromUrl(char *serverUrl);
extern GHIGlobals ghiConnectionsLen;
extern char g_021CE620[];
extern char g_021CE648[];
extern char g_021CE660[];
extern char g_021CE66C[];
extern char g_021CE674[];





int func_021C08B0(void)
{
    int newLen;
    GHIConnection **tempPtr;
    int i;
    int len;

    for (i = 0; i < ghiConnectionsLen.length; i++)
    {
        if (ghiConnectionsLen.connections[i]->inUse == 0)
            return i;
    }
    len = ghiConnectionsLen.length;
    newLen = len + 4;
    tempPtr = (GHIConnection **)gsirealloc(ghiConnectionsLen.connections, newLen * sizeof(GHIConnection *));
    if (tempPtr == 0)
        return -1;
    ghiConnectionsLen.connections = tempPtr;
    for (i = len; i < newLen; i++)
    {
        ghiConnectionsLen.connections[i] = (GHIConnection *)gsimalloc(sizeof(GHIConnection));
        if (ghiConnectionsLen.connections[i] == 0)
        {
            for (i--; i >= len; i--)
                gsifree(ghiConnectionsLen.connections[i]);
            return -1;
        }
        ghiConnectionsLen.connections[i]->inUse = 0;
    }
    ghiConnectionsLen.length = newLen;
    return len;
}





/*
 * sdk:      ghiNewConnection (ghttpconnection.o)
 */
GHIConnection *func_021C0998(void)
{
    int bResult;
    GHIConnection *connection;
    int slot;

    func_021C0370();

    slot = func_021C08B0();
    if (slot == -1) {
        func_021C0374();
        return 0;
    }

    connection = ghiConnectionsLen.connections[slot];
    func_020923B0(connection, 0, sizeof(GHIConnection));
    connection->inUse = 1;
    connection->request = slot;
    connection->uniqueID = ghiConnectionsLen.nextUniqueID++;
    connection->type = 0;
    connection->state = 0;
    connection->URL = 0;
    connection->serverAddress = 0;
    connection->serverIP = 0;
    connection->serverPort = 0;
    connection->requestPath = 0;
    connection->sendHeaders = 0;
    connection->saveFile = 0;
    connection->blocking = 0;
    connection->persistConnection = 0;
    connection->result = 0;
    connection->progressCallback = 0;
    connection->completedCallback = 0;
    connection->callbackParam = 0;
    connection->socket = -1;
    connection->socketError = 0;
    connection->userBufferSupplied = 0;
    connection->statusMajorVersion = 0;
    connection->statusMinorVersion = 0;
    connection->statusCode = 0;
    connection->statusStringIndex = 0;
    connection->headerStringIndex = 0;
    connection->completed = 0;
    connection->fileBytesReceived = 0;
    connection->totalSize = -1;
    connection->redirectURL = 0;
    connection->redirectCount = 0;
    connection->chunkedTransfer = 0;
    connection->processing = 0;
    connection->throttle = 0;
    connection->lastThrottleRecv = 0;
    connection->post = 0;
    connection->maxRecvTime = 500;
    connection->proxyOverridePort = 80;
    connection->proxyOverrideServer = 0;
    connection->encryptor.mInterface = 0;
    connection->encryptor.field_08 = 0;
    connection->receiveFileIdleTime = 0;
    connection->handle = 0;

    bResult = func_021BFBD0((unsigned int)connection, (unsigned int *)&connection->sendBuffer, 0x800, 0x1000);
    if (bResult)
        bResult = func_021BFBD0((unsigned int)connection, (unsigned int *)&connection->encodeBuffer, 0x800, 0x400);
    if (bResult)
        bResult = func_021BFBD0((unsigned int)connection, (unsigned int *)&connection->recvBuffer, 0x800, 0x800);
    if (bResult)
        bResult = func_021BFBD0((unsigned int)connection, (unsigned int *)&connection->decodeBuffer, 0x800, 0x400);
    if (!bResult) {
        func_021C0D40(connection);
        func_021C0374();
        return 0;
    }

    ghiConnectionsLen.numConnections++;
    func_021C0374();
    return connection;
}




int ghiCloseConnection(GHIConnection *connection)
{
    if (connection == 0)
        return 0;
    if (connection->inUse == 0)
        return 0;
    if (connection->request < 0)
        return 0;
    if (connection->request >= ghiConnectionsLen.length)
        return 0;
    ghiLock();
    if (connection->handle != 0)
    {
        gsDebugFormat(8, 3, 0x10, g_021CE620);
        gsiCancelResolvingHostname(connection->handle);
        connection->handle = 0;
    }
    if (connection->socket != -1)
    {
        shutdown(connection->socket, 2);
        if (closesocketsure(connection->socket, &connection->handleStatus) == 0)
        {
            ghiUnlock();
            return 0;
        }
        connection->socket = -1;
    }
    ghiUnlock();
    return 1;
}



int ghiFreeConnectionData(GHIConnection *connection)
{
    if (connection == 0)
        return 0;
    if (connection->inUse == 0)
        return 0;
    if (connection->request < 0)
        return 0;
    if (connection->request >= ghiConnectionsLen.length)
        return 0;
    ghiLock();
    gsifree(connection->URL);
    connection->URL = 0;
    gsifree(connection->saveFileName);
    connection->saveFileName = 0;
    gsifree(connection->serverAddress);
    connection->serverAddress = 0;
    gsifree(connection->requestPath);
    connection->requestPath = 0;
    gsifree(connection->sendHeaders);
    connection->sendHeaders = 0;
    gsifree(connection->redirectURL);
    connection->sendHeaders = 0;
    gsifree(connection->proxyOverrideServer);
    connection->proxyOverrideServer = 0;
    ghiFreeBuffer(&connection->sendBuffer);
    ghiFreeBuffer(&connection->encodeBuffer);
    ghiFreeBuffer(&connection->recvBuffer);
    ghiFreeBuffer(&connection->decodeBuffer);
    ghiFreeBuffer(&connection->getFileBuffer);
    if (connection->postingState.states != 0)
        ghiPostCleanupState(connection);
    if (connection->encryptor.field_08 != 0)
    {
        if (connection->encryptor.cleanupFunc != 0)
            connection->encryptor.cleanupFunc(connection, &connection->encryptor);
        connection->encryptor.field_08 = 0;
    }
    connection->receiveFileIdleTime = 0;
    connection->inUse = 0;
    ghiConnectionsLen.numConnections--;
    ghiUnlock();
    return 1;
}



int ghiFreeConnection(GHIConnection *connection)
{
    if (connection == 0)
        return 0;
    if (connection->inUse == 0)
        return 0;
    if (connection->request < 0)
        return 0;
    if (connection->request >= ghiConnectionsLen.length)
        return 0;
    if (ghiCloseConnection(connection) != 1)
        return 0;
    return ghiFreeConnectionData(connection);
}



GHIConnection *ghiRequestToConnection(int request)
{
    GHIConnection *connection;

    ghiLock();
    if (request < 0 || request >= ghiConnectionsLen.length)
    {
        ghiUnlock();
        return 0;
    }
    connection = ghiConnectionsLen.connections[request];
    if (connection->inUse == 0)
        connection = 0;
    ghiUnlock();
    return connection;
}



void ghiEnumConnections(int (*callback)(GHIConnection *))
{
    int i;

    if (ghiConnectionsLen.numConnections <= 0)
        return;
    ghiLock();
    for (i = 0; i < ghiConnectionsLen.length; i++)
    {
        GHIConnection *connection = ghiConnectionsLen.connections[i];
        if (connection->inUse != 0)
            callback(connection);
    }
    ghiUnlock();
}



/*
 * sdk:      ghiRedirectConnection (libdwcgsghttp.TWL.HYB.a ghttpconnection.o)
 */
void func_021C0E58(GHIConnection *connection)
{
    func_0217D254(8, (char *)3, 0x10, g_021CE648);
    if (connection->handle != 0) {
        func_0217D254(8, (char *)3, 0x10, g_021CE620);
        func_0217F1C0(connection->handle);
        connection->handle = 0;
    }
    func_0217EB9C(connection->socket, 2);
    if (func_0217EB40(connection->socket, &connection->handleStatus) == 0)
        return;
    func_0217EAE0(connection->URL);
    connection->URL = connection->redirectURL;
    connection->redirectURL = 0;
    func_0217EAE0(connection->serverAddress);
    connection->serverAddress = 0;
    connection->serverIP = 0;
    connection->serverPort = 0;
    func_0217EAE0(connection->requestPath);
    connection->requestPath = 0;
    connection->state = 0;
    connection->socket = -1;
    func_021C00FC(&connection->sendBuffer);
    func_021C00FC(&connection->encodeBuffer);
    func_021C00FC(&connection->recvBuffer);
    func_021C00FC(&connection->decodeBuffer);
    connection->statusMajorVersion = 0;
    connection->statusMinorVersion = 0;
    connection->statusCode = 0;
    connection->statusStringIndex = 0;
    connection->headerStringIndex = 0;
    connection->connectionClosed = 0;
    if (connection->encryptor.field_08 != 0) {
        if (connection->encryptor.cleanupFunc != 0)
            connection->encryptor.cleanupFunc(connection, &connection->encryptor);
        connection->encryptor.field_08 = 0;
        if (func_020949F4((const u8 *)g_021CE660, (const u8 *)connection->URL, 8) != 0) {
            connection->encryptor.engine = 0;
            connection->encryptor.mInterface = 0;
        }
    }
    connection->redirectCount++;
}



void ghiCleanupConnections(void)
{
    int i;

    if (ghiConnectionsLen.connections == 0)
        return;
    ghiEnumConnections(ghiFreeConnection);
    for (i = 0; i < ghiConnectionsLen.length; i++)
        gsifree(ghiConnectionsLen.connections[i]);
    gsifree(ghiConnectionsLen.connections);
    ghiConnectionsLen.connections = 0;
    ghiConnectionsLen.length = 0;
    ghiConnectionsLen.numConnections = 0;
}



char *ghiGetServerAddressFromUrl(char *serverUrl)
{
    int nIndex;
    char *url;
    char tempChar;
    char *serverAddress;

    if (strncmp(serverUrl, g_021CE66C, 7) == 0)
        url = serverUrl + 7;
    else if (strncmp(serverUrl, g_021CE660, 8) == 0)
        url = serverUrl + 8;
    else
        return 0;

    nIndex = strcspn(url, g_021CE674);
    tempChar = url[nIndex];
    url[nIndex] = 0;
    serverAddress = goastrdup(url);
    url[nIndex] = tempChar;
    return serverAddress;
}
