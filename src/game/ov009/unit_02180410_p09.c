/*
 * file:     unit_02180410_p09.c
 * unit:     yes
 * function: func_021810CC, func_02181350
 * address:  0x021810CC
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
 *   func_02180404                  0x02180404  arm ov009
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
 *   func_02180518                  0x02180518  arm ov009
 *   func_021806A8                  0x021806A8  arm ov009
 *   func_02180924                  0x02180924  arm ov009
 *   func_02180A64                  0x02180A64  arm ov009
 *   g_021A3B9C                     0x021A3B9C  data
 *   g_021A3BC4                     0x021A3BC4  data
 *   g_021A3BF8                     0x021A3BF8  data
 *   func_02195E48                  0x02195E48  arm ov009
 *   func_0217EAB0                  0x0217EAB0  arm ov009
 *   memcpy                         0x02092344  arm
 *   func_02195CC0                  0x02195CC0  arm ov009
 *   func_0217EAE0                  0x0217EAE0  arm ov009
 *   g_021A3C34                     0x021A3C34  data
 *   g_021A3C68                     0x021A3C68  data
 */
struct GTI2Connection;
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

typedef unsigned char  u8;

extern void *func_02180404(void);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_021843E8(void *array, void *key, int (*comparator)(void *, void *), int fromIndex, int isSorted);
extern void *func_02184208(void *array, int n);
extern int func_02195E00(const int *p);
extern char *func_02198620(unsigned int ip, unsigned short port, char *string);
extern int func_02195B44(void *socket, struct GTI2Connection **connection, char *remoteAddress, u8 *message, int len, int timeout, void *callbacks, int blocking);
extern void func_02184234(void *array, void *newElem);
extern int func_02184200(const int *p);
extern int func_02180448(void *theFirstPeer, void *theSecondPeer);
extern int func_02180420(void *theFirstHandler, void *theSecondHandler);
extern void func_02180518(void *theConnection, int reason);
extern void func_021806A8(void *theConnection, int theResult);
extern void func_02180924(void *theConnection, int theLatency);
extern void func_02180A64(void *theConnection, unsigned char *theMessage, int theMessageLen, int reliable);
extern int func_02195E48(const int *p);
extern void *func_0217EAB0(unsigned long size);
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern int func_02195CC0(void *connection, unsigned char *message, int len, int reliable);
extern void func_0217EAE0(void *ptr);
int func_021810CC(unsigned int theIp, unsigned short thePort, char *theInitMsg, int timeOut);
int func_02181350(unsigned int theIp, unsigned short thePort, char *theHeader, unsigned char *theMsg, unsigned int theMsgLen, int theReliable);
extern char g_021A3B9C[];
extern char g_021A3BC4[];
extern char g_021A3BF8[];
extern char g_021A3C34[];
extern char g_021A3C68[];


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
