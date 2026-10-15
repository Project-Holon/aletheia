/*
 * function: gsUdpEngineInitialize
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
 *   gsUdpEngineContext                  0x02180404  arm ov009
 *   gt2AddressToString                  0x02198620  arm ov009
 *   gt2CreateSocket                  0x02195AB4  arm ov009
 *   gsDebugFormat                  0x0217D254  arm ov009
 *   func_02184144                  0x02184144  arm ov009
 *   gt2SetUnrecognizedMessageCallback                  0x02195E68  arm ov009
 *   gt2Listen                  0x02195B20  arm ov009
 *   gt2GetLocalIP                  0x02195E38  arm ov009
 *   gt2GetLocalPort                  0x02195E40  arm ov009
 *   gsUdpSocketError                  0x0218048C  arm ov009
 *   func_02180410                  0x02180410  arm ov009
 *   gsUdpUnrecognizedMsgCB                  0x02180BFC  arm ov009
 *   gsUdpConnAttemptCB                  0x02180C94  arm ov009
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

extern void *gsUdpEngineContext(void);
extern char *gt2AddressToString(unsigned int ip, unsigned short port, char *string);
extern int gt2CreateSocket(void **sock, char *addr, int outSize, int inSize, void *callback);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern void *func_02184144(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void gt2SetUnrecognizedMessageCallback(int *p, int v);
extern void gt2Listen(int *p, int v);
extern int gt2GetLocalIP(const int *p);
extern unsigned short gt2GetLocalPort(const unsigned short *p);
extern void gsUdpSocketError(void);
extern void func_02180410(void *theMsgHandler);
extern int gsUdpUnrecognizedMsgCB(void *theSocket, unsigned int theIp, unsigned short thePort, unsigned char *theMessage, int theMsgLen);
extern void gsUdpConnAttemptCB(void *socket, void *connection, unsigned int ip, unsigned short port, int latency, unsigned char *message, int len);
extern char g_021A3B44[];
extern char g_021A3B7C[];

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

    aUdp->mRemotePeers = func_02184144(12, 1, 0);
    if (aUdp->mRemotePeers == 0) {
        gsDebugFormat(12, (char *)2, 1, g_021A3B7C);
        return 1;
    }

    aUdp->mMsgHandlers = func_02184144(60, 1, func_02180410);
    if (aUdp->mMsgHandlers == 0) {
        gsDebugFormat(12, (char *)2, 1, g_021A3B7C);
        return 1;
    }

    gt2SetUnrecognizedMessageCallback(aUdp->mSocket, (int)gsUdpUnrecognizedMsgCB);
    gt2Listen(aUdp->mSocket, (int)gsUdpConnAttemptCB);
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
