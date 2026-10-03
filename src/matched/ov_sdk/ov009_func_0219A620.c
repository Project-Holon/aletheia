/*
 * function: func_0219A620
 * address:  0x0219A620
 * packet:   pkt_ov009_0219A620
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ProcessConnectPacket (libdwcgsnatneg.TWL.HYB.a natneg.o)
 *
 * symbols:
 *   func_0215FA9C  0x0215FA9C  arm   ov009
 *   func_0217D254  0x0217D254  arm   ov009
 *   func_0219A52C  0x0219A52C  arm   ov009
 *   func_021994F0  0x021994F0  arm   ov009
 *   func_02199A90  0x02199A90  arm   ov009
 *   g_021A621C     0x021A621C  data
 *   g_021A6274     0x021A6274  data
 *   g_021A62CC     0x021A62CC  data
 *   g_021A6300     0x021A6300  data
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
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_0219A52C(NATNegotiator *neg, SOCSockAddrIn *toaddr);
extern void func_02199A90(NATNegotiator *neg);
extern void func_021994F0(NATNegotiator *neg, int result, int socket, SOCSockAddrIn *remoteaddr);

extern char g_021A621C[];
extern char g_021A6274[];
extern char g_021A62CC[];
extern char g_021A6300[];

void func_0219A620(NATNegotiator *neg, NatNegPacket *p, SOCSockAddrIn *fromaddr)
{
    int errcode;

    func_0217D254(7, 0, 8, g_021A621C, neg->cookie, p->finished, func_0215FA9C(p->ipaddr), NN_NTOHS(p->port));

    if (p->finished == 0)
        func_0219A52C(neg, fromaddr);

    if (neg->state >= 4) {
        func_0217D254(7, 0, 8, g_021A6274, neg->cookie);
        return;
    }

    if (p->finished != 0) {
        errcode = 4;
        if (p->finished == 1) {
            func_0217D254(7, 0, 8, g_021A62CC, neg->cookie);
            errcode = 1;
        } else if (p->finished == 2) {
            func_0217D254(7, 0, 8, g_021A6300, neg->cookie);
            errcode = 2;
        }
        func_021994F0(neg, errcode, -1, 0);
        return;
    }

    neg->guessedIP = p->ipaddr;
    neg->guessedPort = NN_NTOHS(p->port);
    neg->retryCount = 0;
    neg->state = 4;
    neg->progressCallback(4, neg->userdata);
    func_02199A90(neg);
}
