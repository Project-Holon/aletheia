/*
 * function: gsUdpPingRoutingCB
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
 *   gsUdpEngineContext                  0x02180404  arm ov009
 *   gt2GetRemoteIP                  0x02195E28  arm ov009
 *   gt2GetRemotePort                  0x02195E30  arm ov009
 *   gt2AddressToString                  0x02198620  arm ov009
 *   gsDebugFormat                  0x0217D254  arm ov009
 *   ArrayLength                  0x02184200  arm ov009
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

extern void *gsUdpEngineContext(void);
extern int gt2GetRemoteIP(const int *p);
extern unsigned short gt2GetRemotePort(const unsigned short *p);
extern char *gt2AddressToString(unsigned int ip, unsigned short port, char *string);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern int ArrayLength(const int *p);
extern void *func_02184208(void *array, int n);
extern char g_021A39C8[];
extern char g_021A39EC[];
extern char g_021A3A14[];

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
        aHandler = (GSUdpMsgHandler *)func_02184208(aUdp->mMsgHandlers, index);
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
