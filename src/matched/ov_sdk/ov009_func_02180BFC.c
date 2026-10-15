/*
 * function: gsUdpUnrecognizedMsgCB
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
 *   gt2AddressToString                  0x02198620  arm ov009
 *   gsDebugFormat                  0x0217D254  arm ov009
 *   g_021A3A54                     0x021A3A54  data
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

extern char *gt2AddressToString(unsigned int ip, unsigned short port, char *string);
extern char g_021A3A54[];

int gsUdpUnrecognizedMsgCB(void *theSocket, unsigned int theIp, unsigned short thePort, unsigned char *theMessage, int theMsgLen)
{
    int aRet;
    char anAddr[22];
    GSUdpEngineObject *aUdp;

    aUdp = gsUdpEngineContext();
    if (aUdp->unrecognizedCB != 0) {
        gsDebugFormat(12, 0, 16, g_021A3A54, gt2AddressToString(theIp, thePort, anAddr));
        aRet = aUdp->unrecognizedCB(theIp, thePort, theMessage, theMsgLen, aUdp->userData);
        if (aRet != 0)
            return 1;
        return 0;
    }
    return 0;
}
