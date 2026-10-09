/*
 * file:     unit_02180410_p07.c
 * unit:     yes
 * function: func_02181010
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
 *   func_02180404                  0x02180404  arm ov009
 *   func_0217D254                  0x0217D254  arm ov009
 *   func_021843E8                  0x021843E8  arm ov009
 *   func_02184208                  0x02184208  arm ov009
 *   func_02195E00                  0x02195E00  arm ov009
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
extern void *func_02180404(void);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);

extern int func_021843E8(void *array, void *key, int (*comparator)(void *, void *), int fromIndex, int isSorted);
extern int func_02195E00(const int *p);
extern int func_02180448(void *theFirstPeer, void *theSecondPeer);
extern char g_021A3B9C[];

int func_02181010(unsigned int theIp, unsigned short thePort, int *thePeerState)
{
    GSUdpEngineObject *aUdp;
    GSUdpRemotePeer aPeer;
    GSUdpRemotePeer *aPeerFound;
    int index;

    aUdp = func_02180404();
    if (aUdp->initialized == 0) {
        func_0217D254(12, (char *)3, 15, g_021A3B9C);
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
    *thePeerState = func_02195E00(aPeerFound->connection);
    return 0;
}
