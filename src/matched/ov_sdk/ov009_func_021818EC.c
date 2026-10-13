/*
 * function: func_021818EC
 * address:  0x021818EC
 * packet:   pkt_ov009_021818EC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsUdpEngineGetPeerOutBufferFreeSpace (gsudpengine.o)
 *
 * symbols:
 *   gsUdpEngineContext                  0x02180404  arm ov009
 *   func_0217D254                  0x0217D254  arm ov009
 *   func_021843E8                  0x021843E8  arm ov009
 *   func_02184208                  0x02184208  arm ov009
 *   func_02195E50                  0x02195E50  arm ov009
 *   func_02180448                  0x02180448  arm ov009
 *   g_021A3B9C                     0x021A3B9C  data
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
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);

extern int func_021843E8(void *array, void *key, int (*comparator)(void *, void *), int fromIndex, int isSorted);
extern int func_02195E50(const int *p);
extern int func_02180448(void *theFirstPeer, void *theSecondPeer);
extern char g_021A3B9C[];

int func_021818EC(unsigned int theIp, unsigned short thePort)
{
    GSUdpEngineObject *aUdp;
    GSUdpRemotePeer aRemotePeer;
    GSUdpRemotePeer *aRemotePeerFound;
    int index;

    aUdp = gsUdpEngineContext();
    if (aUdp->initialized == 0) {
        func_0217D254(12, 0, 15, g_021A3B9C);
        return 0;
    }
    aRemotePeer.ip = theIp;
    aRemotePeer.port = thePort;
    index = func_021843E8(aUdp->peers, &aRemotePeer, func_02180448, 0, 0);
    if (index == -1)
        return 0;
    aRemotePeerFound = (GSUdpRemotePeer *)func_02184208(aUdp->peers, index);
    return func_02195E50(aRemotePeerFound->connection);
}
