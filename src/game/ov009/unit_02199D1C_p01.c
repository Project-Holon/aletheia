/*
 * file:     unit_02199D1C_p01.c
 * unit:     yes
 * function: func_02199D1C, func_02199D60, func_02199DFC
 * address:  0x02199D1C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02084F80  0x02084F80  arm
 *   func_02199CE8  0x02199CE8  arm  ov009
 *   g_021A5CA8  0x021A5CA8  data
 *   g_021ACEFC  0x021ACEFC  data
 *   g_021AE698  0x021AE698  data
 *   g_021A5CB0  0x021A5CB0  data
 *   g_021A5CCC  0x021A5CCC  data
 *   g_021A5CE8  0x021A5CE8  data
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_02199138  0x02199138  arm  ov009
 *   func_0217EB18  0x0217EB18  arm  ov009
 *   func_021991C8  0x021991C8  arm  ov009
 *   func_021995E4  0x021995E4  arm  ov009
 *   func_0217ED0C  0x0217ED0C  arm  ov009
 *   g_021ACEF8     0x021ACEF8  data
 *   g_021A5D04     0x021A5D04  data
 *   g_021A5D44     0x021A5D44  data
 *   g_021A5D90     0x021A5D90  data
 *   g_021A5DD0     0x021A5DD0  data
 *   g_021A5E14     0x021A5E14  data
 */
struct NATNegotiator;
typedef struct {
    int pad0;
    char *natneg3Override;
    int pad8[4];
    char *natneg2Override;
    char *natneg1Override;
    int pad20;
    int natneg3IP;
    int natneg2IP;
    int natneg1IP;
} NatnegGlobals;

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

extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);
extern unsigned int func_02199CE8(char *name);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern NATNegotiator *func_02199138(void);
extern int func_0217EB18(int pf, int type, int protocol);
extern void func_021991C8(NATNegotiator *neg);
extern void func_021995E4(struct NATNegotiator *neg);
extern int func_0217ED0C(int sock, void *addr, int *len);
unsigned int func_02199D1C(char *overrideHostname, char *defaultHostname);
int func_02199D60(void);
int func_02199DFC(int gamesocket, int cookie, int clientindex, void (*progresscallback)(int, void *), void (*completedcallback)(int, int, SOCSockAddrIn *, void *), void *userdata);
extern char g_021A5CA8[];
extern char g_021ACEFC[];
extern NatnegGlobals g_021AE698;
extern char g_021A5CB0[];
extern char g_021A5CCC[];
extern char g_021A5CE8[];
extern int g_021ACEF8;
extern char g_021A5D04[];
extern char g_021A5D44[];
extern char g_021A5D90[];
extern char g_021A5DD0[];
extern char g_021A5E14[];


/*
 * sdk:      ResolveServer (natify.o)
 */
unsigned int func_02199D1C(char *overrideHostname, char *defaultHostname)
{
    char hostnameBuffer[64];
    char *hostname;

    hostname = overrideHostname;
    if (!hostname) {
        hostname = hostnameBuffer;
        func_02084F80(hostname, 64, g_021A5CA8, g_021ACEFC, defaultHostname);
    }
    return func_02199CE8(hostname);
}


/*
 * sdk:      ResolveServers (natneg.o)
 */
int func_02199D60(void)
{
    if (!g_021AE698.natneg1IP)
        g_021AE698.natneg1IP = func_02199D1C(g_021AE698.natneg1Override, g_021A5CB0);
    if (!g_021AE698.natneg2IP)
        g_021AE698.natneg2IP = func_02199D1C(g_021AE698.natneg2Override, g_021A5CCC);
    if (!g_021AE698.natneg3IP)
        g_021AE698.natneg3IP = func_02199D1C(g_021AE698.natneg3Override, g_021A5CE8);
    if (g_021AE698.natneg1IP == 0 || g_021AE698.natneg2IP == 0 || g_021AE698.natneg3IP == 0)
        return 0;
    return 1;
}


/*
 * sdk:      NNBeginNegotiationWithSocket (libdwcgsnatneg.TWL.HYB.a natneg.o)
 */
int func_02199DFC(int gamesocket, int cookie, int clientindex,
                  void (*progresscallback)(int, void *),
                  void (*completedcallback)(int, int, SOCSockAddrIn *, void *), void *userdata)
{
    NATNegotiator *neg;
    SOCSockAddrIn saddr;
    int namelen;

    if (g_021ACEF8 != 1) {
        func_0217D254(7, 0, 4, g_021A5D04, cookie);
        return 2;
    }

    if (!func_02199D60()) {
        func_0217D254(7, 0, 4, g_021A5D44, cookie);
        return 3;
    }

    neg = func_02199138();
    if (neg == 0) {
        func_0217D254(7, (char *)2, 1, g_021A5D90);
        return 1;
    }

    neg->negotiateSock = func_0217EB18(2, 2, 0);
    if (neg->negotiateSock == -1) {
        func_0217D254(7, 0, 1, g_021A5DD0);
        func_021991C8(neg);
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

    func_021995E4((struct NATNegotiator *)neg);

    namelen = sizeof(saddr);
    func_0217ED0C(neg->negotiateSock, &saddr, &namelen);
    func_0217D254(7, 0, 8, g_021A5E14, (unsigned short)(((saddr.port >> 8) & 0xFF) | ((saddr.port << 8) & 0xFF00)));

    return 0;
}
