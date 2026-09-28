/*
 * function: func_02180A64
 * address:  0x02180A64
 * packet:   pkt_ov009_02180A64
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      gsUdpReceivedRoutingCB (gsudpengine.o)
 *
 * DIFF, 8 bytes (lane w2_o2): size and every relocation match. The only residue
 * is the 16-byte header copy into aHandler.mHeader: the object keeps the
 * destination (sp+0x30) in r4 and the source copy in r3; every spelling below
 * gives the mirror image (destination r3, source r4). Tried: a GSUdpHdr struct
 * assignment through a cast (as the matched gsUdpEngineRemoveMsgHandler) and
 * with mHeader typed GSUdpHdr, explicit src/dst pointer locals in both
 * declaration orders, a static inline copy helper, a `+ 0` source, a byte loop
 * over index, memcpy (a real call under 1.1p1), and the permuter (seed 7).
 * The same copy matches where the source register is dead afterwards
 * (gsUdpEngineSendMessage, gsUdpEngineStartTalkingToPeer).
 *
 * symbols:
 *   func_02180404                  0x02180404  arm ov009
 *   func_02195E28                  0x02195E28  arm ov009
 *   func_02195E30                  0x02195E30  arm ov009
 *   func_02198620                  0x02198620  arm ov009
 *   func_0217D254                  0x0217D254  arm ov009
 *   func_021843E8                  0x021843E8  arm ov009
 *   func_02184208                  0x02184208  arm ov009
 *   func_02180430                  0x02180430  arm ov009
 *   g_021A3A30                     0x021A3A30  data
 *   g_021A39EC                     0x021A39EC  data
 *   g_021A3A14                     0x021A3A14  data
 */

typedef struct { unsigned char c[16]; } GSUdpHdr;

typedef struct GSUdpRemotePeer {
    unsigned int mAddr;
    unsigned short mPort;
    void *mConnection;
} GSUdpRemotePeer;
typedef struct GSUdpMsgHandler {
    unsigned char mInitialMsg[16];
    GSUdpHdr mHeader;
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
extern void *func_02184208(void *array, int n);
extern int func_021843E8(void *array, void *key, int (*comparator)(void *, void *), int fromIndex, int isSorted);
extern int func_02180430(void *theFirstHandler, void *theSecondHandler);
extern char g_021A3A30[];
extern char g_021A39EC[];
extern char g_021A3A14[];

void func_02180A64(void *theConnection, unsigned char *theMessage, int theMessageLen, int reliable)
{
    GSUdpEngineObject *aUdp;
    GSUdpMsgHandler aHandler;
    int index;
    char anAddr[22];
    GSUdpMsgHandler *aHandlerFound;

    aUdp = func_02180404();
    func_0217D254(12, 0, 16, g_021A3A30,
        func_02198620(func_02195E28(theConnection), func_02195E30(theConnection), anAddr));

    if (theMessageLen >= 16) {
        aHandler.mHeader = *(GSUdpHdr *)theMessage;
        index = func_021843E8(aUdp->mMsgHandlers, &aHandler, func_02180430, 0, 0);
        if (index != -1) {
            aHandlerFound = (GSUdpMsgHandler *)func_02184208(aUdp->mMsgHandlers, index);
            if (aHandlerFound->mReceived) {
                func_0217D254(12, 0, 16, g_021A39EC);
                aHandlerFound->mReceived(func_02195E28(theConnection), func_02195E30(theConnection),
                    theMessage + 16, theMessageLen - 16, reliable, aHandlerFound->mUserData);
                return;
            }
        }
    }

    if (aUdp->mAppRecvData) {
        func_0217D254(12, 0, 16, g_021A3A14);
        aUdp->mAppRecvData(func_02195E28(theConnection), func_02195E30(theConnection),
            theMessage, theMessageLen, reliable, aUdp->mAppUserData);
    }
}
