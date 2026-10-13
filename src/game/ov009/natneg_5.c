/*
 * file:     natneg_5.c
 * unit:     yes
 * function: func_02199D1C, func_02199D60, func_02199DFC, NNCancel, func_0219A034, func_0219A054, func_0219A4A4, func_0219A52C, func_0219A620, func_0219A7AC, func_0219A968, func_0219AA08, func_0219AB8C
 * address:  0x02199D1C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02084F80            0x02084F80  arm
 *   func_02199CE8            0x02199CE8  arm ov009
 *   g_021A5CA8               0x021A5CA8  data
 *   g_021ACEFC               0x021ACEFC  data
 *   g_021AE698               0x021AE698  data
 *   g_021A5CB0               0x021A5CB0  data
 *   g_021A5CCC               0x021A5CCC  data
 *   g_021A5CE8               0x021A5CE8  data
 *   gsDebugFormat            0x0217D254  arm ov009
 *   func_02199138            0x02199138  arm ov009
 *   func_0217EB18            0x0217EB18  arm ov009
 *   func_021991C8            0x021991C8  arm ov009
 *   func_021995E4            0x021995E4  arm ov009
 *   func_0217ED0C            0x0217ED0C  arm ov009
 *   g_021ACEF8               0x021ACEF8  data
 *   g_021A5D04               0x021A5D04  data
 *   g_021A5D44               0x021A5D44  data
 *   g_021A5D90               0x021A5D90  data
 *   g_021A5DD0               0x021A5DD0  data
 *   g_021A5E14               0x021A5E14  data
 *   FindNegotiatorForCookie  0x021990D4  arm
 *   closesocket              0x0217EB2C  arm
 *   g_021A5E2C               0x021A5E2C  data
 *   g_021A5E5C               0x021A5E5C  data
 *   func_02199FB4            0x02199FB4  arm ov009
 *   func_0217EF50            0x0217EF50  arm ov009
 *   func_0217EC60            0x0217EC60  arm ov009
 *   func_0217ED54            0x0217ED54  arm ov009
 *   func_0219AB8C            0x0219AB8C  arm ov009
 *   current_time             0x0217F264  arm ov009
 *   func_021994F0            0x021994F0  arm ov009
 *   func_0219972C            0x0219972C  arm ov009
 *   func_02199A90            0x02199A90  arm ov009
 *   func_02199394            0x02199394  arm ov009
 *   g_021A5E88               0x021A5E88  data
 *   g_021A5EAC               0x021A5EAC  data
 *   g_021AE7A0               0x021AE7A0  data
 *   g_021A5EE8               0x021A5EE8  data
 *   g_021A5F1C               0x021A5F1C  data
 *   g_021A5F5C               0x021A5F5C  data
 *   g_021A5FA0               0x021A5FA0  data
 *   g_021A5FE8               0x021A5FE8  data
 *   g_021A6028               0x021A6028  data
 *   g_021A606C               0x021A606C  data
 *   g_021A60B8               0x021A60B8  data
 *   g_021A60FC               0x021A60FC  data
 *   g_021A6150               0x021A6150  data
 *   g_021A61A0               0x021A61A0  data
 *   func_02199BE4            0x02199BE4  arm ov009
 *   func_02184200            0x02184200  arm ov009
 *   func_02184208            0x02184208  arm ov009
 *   g_021A5A70               0x021A5A70  data
 *   SendPacket               0x021992A8  arm ov009
 *   g_021A5A7C               0x021A5A7C  data
 *   g_021A61E8               0x021A61E8  data
 *   SOC_InetNtoA             0x0215FA9C  arm ov009
 *   g_021A621C               0x021A621C  data
 *   g_021A6274               0x021A6274  data
 *   g_021A62CC               0x021A62CC  data
 *   g_021A6300               0x021A6300  data
 *   g_021A6330               0x021A6330  data
 *   g_021A6384               0x021A6384  data
 *   g_021A63D8               0x021A63D8  data
 *   g_021A640C               0x021A640C  data
 *   g_021A6450               0x021A6450  data
 *   g_021A6470               0x021A6470  data
 *   g_021A648C               0x021A648C  data
 *   g_021A6498               0x021A6498  data
 *   func_02199284            0x02199284  arm ov009
 *   func_021990D4            0x021990D4  arm ov009
 *   func_0219A620            0x0219A620  arm ov009
 *   func_0219A7AC            0x0219A7AC  arm ov009
 *   g_021A64D4               0x021A64D4  data
 *   g_021A6504               0x021A6504  data
 *   g_021A6538               0x021A6538  data
 *   g_021A657C               0x021A657C  data
 *   g_021A65BC               0x021A65BC  data
 */
#include "../../matched/include/G_NatSocks.h"
#include "../../matched/include/G_Magic6.h"
#include "../../matched/arm9_sdk/libc/string.h"

#define NN_SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | (((x) << 24) & 0xFF000000))
#define NN_NTOHL(x) NN_SWAP32(x)
#define NN_SWAP16(x) ((u16)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))
#define NN_NTOHS(x) ((unsigned short)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

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

typedef enum NegotiateState {
    ns_preinitsent, ns_preinitack, ns_initsent, ns_initack, ns_connectping,
    ns_finished, ns_canceled, ns_reportsent, ns_reportack
} NegotiateState;

typedef struct Magic6 Magic6;

/* One packet, four views of the union at 0x0C. 0x4A bytes, 0x4C as a local. */
typedef struct NatNegPacket
{
    u8 magic[6];                                     /* 0x00 */
    u8 version;                                      /* 0x06 */
    u8 packettype;                                   /* 0x07 */
    int cookie;                                      /* 0x08 */
    union {
        struct {
            u8 porttype;                             /* 0x0C */
            u8 clientindex;                          /* 0x0D */
            u8 usegameport;                          /* 0x0E */
            u8 localip[4];                           /* 0x0F */
            u8 localport[2];                         /* 0x13 */
        } init;
        struct {
            u8 clientindex;                          /* 0x0C */
            u8 pad0[3];                              /* 0x0D */
            int clientUniqueID;                      /* 0x10 */
        } preinit;
        struct {
            u32 ipaddr;                              /* 0x0C */
            u16 port;                                /* 0x10 */
            u8 gotyourdata;                          /* 0x12 */
            u8 finished;                             /* 0x13 */
        } connect;
        struct {
            u8 pad0;                                 /* 0x0C */
            u8 clientindex;                          /* 0x0D */
            u8 negResult;                            /* 0x0E */
            u8 pad1;                                 /* 0x0F */
            int natType;                             /* 0x10 */
            int mappingScheme;                       /* 0x14 */
            char gamename[0x32];                     /* 0x18 */
        } report;
    } u;
} NatNegPacket;

extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);
extern unsigned int func_02199CE8(char *name);
extern void gsDebugFormat(int theCat, int theType, unsigned char theLevel, const char *theTokenStr, ...);
extern NATNegotiator *func_02199138(void);
extern int func_0217EB18(int pf, int type, int protocol);
extern void func_021991C8(NATNegotiator *neg);
extern void func_021995E4(NATNegotiator *neg);
extern int func_0217ED0C(int sock, void *addr, int *len);
extern NATNegotiator *FindNegotiatorForCookie(int cookie);
extern int closesocket(int sock);
extern void func_02199FB4(int v);
extern int func_0217EF50(int sock);
extern int func_0217EC60(int sock, char *buf, int len, int flags, SOCSockAddrIn *addr, int *fromlen);
extern int func_0217ED54(int sock);
extern unsigned long current_time(void);
extern void func_021994F0(NATNegotiator *neg, int result, int socket, SOCSockAddrIn *remoteaddr);
extern void func_0219972C(NATNegotiator *neg);
extern void func_02199A90(NATNegotiator *neg);
extern void func_02199394(NATNegotiator *neg);
extern int func_02199BE4(int sock);
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern void SendPacket(int sock, unsigned int toaddr, unsigned short toport, void *data, int len);
extern char *SOC_InetNtoA(unsigned int in);
extern int func_02199284(char *data);
extern NATNegotiator *func_021990D4(int cookie);
unsigned int func_02199D1C(char *overrideHostname, char *defaultHostname);
int func_02199D60(void);
int func_02199DFC(int gamesocket, int cookie, int clientindex, void (*progresscallback)(int, void *), void (*completedcallback)(int, int, SOCSockAddrIn *, void *), void *userdata);
void NNCancel(int cookie);
void func_0219A034(int *p);
void func_0219A054(NATNegotiator *neg);
void func_0219A4A4(void *p);
void func_0219A52C(NATNegotiator *neg, SOCSockAddrIn *toaddr);
void func_0219A620(NATNegotiator *neg, NatNegPacket *p, SOCSockAddrIn *fromaddr);
void func_0219A7AC(NATNegotiator *neg, NatNegPacket *p, SOCSockAddrIn *fromaddr);
void func_0219A968(NATNegotiator *neg, NatNegPacket *p);
void func_0219AA08(NATNegotiator *neg, NatNegPacket *p, SOCSockAddrIn *fromaddr);
void func_0219AB8C(char *data, int len, SOCSockAddrIn *fromaddr);
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
extern char g_021A6450[];
extern char g_021A6470[];
extern char g_021A648C[];
extern char g_021A6498[];
extern char g_021A64D4[];
extern char g_021A6504[];
extern char g_021A6538[];
extern char g_021A657C[];
extern char g_021A65BC[];



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
        gsDebugFormat(7, 0, 4, g_021A5D04, cookie);
        return 2;
    }

    if (!func_02199D60()) {
        gsDebugFormat(7, 0, 4, g_021A5D44, cookie);
        return 3;
    }

    neg = func_02199138();
    if (neg == 0) {
        gsDebugFormat(7, 2, 1, g_021A5D90);
        return 1;
    }

    neg->negotiateSock = func_0217EB18(2, 2, 0);
    if (neg->negotiateSock == -1) {
        gsDebugFormat(7, 0, 1, g_021A5DD0);
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
    gsDebugFormat(7, 0, 8, g_021A5E14, (unsigned short)(((saddr.port >> 8) & 0xFF) | ((saddr.port << 8) & 0xFF00)));

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
        gsDebugFormat(7, 4, 4, g_021A5E88);
        return;
    }

    if (neg->state == ns_canceled) {
        gsDebugFormat(7, 2, 8, g_021A5EAC, neg->cookie);
        func_021991C8(neg);
        return;
    }

    if (neg->negotiateSock != -1) {
        do {
            if (!func_0217EF50(neg->negotiateSock))
                break;
            error = func_0217EC60(neg->negotiateSock, g_021AE7A0, 512, 0, &saddr, &saddrlen);
            if (error == -1) {
                gsDebugFormat(7, 0, 8, g_021A5EE8, neg->cookie, func_0217ED54(neg->negotiateSock));
                break;
            }
            func_0219AB8C(g_021AE7A0, error, &saddr);
            if (neg->state == ns_canceled)
                break;
        } while (neg->negotiateSock != -1);
    }

    if ((neg->state == ns_preinitsent || neg->state == ns_preinitack || neg->state == ns_initsent ||
         neg->state == ns_connectping) && current_time() > neg->retryTime) {
        if (neg->retryCount > neg->maxRetryCount) {
            gsDebugFormat(7, 0, 8, g_021A5F1C, neg->cookie);
            if ((unsigned int)neg->state <= ns_initsent)
                func_021994F0(neg, 2, -1, 0);
            else
                func_021994F0(neg, 3, -1, 0);
        } else {
            neg->retryCount++;
            gsDebugFormat(7, 0, 8, g_021A5F5C, neg->cookie, neg->retryCount);
            if ((unsigned int)neg->state <= ns_preinitack)
                func_021995E4((NATNegotiator *)neg);
            else if (neg->state == ns_initsent)
                func_0219972C(neg);
            else
                func_02199A90((NATNegotiator *)neg);
        }
    }

    if (neg->state == ns_initack && current_time() > neg->retryTime) {
        gsDebugFormat(7, 0, 8, g_021A5FA0, neg->cookie);
        func_021994F0(neg, 1, -1, 0);
    }

    if (neg->state == ns_connectping && current_time() > neg->retryTime) {
        if (neg->retryCount > neg->maxRetryCount) {
            gsDebugFormat(7, 0, 8, g_021A5FE8, neg->cookie);
            func_021994F0(neg, 3, -1, 0);
        } else {
            neg->retryCount++;
            gsDebugFormat(7, 0, 8, g_021A6028, neg->cookie, neg->retryCount);
            func_02199A90((NATNegotiator *)neg);
            neg->retryTime = current_time() + 700;
        }
    }

    if (neg->state == ns_reportsent && current_time() > neg->retryTime) {
        if (neg->retryCount > neg->maxRetryCount) {
            gsDebugFormat(7, 3, 8, g_021A606C, neg->cookie);
            neg->state = ns_finished;
        } else {
            func_02199394((NATNegotiator *)neg);
            neg->retryCount++;
            gsDebugFormat(7, 0, 8, g_021A60B8, neg->cookie, neg->retryCount);
            neg->retryTime = current_time() + 500;
        }
    }

    if (neg->state == ns_finished || neg->state == ns_reportack) {
        if (neg->sendGotRemoteData)
            gsDebugFormat(7, 3, 8, g_021A60FC, neg->cookie);
        else if (current_time() > neg->retryTime)
            gsDebugFormat(7, 3, 8, g_021A6150, neg->cookie);
        func_0219A034((int *)neg);
    }

    if (neg->state == ns_canceled) {
        gsDebugFormat(7, 2, 8, g_021A61A0, neg->cookie);
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
    NatNegPacket p;

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
    p.u.init.clientindex = neg->clientIndex;
    gsDebugFormat(7, 0, 8, g_021A61E8, neg->cookie);
    SendPacket(neg->negotiateSock, toaddr->addr, NN_SWAP16(toaddr->port), &p, 0x15);
}




/*
 * sdk:      ProcessConnectPacket (libdwcgsnatneg.TWL.HYB.a natneg.o)
 */
void func_0219A620(NATNegotiator *neg, NatNegPacket *p, SOCSockAddrIn *fromaddr)
{
    int errcode;

    gsDebugFormat(7, 0, 8, g_021A621C, neg->cookie, p->u.connect.finished, SOC_InetNtoA(p->u.connect.ipaddr), NN_NTOHS(p->u.connect.port));

    if (p->u.connect.finished == 0)
        func_0219A52C((NATNegotiator *)neg, fromaddr);

    if (neg->state >= 4) {
        gsDebugFormat(7, 0, 8, g_021A6274, neg->cookie);
        return;
    }

    if (p->u.connect.finished != 0) {
        errcode = 4;
        if (p->u.connect.finished == 1) {
            gsDebugFormat(7, 0, 8, g_021A62CC, neg->cookie);
            errcode = 1;
        } else if (p->u.connect.finished == 2) {
            gsDebugFormat(7, 0, 8, g_021A6300, neg->cookie);
            errcode = 2;
        }
        func_021994F0(neg, errcode, -1, 0);
        return;
    }

    neg->guessedIP = p->u.connect.ipaddr;
    neg->guessedPort = NN_NTOHS(p->u.connect.port);
    neg->retryCount = 0;
    neg->state = 4;
    neg->progressCallback(4, neg->userdata);
    func_02199A90((NATNegotiator *)neg);
}




/*
 * sdk:      ProcessPingPacket (libdwcgsnatneg.TWL.HYB.a natneg.o)
 */
void func_0219A7AC(NATNegotiator *neg, NatNegPacket *p, SOCSockAddrIn *fromaddr)
{
    gsDebugFormat(7, 0, 8, g_021A6330, neg->cookie, SOC_InetNtoA(fromaddr->addr),
                  NN_NTOHS(fromaddr->port), p->u.connect.gotyourdata, p->u.connect.finished);

    if (neg->state < 4) {
        gsDebugFormat(7, 0, 8, g_021A6384, neg->cookie);
        return;
    }

    gsDebugFormat(7, 0, 8, g_021A63D8, SOC_InetNtoA(fromaddr->addr), NN_NTOHS(fromaddr->port),
                  p->u.connect.gotyourdata, p->u.connect.finished);

    neg->guessedIP = fromaddr->addr;
    neg->guessedPort = NN_NTOHS(fromaddr->port);
    neg->gotRemoteData = 1;
    neg->sendGotRemoteData = p->u.connect.gotyourdata ? 1 : 0;

    func_02199A90((NATNegotiator *)neg);

    if (neg->state == 4 && neg->sendGotRemoteData) {
        gsDebugFormat(7, 0, 8, g_021A640C, neg->cookie);
        func_021994F0(neg, 0, neg->gameSock == -1 ? neg->negotiateSock : neg->gameSock, fromaddr);
    }
}


/*
 * sdk:      ProcessPreinitAckPacket (natneg.o)
 */
void func_0219A968(NATNegotiator *neg, NatNegPacket *p)
{
    gsDebugFormat(7, 0, 8, g_021A6450, p->u.init.clientindex);
    if (neg->state != 1) {
        neg->state = 1;
        neg->progressCallback(1, neg->userdata);
        neg->retryTime = current_time() + 10000;
        neg->retryCount = 0;
        neg->maxRetryCount = 12;
    }
    switch (p->u.init.clientindex) {
    case 0:
    case 1:
        return;
    case 2:
        func_0219972C(neg);
        break;
    }
}



void func_0219AA08(NATNegotiator *neg, NatNegPacket *p, SOCSockAddrIn *fromaddr)
{
    switch (p->packettype)
    {
    case 1:
        if (p->u.init.porttype > 3)
            return;
        gsDebugFormat(7, 0, 8, g_021A6470, p->u.init.porttype);
        neg->initAckRecv[p->u.init.porttype] = 1;
        if (neg->state != 2)
            return;
        if (!neg->initAckRecv[1] || !neg->initAckRecv[2] || !neg->initAckRecv[3])
            return;
        if (neg->gameSock != -1)
        {
            if (!neg->initAckRecv[0])
                return;
        }
        neg->state = 3;
        neg->retryTime = current_time() + 60000;
        neg->progressCallback(neg->state, neg->userdata);
        break;
    case 2:
        gsDebugFormat(7, 0, 8, g_021A648C);
        p->packettype = 3;
        SendPacket(neg->negotiateSock, fromaddr->addr, (u16)NN_SWAP16(fromaddr->port), p, 0x15);
        break;
    case 14:
        gsDebugFormat(7, 0, 8, g_021A6498, neg->cookie);
        neg->state = 8;
        break;
    }
}



void func_0219AB8C(char *data, int len, SOCSockAddrIn *fromaddr)
{
    NatNegPacket p;
    NATNegotiator *neg;
    unsigned char ptype;

    if (!func_02199284(data)) {
        gsDebugFormat(7, 0, 4, g_021A64D4);
        return;
    }

    ptype = ((NatNegPacket *)data)->packettype;
    gsDebugFormat(7, 0, 8, g_021A6504, ptype, len, SOC_InetNtoA(fromaddr->addr), NN_NTOHS(fromaddr->port));

    if (ptype == 5 || ptype == 7) {
        if (len < 20) {
            gsDebugFormat(7, 0, 4, g_021A6538);
            return;
        }
        memcpy(&p, data, 20);
        neg = func_021990D4(NN_NTOHL((unsigned int)p.cookie));
        if (neg == 0) {
            gsDebugFormat(7, 0, 4, g_021A657C, NN_NTOHL((unsigned int)p.cookie));
            return;
        }
        if (ptype == 5)
            func_0219A620(neg, &p, fromaddr);
        else
            func_0219A7AC(neg, &p, fromaddr);
    } else if (ptype == 16) {
        if (len < 18)
            return;
        memcpy(&p, data, 18);
        neg = func_021990D4(NN_NTOHL((unsigned int)p.cookie));
        if (neg == 0)
            return;
        func_0219A968(neg, (NatNegPacket *)&p);
    } else {
        if (len < 21) {
            gsDebugFormat(7, 0, 4, g_021A65BC);
            return;
        }
        memcpy(&p, data, 21);
        neg = func_021990D4(NN_NTOHL((unsigned int)p.cookie));
        if (neg == 0) {
            gsDebugFormat(7, 0, 4, g_021A657C, NN_NTOHL((unsigned int)p.cookie));
            return;
        }
        func_0219AA08(neg, &p, fromaddr);
    }
}
