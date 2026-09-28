/*
 * function: func_02180C94
 * address:  0x02180C94
 * packet:   pkt_ov009_02180C94
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      gsUdpConnAttemptCB (gsudpengine.o)
 *
 * DIFF, 8 bytes (lane w2_o2): the same residue as gsUdpReceivedRoutingCB
 * (0x02180A64): the 16-byte message-to-aHandler.mInitialMsg copy colours the
 * destination r3 and the loaded stack-parameter source r4; the object has
 * destination r4 and source r3. Tried: GSUdpHdr cast assignment, the whole
 * aHandler as the destination, a temp pointer, a GSUdpHdr value temp, a static
 * inline helper in both argument orders, __builtin_memcpy (a call), byte loops,
 * and the permuter (400 anneal, 2000 random).
 *
 * symbols:
 *   func_02180404                  0x02180404  arm ov009
 *   func_02198620                  0x02198620  arm ov009
 *   func_0217D254                  0x0217D254  arm ov009
 *   func_02184234                  0x02184234  arm ov009
 *   func_021843E8                  0x021843E8  arm ov009
 *   func_02195B2C                  0x02195B2C  arm ov009
 *   func_02195B38                  0x02195B38  arm ov009
 *   func_02184200                  0x02184200  arm ov009
 *   func_02184324                  0x02184324  arm ov009
 *   func_02180420                  0x02180420  arm ov009
 *   func_02180518                  0x02180518  arm ov009
 *   func_021806A8                  0x021806A8  arm ov009
 *   func_02180924                  0x02180924  arm ov009
 *   func_02180A64                  0x02180A64  arm ov009
 *   g_021A3A8C                     0x021A3A8C  data
 *   g_021A3AB8                     0x021A3AB8  data
 *   g_021A3AFC                     0x021A3AFC  data
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

extern GSUdpEngineObject *func_02180404(void);
extern char *func_02198620(unsigned int ip, unsigned short port, char *string);
extern void func_0217D254(int theCat, int theType, unsigned char theLevel, char *theTokenStr, ...);
extern void func_02184234(void *array, void *newElem);
extern int func_021843E8(void *array, void *key, int (*comparator)(void *, void *), int fromIndex, int isSorted);
extern int func_02195B2C(void *connection, GT2ConnectionCallbacks *callbacks);
extern void func_02195B38(void *connection, unsigned char *message, int len);
extern int func_02184200(void *array);
extern void func_02184324(void *array, int n);
extern int func_02180420(void *theFirstHandler, void *theSecondHandler);
extern void func_02180518(void *theConnection, int reason);
extern void func_021806A8(void *theConnection, int theResult, unsigned char *theMessage, int theMessageLen);
extern void func_02180924(void *theConnection, int theLatency);
extern void func_02180A64(void *theConnection, unsigned char *theMessage, int theMessageLen, int reliable);
extern char g_021A3A8C[];
extern char g_021A3AB8[];
extern char g_021A3AFC[];

void func_02180C94(void *socket, void *connection, unsigned int ip, unsigned short port, int latency, unsigned char *message, int len)
{
    int index;
    GSUdpMsgHandler aHandler;
    GSUdpRemotePeer aRemotePeer;
    GSUdpEngineObject *aUdp;
    char anAddr[22];
    GT2ConnectionCallbacks aCallbacks;

    aUdp = func_02180404();
    func_0217D254(12, 0, 16, g_021A3A8C, func_02198620(ip, port, anAddr));

    if (len >= 16) {
        *(GSUdpHdr *)aHandler.mInitialMsg = *(GSUdpHdr *)message;
        aRemotePeer.mAddr = ip;
        aRemotePeer.mPort = port;
        aRemotePeer.mConnection = connection;
        func_02184234(aUdp->mRemotePeers, &aRemotePeer);
        index = func_021843E8(aUdp->mMsgHandlers, &aHandler, func_02180420, 0, 0);
        if (index != -1) {
            aCallbacks.closed = (void (*)(void *, int))func_02180518;
            aCallbacks.connected = (void (*)(void *, int, unsigned char *, int))func_021806A8;
            aCallbacks.ping = (void (*)(void *, int))func_02180924;
            aCallbacks.received = (void (*)(void *, unsigned char *, int, int))func_02180A64;
            func_02195B2C(aRemotePeer.mConnection, &aCallbacks);
            func_0217D254(12, 0, 16, g_021A3AB8);
            return;
        }
    }

    if (aUdp->mAppConnAttempt) {
        func_0217D254(12, 0, 16, g_021A3AFC, func_02198620(ip, port, anAddr));
        aUdp->mAppConnAttempt(ip, port, latency, message, len, aUdp->mAppUserData);
        return;
    }

    func_02195B38(connection, 0, 0);
    func_02184324(aUdp->mRemotePeers, func_02184200(aUdp->mRemotePeers) - 1);
}
