/*
 * file:     ghttpmain.c
 * unit:     yes
 * function: ghiHandleStatus, ghiProcessConnection, ghttpStartup, ghttpCleanup, ghttpGetExA, ghttpThink, ghttpRequestThink, ghttpCancelRequest, ghttpGetState, ghttpSetMaxRecvTime, ghttpNewPost, ghttpPostSetAutoFree, ghttpFreePostAndUpdateConnection, ghttpPostAddXml, ghttpSetRootCAList, ghttpCleanupRootCAList
 * address:  0x021C1D30
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Tail call of ghiEnumConnections on the 0x021C1DEC record.
 *
 * symbols:
 *   ghiDoSocketInit                    0x021c3bac arm  ov114
 *   ghiDoHostLookup                    0x021c3d10 arm  ov114
 *   ghiDoLookupPending                    0x021c3e10 arm  ov114
 *   ghiDoConnecting                    0x021c3ec0 arm  ov114
 *   ghiDoSecuringSession                    0x021c4150 arm  ov114
 *   ghiDoSendingRequest                    0x021c4384 arm  ov114
 *   ghiDoPosting                    0x021c4684 arm  ov114
 *   ghiDoWaiting                    0x021c4764 arm  ov114
 *   ghiDoReceivingStatus                    0x021c492c arm  ov114
 *   ghiDoReceivingHeaders                    0x021c4e7c arm  ov114
 *   ghiDoReceivingFile                    0x021c5430 arm  ov114
 *   gsDebugFormat                    0x0217d254 arm  ov009
 *   ghiRedirectConnection                    0x021c0e58 arm  ov114
 *   CanReceiveOnSocket                    0x0217ef50 arm  ov009
 *   ghiCloseConnection                    0x021c0b4c arm  ov114
 *   ghiCallCompletedCallback                    0x021c0244 arm  ov114
 *   ghiFreeConnectionData                    0x021c0c14 arm  ov114
 *   sGhttpConnectionClosing                       0x021ced74 data
 *   ghiLock  0x021C0370  arm  ov114
 *   ghiInitLock  0x021C0368  arm  ov114
 *   ghiUnlock  0x021C0374  arm  ov114
 *   gGhttpInitCount  0x021D3B64  data
 *   gGhttpThrottle  0x021CE5AC  data
 *   gGhttpThrottleBufferSize  0x021CE5B0  data
 *   ghiCleanupConnections  0x021C0FB0  arm  ov114
 *   gsifree  0x0217EAE0  arm  ov009
 *   ghiFreeLock  0x021C036C  arm  ov114
 *   gGhttpProxyServer  0x021D3B2C  data
 *   ghiNewConnection                    0x021c0998 arm  ov114
 *   goastrdup                    0x0217f1e0 arm  ov009
 *   ghiFreeConnection                    0x021c0d40 arm  ov114
 *   ghiInitFixedBuffer                    0x021bfc54 arm  ov114
 *   ghiInitBuffer                    0x021bfbd0 arm  ov114
 *   ghiPostInitState                    0x021c2a78 arm  ov114
 *   msleep                    0x0217f2bc arm  ov009
 *   ghiEnumConnections  0x021C0DF8  arm  ov114
 *   ghiRequestToConnection  0x021C0DA4 arm ov114
 *   ghiProcessConnection    0x021C1DEC arm ov114
 *   ghiCloseConnection      0x021C0B4C arm ov114
 *   ghiRequestToConnection  0x021C0DA4  arm  ov114
 *   ghiNewPost  0x021C23E4  arm  ov114
 *   ghiPostSetAutoFree  0x021C245C  arm  ov114
 *   ghiFreePostAndUpdateConnection  0x021C2490  arm  ov114
 *   ghiPostAddXml  0x021C2584  arm  ov114
 *   ghiEncyptorSetRootCAList  0x021C1184  arm  ov114
 *   ghiEncryptorCleanupRootCAList  0x021C1210  arm  ov114
 */
#include "ghttp_types.h"

extern void ghiDoSocketInit(GHIConnection *connection);
extern void ghiDoHostLookup(GHIConnection *connection);
extern void ghiDoLookupPending(GHIConnection *connection);
extern void ghiDoConnecting(GHIConnection *connection);
extern void ghiDoSecuringSession(GHIConnection *connection);
extern void ghiDoSendingRequest(GHIConnection *connection);
extern void ghiDoPosting(GHIConnection *connection);
extern void ghiDoWaiting(GHIConnection *connection);
extern void ghiDoReceivingStatus(GHIConnection *connection);
extern void ghiDoReceivingHeaders(GHIConnection *connection);
extern void ghiDoReceivingFile(GHIConnection *connection);
extern void gsDebugFormat(int cat, int type, int level, char *fmt, ...);
extern void ghiRedirectConnection(GHIConnection *connection);
extern int CanReceiveOnSocket(int sock);
extern int ghiCloseConnection(GHIConnection *connection);
extern void ghiCallCompletedCallback(GHIConnection *connection);
extern int ghiFreeConnectionData(GHIConnection *connection);
extern void ghiLock(void);
extern void ghiInitLock(void);
extern void ghiUnlock(void);
extern void ghiCleanupConnections(void);
extern void gsifree(void *ptr);
extern void ghiFreeLock(void);
extern GHIConnection *ghiNewConnection(void);
extern char *goastrdup(const char *src);
extern int ghiFreeConnection(GHIConnection *connection);
extern int ghiInitFixedBuffer(GHIConnection *connection, GHIBuffer *buffer, char *data, int size);
extern int ghiInitBuffer(GHIConnection *connection, GHIBuffer *buffer, int initialSize, int sizeIncrement);
extern int ghiPostInitState(GHIConnection *connection);
extern void msleep(unsigned int msec);
extern void ghiEnumConnections(int (*callback)(GHIConnection *));
extern GHIConnection *ghiRequestToConnection(int request);
extern int ghiProcessConnection(GHIConnection *connection);
extern GHIPost *ghiNewPost(void);
extern void ghiPostSetAutoFree(GHIPost *post, GHTTPBool autoFree);
extern void ghiFreePostAndUpdateConnection(int request, GHIPost *post);
extern int ghiPostAddXml(GHIPost *post, void *xml);
extern int ghiEncyptorSetRootCAList(char *url, void *theRootCAList);
extern int ghiEncryptorCleanupRootCAList(char *url);
void ghiHandleStatus(GHIConnection *connection);
void ghttpStartup(void);
void ghttpCleanup(void);
int ghttpGetExA(const char *URL, const char *headers, char *buffer, int bufferSize, GHIPost *post, int throttle, int blocking, GHTTPProgressCallbackFn progressCallback, GHTTPCompletedCallbackFn completedCallback, void *param);
void ghttpThink(void);
int ghttpRequestThink(int request);
void ghttpCancelRequest(int request);
int ghttpGetState(int request);
void ghttpSetMaxRecvTime(int request, unsigned int maxRecvTime);
GHIPost *ghttpNewPost(void);
void ghttpPostSetAutoFree(GHIPost *post, GHTTPBool autoFree);
void ghttpFreePostAndUpdateConnection(int request, GHIPost *post);
int ghttpPostAddXml(GHIPost *post, void *xml);
int ghttpSetRootCAList(char *url, void *theRootCAList);
int ghttpCleanupRootCAList(char *url);
extern char sGhttpConnectionClosing[];
extern int gGhttpInitCount;
extern int gGhttpThrottleBufferSize;
extern GHIThrottle gGhttpThrottle;
extern void *gGhttpProxyServer;



void ghiHandleStatus(GHIConnection *connection)
{
    switch (connection->statusCode / 100) {
    case 1:
    case 2:
    case 3:
        return;
    case 4:
        switch (connection->statusCode) {
        case 401:
            connection->result = 9;
            break;
        case 403:
            connection->result = 10;
            break;
        case 404:
        case 410:
            connection->result = 11;
            break;
        default:
            connection->result = 8;
            break;
        }
        break;
    case 5:
        connection->result = 12;
        break;
    }
}



/*
 * sdk:      ghiProcessConnection (ghttpmain.o, static)
 */
int ghiProcessConnection(GHIConnection *connection)
{
    int completed;

    if (connection->processing)
        return 0;
    connection->processing = 1;

    if (connection->state == 0)
        ghiDoSocketInit(connection);
    if (connection->state == 1)
        ghiDoHostLookup(connection);
    if (connection->state == 2)
        ghiDoLookupPending(connection);
    if (connection->state == 3)
        ghiDoConnecting(connection);
    if (connection->state == 4)
        ghiDoSecuringSession(connection);
    if (connection->state == 5)
        ghiDoSendingRequest(connection);
    if (connection->state == 6)
        ghiDoPosting(connection);
    if (connection->state == 7)
        ghiDoWaiting(connection);
    if (connection->state == 8)
        ghiDoReceivingStatus(connection);
    if (connection->state == 9)
        ghiDoReceivingHeaders(connection);
    if (connection->state == 10)
        ghiDoReceivingFile(connection);
    if (connection->state == 11)
        gsDebugFormat((int)8, (int)3, 0x10, sGhttpConnectionClosing);

    if (connection->redirectURL)
        ghiRedirectConnection(connection);

    completed = connection->completed;
    if (connection->result == 0x12 && !completed) {
        if (!CanReceiveOnSocket(connection->socket))
            connection->completed = 1;
    }

    if (connection->completed) {
        if (connection->handleStatus == 1) {
            ghiHandleStatus(connection);
            if (!ghiCloseConnection(connection)) {
                connection->processing = 0;
                connection->state = 11;
                return 0;
            }
            ghiCallCompletedCallback(connection);
            if (!ghiFreeConnectionData(connection)) {
                connection->processing = 0;
                return 0;
            }
        } else {
            if (!ghiCloseConnection(connection)) {
                connection->processing = 0;
                connection->state = 11;
                return 0;
            }
            ghiCallCompletedCallback(connection);
            if (!ghiFreeConnectionData(connection)) {
                connection->processing = 0;
                return 0;
            }
        }
    } else {
        connection->processing = 0;
    }

    return completed;
}



/*
 * sdk:      ghttpStartup (libdwcgsghttp.TWL.HYB.a(ghttpmain.o))
 */
void ghttpStartup(void)
{
    ghiLock();
    if (++gGhttpInitCount == 1) {
        ghiInitLock();
        gGhttpThrottleBufferSize = 125;
        gGhttpThrottle.timeDelay = 250;
    } else {
        ghiUnlock();
    }
}



/*
 * sdk:      ghttpCleanup (libdwcgsghttp.TWL.HYB.a(ghttpmain.o))
 */
void ghttpCleanup(void)
{
    ghiLock();
    if (--gGhttpInitCount == 0) {
        ghiCleanupConnections();
        if (gGhttpProxyServer != 0) {
            gsifree(gGhttpProxyServer);
            gGhttpProxyServer = 0;
        }
        ghiUnlock();
        ghiFreeLock();
    } else {
        ghiUnlock();
    }
}



/*
 * sdk:      ghttpGetExA (ghttpmain.o)
 */
int ghttpGetExA(const char *URL, const char *headers, char *buffer, int bufferSize,
                  GHIPost *post, int throttle, int blocking,
                  GHTTPProgressCallbackFn progressCallback,
                  GHTTPCompletedCallbackFn completedCallback, void *param)
{
    GHIConnection *connection;
    int bResult;

    if (!URL || !*URL)
        return -1;
    if (bufferSize < 0)
        return -1;
    if (buffer && !bufferSize)
        return -1;

    if (!gGhttpInitCount)
        ghttpStartup();

    connection = ghiNewConnection();
    if (!connection)
        return -1;

    connection->type = 0;
    connection->URL = goastrdup(URL);
    if (!connection->URL) {
        ghiFreeConnection(connection);
        return -1;
    }
    if (headers && *headers) {
        connection->sendHeaders = goastrdup(headers);
        if (!connection->sendHeaders) {
            ghiFreeConnection(connection);
            return -1;
        }
    }
    connection->post = post;
    connection->blocking = blocking;
    connection->progressCallback = progressCallback;
    connection->completedCallback = completedCallback;
    connection->callbackParam = param;
    connection->throttle = throttle;
    connection->userBufferSupplied = (buffer != 0);

    if (connection->userBufferSupplied)
        bResult = ghiInitFixedBuffer(connection, &connection->getFileBuffer, buffer, bufferSize);
    else
        bResult = ghiInitBuffer(connection, &connection->getFileBuffer, 0x800, 0x800);
    if (!bResult) {
        ghiFreeConnection(connection);
        return -1;
    }

    if (post) {
        if (!ghiPostInitState(connection)) {
            ghiFreeConnection(connection);
            return -1;
        }
    }

    if (blocking) {
        while (!ghiProcessConnection(connection))
            msleep(10);
        return 0;
    }

    return connection->request;
}


void ghttpThink(void)
{
    ghiEnumConnections(ghiProcessConnection);
}




/*
 * sdk:      ghttpRequestThink (ghttpmain)
 */
int ghttpRequestThink(int request)
{
    GHIConnection *connection = ghiRequestToConnection(request);
    if (connection == 0)
        return 0;
    ghiProcessConnection(connection);
    return 1;
}




/*
 * sdk:      ghttpCancelRequest (ghttpmain)
 */
void ghttpCancelRequest(int request)
{
    GHIConnection *connection = ghiRequestToConnection(request);
    if (connection == 0)
        return;
    connection->result = 18;
    connection->state = 11;
    connection->completed = 1;
    ghiCloseConnection(connection);
}




/*
 * Returns the connection state of `request`, or 0 when it does not exist.
 */
int ghttpGetState(int request)
{
    GHIConnection *connection = ghiRequestToConnection(request);
    if (connection != 0)
        return connection->state;
    return 0;
}




/*
 * Sets the receive time limit of `request`.
 */
void ghttpSetMaxRecvTime(int request, unsigned int maxRecvTime)
{
    GHIConnection *connection = ghiRequestToConnection(request);
    if (connection != 0)
        connection->maxRecvTime = maxRecvTime;
}



GHIPost *ghttpNewPost(void)
{
    return ghiNewPost();
}




/*
 * Sets the auto-free flag of `post` (ignored when `post` is null).
 */
void ghttpPostSetAutoFree(GHIPost *post, GHTTPBool autoFree)
{
    if (post == 0)
        return;
    ghiPostSetAutoFree(post, autoFree);
}




/*
 * Frees `post` and updates the connection of `request` (ignored when `post` is null).
 */
void ghttpFreePostAndUpdateConnection(int request, GHIPost *post)
{
    if (post == 0)
        return;
    ghiFreePostAndUpdateConnection(request, post);
}



int ghttpPostAddXml(GHIPost *post, void *xml)
{
    return ghiPostAddXml(post, xml);
}



/*
 * Tail-call thunk to the root CA list setter.
 */
int ghttpSetRootCAList(char *url, void *theRootCAList)
{
    return ghiEncyptorSetRootCAList(url, theRootCAList);
}



/*
 * Tail-call thunk to the root CA list cleanup.
 */
int ghttpCleanupRootCAList(char *url)
{
    return ghiEncryptorCleanupRootCAList(url);
}
