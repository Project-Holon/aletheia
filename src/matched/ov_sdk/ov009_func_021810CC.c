/*
 * function: gsUdpEngineStartTalkingToPeer
 * address:  0x021810CC
 * packet:   pkt_ov009_021810CC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsUdpEngineStartTalkingToPeer (gsudpengine.o)
 *
 * symbols:
 *   gsUdpEngineContext                  0x02180404  arm ov009
 *   func_0217D254                  0x0217D254  arm ov009
 *   func_021843E8                  0x021843E8  arm ov009
 *   func_02184208                  0x02184208  arm ov009
 *   func_02195E00                  0x02195E00  arm ov009
 *   func_02198620                  0x02198620  arm ov009
 *   func_02195B44                  0x02195B44  arm ov009
 *   func_02184234                  0x02184234  arm ov009
 *   func_02184200                  0x02184200  arm ov009
 *   func_02180448                  0x02180448  arm ov009
 *   func_02180420                  0x02180420  arm ov009
 *   gsUdpClosedRoutingCB                  0x02180518  arm ov009
 *   gsUdpConnectedRoutingCB                  0x021806A8  arm ov009
 *   gsUdpPingRoutingCB                  0x02180924  arm ov009
 *   gsUdpReceivedRoutingCB                  0x02180A64  arm ov009
 *   g_021A3B9C                     0x021A3B9C  data
 *   g_021A3BC4                     0x021A3BC4  data
 *   g_021A3BF8                     0x021A3BF8  data
 */

typedef struct { char c[16]; } GSUdpHdr;

typedef struct GSUdpRemotePeer {
    unsigned int mAddr;
    unsigned short mPort;
    void *mConnection;
} GSUdpRemotePeer;
typedef struct GSUdpMsgHandler {
    unsigned char mInitialMsg[16];
    unsigned char mHeader[16];
    void *mPendingConnections;
    void (*mClosed)(unsigned int, unsigned short, int, void *);
    void (*mReceived)(unsigned int, unsigned short, unsigned char *, unsigned int, int, void *);
    void (*mConnected)(unsigned int, unsigned short, int, int, void *);
    void (*mPingReply)(unsigned int, unsigned short, unsigned int, void *);
    void (*mNetworkError)(int, void *);
    void *mUserData;
} GSUdpMsgHandler;
typedef struct GSUdpEngineObject {
    void *mSocket;
    void *mRemotePeers;
    void *mMsgHandlers;
    int mInitialized;
    void (*mAppConnected)(unsigned int, unsigned short, int, int, void *);
    void (*mAppClosed)(unsigned int, unsigned short, int, void *);
    void (*mAppPingReply)(unsigned int, unsigned short, unsigned int, void *);
    void (*mAppRecvData)(unsigned int, unsigned short, unsigned char *, unsigned int, int, void *);
    void (*mAppConnAttempt)(unsigned int, unsigned short, int, unsigned char *, unsigned int, void *);
    void (*mAppNetworkError)(int, void *);
    int (*mAppUnknownMessage)(unsigned int, unsigned short, unsigned char *, unsigned int, void *);
    void *mAppUserData;
    int mAppPendingConnections;
    unsigned int mLocalAddr;
    unsigned short mLocalPort;
} GSUdpEngineObject;
typedef struct GT2ConnectionCallbacks {
    void (*connected)(void *, int, unsigned char *, int);
    void (*received)(void *, unsigned char *, int, int);
    void (*closed)(void *, int);
    void (*ping)(void *, int);
} GT2ConnectionCallbacks;

extern void *gsUdpEngineContext(void);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_021843E8(void *array, void *key, int (*comparator)(void *, void *), int fromIndex, int isSorted);
extern void *func_02184208(void *array, int n);
extern int func_02195E00(const int *p);
extern char *func_02198620(unsigned int ip, unsigned short port, char *string);
typedef unsigned char  u8;
struct GTI2Connection;
extern int func_02195B44(void *socket, struct GTI2Connection **connection, char *remoteAddress, u8 *message, int len, int timeout, void *callbacks, int blocking);
extern void func_02184234(void *array, void *newElem);
extern int func_02184200(const int *p);
extern int func_02180448(void *theFirstPeer, void *theSecondPeer);
extern int func_02180420(void *theFirstHandler, void *theSecondHandler);
extern void gsUdpClosedRoutingCB(void *theConnection, int reason);
extern void gsUdpConnectedRoutingCB(void *theConnection, int theResult);
extern void gsUdpPingRoutingCB(void *theConnection, int theLatency);
extern void gsUdpReceivedRoutingCB(void *theConnection, unsigned char *theMessage, int theMessageLen, int reliable);
extern char g_021A3B9C[];
extern char g_021A3BC4[];
extern char g_021A3BF8[];

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
        aCallbacks.closed = (void (*)(void *, int))gsUdpClosedRoutingCB;
        aCallbacks.connected = (void (*)(void *, int, unsigned char *, int))gsUdpConnectedRoutingCB;
        aCallbacks.ping = (void (*)(void *, int))gsUdpPingRoutingCB;
        aCallbacks.received = (void (*)(void *, unsigned char *, int, int))gsUdpReceivedRoutingCB;
        func_02195B44(aUdp->mSocket, (struct GTI2Connection **)(&aRemotePeer.mConnection), anAddr, (unsigned char *)theInitMsg, 16, timeOut, &aCallbacks, 0);
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
