/*
 * file:     unit_02199D1C_p01.c
 * unit:     yes
 * function: func_02199D1C, func_02199D60, func_02199DFC, NNCancel, func_0219A034, func_0219A054, func_0219A4A4, func_0219A52C, func_0219A620, func_0219A7AC
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
 *   FindNegotiatorForCookie  0x021990D4 arm
 *   gsDebugFormat            0x0217D254 arm
 *   closesocket              0x0217EB2C arm
 *   g_021A5E2C               0x021A5E2C data
 *   g_021A5E5C               0x021A5E5C data
 *   func_02199FB4  0x02199FB4  arm  ov009
 *   func_0217EF50  0x0217EF50  arm  ov009
 *   func_0217EC60  0x0217EC60  arm  ov009
 *   func_0217ED54  0x0217ED54  arm  ov009
 *   func_0219AB8C  0x0219AB8C  arm  ov009
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_021994F0  0x021994F0  arm  ov009
 *   func_0219972C  0x0219972C  arm  ov009
 *   func_02199A90  0x02199A90  arm  ov009
 *   func_02199394  0x02199394  arm  ov009
 *   g_021A5E88     0x021A5E88  data
 *   g_021A5EAC     0x021A5EAC  data
 *   g_021AE7A0     0x021AE7A0  data
 *   g_021A5EE8     0x021A5EE8  data
 *   g_021A5F1C     0x021A5F1C  data
 *   g_021A5F5C     0x021A5F5C  data
 *   g_021A5FA0     0x021A5FA0  data
 *   g_021A5FE8     0x021A5FE8  data
 *   g_021A6028     0x021A6028  data
 *   g_021A606C     0x021A606C  data
 *   g_021A60B8     0x021A60B8  data
 *   g_021A60FC     0x021A60FC  data
 *   g_021A6150     0x021A6150  data
 *   g_021A61A0     0x021A61A0  data
 *   func_02199BE4  0x02199BE4  arm  ov009
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   g_021A5A70  0x021A5A70  data
 *   SendPacket     0x021992A8  arm  ov009
 *   g_021A5A7C     0x021A5A7C  data
 *   g_021A61E8     0x021A61E8  data
 *   func_0215FA9C  0x0215FA9C  arm   ov009
 *   g_021A621C     0x021A621C  data
 *   g_021A6274     0x021A6274  data
 *   g_021A62CC     0x021A62CC  data
 *   g_021A6300     0x021A6300  data
 *   g_021A6330     0x021A6330  data
 *   g_021A6384     0x021A6384  data
 *   g_021A63D8     0x021A63D8  data
 *   g_021A640C     0x021A640C  data
 */
#include "../../matched/include/G_NatSocks.h"
#include "../../matched/include/G_Magic6.h"

#define NN_SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | (((x) << 24) & 0xFF000000))
#define NN_SWAP16(x) ((u16)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))
#define NN_NTOHS(x) ((unsigned short)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))
typedef struct NAT {
    char pad0[0x8C];
    int natType;
    int mappingScheme;
    char pad1[0x44];
} NAT;

typedef struct NatnegGlobals {
    void *negotiateList;                             /* 0x00 */
    char *natneg3Override;                           /* 0x04 */
    int natMappingScheme;                            /* 0x08 */
    void (*natifyCallback)(int success, NAT nat);    /* 0x0C */
    unsigned int natifyStartTime;                    /* 0x10 */
    int pad14;                                       /* 0x14 */
    char *natneg2Override;                           /* 0x18 */
    char *natneg1Override;                           /* 0x1C */
    int natifyActive;                                /* 0x20 */
    unsigned int natneg3IP;                          /* 0x24 */
    unsigned int natneg2IP;                          /* 0x28 */
    unsigned int natneg1IP;                          /* 0x2C */
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
    int socket;                                      /* 0x48 */
    SOCSockAddrIn remoteaddr;                        /* 0x4C */
} NATNegotiator;

typedef unsigned char u8;

typedef enum NegotiateState {
    ns_preinitsent, ns_preinitack, ns_initsent, ns_initack, ns_connectping,
    ns_finished, ns_canceled, ns_reportsent, ns_reportack
} NegotiateState;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Magic6 Magic6;

typedef struct NatNegPacket_0219A034
{
    Magic6 magic;
    u8 version;
    u8 packettype;
    int cookie;
    u8 clientindex;
    u8 porttype;
    u8 pad[0x3E];
} NatNegPacket_0219A034;

typedef struct _NatNegPacket {
    unsigned char magic[6];                          /* 0x00 */
    unsigned char version;                           /* 0x06 */
    unsigned char packettype;                        /* 0x07 */
    int cookie;                                      /* 0x08 */
    unsigned int ipaddr;                             /* 0x0C */
    unsigned short port;                             /* 0x10 */
    unsigned char gotyourdata;                       /* 0x12 */
    unsigned char finished;                          /* 0x13 */
} NatNegPacket_0219A620;

extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);
extern unsigned int func_02199CE8(char *name);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern NATNegotiator *func_02199138(void);
extern int func_0217EB18(int pf, int type, int protocol);
extern void func_021991C8(NATNegotiator *neg);
extern void func_021995E4(NATNegotiator *neg);
extern int func_0217ED0C(int sock, void *addr, int *len);
extern NATNegotiator * FindNegotiatorForCookie(int cookie);
extern int gsDebugFormat(int theCat, int theType, unsigned char theLevel, char *theTokenStr, ...);
extern int closesocket(int sock);
extern void func_02199FB4(int v);
extern int func_0217EF50(int sock);
extern int func_0217EC60(int sock, char *buf, int len, int flags, SOCSockAddrIn *addr, int *fromlen);
extern int func_0217ED54(int sock);
extern void func_0219AB8C(char *data, int len, SOCSockAddrIn *fromaddr);
extern unsigned long func_0217F264(void);
extern void func_021994F0(NATNegotiator *neg, int result, int socket, SOCSockAddrIn *remoteaddr);
extern void func_0219972C(NATNegotiator *neg);
extern void func_02199A90(NATNegotiator *neg);
extern void func_02199394(NATNegotiator *neg);
extern int func_02199BE4(int sock);
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern void SendPacket();
extern char *func_0215FA9C(unsigned int in);
unsigned int func_02199D1C(char *overrideHostname, char *defaultHostname);
int func_02199D60(void);
int func_02199DFC(int gamesocket, int cookie, int clientindex, void (*progresscallback)(int, void *), void (*completedcallback)(int, int, SOCSockAddrIn *, void *), void *userdata);
void NNCancel(int cookie);
void func_0219A034(int *p);
void func_0219A054(NATNegotiator *neg);
void func_0219A4A4(void *p);
void func_0219A52C(NATNegotiator *neg, SOCSockAddrIn *toaddr);
void func_0219A620(NATNegotiator *neg, NatNegPacket_0219A620 *p, SOCSockAddrIn *fromaddr);
void func_0219A7AC(NATNegotiator *neg, NatNegPacket_0219A620 *p, SOCSockAddrIn *fromaddr);
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
extern char g_021A5E2C[];
extern char g_021A5E5C[];
extern char g_021A5E88[];
extern char g_021A5EAC[];
extern char g_021AE7A0[];
extern char g_021A5EE8[];
extern char g_021A5F1C[];
extern char g_021A5F5C[];
extern char g_021A5FA0[];
extern char g_021A5FE8[];
extern char g_021A6028[];
extern char g_021A606C[];
extern char g_021A60B8[];
extern char g_021A60FC[];
extern char g_021A6150[];
extern char g_021A61A0[];
extern struct NatSocks g_021A5A70;
extern struct Magic6 g_021A5A7C;
extern char g_021A61E8[];
extern char g_021A621C[];
extern char g_021A6274[];
extern char g_021A62CC[];
extern char g_021A6300[];
extern char g_021A6330[];
extern char g_021A6384[];
extern char g_021A63D8[];
extern char g_021A640C[];




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

    func_021995E4((NATNegotiator *)neg);

    namelen = sizeof(saddr);
    func_0217ED0C(neg->negotiateSock, &saddr, &namelen);
    func_0217D254(7, 0, 8, g_021A5E14, (unsigned short)(((saddr.port >> 8) & 0xFF) | ((saddr.port << 8) & 0xFF00)));

    return 0;
}



void NNCancel(int cookie)
{
    NATNegotiator *neg = FindNegotiatorForCookie(cookie);

    if (neg == 0) {
        gsDebugFormat(7, 4, 4, g_021A5E2C, cookie);
        return;
    }
    gsDebugFormat(7, 4, 8, g_021A5E5C, cookie);
    if (neg->negotiateSock != -1) {
        closesocket(neg->negotiateSock);
        neg->negotiateSock = -1;
    }
    neg->state = 6;
}






/*
 * Marks the record spent and tail calls on its second word.
 */
void func_0219A034(int *p)
{
    if (p[0] == -1) {
        p[6] = -1;
    }

    func_02199FB4(p[1]);
}






/*
 * sdk:      NegotiateThink (libdwcgsnatneg.TWL.HYB.a natneg.o)
 *
 * State enum is compared unsigned in the two range tests (bhi), so those
 * two reads are cast to unsigned int. The receive loop is a do/while with
 * the socket test at the bottom, inside an outer socket test.
 */
void func_0219A054(NATNegotiator *neg)
{
    SOCSockAddrIn saddr;
    int saddrlen = sizeof(SOCSockAddrIn);
    int error;

    if (neg == 0) {
        func_0217D254(7, (char *)4, 4, g_021A5E88);
        return;
    }

    if (neg->state == ns_canceled) {
        func_0217D254(7, (char *)2, 8, g_021A5EAC, neg->cookie);
        func_021991C8(neg);
        return;
    }

    if (neg->negotiateSock != -1) {
        do {
            if (!func_0217EF50(neg->negotiateSock))
                break;
            error = func_0217EC60(neg->negotiateSock, g_021AE7A0, 512, 0, &saddr, &saddrlen);
            if (error == -1) {
                func_0217D254(7, 0, 8, g_021A5EE8, neg->cookie, func_0217ED54(neg->negotiateSock));
                break;
            }
            func_0219AB8C(g_021AE7A0, error, &saddr);
            if (neg->state == ns_canceled)
                break;
        } while (neg->negotiateSock != -1);
    }

    if ((neg->state == ns_preinitsent || neg->state == ns_preinitack || neg->state == ns_initsent ||
         neg->state == ns_connectping) && func_0217F264() > neg->retryTime) {
        if (neg->retryCount > neg->maxRetryCount) {
            func_0217D254(7, 0, 8, g_021A5F1C, neg->cookie);
            if ((unsigned int)neg->state <= ns_initsent)
                func_021994F0(neg, 2, -1, 0);
            else
                func_021994F0(neg, 3, -1, 0);
        } else {
            neg->retryCount++;
            func_0217D254(7, 0, 8, g_021A5F5C, neg->cookie, neg->retryCount);
            if ((unsigned int)neg->state <= ns_preinitack)
                func_021995E4((NATNegotiator *)neg);
            else if (neg->state == ns_initsent)
                func_0219972C(neg);
            else
                func_02199A90((NATNegotiator *)neg);
        }
    }

    if (neg->state == ns_initack && func_0217F264() > neg->retryTime) {
        func_0217D254(7, 0, 8, g_021A5FA0, neg->cookie);
        func_021994F0(neg, 1, -1, 0);
    }

    if (neg->state == ns_connectping && func_0217F264() > neg->retryTime) {
        if (neg->retryCount > neg->maxRetryCount) {
            func_0217D254(7, 0, 8, g_021A5FE8, neg->cookie);
            func_021994F0(neg, 3, -1, 0);
        } else {
            neg->retryCount++;
            func_0217D254(7, 0, 8, g_021A6028, neg->cookie, neg->retryCount);
            func_02199A90((NATNegotiator *)neg);
            neg->retryTime = func_0217F264() + 700;
        }
    }

    if (neg->state == ns_reportsent && func_0217F264() > neg->retryTime) {
        if (neg->retryCount > neg->maxRetryCount) {
            func_0217D254(7, (char *)3, 8, g_021A606C, neg->cookie);
            neg->state = ns_finished;
        } else {
            func_02199394((NATNegotiator *)neg);
            neg->retryCount++;
            func_0217D254(7, 0, 8, g_021A60B8, neg->cookie, neg->retryCount);
            neg->retryTime = func_0217F264() + 500;
        }
    }

    if (neg->state == ns_finished || neg->state == ns_reportack) {
        if (neg->sendGotRemoteData)
            func_0217D254(7, (char *)3, 8, g_021A60FC, neg->cookie);
        else if (func_0217F264() > neg->retryTime)
            func_0217D254(7, (char *)3, 8, g_021A6150, neg->cookie);
        func_0219A034((int *)neg);
    }

    if (neg->state == ns_canceled) {
        func_0217D254(7, (char *)2, 8, g_021A61A0, neg->cookie);
        func_021991C8(neg);
    }
}





/*
 * sdk:      NNThink (natneg.o)
 */
void func_0219A4A4(void *p)
{
    int i;

    if (g_021AE698.natifyActive)
        g_021AE698.natifyActive = func_02199BE4(g_021A5A70.mappingSock) && func_02199BE4(g_021A5A70.ertSock);
    if (!g_021AE698.negotiateList)
        return;
    for (i = func_02184200(g_021AE698.negotiateList) - 1; i >= 0; i--)
        func_0219A054(func_02184208(g_021AE698.negotiateList, i));
}




/*
 * sdk:      SendConnectAck (libdwcgsnatneg.TWL.HYB.a(natneg.o))
 *
 * Builds a NATNEG connect-ack packet (6-byte magic block copy, version 4,
 * packettype 6, byte-swapped cookie and porttype) and sends it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_0219A52C.c \
 *       --func func_0219A52C --addr 0x0219A52C --region ov009 --arm --cc 1.1p1 --lang c99
 */
void func_0219A52C(NATNegotiator *neg, SOCSockAddrIn *toaddr)
{
    NatNegPacket_0219A034 p;

    {
        u8 *m = (u8 *)&g_021A5A7C;
        u8 *d = (u8 *)&p;
        d[0] = m[0];
        d[1] = m[1];
        d[2] = m[2];
        d[3] = m[3];
        d[4] = m[4];
        d[5] = m[5];
    }
    p.version = 4;
    p.packettype = 6;
    p.cookie = NN_SWAP32((u32)neg->cookie);
    p.porttype = neg->clientIndex;
    gsDebugFormat(7, 0, 8, g_021A61E8, neg->cookie);
    SendPacket(neg->negotiateSock, toaddr->addr, NN_SWAP16(toaddr->port), &p, 0x15);
}




/*
 * sdk:      ProcessConnectPacket (libdwcgsnatneg.TWL.HYB.a natneg.o)
 */
void func_0219A620(NATNegotiator *neg, NatNegPacket_0219A620 *p, SOCSockAddrIn *fromaddr)
{
    int errcode;

    func_0217D254(7, 0, 8, g_021A621C, neg->cookie, p->finished, func_0215FA9C(p->ipaddr), NN_NTOHS(p->port));

    if (p->finished == 0)
        func_0219A52C((NATNegotiator *)neg, fromaddr);

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
    func_02199A90((NATNegotiator *)neg);
}




/*
 * sdk:      ProcessPingPacket (libdwcgsnatneg.TWL.HYB.a natneg.o)
 */
void func_0219A7AC(NATNegotiator *neg, NatNegPacket_0219A620 *p, SOCSockAddrIn *fromaddr)
{
    func_0217D254(7, 0, 8, g_021A6330, neg->cookie, func_0215FA9C(fromaddr->addr),
                  NN_NTOHS(fromaddr->port), p->gotyourdata, p->finished);

    if (neg->state < 4) {
        func_0217D254(7, 0, 8, g_021A6384, neg->cookie);
        return;
    }

    func_0217D254(7, 0, 8, g_021A63D8, func_0215FA9C(fromaddr->addr), NN_NTOHS(fromaddr->port),
                  p->gotyourdata, p->finished);

    neg->guessedIP = fromaddr->addr;
    neg->guessedPort = NN_NTOHS(fromaddr->port);
    neg->gotRemoteData = 1;
    neg->sendGotRemoteData = p->gotyourdata ? 1 : 0;

    func_02199A90((NATNegotiator *)neg);

    if (neg->state == 4 && neg->sendGotRemoteData) {
        func_0217D254(7, 0, 8, g_021A640C, neg->cookie);
        func_021994F0(neg, 0, neg->gameSock == -1 ? neg->negotiateSock : neg->gameSock, fromaddr);
    }
}
