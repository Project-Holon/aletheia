/*
 * function: NNBeginNegotiationWithSocket
 * address:  0x02199DFC
 * packet:   pkt_ov009_02199DFC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NNBeginNegotiationWithSocket (libdwcgsnatneg.TWL.HYB.a natneg.o)
 *
 * symbols:
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   ResolveServers  0x02199D60  arm  ov009
 *   AddNegotiator  0x02199138  arm  ov009
 *   socket  0x0217EB18  arm  ov009
 *   RemoveNegotiator  0x021991C8  arm  ov009
 *   SendPreinitPacket  0x021995E4  arm  ov009
 *   func_0217ED0C  0x0217ED0C  arm  ov009
 *   gGsAvailabilityState     0x021ACEF8  data
 *   gNatNegBackendUnavailFmt     0x021A5D04  data
 *   gNatNegResolveFailFmt     0x021A5D44  data
 *   gNatNegAllocFailFmt     0x021A5D90  data
 *   gNatNegSocketFailFmt     0x021A5DD0  data
 *   gNatNegSocketFmt     0x021A5E14  data
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

extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern int ResolveServers(void);
extern NATNegotiator *AddNegotiator(void);
extern int socket(int pf, int type, int protocol);
extern void RemoveNegotiator(NATNegotiator *neg);
struct NATNegotiator;
extern void SendPreinitPacket(struct NATNegotiator *neg);
extern int func_0217ED0C(int sock, void *addr, int *len);

extern int gGsAvailabilityState;
extern char gNatNegBackendUnavailFmt[];
extern char gNatNegResolveFailFmt[];
extern char gNatNegAllocFailFmt[];
extern char gNatNegSocketFailFmt[];
extern char gNatNegSocketFmt[];

int NNBeginNegotiationWithSocket(int gamesocket, int cookie, int clientindex,
                  void (*progresscallback)(int, void *),
                  void (*completedcallback)(int, int, SOCSockAddrIn *, void *), void *userdata)
{
    NATNegotiator *neg;
    SOCSockAddrIn saddr;
    int namelen;

    if (gGsAvailabilityState != 1) {
        gsDebugFormat(7, 0, 4, gNatNegBackendUnavailFmt, cookie);
        return 2;
    }

    if (!ResolveServers()) {
        gsDebugFormat(7, 0, 4, gNatNegResolveFailFmt, cookie);
        return 3;
    }

    neg = AddNegotiator();
    if (neg == 0) {
        gsDebugFormat(7, (char *)2, 1, gNatNegAllocFailFmt);
        return 1;
    }

    neg->negotiateSock = socket(2, 2, 0);
    if (neg->negotiateSock == -1) {
        gsDebugFormat(7, 0, 1, gNatNegSocketFailFmt);
        RemoveNegotiator(neg);
        return 2;
    }

    neg->gameSock = gamesocket;
    neg->clientIndex = clientindex;
    neg->cookie = cookie;
    neg->progressCallback = progresscallback;
    neg->completedCallback = completedcallback;
    neg->userdata = userdata;
    neg->gotRemoteData = 0;
    neg->sendGotRemoteData = 0;
    neg->guessedIP = 0;
    neg->guessedPort = 0;
    neg->result = 5;
    neg->retryCount = 0;
    neg->maxRetryCount = 0;

    SendPreinitPacket((struct NATNegotiator *)neg);

    namelen = sizeof(saddr);
    func_0217ED0C(neg->negotiateSock, &saddr, &namelen);
    gsDebugFormat(7, 0, 8, gNatNegSocketFmt, (unsigned short)(((saddr.port >> 8) & 0xFF) | ((saddr.port << 8) & 0xFF00)));

    return 0;
}
