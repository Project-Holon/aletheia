/*
 * function: gsUdpEngineGetPeerState
 * address:  0x02181010
 * packet:   pkt_ov009_02181010
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsUdpEngineGetPeerState (gsudpengine.o)
 *
 * symbols:
 *   gsUdpEngineContext                  0x02180404  arm ov009
 *   gsDebugFormat                  0x0217D254  arm ov009
 *   func_021843E8                  0x021843E8  arm ov009
 *   func_02184208                  0x02184208  arm ov009
 *   gt2GetConnectionState                  0x02195E00  arm ov009
 *   func_02180448                  0x02180448  arm ov009
 *   g_021A3B9C                     0x021A3B9C  data
 *   ArrayLength  0x02184200  arm
 */

typedef void (*GSUdpErrCB)(int, void *);
typedef struct GSUdpMsgHandler {
    char pad0[0x34];
    GSUdpErrCB errCB;
    void *userData;
} GSUdpMsgHandler;
typedef struct GSUdpRemotePeer {
    unsigned int ip;
    unsigned short port;
    void *connection;
} GSUdpRemotePeer;
typedef struct GSUdpEngineObject {
    char pad0[4];
    void *peers;
    void *handlers;
    int initialized;
    char pad10[0x24 - 0x10];
    GSUdpErrCB socketErrorCB;
    int (*unrecognizedCB)(unsigned int, unsigned short, unsigned char *, int, void *);
    void *userData;
} GSUdpEngineObject;
extern void *gsUdpEngineContext(void);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern int ArrayLength(const int *p);
extern void *func_02184208(void *array, int n);

extern int func_021843E8(void *array, void *key, int (*comparator)(void *, void *), int fromIndex, int isSorted);
extern int gt2GetConnectionState(const int *p);
extern int func_02180448(void *theFirstPeer, void *theSecondPeer);
extern char g_021A3B9C[];

int gsUdpEngineGetPeerState(unsigned int theIp, unsigned short thePort, int *thePeerState)
{
    GSUdpEngineObject *aUdp;
    GSUdpRemotePeer aPeer;
    GSUdpRemotePeer *aPeerFound;
    int index;

    aUdp = gsUdpEngineContext();
    if (aUdp->initialized == 0) {
        gsDebugFormat(12, (char *)3, 15, g_021A3B9C);
        *thePeerState = 3;
        return 11;
    }
    aPeer.ip = theIp;
    aPeer.port = thePort;
    index = func_021843E8(aUdp->peers, &aPeer, func_02180448, 0, 0);
    if (index == -1) {
        *thePeerState = 3;
        return 0;
    }
    aPeerFound = (GSUdpRemotePeer *)func_02184208(aUdp->peers, index);
    *thePeerState = gt2GetConnectionState(aPeerFound->connection);
    return 0;
}
