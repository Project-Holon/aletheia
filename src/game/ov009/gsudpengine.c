/*
 * file:     gsudpengine.c
 * unit:     yes
 * function: gsUdpMsgHandlerFree, gsUdpMsgHandlerCompare, gsUdpMsgHandlerCompare2, gsUdpRemotePeerCompare, gsUdpRemotePeerCompare2, gsUdpSocketError, gsUdpClosedRoutingCB, gsUdpConnectedRoutingCB, gsUdpPingRoutingCB, gsUdpReceivedRoutingCB, gsUdpUnrecognizedMsgCB, gsUdpConnAttemptCB, gsUdpEngineIsInitialized, gsUdpEngineInitialize, gsUdpEngineGetPeerState, gsUdpEngineStartTalkingToPeer, gsUdpEngineSendMessage, gsUdpEngineThink, gsUdpEngineShutdown, gsUdpEngineGetLocalPort, gsUdpEngineAddMsgHandler, gsUdpEngineRemoveMsgHandler, gsUdpEngineNoMoreMsgHandlers, gsUdpEngineNoApp, gsUdpEngineGetPeerOutBufferFreeSpace
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
 *   memcmp                0x020923F0  arm
 *   gsUdpEngineContext                  0x02180404  arm ov009
 *   gsDebugFormat                  0x0217D254  arm ov009
 *   ArrayLength                  0x02184200  arm ov009
 *   ArrayNth                  0x02184208  arm ov009
 *   g_021A3868                     0x021A3868  data
 *   gt2GetRemoteIP                  0x02195E28  arm ov009
 *   gt2GetRemotePort                  0x02195E30  arm ov009
 *   gt2AddressToString                  0x02198620  arm ov009
 *   ArraySearch                  0x021843E8  arm ov009
 *   ArrayDeleteAt                  0x0218437C  arm ov009
 *   gsUdpRemotePeerCompare2                  0x02180474  arm ov009
 *   g_021A38A8                     0x021A38A8  data
 *   g_021A38D0                     0x021A38D0  data
 *   g_021A390C                     0x021A390C  data
 *   gsUdpRemotePeerCompare                  0x02180448  arm ov009
 *   g_021A393C                     0x021A393C  data
 *   g_021A3964                     0x021A3964  data
 *   g_021A399C                     0x021A399C  data
 *   g_021A39C8                     0x021A39C8  data
 *   g_021A39EC                     0x021A39EC  data
 *   g_021A3A14                     0x021A3A14  data
 *   gsUdpMsgHandlerCompare2                  0x02180430  arm ov009
 *   g_021A3A30                     0x021A3A30  data
 *   g_021A3A54                     0x021A3A54  data
 *   ArrayAppend                  0x02184234  arm ov009
 *   gt2Accept                  0x02195B2C  arm ov009
 *   gt2Reject                  0x02195B38  arm ov009
 *   ArrayRemoveAt                  0x02184324  arm ov009
 *   gsUdpMsgHandlerCompare                  0x02180420  arm ov009
 *   g_021A3A8C                     0x021A3A8C  data
 *   g_021A3AB8                     0x021A3AB8  data
 *   g_021A3AFC                     0x021A3AFC  data
 *   gt2CreateSocket                  0x02195AB4  arm ov009
 *   ArrayNew                  0x02184144  arm ov009
 *   gt2SetUnrecognizedMessageCallback                  0x02195E68  arm ov009
 *   gt2Listen                  0x02195B20  arm ov009
 *   gt2GetLocalIP                  0x02195E38  arm ov009
 *   gt2GetLocalPort                  0x02195E40  arm ov009
 *   gsUdpMsgHandlerFree                  0x02180410  arm ov009
 *   g_021A3B44                     0x021A3B44  data
 *   g_021A3B7C                     0x021A3B7C  data
 *   gt2GetConnectionState                  0x02195E00  arm ov009
 *   g_021A3B9C                     0x021A3B9C  data
 *   gt2Connect                  0x02195B44  arm ov009
 *   g_021A3BC4                     0x021A3BC4  data
 *   g_021A3BF8                     0x021A3BF8  data
 *   gt2GetOutgoingBufferSize                  0x02195E48  arm ov009
 *   gsimalloc                  0x0217EAB0  arm ov009
 *   memcpy                         0x02092344  arm
 *   gt2Send                  0x02195CC0  arm ov009
 *   gsifree                  0x0217EAE0  arm ov009
 *   g_021A3C34                     0x021A3C34  data
 *   g_021A3C68                     0x021A3C68  data
 *   gt2Think                         0x02195af0 arm
 *   gt2CloseSocket                   0x02195ad8 arm
 *   g_021A3CA0                     0x021A3CA0  data
 *   g_021A3CC4                     0x021A3CC4  data
 *   g_021A3CE4               0x021A3CE4 data
 *   gt2GetOutgoingBufferFreeSpace                  0x02195E50  arm ov009
 */
#include "gsudp_types.h"
#include "gsdebug.h"
#include "gsstringutil.h"
#include "../../matched/arm9_sdk/libc/string.h"

#include "../arm9/msl_string_mem.h"
struct GTI2Connection;
#include "gt2main.h"
#include "gt2utility.h"
extern int gsUdpRemotePeerCompare2(void *theFirstPeer, void *theSecondPeer);
struct GT2ConnectionCallbacks;
struct DArrayImplementation;
extern void ArrayRemoveAt(struct DArrayImplementation *array, int n);
extern struct DArrayImplementation *ArrayNew(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
struct GTI2Socket;
#include "gsmemory.h"
struct GTI2Socket;
void gsUdpMsgHandlerFree(GSUdpMsgHandler *theHandler);
int gsUdpMsgHandlerCompare(void *theFirst, void *theSecond);
int gsUdpMsgHandlerCompare2(void *theFirst, void *theSecond);
int gsUdpRemotePeerCompare(void *theFirstPeer, void *theSecondPeer);
int gsUdpRemotePeerCompare2(void *theFirstPeer, void *theSecondPeer);
void gsUdpSocketError(void);
void gsUdpClosedRoutingCB(void *theConnection, int reason);
void gsUdpConnectedRoutingCB(void *theConnection, int theResult);
void gsUdpPingRoutingCB(void *theConnection, int theLatency);
void gsUdpReceivedRoutingCB(void *theConnection, unsigned char *theMessage, int theMessageLen, int reliable);
int gsUdpUnrecognizedMsgCB(void *theSocket, unsigned int theIp, unsigned short thePort, unsigned char *theMessage, int theMsgLen);
void gsUdpConnAttemptCB(void *socket, void *connection, unsigned int ip, unsigned short port, int latency, unsigned char *message, int len);
int gsUdpEngineIsInitialized(void);
int gsUdpEngineInitialize(unsigned short thePort, int theIncomingBufSize, int theOutgoingBufSize, void (*theAppNetworkError)(int, void *), void (*theAppConnected)(unsigned int, unsigned short, int, int, void *), void (*theAppClosed)(unsigned int, unsigned short, int, void *), void (*theAppPing)(unsigned int, unsigned short, unsigned int, void *), void (*theAppReceive)(unsigned int, unsigned short, unsigned char *, unsigned int, int, void *), int (*theAppUnownMsg)(unsigned int, unsigned short, unsigned char *, unsigned int, void *), void (*theAppConnectAttempt)(unsigned int, unsigned short, int, unsigned char *, unsigned int, void *), void *theAppUserData);
int gsUdpEngineGetPeerState(unsigned int theIp, unsigned short thePort, int *thePeerState);
int gsUdpEngineStartTalkingToPeer(unsigned int theIp, unsigned short thePort, char *theInitMsg, int timeOut);
int gsUdpEngineSendMessage(unsigned int theIp, unsigned short thePort, char *theHeader, unsigned char *theMsg, unsigned int theMsgLen, int theReliable);
int gsUdpEngineThink(void);
int gsUdpEngineShutdown(void);
unsigned short gsUdpEngineGetLocalPort(void);
int gsUdpEngineAddMsgHandler(char *theInitMsg, char *theHeader, void (*theMsgHandlerError)(int, void *), void (*theMsgHandlerConnected)(unsigned int, unsigned short, int, int, void *), void (*theMsgHandlerClosed)(unsigned int, unsigned short, int, void *), void (*theMsgHandlerPing)(unsigned int, unsigned short, unsigned int, void *), void (*theMsgHandlerRecv)(unsigned int, unsigned short, unsigned char *, unsigned int, int, void *), void *theUserData);
int gsUdpEngineRemoveMsgHandler(char *theHeader);
int gsUdpEngineNoMoreMsgHandlers(void);
int gsUdpEngineNoApp(void);
int gsUdpEngineGetPeerOutBufferFreeSpace(unsigned int theIp, unsigned short thePort);
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
    return memcmp(theFirst, theSecond, 16);
}


int gsUdpMsgHandlerCompare2(void *theFirst, void *theSecond)
{
    return memcmp((unsigned char *)theFirst + 16, (unsigned char *)theSecond + 16, 16);
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
void gsUdpSocketError(void)
{
    int i;
    int len;
    GSUdpEngineObject *aUdp;
    GSUdpMsgHandler *aMsgHandler;

    aUdp = gsUdpEngineContext();
    gsDebugFormat(12, 0, 16, g_021A3868);
    if (aUdp->mAppNetworkError != 0)
        aUdp->mAppNetworkError(3, aUdp->mAppUserData);
    len = ArrayLength(aUdp->mMsgHandlers);
    for (i = 0; i < len; i++) {
        aMsgHandler = (GSUdpMsgHandler *)ArrayNth(aUdp->mMsgHandlers, i);
        if (aMsgHandler->mNetworkError != 0)
            aMsgHandler->mNetworkError(3, aMsgHandler->mUserData);
    }
}


/*
 * sdk:      gsUdpClosedRoutingCB (gsudpengine.o)
 */
void gsUdpClosedRoutingCB(void *theConnection, int reason)
{
    GSUdpEngineObject *aUdp;
    GSUdpRemotePeer aRemotePeer;
    int index;
    int len;
    int aReason;
    char anAddr[22];
    GSUdpMsgHandler *aHandler;

    aUdp = gsUdpEngineContext();
    if (reason == 2 || reason == 3)
        aReason = 2;
    else if (reason == 4)
        aReason = 3;
    else
        aReason = reason;

    gsDebugFormat(12, 0, 16, g_021A38A8,
        gt2AddressToString(gt2GetRemoteIP(theConnection), gt2GetRemotePort(theConnection), anAddr));

    len = ArrayLength(aUdp->mMsgHandlers);
    for (index = 0; index < len; index++) {
        aHandler = (GSUdpMsgHandler *)ArrayNth(aUdp->mMsgHandlers, index);
        if (aHandler->mClosed) {
            gsDebugFormat(12, 0, 16, g_021A38D0);
            aHandler->mClosed(gt2GetRemoteIP(theConnection), gt2GetRemotePort(theConnection), aReason, aHandler->mUserData);
        }
    }

    if (aUdp->mAppClosed) {
        gsDebugFormat(12, 0, 16, g_021A390C);
        aUdp->mAppClosed(gt2GetRemoteIP(theConnection), gt2GetRemotePort(theConnection), aReason, aUdp->mAppUserData);
    }

    aRemotePeer.mConnection = theConnection;
    index = ArraySearch(aUdp->mRemotePeers, &aRemotePeer, gsUdpRemotePeerCompare2, 0, 0);
    if (index == -1)
        return;
    ArrayDeleteAt(aUdp->mRemotePeers, index);
}


/*
 * sdk:      gsUdpConnectedRoutingCB (gsudpengine.o)
 */
void gsUdpConnectedRoutingCB(void *theConnection, int theResult)
{
    GSUdpEngineObject *aUdp;
    int aIndex;
    int len;
    int aCode;
    char anAddr[22];

    aUdp = gsUdpEngineContext();
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

        aRemotePeer.mAddr = gt2GetRemoteIP(theConnection);
        aRemotePeer.mPort = gt2GetRemotePort(theConnection);
        aRemotePeerIdx = ArraySearch(aUdp->mRemotePeers, &aRemotePeer, gsUdpRemotePeerCompare, 0, 0);
        if (aRemotePeerIdx != -1) {
            gsDebugFormat(12, 0, 16, g_021A393C,
                gt2AddressToString(gt2GetRemoteIP(theConnection), gt2GetRemotePort(theConnection), anAddr));
            ArrayDeleteAt(aUdp->mRemotePeers, aRemotePeerIdx);
        }
    }

    len = ArrayLength(aUdp->mMsgHandlers);
    for (aIndex = 0; aIndex < len; aIndex++) {
        int aRemotePeerIdx;
        GSUdpRemotePeer aRemotePeer;
        GSUdpMsgHandler *aTempHandler;

        aTempHandler = (GSUdpMsgHandler *)ArrayNth(aUdp->mMsgHandlers, aIndex);
        aRemotePeer.mAddr = gt2GetRemoteIP(theConnection);
        aRemotePeer.mPort = gt2GetRemotePort(theConnection);
        aRemotePeerIdx = ArraySearch(aTempHandler->mPendingConnections, &aRemotePeer, gsUdpRemotePeerCompare, 0, 0);
        if (aRemotePeerIdx != -1) {
            if (aTempHandler->mConnected) {
                gsDebugFormat(12, 0, 16, g_021A3964);
                aTempHandler->mConnected(gt2GetRemoteIP(theConnection), gt2GetRemotePort(theConnection),
                    aCode, (theResult == 2) ? 1 : 0, aTempHandler->mUserData);
            }
            ArrayDeleteAt(aTempHandler->mPendingConnections, aRemotePeerIdx);
            return;
        }
    }

    if (aUdp->mAppPendingConnections > 0) {
        if (aUdp->mAppConnected) {
            gsDebugFormat(12, 0, 16, g_021A399C);
            aUdp->mAppConnected(gt2GetRemoteIP(theConnection), gt2GetRemotePort(theConnection),
                aCode, (theResult == 2) ? 1 : 0, aUdp->mAppUserData);
        }
        aUdp->mAppPendingConnections--;
    }
}


void gsUdpPingRoutingCB(void *theConnection, int theLatency)
{
    GSUdpEngineObject *aUdp;
    char anAddr[22];
    int index;
    int len;
    GSUdpMsgHandler *aHandler;

    aUdp = gsUdpEngineContext();

    gsDebugFormat(12, 0, 16, g_021A39C8,
        gt2AddressToString(gt2GetRemoteIP(theConnection), gt2GetRemotePort(theConnection), anAddr));

    len = ArrayLength(aUdp->mMsgHandlers);
    for (index = 0; index < len; index++) {
        aHandler = (GSUdpMsgHandler *)ArrayNth(aUdp->mMsgHandlers, index);
        if (aHandler->mPingReply) {
            gsDebugFormat(12, 0, 16, g_021A39EC);
            aHandler->mPingReply(gt2GetRemoteIP(theConnection), gt2GetRemotePort(theConnection), theLatency, aHandler->mUserData);
            return;
        }
    }

    if (aUdp->mAppPingReply) {
        gsDebugFormat(12, 0, 16, g_021A3A14);
        aUdp->mAppPingReply(gt2GetRemoteIP(theConnection), gt2GetRemotePort(theConnection), theLatency, aUdp->mAppUserData);
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
 * sendto (sendto) and gsUdpConnAttemptCB (0x02180C94).
 */
void gsUdpReceivedRoutingCB(void *theConnection, unsigned char *theMessage, int theMessageLen, int reliable)
{
    GSUdpEngineObject *aUdp;
    GSUdpMsgHandler aHandler;
    int index;
    char anAddr[22];
    GSUdpMsgHandler *aHandlerFound;

    aUdp = gsUdpEngineContext();
    gsDebugFormat(12, 0, 16, g_021A3A30,
        gt2AddressToString(gt2GetRemoteIP(theConnection), gt2GetRemotePort(theConnection), anAddr));

    if (theMessageLen >= 16) {
        memcpy(&aHandler.mHeader, theMessage, sizeof(aHandler.mHeader));
        index = ArraySearch(aUdp->mMsgHandlers, &aHandler, gsUdpMsgHandlerCompare2, 0, 0);
        if (index != -1) {
            aHandlerFound = (GSUdpMsgHandler *)ArrayNth(aUdp->mMsgHandlers, index);
            if (aHandlerFound->mReceived) {
                gsDebugFormat(12, 0, 16, g_021A39EC);
                aHandlerFound->mReceived(gt2GetRemoteIP(theConnection), gt2GetRemotePort(theConnection),
                    theMessage + 16, theMessageLen - 16, reliable, aHandlerFound->mUserData);
                return;
            }
        }
    }

    if (aUdp->mAppRecvData) {
        gsDebugFormat(12, 0, 16, g_021A3A14);
        aUdp->mAppRecvData(gt2GetRemoteIP(theConnection), gt2GetRemotePort(theConnection),
            theMessage, theMessageLen, reliable, aUdp->mAppUserData);
    }
}


int gsUdpUnrecognizedMsgCB(void *theSocket, unsigned int theIp, unsigned short thePort, unsigned char *theMessage, int theMsgLen)
{
    int aRet;
    char anAddr[22];
    GSUdpEngineObject *aUdp;

    aUdp = gsUdpEngineContext();
    if (aUdp->mAppUnknownMessage != 0) {
        gsDebugFormat(12, 0, 16, g_021A3A54, gt2AddressToString(theIp, thePort, anAddr));
        aRet = aUdp->mAppUnknownMessage(theIp, thePort, theMessage, theMsgLen, aUdp->mAppUserData);
        if (aRet != 0)
            return 1;
        return 0;
    }
    return 0;
}


void gsUdpConnAttemptCB(void *socket, void *connection, unsigned int ip, unsigned short port, int latency, unsigned char *message, int len)
{
    int index;
    GSUdpMsgHandler aHandler;
    GSUdpRemotePeer aRemotePeer;
    GSUdpEngineObject *aUdp;
    char anAddr[22];
    GT2ConnectionCallbacks aCallbacks;

    aUdp = gsUdpEngineContext();
    gsDebugFormat(12, 0, 16, g_021A3A8C, gt2AddressToString(ip, port, anAddr));

    if (len >= 16) {
        memcpy(&aHandler.mInitialMsg, message, sizeof(aHandler.mInitialMsg));
        aRemotePeer.mAddr = ip;
        aRemotePeer.mPort = port;
        aRemotePeer.mConnection = connection;
        ArrayAppend(aUdp->mRemotePeers, &aRemotePeer);
        index = ArraySearch(aUdp->mMsgHandlers, &aHandler, gsUdpMsgHandlerCompare, 0, 0);
        if (index != -1) {
            aCallbacks.closed = (void (*)(GTI2Connection *, int))gsUdpClosedRoutingCB;
            aCallbacks.connected = (void (*)(GTI2Connection *, int, unsigned char *, int))gsUdpConnectedRoutingCB;
            aCallbacks.ping = (void (*)(GTI2Connection *, int))gsUdpPingRoutingCB;
            aCallbacks.received = (void (*)(GTI2Connection *, unsigned char *, int, int))gsUdpReceivedRoutingCB;
            gt2Accept(aRemotePeer.mConnection, &aCallbacks);
            gsDebugFormat(12, 0, 16, g_021A3AB8);
            return;
        }
    }

    if (aUdp->mAppConnAttempt) {
        gsDebugFormat(12, 0, 16, g_021A3AFC, gt2AddressToString(ip, port, anAddr));
        aUdp->mAppConnAttempt(ip, port, latency, message, len, aUdp->mAppUserData);
        return;
    }

    gt2Reject(connection, 0, 0);
    ArrayRemoveAt(aUdp->mRemotePeers, ArrayLength(aUdp->mRemotePeers) - 1);
}


int gsUdpEngineIsInitialized(void)
{
    return gsUdpEngineContext()->mInitialized;
}


int gsUdpEngineInitialize(unsigned short thePort, int theIncomingBufSize, int theOutgoingBufSize,
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

    aUdp = gsUdpEngineContext();
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


    gt2AddressToString(0, thePort, anAddr);
    aGt2Result = gt2CreateSocket(&aUdp->mSocket, anAddr, theOutgoingBufSize, theIncomingBufSize, gsUdpSocketError);
    if (aGt2Result != 0) {
        gsDebugFormat(12, 0, 2, g_021A3B44, aGt2Result);
        return 3;
    }

    aUdp->mRemotePeers = ArrayNew(12, 1, 0);
    if (aUdp->mRemotePeers == 0) {
        gsDebugFormat(12, 2, 1, g_021A3B7C);
        return 1;
    }

    aUdp->mMsgHandlers = ArrayNew(60, 1, (void (*)(void *))gsUdpMsgHandlerFree);
    if (aUdp->mMsgHandlers == 0) {
        gsDebugFormat(12, 2, 1, g_021A3B7C);
        return 1;
    }

    gt2SetUnrecognizedMessageCallback(aUdp->mSocket, gsUdpUnrecognizedMsgCB);
    gt2Listen(aUdp->mSocket, gsUdpConnAttemptCB);
    aUdp->mLocalAddr = gt2GetLocalIP(aUdp->mSocket);
    aUdp->mLocalPort = gt2GetLocalPort(aUdp->mSocket);
    aUdp->mAppPendingConnections = 0;
    aUdp->mInitialized = 1;
    if (theAppUserData)
        aUdp->mAppUserData = theAppUserData;
    else
        aUdp->mAppUserData = 0;
    return 0;
}


int gsUdpEngineGetPeerState(unsigned int theIp, unsigned short thePort, int *thePeerState)
{
    GSUdpEngineObject *aUdp;
    GSUdpRemotePeer aPeer;
    GSUdpRemotePeer *aPeerFound;
    int index;

    aUdp = gsUdpEngineContext();
    if (aUdp->mInitialized == 0) {
        gsDebugFormat(12, 3, 15, g_021A3B9C);
        *thePeerState = 3;
        return 11;
    }
    aPeer.mAddr = theIp;
    aPeer.mPort = thePort;
    index = ArraySearch(aUdp->mRemotePeers, &aPeer, gsUdpRemotePeerCompare, 0, 0);
    if (index == -1) {
        *thePeerState = 3;
        return 0;
    }
    aPeerFound = (GSUdpRemotePeer *)ArrayNth(aUdp->mRemotePeers, index);
    *thePeerState = gt2GetConnectionState(aPeerFound->mConnection);
    return 0;
}


/*
 * sdk:      gsUdpEngineStartTalkingToPeer (gsudpengine.o)
 */
int gsUdpEngineStartTalkingToPeer(unsigned int theIp, unsigned short thePort, char *theInitMsg, int timeOut)
{
    char anAddr[22];
    GSUdpRemotePeer aRemotePeer;
    GSUdpMsgHandler aHandler;
    GSUdpEngineObject *aUdp;
    GT2ConnectionCallbacks aCallbacks;
    int index;

    aUdp = gsUdpEngineContext();
    if (aUdp->mInitialized == 0) {
        gsDebugFormat(12, 0, 15, g_021A3B9C);
        return 3;
    }
    if (theIp == 0 || thePort == 0) {
        gsDebugFormat(12, 0, 15, g_021A3BC4);
        return 10;
    }

    aRemotePeer.mAddr = theIp;
    aRemotePeer.mPort = thePort;
    index = ArraySearch(aUdp->mRemotePeers, &aRemotePeer, gsUdpRemotePeerCompare, 0, 0);
    if (index != -1) {
        GSUdpRemotePeer *aPeerFound;
        int aState;

        aPeerFound = (GSUdpRemotePeer *)ArrayNth(aUdp->mRemotePeers, index);
        aState = gt2GetConnectionState(aPeerFound->mConnection);
        if (aState == 1) {
            gsDebugFormat(12, 0, 15, g_021A3BF8);
            return 5;
        }
        if (aState == 0) {
            GSUdpMsgHandler *aHandlerFound;

            *(GSUdpHdr *)aHandler.mInitialMsg = *(GSUdpHdr *)theInitMsg;
            index = ArraySearch(aUdp->mMsgHandlers, &aHandler, gsUdpMsgHandlerCompare, 0, 0);
            if (index != -1) {
                aHandlerFound = (GSUdpMsgHandler *)ArrayNth(aUdp->mMsgHandlers, index);
                ArrayAppend(aHandlerFound->mPendingConnections, aPeerFound);
            }
        }
    } else {
        GSUdpMsgHandler *aHandlerFound;
        GSUdpRemotePeer *aRemotePeerPtr;

        gt2AddressToString(theIp, thePort, anAddr);
        aCallbacks.closed = (void (*)(GTI2Connection *, int))gsUdpClosedRoutingCB;
        aCallbacks.connected = (void (*)(GTI2Connection *, int, unsigned char *, int))gsUdpConnectedRoutingCB;
        aCallbacks.ping = (void (*)(GTI2Connection *, int))gsUdpPingRoutingCB;
        aCallbacks.received = (void (*)(GTI2Connection *, unsigned char *, int, int))gsUdpReceivedRoutingCB;
        gt2Connect(aUdp->mSocket, (struct GTI2Connection **)(&aRemotePeer.mConnection), anAddr, (unsigned char *)theInitMsg, 16, timeOut, &aCallbacks, 0);
        ArrayAppend(aUdp->mRemotePeers, &aRemotePeer);
        *(GSUdpHdr *)aHandler.mInitialMsg = *(GSUdpHdr *)theInitMsg;
        index = ArraySearch(aUdp->mMsgHandlers, &aHandler, gsUdpMsgHandlerCompare, 0, 0);
        if (index == -1) {
            aUdp->mAppPendingConnections++;
        } else {
            aRemotePeerPtr = (GSUdpRemotePeer *)ArrayNth(aUdp->mRemotePeers, ArrayLength(aUdp->mRemotePeers) - 1);
            aHandlerFound = (GSUdpMsgHandler *)ArrayNth(aUdp->mMsgHandlers, index);
            ArrayAppend(aHandlerFound->mPendingConnections, &aRemotePeerPtr);
        }
    }
    return 0;
}


/*
 * sdk:      gsUdpEngineSendMessage (gsudpengine.o)
 */
int gsUdpEngineSendMessage(unsigned int theIp, unsigned short thePort, char *theHeader, unsigned char *theMsg, unsigned int theMsgLen, int theReliable)
{
    GSUdpEngineObject *aUdp;
    int aTotalMessageLen;
    int index;
    GSUdpRemotePeer aRemotePeer;
    GSUdpRemotePeer *aRemotePeerFound;
    unsigned char *fullMessage;
    int aResult;
    char anAddr[22];

    aUdp = gsUdpEngineContext();
    if (aUdp->mInitialized == 0) {
        gsDebugFormat(12, 0, 15, g_021A3B9C);
        return 3;
    }

    if (theHeader[0])
        aTotalMessageLen = theMsgLen + 16;
    else
        aTotalMessageLen = theMsgLen;

    aRemotePeer.mAddr = theIp;
    aRemotePeer.mPort = thePort;
    index = ArraySearch(aUdp->mRemotePeers, &aRemotePeer, gsUdpRemotePeerCompare, 0, 0);
    if (index == -1) {
        gt2AddressToString(theIp, thePort, anAddr);
        gsDebugFormat(12, 0, 2, g_021A3C34, anAddr);
        return 4;
    }

    aRemotePeerFound = (GSUdpRemotePeer *)ArrayNth(aUdp->mRemotePeers, index);
    if (aTotalMessageLen > gt2GetOutgoingBufferSize(aRemotePeerFound->mConnection) && theReliable) {
        gsDebugFormat(12, 0, 2, g_021A3C68);
        return 12;
    }

    fullMessage = (unsigned char *)gsimalloc(aTotalMessageLen);
    *(GSUdpHdr *)fullMessage = *(GSUdpHdr *)theHeader;
    memcpy(fullMessage + 16, theMsg, theMsgLen);
    aResult = gt2Send(aRemotePeerFound->mConnection, fullMessage, aTotalMessageLen, theReliable);
    gsifree(fullMessage);
    if (aResult != 0)
        return 8;
    return 0;
}


int gsUdpEngineThink(void)
{
    GSUdpEngineObject *aUdp = gsUdpEngineContext();

    if (aUdp->mInitialized == 0) {
        gsDebugFormat(0xc, 0, 0xf, g_021A3B9C);
        return 3;
    }
    gt2Think(aUdp->mSocket);
    return 0;
}


int gsUdpEngineShutdown(void)
{
    GSUdpEngineObject *aUdp = gsUdpEngineContext();

    if (aUdp->mInitialized == 0) {
        gsDebugFormat(0xc, 0, 0xf, g_021A3B9C);
        return 3;
    }
    gt2CloseSocket(aUdp->mSocket);
    ArrayFree(aUdp->mMsgHandlers);
    ArrayFree(aUdp->mRemotePeers);
    aUdp->mInitialized = 0;
    return 0;
}


unsigned short gsUdpEngineGetLocalPort(void)
{
    GSUdpEngineObject *aUdp = gsUdpEngineContext();

    if (aUdp->mInitialized == 0) {
        gsDebugFormat(0xc, 0, 1, g_021A3B9C);
        return 0;
    }
    return aUdp->mLocalPort;
}


int gsUdpEngineAddMsgHandler(char *theInitMsg, char *theHeader,
                  void (*theMsgHandlerError)(int, void *),
                  void (*theMsgHandlerConnected)(unsigned int, unsigned short, int, int, void *),
                  void (*theMsgHandlerClosed)(unsigned int, unsigned short, int, void *),
                  void (*theMsgHandlerPing)(unsigned int, unsigned short, unsigned int, void *),
                  void (*theMsgHandlerRecv)(unsigned int, unsigned short, unsigned char *, unsigned int, int, void *),
                  void *theUserData)
{
    GSUdpMsgHandler aMsgHandler;
    GSUdpEngineObject *aUdp;

    aUdp = gsUdpEngineContext();
    if (!aUdp->mInitialized) {
        gsDebugFormat(12, 0, 15, g_021A3B9C);
        return 3;
    }
    if (theInitMsg[0] == 0) {
        gsDebugFormat(12, 0, 15, g_021A3CA0);
        return 10;
    }
    if (theHeader[0] == 0) {
        gsDebugFormat(12, 0, 15, g_021A3CC4);
        return 10;
    }

    aMsgHandler.mClosed = theMsgHandlerClosed;
    aMsgHandler.mConnected = theMsgHandlerConnected;
    aMsgHandler.mPingReply = theMsgHandlerPing;
    aMsgHandler.mReceived = theMsgHandlerRecv;
    aMsgHandler.mNetworkError = theMsgHandlerError;
    *(GSUdpHdr *)aMsgHandler.mInitialMsg = *(GSUdpHdr *)theInitMsg;
    *(GSUdpHdr *)aMsgHandler.mHeader = *(GSUdpHdr *)theHeader;

    aMsgHandler.mPendingConnections = ArrayNew(4, 1, 0);
    if (aMsgHandler.mPendingConnections == 0) {
        gsDebugFormat(12, 2, 1, g_021A3B7C);
        return 1;
    }
    aMsgHandler.mUserData = theUserData;
    ArrayAppend(aUdp->mMsgHandlers, &aMsgHandler);
    return 0;
}


int gsUdpEngineRemoveMsgHandler(char *theHeader)
{
    int index;
    GSUdpMsgHandler aHandler;
    GSUdpEngineObject *aUdp;

    aUdp = gsUdpEngineContext();
    if (aUdp->mInitialized == 0)
    {
        gsDebugFormat(12, 0, 15, g_021A3B9C);
        return 3;
    }
    if (theHeader == 0 || theHeader[0] == 0)
    {
        gsDebugFormat(12, 0, 15, g_021A3CE4);
        return 10;
    }
    *(GSUdpHdr *)aHandler.mHeader = *(GSUdpHdr *)theHeader;
    index = ArraySearch(aUdp->mMsgHandlers, &aHandler, gsUdpMsgHandlerCompare2, 0, 0);
    if (index != -1)
        ArrayDeleteAt(aUdp->mMsgHandlers, index);
    return 0;
}


int gsUdpEngineNoMoreMsgHandlers(void)
{
    GSUdpEngineObject *aUdp = gsUdpEngineContext();

    if (aUdp->mInitialized == 0) {
        gsDebugFormat(0xc, 0, 0xf, g_021A3B9C);
        return 1;
    }
    return ArrayLength(aUdp->mMsgHandlers) == 0;
}


int gsUdpEngineNoApp(void)
{
    GSUdpEngineObject *aUdp = gsUdpEngineContext();

    if (aUdp->mInitialized == 0) {
        gsDebugFormat(0xc, 0, 0xf, g_021A3B9C);
        return 1;
    }
    if (aUdp->mAppClosed != 0 || aUdp->mAppConnAttempt != 0 || aUdp->mAppConnected != 0 ||
        aUdp->mAppNetworkError != 0 || aUdp->mAppPingReply != 0 || aUdp->mAppRecvData != 0 ||
        aUdp->mAppUnknownMessage != 0)
        return 0;
    return 1;
}


int gsUdpEngineGetPeerOutBufferFreeSpace(unsigned int theIp, unsigned short thePort)
{
    GSUdpEngineObject *aUdp;
    GSUdpRemotePeer aRemotePeer;
    GSUdpRemotePeer *aRemotePeerFound;
    int index;

    aUdp = gsUdpEngineContext();
    if (aUdp->mInitialized == 0) {
        gsDebugFormat(12, 0, 15, g_021A3B9C);
        return 0;
    }
    aRemotePeer.mAddr = theIp;
    aRemotePeer.mPort = thePort;
    index = ArraySearch(aUdp->mRemotePeers, &aRemotePeer, gsUdpRemotePeerCompare, 0, 0);
    if (index == -1)
        return 0;
    aRemotePeerFound = (GSUdpRemotePeer *)ArrayNth(aUdp->mRemotePeers, index);
    return gt2GetOutgoingBufferFreeSpace(aRemotePeerFound->mConnection);
}
