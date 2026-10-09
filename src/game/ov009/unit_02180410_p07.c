/*
 * file:     unit_02180410_p07.c
 * unit:     yes
 * function: func_02180E58
 * address:  0x02180E58
 * packet:   pkt_ov009_02180E58
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsUdpEngineInitialize (gsudpengine.o)
 *
 * symbols:
 *   func_02180404                  0x02180404  arm ov009
 *   func_02198620                  0x02198620  arm ov009
 *   func_02195AB4                  0x02195AB4  arm ov009
 *   func_0217D254                  0x0217D254  arm ov009
 *   func_02184144                  0x02184144  arm ov009
 *   func_02195E68                  0x02195E68  arm ov009
 *   func_02195B20                  0x02195B20  arm ov009
 *   func_02195E38                  0x02195E38  arm ov009
 *   func_02195E40                  0x02195E40  arm ov009
 *   func_0218048C                  0x0218048C  arm ov009
 *   func_02180410                  0x02180410  arm ov009
 *   func_02180BFC                  0x02180BFC  arm ov009
 *   func_02180C94                  0x02180C94  arm ov009
 *   g_021A3B44                     0x021A3B44  data
 *   g_021A3B7C                     0x021A3B7C  data
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

extern void *func_02180404(void);
extern char *func_02198620(unsigned int ip, unsigned short port, char *string);
extern int func_02195AB4(void **sock, char *addr, int outSize, int inSize, void *callback);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void *func_02184144(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void func_02195E68(int *p, int v);
extern void func_02195B20(int *p, int v);
extern int func_02195E38(const int *p);
extern unsigned short func_02195E40(const unsigned short *p);
extern void func_0218048C(void);
extern void func_02180410(void *theMsgHandler);
extern int func_02180BFC(void *theSocket, unsigned int theIp, unsigned short thePort, unsigned char *theMessage, int theMsgLen);
extern void func_02180C94(void *socket, void *connection, unsigned int ip, unsigned short port, int latency, unsigned char *message, int len);
extern char g_021A3B44[];
extern char g_021A3B7C[];

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
        func_0217D254(12, (char *)2, 1, g_021A3B7C);
        return 1;
    }

    aUdp->mMsgHandlers = func_02184144(60, 1, func_02180410);
    if (aUdp->mMsgHandlers == 0) {
        func_0217D254(12, (char *)2, 1, g_021A3B7C);
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
