/*
 * function: func_02181350
 * address:  0x02181350
 * packet:   pkt_ov009_02181350
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsUdpEngineSendMessage (gsudpengine.o)
 *
 * symbols:
 *   gsUdpEngineContext                  0x02180404  arm ov009
 *   func_0217D254                  0x0217D254  arm ov009
 *   func_021843E8                  0x021843E8  arm ov009
 *   func_02198620                  0x02198620  arm ov009
 *   func_02184208                  0x02184208  arm ov009
 *   gt2GetOutgoingBufferSize                  0x02195E48  arm ov009
 *   func_0217EAB0                  0x0217EAB0  arm ov009
 *   memcpy                         0x02092344  arm
 *   func_02195CC0                  0x02195CC0  arm ov009
 *   func_0217EAE0                  0x0217EAE0  arm ov009
 *   func_02180448                  0x02180448  arm ov009
 *   g_021A3B9C                     0x021A3B9C  data
 *   g_021A3C34                     0x021A3C34  data
 *   g_021A3C68                     0x021A3C68  data
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

extern void *gsUdpEngineContext(void);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_021843E8(void *array, void *key, int (*comparator)(void *, void *), int fromIndex, int isSorted);
extern char *func_02198620(unsigned int ip, unsigned short port, char *string);
extern void *func_02184208(void *array, int n);
extern int gt2GetOutgoingBufferSize(const int *p);
extern void *func_0217EAB0(unsigned long size);
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern int func_02195CC0(void *connection, unsigned char *message, int len, int reliable);
extern void func_0217EAE0(void *ptr);
extern int func_02180448(void *theFirstPeer, void *theSecondPeer);
extern char g_021A3B9C[];
extern char g_021A3C34[];
extern char g_021A3C68[];

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

    aUdp = gsUdpEngineContext();
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
    if (aTotalMessageLen > gt2GetOutgoingBufferSize(aRemotePeerFound->mConnection) && theReliable) {
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
