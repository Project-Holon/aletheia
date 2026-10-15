/*
 * function: gsUdpConnectedRoutingCB
 * address:  0x021806A8
 * packet:   pkt_ov009_021806A8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsUdpConnectedRoutingCB (gsudpengine.o)
 *
 * symbols:
 *   gsUdpEngineContext                  0x02180404  arm ov009
 *   gt2GetRemoteIP                  0x02195E28  arm ov009
 *   gt2GetRemotePort                  0x02195E30  arm ov009
 *   func_021843E8                  0x021843E8  arm ov009
 *   func_02198620                  0x02198620  arm ov009
 *   func_0217D254                  0x0217D254  arm ov009
 *   func_0218437C                  0x0218437C  arm ov009
 *   func_02184200                  0x02184200  arm ov009
 *   func_02184208                  0x02184208  arm ov009
 *   func_02180448                  0x02180448  arm ov009
 *   g_021A393C                     0x021A393C  data
 *   g_021A3964                     0x021A3964  data
 *   g_021A399C                     0x021A399C  data
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
extern int gt2GetRemoteIP(const int *p);
extern unsigned short gt2GetRemotePort(const unsigned short *p);
extern int func_021843E8(void *array, void *key, int (*comparator)(void *, void *), int fromIndex, int isSorted);
extern char *func_02198620(unsigned int ip, unsigned short port, char *string);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_0218437C(int a, int b);
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern int func_02180448(void *theFirstPeer, void *theSecondPeer);
extern char g_021A393C[];
extern char g_021A3964[];
extern char g_021A399C[];

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
        aRemotePeerIdx = func_021843E8(aUdp->mRemotePeers, &aRemotePeer, func_02180448, 0, 0);
        if (aRemotePeerIdx != -1) {
            func_0217D254(12, 0, 16, g_021A393C,
                func_02198620(gt2GetRemoteIP(theConnection), gt2GetRemotePort(theConnection), anAddr));
            func_0218437C((int)aUdp->mRemotePeers, aRemotePeerIdx);
        }
    }

    len = func_02184200(aUdp->mMsgHandlers);
    for (aIndex = 0; aIndex < len; aIndex++) {
        int aRemotePeerIdx;
        GSUdpRemotePeer aRemotePeer;
        GSUdpMsgHandler *aTempHandler;

        aTempHandler = (GSUdpMsgHandler *)func_02184208(aUdp->mMsgHandlers, aIndex);
        aRemotePeer.mAddr = gt2GetRemoteIP(theConnection);
        aRemotePeer.mPort = gt2GetRemotePort(theConnection);
        aRemotePeerIdx = func_021843E8(aTempHandler->mPendingConnections, &aRemotePeer, func_02180448, 0, 0);
        if (aRemotePeerIdx != -1) {
            if (aTempHandler->mConnected) {
                func_0217D254(12, 0, 16, g_021A3964);
                aTempHandler->mConnected(gt2GetRemoteIP(theConnection), gt2GetRemotePort(theConnection),
                    aCode, (theResult == 2) ? 1 : 0, aTempHandler->mUserData);
            }
            func_0218437C((int)aTempHandler->mPendingConnections, aRemotePeerIdx);
            return;
        }
    }

    if (aUdp->mAppPendingConnections > 0) {
        if (aUdp->mAppConnected) {
            func_0217D254(12, 0, 16, g_021A399C);
            aUdp->mAppConnected(gt2GetRemoteIP(theConnection), gt2GetRemotePort(theConnection),
                aCode, (theResult == 2) ? 1 : 0, aUdp->mAppUserData);
        }
        aUdp->mAppPendingConnections--;
    }
}
