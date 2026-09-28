/*
 * function: func_021815C8
 * address:  0x021815C8
 * packet:   pkt_ov009_021815C8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsUdpEngineAddMsgHandler (libdwcgscommon.TWL.HYB.a(gsudpengine.o))
 *
 * symbols:
 *   func_02180404                  0x02180404  arm ov009
 *   func_0217D254                  0x0217D254  arm ov009
 *   func_02184144                  0x02184144  arm ov009
 *   func_02184234                  0x02184234  arm ov009
 *   g_021A3B9C                     0x021A3B9C  data
 *   g_021A3CA0                     0x021A3CA0  data
 *   g_021A3CC4                     0x021A3CC4  data
 *   g_021A3B7C                     0x021A3B7C  data
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

typedef struct { char c[16]; } GSChar16;

extern GSUdpEngineObject *func_02180404(void);
extern void func_0217D254(int theCat, int theType, unsigned char theLevel, char *theTokenStr, ...);
extern void *func_02184144(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void func_02184234(void *array, void *newElem);
extern char g_021A3B9C[];
extern char g_021A3CA0[];
extern char g_021A3CC4[];
extern char g_021A3B7C[];

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
    *(GSChar16 *)aMsgHandler.mInitialMsg = *(GSChar16 *)theInitMsg;
    *(GSChar16 *)aMsgHandler.mHeader = *(GSChar16 *)theHeader;

    aMsgHandler.mPendingConnections = func_02184144(4, 1, 0);
    if (aMsgHandler.mPendingConnections == 0) {
        func_0217D254(12, 2, 1, g_021A3B7C);
        return 1;
    }
    aMsgHandler.mUserData = theUserData;
    func_02184234(aUdp->mMsgHandlers, &aMsgHandler);
    return 0;
}
