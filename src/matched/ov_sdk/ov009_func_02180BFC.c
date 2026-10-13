/*
 * function: func_02180BFC
 * address:  0x02180BFC
 * packet:   pkt_ov009_02180BFC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsUdpUnrecognizedMsgCB (gsudpengine.o)
 *
 * symbols:
 *   gsUdpEngineContext                  0x02180404  arm ov009
 *   func_02198620                  0x02198620  arm ov009
 *   func_0217D254                  0x0217D254  arm ov009
 *   g_021A3A54                     0x021A3A54  data
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

extern char *func_02198620(unsigned int ip, unsigned short port, char *string);
extern char g_021A3A54[];

int func_02180BFC(void *theSocket, unsigned int theIp, unsigned short thePort, unsigned char *theMessage, int theMsgLen)
{
    int aRet;
    char anAddr[22];
    GSUdpEngineObject *aUdp;

    aUdp = gsUdpEngineContext();
    if (aUdp->unrecognizedCB != 0) {
        func_0217D254(12, 0, 16, g_021A3A54, func_02198620(theIp, thePort, anAddr));
        aRet = aUdp->unrecognizedCB(theIp, thePort, theMessage, theMsgLen, aUdp->userData);
        if (aRet != 0)
            return 1;
        return 0;
    }
    return 0;
}
