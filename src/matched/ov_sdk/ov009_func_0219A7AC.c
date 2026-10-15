/*
 * function: ProcessPingPacket
 * address:  0x0219A7AC
 * packet:   pkt_ov009_0219A7AC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ProcessPingPacket (libdwcgsnatneg.TWL.HYB.a natneg.o)
 *
 * symbols:
 *   func_0215FA9C  0x0215FA9C  arm  ov009
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   SendPingPacket  0x02199A90  arm  ov009
 *   StartReport  0x021994F0  arm  ov009
 *   gNatNegPingPacketFmt     0x021A6330  data
 *   gNatNegPingEarlyFmt     0x021A6384  data
 *   gNatNegGotPingFmt     0x021A63D8  data
 *   gNatNegConnectFinishedFmt     0x021A640C  data
 */

typedef struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
} SOCSockAddrIn;

typedef struct _NATNegotiator {
    int gameSock;                                    /* 0x00 */
    int cookie;                                      /* 0x04 */
    int clientIndex;                                 /* 0x08 */
    void (*progressCallback)(int state, void *userdata);                              /* 0x0C */
    void (*completedCallback)(int result, int gameSocket, SOCSockAddrIn *remoteaddr, void *userdata); /* 0x10 */
    void *userdata;                                  /* 0x14 */
    int negotiateSock;                               /* 0x18 */
    int state;                                       /* 0x1C */
    int initAckRecv[4];                              /* 0x20 */
    int retryCount;                                  /* 0x30 */
    int maxRetryCount;                               /* 0x34 */
    unsigned int retryTime;                          /* 0x38 */
    unsigned int guessedIP;                          /* 0x3C */
    unsigned short guessedPort;                      /* 0x40 */
    unsigned char gotRemoteData;                     /* 0x42 */
    unsigned char sendGotRemoteData;                 /* 0x43 */
    int result;                                      /* 0x44 */
} NATNegotiator;

typedef struct _NatNegPacket {
    unsigned char magic[6];                          /* 0x00 */
    unsigned char version;                           /* 0x06 */
    unsigned char packettype;                        /* 0x07 */
    int cookie;                                      /* 0x08 */
    unsigned int ipaddr;                             /* 0x0C */
    unsigned short port;                             /* 0x10 */
    unsigned char gotyourdata;                       /* 0x12 */
    unsigned char finished;                          /* 0x13 */
} NatNegPacket;

#define NN_NTOHS(x) ((unsigned short)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))

extern char *func_0215FA9C(unsigned int in);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
struct NATNegotiator;
extern void SendPingPacket(struct NATNegotiator *neg);
extern void StartReport(NATNegotiator *neg, int result, int socket, SOCSockAddrIn *remoteaddr);

extern char gNatNegPingPacketFmt[];
extern char gNatNegPingEarlyFmt[];
extern char gNatNegGotPingFmt[];
extern char gNatNegConnectFinishedFmt[];

void ProcessPingPacket(NATNegotiator *neg, NatNegPacket *p, SOCSockAddrIn *fromaddr)
{
    gsDebugFormat(7, 0, 8, gNatNegPingPacketFmt, neg->cookie, func_0215FA9C(fromaddr->addr),
                  NN_NTOHS(fromaddr->port), p->gotyourdata, p->finished);

    if (neg->state < 4) {
        gsDebugFormat(7, 0, 8, gNatNegPingEarlyFmt, neg->cookie);
        return;
    }

    gsDebugFormat(7, 0, 8, gNatNegGotPingFmt, func_0215FA9C(fromaddr->addr), NN_NTOHS(fromaddr->port),
                  p->gotyourdata, p->finished);

    neg->guessedIP = fromaddr->addr;
    neg->guessedPort = NN_NTOHS(fromaddr->port);
    neg->gotRemoteData = 1;
    neg->sendGotRemoteData = p->gotyourdata ? 1 : 0;

    SendPingPacket((struct NATNegotiator *)neg);

    if (neg->state == 4 && neg->sendGotRemoteData) {
        gsDebugFormat(7, 0, 8, gNatNegConnectFinishedFmt, neg->cookie);
        StartReport(neg, 0, neg->gameSock == -1 ? neg->negotiateSock : neg->gameSock, fromaddr);
    }
}
