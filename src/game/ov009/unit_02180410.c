/*
 * file:     unit_02180410.c
 * unit:     yes
 * function: func_02180410, func_02180420, func_02180430, gsUdpRemotePeerCompare, func_02180474, func_0218048C, func_02180518, func_021806A8, func_02180924, func_02180A64, func_02180BFC, func_02180C94, func_02180E48, func_02180E58, func_02181010, func_021810CC, func_02181350, gsUdpEngineThink, gsUdpEngineShutdown, gsUdpEngineGetLocalPort, func_021815C8, func_02181748, gsUdpEngineNoMoreMsgHandlers, gsUdpEngineNoApp, func_021818EC
 * address:  0x02180410
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ArrayFree                    0x021841B0  arm
 *   func_020923F0                0x020923F0  arm
 *   func_02180404                  0x02180404  arm ov009
 *   func_0217D254                  0x0217D254  arm ov009
 *   func_02184200                  0x02184200  arm ov009
 *   func_02184208                  0x02184208  arm ov009
 *   g_021A3868                     0x021A3868  data
 *   func_02195E28                  0x02195E28  arm ov009
 *   func_02195E30                  0x02195E30  arm ov009
 *   func_02198620                  0x02198620  arm ov009
 *   func_021843E8                  0x021843E8  arm ov009
 *   func_0218437C                  0x0218437C  arm ov009
 *   func_02180474                  0x02180474  arm ov009
 *   g_021A38A8                     0x021A38A8  data
 *   g_021A38D0                     0x021A38D0  data
 *   g_021A390C                     0x021A390C  data
 *   func_02180448                  0x02180448  arm ov009
 *   g_021A393C                     0x021A393C  data
 *   g_021A3964                     0x021A3964  data
 *   g_021A399C                     0x021A399C  data
 *   g_021A39C8                     0x021A39C8  data
 *   g_021A39EC                     0x021A39EC  data
 *   g_021A3A14                     0x021A3A14  data
 *   func_02180430                  0x02180430  arm ov009
 *   g_021A3A30                     0x021A3A30  data
 *   g_021A3A54                     0x021A3A54  data
 *   func_02184234                  0x02184234  arm ov009
 *   func_02195B2C                  0x02195B2C  arm ov009
 *   func_02195B38                  0x02195B38  arm ov009
 *   func_02184324                  0x02184324  arm ov009
 *   func_02180420                  0x02180420  arm ov009
 *   g_021A3A8C                     0x021A3A8C  data
 *   g_021A3AB8                     0x021A3AB8  data
 *   g_021A3AFC                     0x021A3AFC  data
 *   func_02195AB4                  0x02195AB4  arm ov009
 *   func_02184144                  0x02184144  arm ov009
 *   func_02195E68                  0x02195E68  arm ov009
 *   func_02195B20                  0x02195B20  arm ov009
 *   func_02195E38                  0x02195E38  arm ov009
 *   func_02195E40                  0x02195E40  arm ov009
 *   func_02180410                  0x02180410  arm ov009
 *   g_021A3B44                     0x021A3B44  data
 *   g_021A3B7C                     0x021A3B7C  data
 *   func_02195E00                  0x02195E00  arm ov009
 *   g_021A3B9C                     0x021A3B9C  data
 *   func_02195B44                  0x02195B44  arm ov009
 *   g_021A3BC4                     0x021A3BC4  data
 *   g_021A3BF8                     0x021A3BF8  data
 *   func_02195E48                  0x02195E48  arm ov009
 *   func_0217EAB0                  0x0217EAB0  arm ov009
 *   memcpy                         0x02092344  arm
 *   func_02195CC0                  0x02195CC0  arm ov009
 *   func_0217EAE0                  0x0217EAE0  arm ov009
 *   g_021A3C34                     0x021A3C34  data
 *   g_021A3C68                     0x021A3C68  data
 *   func_02195AF0                         0x02195af0 arm
 *   func_02195AD8                   0x02195ad8 arm
 *   g_021A3CA0                     0x021A3CA0  data
 *   g_021A3CC4                     0x021A3CC4  data
 *   g_021A3CE4               0x021A3CE4 data
 *   func_02195E50                  0x02195E50  arm ov009
 */
#include "gsudp_types.h"
#include "../../matched/arm9_sdk/libc/string.h"

extern int func_020923F0(const void *a, const void *b, int n);
extern int func_02195E28(const int *p);
extern unsigned short func_02195E30(const unsigned short *p);
extern char *func_02198620(unsigned int ip, unsigned short port, char *string);
extern void func_0218437C(int a, int b);
extern int func_02180474(void *theFirstPeer, void *theSecondPeer);
extern int func_02180448(void *theFirstPeer, void *theSecondPeer);
extern int func_02180430(void *theFirstHandler, void *theSecondHandler);
extern int func_02195B2C(void *connection, GT2ConnectionCallbacks *callbacks);
extern void func_02195B38(void *connection, unsigned char *message, int len);
extern void func_02184324(void *array, int n);
extern int func_02180420(void *theFirstHandler, void *theSecondHandler);
extern int func_02195AB4(void **sock, char *addr, int outSize, int inSize, void *callback);
extern void *func_02184144(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void func_02195E68(int *p, int v);
extern void func_02195B20(int *p, int v);
extern int func_02195E38(const int *p);
extern unsigned short func_02195E40(const unsigned short *p);
extern void func_02180410(void *theMsgHandler);
extern int func_02195E00(const int *p);
extern int func_02195B44(void *socket, void **connection, char *remoteAddress, u8 *message, int len, int timeout, void *callbacks, int blocking);
extern int func_02195E48(const int *p);
extern void *func_0217EAB0(unsigned long size);
extern int func_02195CC0(void *connection, unsigned char *message, int len, int reliable);
extern void func_0217EAE0(void *ptr);
extern void func_02195AF0(void *socket);
extern void func_02195AD8(void *socket);
extern int func_021843E8(void *array, void *key, int (*comparator)(void *, void *), int fromIndex, int isSorted);
extern void *memcpy(void *dst, const void *src, unsigned long n);
extern int func_02184200(void *array);
extern int func_02195E50(const int *p);
void gsUdpMsgHandlerFree(GSUdpMsgHandler *theHandler);
int gsUdpMsgHandlerCompare(void *theFirst, void *theSecond);
int gsUdpMsgHandlerCompare2(void *theFirst, void *theSecond);
int gsUdpRemotePeerCompare(void *theFirstPeer, void *theSecondPeer);
int gsUdpRemotePeerCompare2(void *theFirstPeer, void *theSecondPeer);
void func_0218048C(void);
void func_02180518(void *theConnection, int reason);
void func_021806A8(void *theConnection, int theResult);
void func_02180924(void *theConnection, int theLatency);
void func_02180A64(void *theConnection, unsigned char *theMessage, int theMessageLen, int reliable);
int func_02180BFC(void *theSocket, unsigned int theIp, unsigned short thePort, unsigned char *theMessage, int theMsgLen);
void func_02180C94(void *socket, void *connection, unsigned int ip, unsigned short port, int latency, unsigned char *message, int len);
int func_02180E48(void);
int func_02180E58(unsigned short thePort, int theIncomingBufSize, int theOutgoingBufSize, void (*theAppNetworkError)(int, void *), void (*theAppConnected)(unsigned int, unsigned short, int, int, void *), void (*theAppClosed)(unsigned int, unsigned short, int, void *), void (*theAppPing)(unsigned int, unsigned short, unsigned int, void *), void (*theAppReceive)(unsigned int, unsigned short, unsigned char *, unsigned int, int, void *), int (*theAppUnownMsg)(unsigned int, unsigned short, unsigned char *, unsigned int, void *), void (*theAppConnectAttempt)(unsigned int, unsigned short, int, unsigned char *, unsigned int, void *), void *theAppUserData);
int func_02181010(unsigned int theIp, unsigned short thePort, int *thePeerState);
int func_021810CC(unsigned int theIp, unsigned short thePort, char *theInitMsg, int timeOut);
int func_02181350(unsigned int theIp, unsigned short thePort, char *theHeader, unsigned char *theMsg, unsigned int theMsgLen, int theReliable);
int gsUdpEngineThink(void);
int gsUdpEngineShutdown(void);
unsigned short gsUdpEngineGetLocalPort(void);
int func_021815C8(char *theInitMsg, char *theHeader, void (*theMsgHandlerError)(int, void *), void (*theMsgHandlerConnected)(unsigned int, unsigned short, int, int, void *), void (*theMsgHandlerClosed)(unsigned int, unsigned short, int, void *), void (*theMsgHandlerPing)(unsigned int, unsigned short, unsigned int, void *), void (*theMsgHandlerRecv)(unsigned int, unsigned short, unsigned char *, unsigned int, int, void *), void *theUserData);
int func_02181748(char *theHeader);
int gsUdpEngineNoMoreMsgHandlers(void);
int gsUdpEngineNoApp(void);
int func_021818EC(unsigned int theIp, unsigned short thePort);
extern char g_021A3868[];
extern char g_021A38A8[];
extern char g_021A38D0[];
extern char g_021A390C[];
extern char g_021A393C[];
extern char g_021A3964[];
extern char g_021A399C[];
extern char g_021A39C8[];
extern char g_021A39EC[];
extern char g_021A3A14[];
extern char g_021A3A30[];
extern char g_021A3A54[];
extern char g_021A3A8C[];
extern char g_021A3AB8[];
extern char g_021A3AFC[];
extern char g_021A3B44[];
extern char g_021A3B7C[];
extern char g_021A3BC4[];
extern char g_021A3BF8[];
extern char g_021A3C34[];
extern char g_021A3C68[];
extern char g_021A3CA0[];
extern char g_021A3CC4[];
extern char g_021A3CE4[];


void gsUdpMsgHandlerFree(GSUdpMsgHandler *theHandler)
{
    ArrayFree(theHandler->mPendingConnections);
}


int gsUdpMsgHandlerCompare(void *theFirst, void *theSecond)
{
    return func_020923F0(theFirst, theSecond, 16);
}


int gsUdpMsgHandlerCompare2(void *theFirst, void *theSecond)
{
    return func_020923F0((char *)theFirst + 16, (char *)theSecond + 16, 16);
}


int gsUdpRemotePeerCompare(void *theFirstPeer, void *theSecondPeer)
{
    GSUdpRemotePeer *aPeer1 = (GSUdpRemotePeer *)theFirstPeer;
    GSUdpRemotePeer *aPeer2 = (GSUdpRemotePeer *)theSecondPeer;

    if (aPeer1->mAddr != aPeer2->mAddr)
        return 1;
    if (aPeer1->mPort != aPeer2->mPort)
        return 1;
    return 0;
}


int gsUdpRemotePeerCompare2(void *theFirstPeer, void *theSecondPeer)
{
    return ((GSUdpRemotePeer *)theFirstPeer)->mConnection != ((GSUdpRemotePeer *)theSecondPeer)->mConnection;
}


/*
 * sdk:      gsUdpSocketError (gsudpengine.o)
 */
void func_0218048C(void)
{
    int i;
    int len;
    GSUdpEngineObject *aUdp;
    GSUdpMsgHandler *aMsgHandler;

    aUdp = func_02180404();
    func_0217D254(12, 0, 16, g_021A3868);
    if (aUdp->mAppNetworkError != 0)
        aUdp->mAppNetworkError(3, aUdp->mAppUserData);
    len = func_02184200(aUdp->mMsgHandlers);
    for (i = 0; i < len; i++) {
        aMsgHandler = (GSUdpMsgHandler *)func_02184208(aUdp->mMsgHandlers, i);
        if (aMsgHandler->mNetworkError != 0)
            aMsgHandler->mNetworkError(3, aMsgHandler->mUserData);
    }
}


/*
 * sdk:      gsUdpClosedRoutingCB (gsudpengine.o)
 */
void func_02180518(void *theConnection, int reason)
{
    GSUdpEngineObject *aUdp;
    GSUdpRemotePeer aRemotePeer;
    int index;
    int len;
    int aReason;
    char anAddr[22];
    GSUdpMsgHandler *aHandler;

    aUdp = func_02180404();
    if (reason == 2 || reason == 3)
        aReason = 2;
    else if (reason == 4)
        aReason = 3;
    else
        aReason = reason;

    func_0217D254(12, 0, 16, g_021A38A8,
        func_02198620(func_02195E28(theConnection), func_02195E30(theConnection), anAddr));

    len = func_02184200(aUdp->mMsgHandlers);
    for (index = 0; index < len; index++) {
        aHandler = (GSUdpMsgHandler *)func_02184208(aUdp->mMsgHandlers, index);
        if (aHandler->mClosed) {
            func_0217D254(12, 0, 16, g_021A38D0);
            aHandler->mClosed(func_02195E28(theConnection), func_02195E30(theConnection), aReason, aHandler->mUserData);
        }
    }

    if (aUdp->mAppClosed) {
        func_0217D254(12, 0, 16, g_021A390C);
        aUdp->mAppClosed(func_02195E28(theConnection), func_02195E30(theConnection), aReason, aUdp->mAppUserData);
    }

    aRemotePeer.mConnection = theConnection;
    index = func_021843E8(aUdp->mRemotePeers, &aRemotePeer, func_02180474, 0, 0);
    if (index == -1)
        return;
    func_0218437C((int)aUdp->mRemotePeers, index);
}


/*
 * sdk:      gsUdpConnectedRoutingCB (gsudpengine.o)
 */
void func_021806A8(void *theConnection, int theResult)
{
    GSUdpEngineObject *aUdp;
    int aIndex;
    int len;
    int aCode;
    char anAddr[22];

    aUdp = func_02180404();
    switch (theResult) {
    case 7:
        aCode = 7;
        break;
    case 2:
        aCode = 2;
        break;
    case 6:
        aCode = 6;
        break;
    case 0:
        aCode = 0;
        break;
    default:
        aCode = 13;
        break;
    }

    if (theResult == 2) {
        int aRemotePeerIdx;
        GSUdpRemotePeer aRemotePeer;

        aRemotePeer.mAddr = func_02195E28(theConnection);
        aRemotePeer.mPort = func_02195E30(theConnection);
        aRemotePeerIdx = func_021843E8(aUdp->mRemotePeers, &aRemotePeer, func_02180448, 0, 0);
        if (aRemotePeerIdx != -1) {
            func_0217D254(12, 0, 16, g_021A393C,
                func_02198620(func_02195E28(theConnection), func_02195E30(theConnection), anAddr));
            func_0218437C((int)aUdp->mRemotePeers, aRemotePeerIdx);
        }
    }

    len = func_02184200(aUdp->mMsgHandlers);
    for (aIndex = 0; aIndex < len; aIndex++) {
        int aRemotePeerIdx;
        GSUdpRemotePeer aRemotePeer;
        GSUdpMsgHandler *aTempHandler;

        aTempHandler = (GSUdpMsgHandler *)func_02184208(aUdp->mMsgHandlers, aIndex);
        aRemotePeer.mAddr = func_02195E28(theConnection);
        aRemotePeer.mPort = func_02195E30(theConnection);
        aRemotePeerIdx = func_021843E8(aTempHandler->mPendingConnections, &aRemotePeer, func_02180448, 0, 0);
        if (aRemotePeerIdx != -1) {
            if (aTempHandler->mConnected) {
                func_0217D254(12, 0, 16, g_021A3964);
                aTempHandler->mConnected(func_02195E28(theConnection), func_02195E30(theConnection),
                    aCode, (theResult == 2) ? 1 : 0, aTempHandler->mUserData);
            }
            func_0218437C((int)aTempHandler->mPendingConnections, aRemotePeerIdx);
            return;
        }
    }

    if (aUdp->mAppPendingConnections > 0) {
        if (aUdp->mAppConnected) {
            func_0217D254(12, 0, 16, g_021A399C);
            aUdp->mAppConnected(func_02195E28(theConnection), func_02195E30(theConnection),
                aCode, (theResult == 2) ? 1 : 0, aUdp->mAppUserData);
        }
        aUdp->mAppPendingConnections--;
    }
}


void func_02180924(void *theConnection, int theLatency)
{
    GSUdpEngineObject *aUdp;
    char anAddr[22];
    int index;
    int len;
    GSUdpMsgHandler *aHandler;

    aUdp = func_02180404();

    func_0217D254(12, 0, 16, g_021A39C8,
        func_02198620(func_02195E28(theConnection), func_02195E30(theConnection), anAddr));

    len = func_02184200(aUdp->mMsgHandlers);
    for (index = 0; index < len; index++) {
        aHandler = (GSUdpMsgHandler *)func_02184208(aUdp->mMsgHandlers, index);
        if (aHandler->mPingReply) {
            func_0217D254(12, 0, 16, g_021A39EC);
            aHandler->mPingReply(func_02195E28(theConnection), func_02195E30(theConnection), theLatency, aHandler->mUserData);
            return;
        }
    }

    if (aUdp->mAppPingReply) {
        func_0217D254(12, 0, 16, g_021A3A14);
        aUdp->mAppPingReply(func_02195E28(theConnection), func_02195E30(theConnection), theLatency, aUdp->mAppUserData);
    }
}


/*
 * sdk:      gsUdpReceivedRoutingCB (gsudpengine.o)
 * Closed (lane U13): the 16-byte copy into aHandler.mHeader is
 * memcpy(&aHandler.mHeader, theMessage, sizeof(aHandler.mHeader)) with the
 * house string.h prototype (which makes mwccarm expand memcpy as the two-byte
 * loop instead of emitting a call -- a prototype written in the .c file itself
 * always produces the call, which is why lane w2_o2 saw "memcpy (a real call)").
 * The intrinsic expansion colours the destination r4 and the source r3, exactly
 * as the object does; the struct assignment `aHandler.mHeader = *(GSUdpHdr *)
 * theMessage` gives the mirror image (destination r3, source r4).  Same close as
 * ov009_func_0217ECA4 (sendto) and gsUdpConnAttemptCB (0x02180C94).
 */
void func_02180A64(void *theConnection, unsigned char *theMessage, int theMessageLen, int reliable)
{
    GSUdpEngineObject *aUdp;
    GSUdpMsgHandler aHandler;
    int index;
    char anAddr[22];
    GSUdpMsgHandler *aHandlerFound;

    aUdp = func_02180404();
    func_0217D254(12, 0, 16, g_021A3A30,
        func_02198620(func_02195E28(theConnection), func_02195E30(theConnection), anAddr));

    if (theMessageLen >= 16) {
        memcpy(&aHandler.mHeader, theMessage, sizeof(aHandler.mHeader));
        index = func_021843E8(aUdp->mMsgHandlers, &aHandler, func_02180430, 0, 0);
        if (index != -1) {
            aHandlerFound = (GSUdpMsgHandler *)func_02184208(aUdp->mMsgHandlers, index);
            if (aHandlerFound->mReceived) {
                func_0217D254(12, 0, 16, g_021A39EC);
                aHandlerFound->mReceived(func_02195E28(theConnection), func_02195E30(theConnection),
                    theMessage + 16, theMessageLen - 16, reliable, aHandlerFound->mUserData);
                return;
            }
        }
    }

    if (aUdp->mAppRecvData) {
        func_0217D254(12, 0, 16, g_021A3A14);
        aUdp->mAppRecvData(func_02195E28(theConnection), func_02195E30(theConnection),
            theMessage, theMessageLen, reliable, aUdp->mAppUserData);
    }
}


int func_02180BFC(void *theSocket, unsigned int theIp, unsigned short thePort, unsigned char *theMessage, int theMsgLen)
{
    int aRet;
    char anAddr[22];
    GSUdpEngineObject *aUdp;

    aUdp = func_02180404();
    if (aUdp->mAppUnknownMessage != 0) {
        func_0217D254(12, 0, 16, g_021A3A54, func_02198620(theIp, thePort, anAddr));
        aRet = aUdp->mAppUnknownMessage(theIp, thePort, theMessage, theMsgLen, aUdp->mAppUserData);
        if (aRet != 0)
            return 1;
        return 0;
    }
    return 0;
}


void func_02180C94(void *socket, void *connection, unsigned int ip, unsigned short port, int latency, unsigned char *message, int len)
{
    int index;
    GSUdpMsgHandler aHandler;
    GSUdpRemotePeer aRemotePeer;
    GSUdpEngineObject *aUdp;
    char anAddr[22];
    GT2ConnectionCallbacks aCallbacks;

    aUdp = func_02180404();
    func_0217D254(12, 0, 16, g_021A3A8C, func_02198620(ip, port, anAddr));

    if (len >= 16) {
        memcpy(&aHandler.mInitialMsg, message, sizeof(aHandler.mInitialMsg));
        aRemotePeer.mAddr = ip;
        aRemotePeer.mPort = port;
        aRemotePeer.mConnection = connection;
        func_02184234(aUdp->mRemotePeers, &aRemotePeer);
        index = func_021843E8(aUdp->mMsgHandlers, &aHandler, func_02180420, 0, 0);
        if (index != -1) {
            aCallbacks.closed = (void (*)(void *, int))func_02180518;
            aCallbacks.connected = (void (*)(void *, int, unsigned char *, int))func_021806A8;
            aCallbacks.ping = (void (*)(void *, int))func_02180924;
            aCallbacks.received = (void (*)(void *, unsigned char *, int, int))func_02180A64;
            func_02195B2C(aRemotePeer.mConnection, &aCallbacks);
            func_0217D254(12, 0, 16, g_021A3AB8);
            return;
        }
    }

    if (aUdp->mAppConnAttempt) {
        func_0217D254(12, 0, 16, g_021A3AFC, func_02198620(ip, port, anAddr));
        aUdp->mAppConnAttempt(ip, port, latency, message, len, aUdp->mAppUserData);
        return;
    }

    func_02195B38(connection, 0, 0);
    func_02184324(aUdp->mRemotePeers, func_02184200(aUdp->mRemotePeers) - 1);
}


int func_02180E48(void)
{
    return func_02180404()->mInitialized;
}


int func_02180E58(unsigned short thePort, int theIncomingBufSize, int theOutgoingBufSize,
    void (*theAppNetworkError)(int, void *),
    void (*theAppConnected)(unsigned int, unsigned short, int, int, void *),
    void (*theAppClosed)(unsigned int, unsigned short, int, void *),
    void (*theAppPing)(unsigned int, unsigned short, unsigned int, void *),
    void (*theAppReceive)(unsigned int, unsigned short, unsigned char *, unsigned int, int, void *),
    int (*theAppUnownMsg)(unsigned int, unsigned short, unsigned char *, unsigned int, void *),
    void (*theAppConnectAttempt)(unsigned int, unsigned short, int, unsigned char *, unsigned int, void *),
    void *theAppUserData)
{
    char anAddr[22];
    int aGt2Result;
    GSUdpEngineObject *aUdp;

    aUdp = func_02180404();
    if (theIncomingBufSize == 0)
        theIncomingBufSize = 1500;
    if (theOutgoingBufSize == 0)
        theOutgoingBufSize = 1460;
    aUdp->mAppNetworkError = theAppNetworkError;
    aUdp->mAppUnknownMessage = theAppUnownMsg;
    aUdp->mAppConnected = theAppConnected;
    aUdp->mAppClosed = theAppClosed;
    aUdp->mAppPingReply = theAppPing;
    aUdp->mAppRecvData = theAppReceive;
    aUdp->mAppConnAttempt = theAppConnectAttempt;


    func_02198620(0, thePort, anAddr);
    aGt2Result = func_02195AB4(&aUdp->mSocket, anAddr, theOutgoingBufSize, theIncomingBufSize, func_0218048C);
    if (aGt2Result != 0) {
        func_0217D254(12, 0, 2, g_021A3B44, aGt2Result);
        return 3;
    }

    aUdp->mRemotePeers = func_02184144(12, 1, 0);
    if (aUdp->mRemotePeers == 0) {
        func_0217D254(12, 2, 1, g_021A3B7C);
        return 1;
    }

    aUdp->mMsgHandlers = func_02184144(60, 1, func_02180410);
    if (aUdp->mMsgHandlers == 0) {
        func_0217D254(12, 2, 1, g_021A3B7C);
        return 1;
    }

    func_02195E68(aUdp->mSocket, (int)func_02180BFC);
    func_02195B20(aUdp->mSocket, (int)func_02180C94);
    aUdp->mLocalAddr = func_02195E38(aUdp->mSocket);
    aUdp->mLocalPort = func_02195E40(aUdp->mSocket);
    aUdp->mAppPendingConnections = 0;
    aUdp->mInitialized = 1;
    if (theAppUserData)
        aUdp->mAppUserData = theAppUserData;
    else
        aUdp->mAppUserData = 0;
    return 0;
}


int func_02181010(unsigned int theIp, unsigned short thePort, int *thePeerState)
{
    GSUdpEngineObject *aUdp;
    GSUdpRemotePeer aPeer;
    GSUdpRemotePeer *aPeerFound;
    int index;

    aUdp = func_02180404();
    if (aUdp->mInitialized == 0) {
        func_0217D254(12, 3, 15, g_021A3B9C);
        *thePeerState = 3;
        return 11;
    }
    aPeer.mAddr = theIp;
    aPeer.mPort = thePort;
    index = func_021843E8(aUdp->mRemotePeers, &aPeer, func_02180448, 0, 0);
    if (index == -1) {
        *thePeerState = 3;
        return 0;
    }
    aPeerFound = (GSUdpRemotePeer *)func_02184208(aUdp->mRemotePeers, index);
    *thePeerState = func_02195E00(aPeerFound->mConnection);
    return 0;
}


/*
 * sdk:      gsUdpEngineStartTalkingToPeer (gsudpengine.o)
 */
int func_021810CC(unsigned int theIp, unsigned short thePort, char *theInitMsg, int timeOut)
{
    char anAddr[22];
    GSUdpRemotePeer aRemotePeer;
    GSUdpMsgHandler aHandler;
    GSUdpEngineObject *aUdp;
    GT2ConnectionCallbacks aCallbacks;
    int index;

    aUdp = func_02180404();
    if (aUdp->mInitialized == 0) {
        func_0217D254(12, 0, 15, g_021A3B9C);
        return 3;
    }
    if (theIp == 0 || thePort == 0) {
        func_0217D254(12, 0, 15, g_021A3BC4);
        return 10;
    }

    aRemotePeer.mAddr = theIp;
    aRemotePeer.mPort = thePort;
    index = func_021843E8(aUdp->mRemotePeers, &aRemotePeer, func_02180448, 0, 0);
    if (index != -1) {
        GSUdpRemotePeer *aPeerFound;
        int aState;

        aPeerFound = (GSUdpRemotePeer *)func_02184208(aUdp->mRemotePeers, index);
        aState = func_02195E00(aPeerFound->mConnection);
        if (aState == 1) {
            func_0217D254(12, 0, 15, g_021A3BF8);
            return 5;
        }
        if (aState == 0) {
            GSUdpMsgHandler *aHandlerFound;

            *(GSUdpHdr *)aHandler.mInitialMsg = *(GSUdpHdr *)theInitMsg;
            index = func_021843E8(aUdp->mMsgHandlers, &aHandler, func_02180420, 0, 0);
            if (index != -1) {
                aHandlerFound = (GSUdpMsgHandler *)func_02184208(aUdp->mMsgHandlers, index);
                func_02184234(aHandlerFound->mPendingConnections, aPeerFound);
            }
        }
    } else {
        GSUdpMsgHandler *aHandlerFound;
        GSUdpRemotePeer *aRemotePeerPtr;

        func_02198620(theIp, thePort, anAddr);
        aCallbacks.closed = (void (*)(void *, int))func_02180518;
        aCallbacks.connected = (void (*)(void *, int, unsigned char *, int))func_021806A8;
        aCallbacks.ping = (void (*)(void *, int))func_02180924;
        aCallbacks.received = (void (*)(void *, unsigned char *, int, int))func_02180A64;
        func_02195B44(aUdp->mSocket, &aRemotePeer.mConnection, anAddr, (unsigned char *)theInitMsg, 16, timeOut, &aCallbacks, 0);
        func_02184234(aUdp->mRemotePeers, &aRemotePeer);
        *(GSUdpHdr *)aHandler.mInitialMsg = *(GSUdpHdr *)theInitMsg;
        index = func_021843E8(aUdp->mMsgHandlers, &aHandler, func_02180420, 0, 0);
        if (index == -1) {
            aUdp->mAppPendingConnections++;
        } else {
            aRemotePeerPtr = (GSUdpRemotePeer *)func_02184208(aUdp->mRemotePeers, func_02184200(aUdp->mRemotePeers) - 1);
            aHandlerFound = (GSUdpMsgHandler *)func_02184208(aUdp->mMsgHandlers, index);
            func_02184234(aHandlerFound->mPendingConnections, &aRemotePeerPtr);
        }
    }
    return 0;
}


/*
 * sdk:      gsUdpEngineSendMessage (gsudpengine.o)
 */
int func_02181350(unsigned int theIp, unsigned short thePort, char *theHeader, unsigned char *theMsg, unsigned int theMsgLen, int theReliable)
{
    GSUdpEngineObject *aUdp;
    int aTotalMessageLen;
    int index;
    GSUdpRemotePeer aRemotePeer;
    GSUdpRemotePeer *aRemotePeerFound;
    unsigned char *fullMessage;
    int aResult;
    char anAddr[22];

    aUdp = func_02180404();
    if (aUdp->mInitialized == 0) {
        func_0217D254(12, 0, 15, g_021A3B9C);
        return 3;
    }

    if (theHeader[0])
        aTotalMessageLen = theMsgLen + 16;
    else
        aTotalMessageLen = theMsgLen;

    aRemotePeer.mAddr = theIp;
    aRemotePeer.mPort = thePort;
    index = func_021843E8(aUdp->mRemotePeers, &aRemotePeer, func_02180448, 0, 0);
    if (index == -1) {
        func_02198620(theIp, thePort, anAddr);
        func_0217D254(12, 0, 2, g_021A3C34, anAddr);
        return 4;
    }

    aRemotePeerFound = (GSUdpRemotePeer *)func_02184208(aUdp->mRemotePeers, index);
    if (aTotalMessageLen > func_02195E48(aRemotePeerFound->mConnection) && theReliable) {
        func_0217D254(12, 0, 2, g_021A3C68);
        return 12;
    }

    fullMessage = (unsigned char *)func_0217EAB0(aTotalMessageLen);
    *(GSUdpHdr *)fullMessage = *(GSUdpHdr *)theHeader;
    memcpy(fullMessage + 16, theMsg, theMsgLen);
    aResult = func_02195CC0(aRemotePeerFound->mConnection, fullMessage, aTotalMessageLen, theReliable);
    func_0217EAE0(fullMessage);
    if (aResult != 0)
        return 8;
    return 0;
}


int gsUdpEngineThink(void)
{
    GSUdpEngineObject *aUdp = func_02180404();

    if (aUdp->mInitialized == 0) {
        func_0217D254(0xc, 0, 0xf, g_021A3B9C);
        return 3;
    }
    func_02195AF0(aUdp->mSocket);
    return 0;
}


int gsUdpEngineShutdown(void)
{
    GSUdpEngineObject *aUdp = func_02180404();

    if (aUdp->mInitialized == 0) {
        func_0217D254(0xc, 0, 0xf, g_021A3B9C);
        return 3;
    }
    func_02195AD8(aUdp->mSocket);
    ArrayFree(aUdp->mMsgHandlers);
    ArrayFree(aUdp->mRemotePeers);
    aUdp->mInitialized = 0;
    return 0;
}


unsigned short gsUdpEngineGetLocalPort(void)
{
    GSUdpEngineObject *aUdp = func_02180404();

    if (aUdp->mInitialized == 0) {
        func_0217D254(0xc, 0, 1, g_021A3B9C);
        return 0;
    }
    return aUdp->mLocalPort;
}


int func_021815C8(char *theInitMsg, char *theHeader,
                  void (*theMsgHandlerError)(int, void *),
                  void (*theMsgHandlerConnected)(unsigned int, unsigned short, int, int, void *),
                  void (*theMsgHandlerClosed)(unsigned int, unsigned short, int, void *),
                  void (*theMsgHandlerPing)(unsigned int, unsigned short, unsigned int, void *),
                  void (*theMsgHandlerRecv)(unsigned int, unsigned short, unsigned char *, unsigned int, int, void *),
                  void *theUserData)
{
    GSUdpMsgHandler aMsgHandler;
    GSUdpEngineObject *aUdp;

    aUdp = func_02180404();
    if (!aUdp->mInitialized) {
        func_0217D254(12, 0, 15, g_021A3B9C);
        return 3;
    }
    if (theInitMsg[0] == 0) {
        func_0217D254(12, 0, 15, g_021A3CA0);
        return 10;
    }
    if (theHeader[0] == 0) {
        func_0217D254(12, 0, 15, g_021A3CC4);
        return 10;
    }

    aMsgHandler.mClosed = theMsgHandlerClosed;
    aMsgHandler.mConnected = theMsgHandlerConnected;
    aMsgHandler.mPingReply = theMsgHandlerPing;
    aMsgHandler.mReceived = theMsgHandlerRecv;
    aMsgHandler.mNetworkError = theMsgHandlerError;
    *(GSUdpHdr *)aMsgHandler.mInitialMsg = *(GSUdpHdr *)theInitMsg;
    *(GSUdpHdr *)aMsgHandler.mHeader = *(GSUdpHdr *)theHeader;

    aMsgHandler.mPendingConnections = func_02184144(4, 1, 0);
    if (aMsgHandler.mPendingConnections == 0) {
        func_0217D254(12, 2, 1, g_021A3B7C);
        return 1;
    }
    aMsgHandler.mUserData = theUserData;
    func_02184234(aUdp->mMsgHandlers, &aMsgHandler);
    return 0;
}


int func_02181748(char *theHeader)
{
    int index;
    GSUdpMsgHandler aHandler;
    GSUdpEngineObject *aUdp;

    aUdp = func_02180404();
    if (aUdp->mInitialized == 0)
    {
        func_0217D254(12, 0, 15, g_021A3B9C);
        return 3;
    }
    if (theHeader == 0 || theHeader[0] == 0)
    {
        func_0217D254(12, 0, 15, g_021A3CE4);
        return 10;
    }
    *(GSUdpHdr *)aHandler.mHeader = *(GSUdpHdr *)theHeader;
    index = func_021843E8(aUdp->mMsgHandlers, &aHandler, func_02180430, 0, 0);
    if (index != -1)
        func_0218437C((int)aUdp->mMsgHandlers, index);
    return 0;
}


int gsUdpEngineNoMoreMsgHandlers(void)
{
    GSUdpEngineObject *aUdp = func_02180404();

    if (aUdp->mInitialized == 0) {
        func_0217D254(0xc, 0, 0xf, g_021A3B9C);
        return 1;
    }
    return func_02184200(aUdp->mMsgHandlers) == 0;
}


int gsUdpEngineNoApp(void)
{
    GSUdpEngineObject *aUdp = func_02180404();

    if (aUdp->mInitialized == 0) {
        func_0217D254(0xc, 0, 0xf, g_021A3B9C);
        return 1;
    }
    if (aUdp->mAppClosed != 0 || aUdp->mAppConnAttempt != 0 || aUdp->mAppConnected != 0 ||
        aUdp->mAppNetworkError != 0 || aUdp->mAppPingReply != 0 || aUdp->mAppRecvData != 0 ||
        aUdp->mAppUnknownMessage != 0)
        return 0;
    return 1;
}


int func_021818EC(unsigned int theIp, unsigned short thePort)
{
    GSUdpEngineObject *aUdp;
    GSUdpRemotePeer aRemotePeer;
    GSUdpRemotePeer *aRemotePeerFound;
    int index;

    aUdp = func_02180404();
    if (aUdp->mInitialized == 0) {
        func_0217D254(12, 0, 15, g_021A3B9C);
        return 0;
    }
    aRemotePeer.mAddr = theIp;
    aRemotePeer.mPort = thePort;
    index = func_021843E8(aUdp->mRemotePeers, &aRemotePeer, func_02180448, 0, 0);
    if (index == -1)
        return 0;
    aRemotePeerFound = (GSUdpRemotePeer *)func_02184208(aUdp->mRemotePeers, index);
    return func_02195E50(aRemotePeerFound->mConnection);
}
