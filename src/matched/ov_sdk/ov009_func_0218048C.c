/*
 * function: func_0218048C
 * address:  0x0218048C
 * packet:   pkt_ov009_0218048C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsUdpSocketError (gsudpengine.o)
 *
 * symbols:
 *   func_02180404                  0x02180404  arm ov009
 *   func_0217D254                  0x0217D254  arm ov009
 *   func_02184200                  0x02184200  arm ov009
 *   func_02184208                  0x02184208  arm ov009
 *   g_021A3868                     0x021A3868  data
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

extern char g_021A3868[];

void func_0218048C(void)
{
    int i;
    int len;
    GSUdpEngineObject *aUdp;
    GSUdpMsgHandler *aMsgHandler;

    aUdp = func_02180404();
    func_0217D254(12, 0, 16, g_021A3868);
    if (aUdp->socketErrorCB != 0)
        aUdp->socketErrorCB(3, aUdp->userData);
    len = func_02184200(aUdp->handlers);
    for (i = 0; i < len; i++) {
        aMsgHandler = (GSUdpMsgHandler *)func_02184208(aUdp->handlers, i);
        if (aMsgHandler->errCB != 0)
            aMsgHandler->errCB(3, aMsgHandler->userData);
    }
}
