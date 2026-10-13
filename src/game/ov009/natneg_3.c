/*
 * file:     natneg_3.c
 * unit:     yes
 * function: func_02199394, func_021994F0, func_021995E4, func_0219972C, func_02199A90, func_02199BE4
 * address:  0x02199394
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
 *   strlen         0x0209477C  arm
 *   memcpy         0x02092344  arm
 *   func_02094798  0x02094798  arm
 *   SOC_InetNtoA   0x0215FA9C  arm  ov009
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   SendPacket     0x021992A8  arm  ov009
 *   current_time   0x0217F264  arm  ov009
 *   GetClientUniqueID  0x021990A0  arm  ov009
 *   func_021992FC  0x021992FC  arm  ov009
 *   func_02199360  0x02199360  arm  ov009
 *   func_02199FB4  0x02199FB4  arm  ov009
 *   NatifyThink        0x02198E74  arm  ov009
 *   DetermineNatType   0x02198E80  arm  ov009
 *   closesocket        0x0217EB2C  arm  ov009
 *   g_021A5A7C     0x021A5A7C  data
 *   g_021ACEFC     0x021ACEFC  data
 *   g_021A5A70     0x021A5A70  data
 *   g_021AE698     0x021AE698  data
 *   g_021AE6C4     0x021AE6C4  data
 *   g_021AE6C0     0x021AE6C0  data
 *   g_021AE6BC     0x021AE6BC  data
 *   g_021AE6C8     0x021AE6C8  data
 *   g_021A5AB4     0x021A5AB4  data
 *   g_021A5AF8     0x021A5AF8  data
 *   g_021A5B30     0x021A5B30  data
 *   g_021A5B70     0x021A5B70  data
 *   g_021A5B8C     0x021A5B8C  data
 *   g_021A5BAC     0x021A5BAC  data
 *   g_021A5BE8     0x021A5BE8  data
 *   g_021A5C24     0x021A5C24  data
 *   g_021A5C60     0x021A5C60  data
 */
#include "../../matched/include/G_Magic6.h"
#include "../../matched/arm9_sdk/libc/string.h"
#include "../../matched/include/G_NatSocks.h"

#define NN_SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | (((x) << 24) & 0xFF000000))
#define NN_HTONS(x) ((unsigned short)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))
#define NN_SWAP16(x) ((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00))
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

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

typedef struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned char port[2];
    unsigned char addr[4];
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

typedef struct NatSocks NatSocks;

extern int GetClientUniqueID();
extern char *SOC_InetNtoA(unsigned int in);
extern void gsDebugFormat(int theCat, int theType, unsigned char theLevel, const char *theTokenStr, ...);
extern void SendPacket(int sock, unsigned int toaddr, unsigned short toport, void *data, int len);
extern u32 current_time(void);
extern unsigned int func_021992FC(void);
extern char *func_02094798(char *dst, const char *src);
extern unsigned short func_02199360(int sock);
extern void func_02199FB4(int cookie);
extern int NatifyThink();
extern int DetermineNatType();
extern int closesocket();
void func_02199394(NATNegotiator *neg);
void func_021994F0(NATNegotiator *neg, int result, int socket, SOCSockAddrIn *remoteaddr);
void func_021995E4(NATNegotiator *neg);
void func_0219972C(NATNegotiator *neg);
void func_02199A90(NATNegotiator *neg);
int func_02199BE4(int sock);
extern struct Magic6 g_021A5A7C;
extern char g_021ACEFC[];
extern struct NatSocks g_021A5A70;
extern NatnegGlobals g_021AE698;
extern u32 g_021AE6C4;
extern unsigned int g_021AE6C0;
extern unsigned int g_021AE6BC;
extern NAT g_021AE6C8;
extern char g_021A5AB4[];
extern char g_021A5AF8[];
extern char g_021A5B30[];
extern char g_021A5B70[];
extern char g_021A5B8C[];
extern char g_021A5BAC[];
extern char g_021A5BE8[];
extern char g_021A5C24[];
extern char g_021A5C60[];


void func_02199394(NATNegotiator *neg)
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
    p.packettype = 13;
    p.cookie = NN_SWAP32((u32)neg->cookie);
    p.u.report.clientindex = (u8)neg->clientIndex;
    p.u.report.negResult = neg->result == 0 ? 1 : 0;
    p.u.report.natType = g_021A5A70.natType;
    p.u.report.mappingScheme = g_021AE698.natMappingScheme;
    if (strlen(g_021ACEFC))
        memcpy(p.u.report.gamename, g_021ACEFC, 0x32);
    gsDebugFormat(7, 0, 8, g_021A5AB4, neg->cookie, SOC_InetNtoA(g_021AE6C4), 27901, p.u.report.negResult);
    SendPacket(neg->negotiateSock, g_021AE698.natneg1IP, 27901, &p, 0x49);
}


void func_021994F0(NATNegotiator *neg, int result, int socket, SOCSockAddrIn *remoteaddr)
{
    neg->result = result;
    neg->socket = socket;
    if (remoteaddr)
        neg->remoteaddr = *remoteaddr;
    if (result == 1 || result == 2) {
        gsDebugFormat(7, 3, 8, g_021A5AF8, neg->cookie);
        neg->state = 5;
        neg->completedCallback(neg->result, neg->socket, &neg->remoteaddr, neg->userdata);
        func_02199FB4(neg->cookie);
    } else {
        gsDebugFormat(7, 3, 8, g_021A5B30, neg->cookie);
        func_02199394((NATNegotiator *)neg);
        neg->state = 7;
        neg->retryTime = current_time() + 500;
        neg->retryCount = 0;
        neg->maxRetryCount = 4;
        neg->completedCallback(neg->result, neg->socket, &neg->remoteaddr, neg->userdata);
    }
}


/*
 * sdk:      SendPreinitPacket (libdwcgsnatneg.TWL.HYB.a(natneg.o))
 */
void func_021995E4(NATNegotiator *neg)
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
    p.packettype = 15;
    p.cookie = NN_SWAP32((u32)neg->cookie);
    p.u.preinit.clientindex = (u8)neg->clientIndex;
    p.u.preinit.clientUniqueID = GetClientUniqueID();
    gsDebugFormat(7, 0, 8, g_021A5B70, SOC_InetNtoA(g_021AE6C4), 27901);
    SendPacket(neg->negotiateSock, g_021AE698.natneg1IP, 27901, &p, 0x12);
    if (neg->state == 1)
    {
        neg->retryTime = current_time() + 10000;
        neg->maxRetryCount = 12;
    }
    else
    {
        neg->retryTime = current_time() + 500;
        neg->maxRetryCount = 10;
        neg->state = 0;
    }
}



/*
 * sdk:      SendInitPackets (libdwcgsnatneg.TWL.HYB.a natneg.o)
 *
 * localip, localport and gamename are written through buffer, not p: the
 * object addresses them from sp (buffer + 0x0F, + 0x13, + 0x15) while every
 * other field goes through p in r6, and it stores localip and localport one
 * byte at a time, most significant byte first.  The swap macros evaluate
 * their argument once per term, so GetLocalIP runs four times and
 * GetLocalPort twice, as in the object.
 */
void func_0219972C(NATNegotiator *neg)
{
    char buffer[85];
    NatNegPacket *p;
    unsigned int localip;
    unsigned short localport;
    int packetlen;

    p = (NatNegPacket *)buffer;
    memcpy(p->magic, ((unsigned char *)&g_021A5A7C), 6);
    p->version = 4;
    p->packettype = 0;
    p->cookie = NN_SWAP32((unsigned int)neg->cookie);
    p->u.init.clientindex = neg->clientIndex;
    p->u.init.usegameport = (neg->gameSock == -1) ? 0 : 1;
    localip = NN_SWAP32(func_021992FC());
    buffer[15] = (unsigned char)(localip >> 24);
    buffer[16] = (unsigned char)(localip >> 16);
    buffer[17] = (unsigned char)(localip >> 8);
    buffer[18] = (unsigned char)localip;
    buffer[19] = 0;
    buffer[20] = 0;
    func_02094798(buffer + 21, g_021ACEFC);
    packetlen = strlen(g_021ACEFC) + 22;

    if (p->u.init.usegameport && !neg->initAckRecv[0]) {
        p->u.init.porttype = 0;
        gsDebugFormat(7, 0, 8, g_021A5B8C, SOC_InetNtoA(g_021AE6C4), 27901);
        SendPacket(neg->gameSock, g_021AE698.natneg1IP, 27901, p, packetlen);
    }

    if (!neg->initAckRecv[1]) {
        p->u.init.porttype = 1;
        gsDebugFormat(7, 0, 8, g_021A5BAC, neg->cookie, SOC_InetNtoA(g_021AE6C4), 27901);
        SendPacket(neg->negotiateSock, g_021AE698.natneg1IP, 27901, p, packetlen);
    }

    localport = NN_HTONS(func_02199360(p->u.init.usegameport ? neg->gameSock : neg->negotiateSock));
    buffer[19] = (unsigned char)(localport >> 8);
    buffer[20] = (unsigned char)localport;

    if (!neg->initAckRecv[2]) {
        p->u.init.porttype = 2;
        gsDebugFormat(7, 0, 8, g_021A5BE8, neg->cookie, SOC_InetNtoA(g_021AE6C0), 27901);
        SendPacket(neg->negotiateSock, g_021AE698.natneg2IP, 27901, p, packetlen);
    }

    if (!neg->initAckRecv[3]) {
        p->u.init.porttype = 3;
        gsDebugFormat(7, 0, 8, g_021A5C24, neg->cookie, SOC_InetNtoA(g_021AE6BC), 27901);
        SendPacket(neg->negotiateSock, g_021AE698.natneg3IP, 27901, p, packetlen);
    }

    neg->state = 2;
    neg->retryTime = current_time() + 500;
    neg->maxRetryCount = 10;
}



/*
 * sdk:      SendPingPacket (libdwcgsnatneg.TWL.HYB.a(natneg.o))
 */
void func_02199A90(NATNegotiator *neg)
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
    p.packettype = 7;
    p.cookie = NN_SWAP32((u32)neg->cookie);
    p.u.connect.ipaddr = neg->guessedIP;
    p.u.connect.port = NN_SWAP16(neg->guessedPort);
    p.u.connect.gotyourdata = neg->gotRemoteData;
    p.u.connect.finished = (neg->gotRemoteData && neg->sendGotRemoteData) ? 1 : 0;
    gsDebugFormat(7, 0, 8, g_021A5C60, neg->cookie, SOC_InetNtoA(neg->guessedIP), neg->guessedPort, neg->gotRemoteData);
    SendPacket(neg->gameSock == -1 ? neg->negotiateSock : neg->gameSock, neg->guessedIP, neg->guessedPort, &p, 0x14);
    neg->retryTime = current_time() + 700;
    neg->maxRetryCount = 7;
}



/*
 * sdk:      CheckNatifyStatus (libdwcgsnatneg.TWL.HYB.a(natneg.o))
 */
int func_02199BE4(int sock)
{
    int active = 1;
    int success;

    if (sock != -1)
    {
        if (current_time() - g_021AE698.natifyStartTime < 10000)
            active = NatifyThink(sock, &g_021AE6C8);
        else
            active = 0;
        if (active)
            goto done;
        success = DetermineNatType(&g_021AE6C8);
        g_021AE698.natifyCallback(success, g_021AE6C8);
        g_021A5A70.natType = g_021AE6C8.natType;
        g_021AE698.natMappingScheme = g_021AE6C8.mappingScheme;
        if (g_021A5A70.mappingSock != -1)
        {
            closesocket();
            g_021A5A70.mappingSock = -1;
        }
        if (g_021A5A70.ertSock != -1)
        {
            closesocket();
            g_021A5A70.ertSock = -1;
        }
    }
done:
    return active;
}
