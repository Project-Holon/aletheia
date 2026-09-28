/*
 * function: func_02180924
 * address:  0x02180924
 * packet:   pkt_ov009_02180924
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsUdpPingRoutingCB (libdwcgscommon.TWL.HYB.a(gsudpengine.o))
 *
 * symbols:
 *   func_02180404                  0x02180404  arm ov009
 *   func_02195E28                  0x02195E28  arm ov009
 *   func_02195E30                  0x02195E30  arm ov009
 *   func_02198620                  0x02198620  arm ov009
 *   func_0217D254                  0x0217D254  arm ov009
 *   func_02184200                  0x02184200  arm ov009
 *   func_02184208                  0x02184208  arm ov009
 *   g_021A39C8                     0x021A39C8  data
 *   g_021A39EC                     0x021A39EC  data
 *   g_021A3A14                     0x021A3A14  data
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

extern GSUdpEngineObject *func_02180404(void);
extern unsigned int func_02195E28(void *connection);
extern unsigned short func_02195E30(void *connection);
extern char *func_02198620(unsigned int ip, unsigned short port, char *string);
extern void func_0217D254(int theCat, int theType, unsigned char theLevel, char *theTokenStr, ...);
extern int func_02184200(void *array);
extern void *func_02184208(void *array, int n);
extern char g_021A39C8[];
extern char g_021A39EC[];
extern char g_021A3A14[];

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
