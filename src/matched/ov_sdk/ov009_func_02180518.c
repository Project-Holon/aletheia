/*
 * function: func_02180518
 * address:  0x02180518
 * packet:   pkt_ov009_02180518
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsUdpClosedRoutingCB (gsudpengine.o)
 *
 * symbols:
 *   func_02180404                  0x02180404  arm ov009
 *   func_02195E28                  0x02195E28  arm ov009
 *   func_02195E30                  0x02195E30  arm ov009
 *   func_02198620                  0x02198620  arm ov009
 *   func_0217D254                  0x0217D254  arm ov009
 *   func_02184200                  0x02184200  arm ov009
 *   func_02184208                  0x02184208  arm ov009
 *   func_021843E8                  0x021843E8  arm ov009
 *   func_0218437C                  0x0218437C  arm ov009
 *   func_02180474                  0x02180474  arm ov009
 *   g_021A38A8                     0x021A38A8  data
 *   g_021A38D0                     0x021A38D0  data
 *   g_021A390C                     0x021A390C  data
 */

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

extern void *func_02180404(void);
extern int func_02195E28(const int *p);
extern unsigned short func_02195E30(const unsigned short *p);
extern char *func_02198620(unsigned int ip, unsigned short port, char *string);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern int func_021843E8(void *array, void *key, int (*comparator)(void *, void *), int fromIndex, int isSorted);
extern void func_0218437C(int a, int b);
extern int func_02180474(void *theFirstPeer, void *theSecondPeer);
extern char g_021A38A8[];
extern char g_021A38D0[];
extern char g_021A390C[];

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
