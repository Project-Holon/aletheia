/*
 * file:     unit_02180410_p03.c
 * unit:     yes
 * function: func_02180518, func_021806A8, func_02180924, func_02180A64
 * address:  0x02180518
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   func_02180448                  0x02180448  arm ov009
 *   g_021A393C                     0x021A393C  data
 *   g_021A3964                     0x021A3964  data
 *   g_021A399C                     0x021A399C  data
 *   g_021A39C8                     0x021A39C8  data
 *   g_021A39EC                     0x021A39EC  data
 *   g_021A3A14                     0x021A3A14  data
 *   func_02180430                  0x02180430  arm ov009
 *   g_021A3A30                     0x021A3A30  data
 */
#include "../../matched/arm9_sdk/libc/string.h"

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

typedef struct { char c[16]; } GSUdpHdr;

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
extern int func_02180448(void *theFirstPeer, void *theSecondPeer);
extern int func_02180430(void *theFirstHandler, void *theSecondHandler);
/*
 * sdk: gsUdpClosedRoutingCB (gsudpengine.o)
 */
void func_02180518(void *theConnection, int reason);
/*
 * sdk: gsUdpConnectedRoutingCB (gsudpengine.o)
 */
void func_021806A8(void *theConnection, int theResult);
void func_02180924(void *theConnection, int theLatency);
void func_02180A64(void *theConnection, unsigned char *theMessage, int theMessageLen, int reliable);
extern char g_021A38A8[];
extern char g_021A38D0[];
extern char g_021A390C[];
extern char g_021A393C[];
extern char g_021A3964[];
extern char g_021A399C[];
extern char g_021A39C8[];
extern char g_021A39EC[];
extern char g_021A3A14[];
extern char g_021A3A30[];



/*
 * sdk:      gsUdpClosedRoutingCB (gsudpengine.o)
 */
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



/*
 * sdk:      gsUdpConnectedRoutingCB (gsudpengine.o)
 */
void func_021806A8(void *theConnection, int theResult)
{
    GSUdpEngineObject *aUdp;
    int aIndex;
    int len;
    int aCode;
    char anAddr[22];

    aUdp = func_02180404();
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

        aRemotePeer.mAddr = func_02195E28(theConnection);
        aRemotePeer.mPort = func_02195E30(theConnection);
        aRemotePeerIdx = func_021843E8(aUdp->mRemotePeers, &aRemotePeer, func_02180448, 0, 0);
        if (aRemotePeerIdx != -1) {
            func_0217D254(12, 0, 16, g_021A393C,
                func_02198620(func_02195E28(theConnection), func_02195E30(theConnection), anAddr));
            func_0218437C((int)aUdp->mRemotePeers, aRemotePeerIdx);
        }
    }

    len = func_02184200(aUdp->mMsgHandlers);
    for (aIndex = 0; aIndex < len; aIndex++) {
        int aRemotePeerIdx;
        GSUdpRemotePeer aRemotePeer;
        GSUdpMsgHandler *aTempHandler;

        aTempHandler = (GSUdpMsgHandler *)func_02184208(aUdp->mMsgHandlers, aIndex);
        aRemotePeer.mAddr = func_02195E28(theConnection);
        aRemotePeer.mPort = func_02195E30(theConnection);
        aRemotePeerIdx = func_021843E8(aTempHandler->mPendingConnections, &aRemotePeer, func_02180448, 0, 0);
        if (aRemotePeerIdx != -1) {
            if (aTempHandler->mConnected) {
                func_0217D254(12, 0, 16, g_021A3964);
                aTempHandler->mConnected(func_02195E28(theConnection), func_02195E30(theConnection),
                    aCode, (theResult == 2) ? 1 : 0, aTempHandler->mUserData);
            }
            func_0218437C((int)aTempHandler->mPendingConnections, aRemotePeerIdx);
            return;
        }
    }

    if (aUdp->mAppPendingConnections > 0) {
        if (aUdp->mAppConnected) {
            func_0217D254(12, 0, 16, g_021A399C);
            aUdp->mAppConnected(func_02195E28(theConnection), func_02195E30(theConnection),
                aCode, (theResult == 2) ? 1 : 0, aUdp->mAppUserData);
        }
        aUdp->mAppPendingConnections--;
    }
}



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


/*
 * sdk:      gsUdpReceivedRoutingCB (gsudpengine.o)
 * Closed (lane U13): the 16-byte copy into aHandler.mHeader is
 * memcpy(&aHandler.mHeader, theMessage, sizeof(aHandler.mHeader)) with the
 * house string.h prototype (which makes mwccarm expand memcpy as the two-byte
 * loop instead of emitting a call -- a prototype written in the .c file itself
 * always produces the call, which is why lane w2_o2 saw "memcpy (a real call)").
 * The intrinsic expansion colours the destination r4 and the source r3, exactly
 * as the object does; the struct assignment `aHandler.mHeader = *(GSUdpHdr *)
 * theMessage` gives the mirror image (destination r3, source r4).  Same close as
 * ov009_func_0217ECA4 (sendto) and gsUdpConnAttemptCB (0x02180C94).
 */
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
        memcpy(&aHandler.mHeader, theMessage, sizeof(aHandler.mHeader));
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
