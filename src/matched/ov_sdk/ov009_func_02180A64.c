/*
 * function: gsUdpReceivedRoutingCB
 * address:  0x02180A64
 * packet:   pkt_ov009_02180A64
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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
 *
 * symbols:
 *   gsUdpEngineContext                  0x02180404  arm ov009
 *   gt2GetRemoteIP                  0x02195E28  arm ov009
 *   gt2GetRemotePort                  0x02195E30  arm ov009
 *   gt2AddressToString                  0x02198620  arm ov009
 *   gsDebugFormat                  0x0217D254  arm ov009
 *   func_021843E8                  0x021843E8  arm ov009
 *   func_02184208                  0x02184208  arm ov009
 *   func_02180430                  0x02180430  arm ov009
 *   g_021A3A30                     0x021A3A30  data
 *   g_021A39EC                     0x021A39EC  data
 *   g_021A3A14                     0x021A3A14  data
 */

#include "../arm9_sdk/libc/string.h"

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

extern GSUdpEngineObject *gsUdpEngineContext(void);
extern unsigned int gt2GetRemoteIP(void *connection);
extern unsigned short gt2GetRemotePort(void *connection);
extern char *gt2AddressToString(unsigned int ip, unsigned short port, char *string);
extern void gsDebugFormat(int theCat, int theType, unsigned char theLevel, char *theTokenStr, ...);
extern void *func_02184208(void *array, int n);
extern int func_021843E8(void *array, void *key, int (*comparator)(void *, void *), int fromIndex, int isSorted);
extern int func_02180430(void *theFirstHandler, void *theSecondHandler);
extern char g_021A3A30[];
extern char g_021A39EC[];
extern char g_021A3A14[];

void gsUdpReceivedRoutingCB(void *theConnection, unsigned char *theMessage, int theMessageLen, int reliable)
{
    GSUdpEngineObject *aUdp;
    GSUdpMsgHandler aHandler;
    int index;
    char anAddr[22];
    GSUdpMsgHandler *aHandlerFound;

    aUdp = gsUdpEngineContext();
    gsDebugFormat(12, 0, 16, g_021A3A30,
        gt2AddressToString(gt2GetRemoteIP(theConnection), gt2GetRemotePort(theConnection), anAddr));

    if (theMessageLen >= 16) {
        memcpy(&aHandler.mHeader, theMessage, sizeof(aHandler.mHeader));
        index = func_021843E8(aUdp->mMsgHandlers, &aHandler, func_02180430, 0, 0);
        if (index != -1) {
            aHandlerFound = (GSUdpMsgHandler *)func_02184208(aUdp->mMsgHandlers, index);
            if (aHandlerFound->mReceived) {
                gsDebugFormat(12, 0, 16, g_021A39EC);
                aHandlerFound->mReceived(gt2GetRemoteIP(theConnection), gt2GetRemotePort(theConnection),
                    theMessage + 16, theMessageLen - 16, reliable, aHandlerFound->mUserData);
                return;
            }
        }
    }

    if (aUdp->mAppRecvData) {
        gsDebugFormat(12, 0, 16, g_021A3A14);
        aUdp->mAppRecvData(gt2GetRemoteIP(theConnection), gt2GetRemotePort(theConnection),
            theMessage, theMessageLen, reliable, aUdp->mAppUserData);
    }
}
