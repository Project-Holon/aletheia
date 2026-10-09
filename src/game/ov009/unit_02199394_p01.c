/*
 * file:     unit_02199394_p01.c
 * unit:     yes
 * function: func_02199394, func_021994F0
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
 *   SOC_InetNtoA   0x0215FA9C  arm  ov009
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   SendPacket     0x021992A8  arm  ov009
 *   g_021A5A7C     0x021A5A7C  data
 *   g_021ACEFC     0x021ACEFC  data
 *   g_021A5A70     0x021A5A70  data
 *   g_021AE698     0x021AE698  data
 *   g_021AE6C4     0x021AE6C4  data
 *   g_021A5AB4     0x021A5AB4  data
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_02199FB4  0x02199FB4  arm  ov009
 *   func_0217F264  0x0217F264  arm  ov009
 *   g_021A5AF8  0x021A5AF8  data
 *   g_021A5B30  0x021A5B30  data
 */
#include "../../matched/include/G_Magic6.h"
#include "../../matched/include/G_NatSocks.h"

#define NN_SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | (((x) << 24) & 0xFF000000))
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Magic6 Magic6;

typedef struct NatNegPacket
{
    Magic6 magic;
    u8 version;
    u8 packettype;
    int cookie;
    u8 pad0;
    u8 clientindex;
    u8 negResult;
    u8 pad1;
    int natType;
    int mappingScheme;
    char gamename[0x32];
    u8 pad2[2];
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

extern int strlen();
extern void *memcpy();
extern char *SOC_InetNtoA();
extern void gsDebugFormat();
extern void SendPacket();
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_02199FB4(int cookie);
extern unsigned int func_0217F264(void);
void func_02199394(NATNegotiator *neg);
void func_021994F0(NATNegotiator *neg, int result, int socket, SOCSockAddrIn *remoteaddr);
extern struct Magic6 g_021A5A7C;
extern char g_021ACEFC[];
extern struct NatSocks g_021A5A70;
extern NatnegGlobals g_021AE698;
extern u32 g_021AE6C4;
extern char g_021A5AB4[];
extern char g_021A5AF8[];
extern char g_021A5B30[];


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
    p.clientindex = (u8)neg->clientIndex;
    p.negResult = neg->result == 0 ? 1 : 0;
    p.natType = g_021A5A70.natType;
    p.mappingScheme = g_021AE698.natMappingScheme;
    if (strlen(g_021ACEFC))
        memcpy(p.gamename, g_021ACEFC, 0x32);
    gsDebugFormat(7, 0, 8, g_021A5AB4, neg->cookie, SOC_InetNtoA(g_021AE6C4), 27901, p.negResult);
    SendPacket(neg->negotiateSock, g_021AE698.natneg1IP, 27901, &p, 0x49);
}


void func_021994F0(NATNegotiator *neg, int result, int socket, SOCSockAddrIn *remoteaddr)
{
    neg->result = result;
    neg->socket = socket;
    if (remoteaddr)
        neg->remoteaddr = *remoteaddr;
    if (result == 1 || result == 2) {
        func_0217D254(7, (char *)3, 8, g_021A5AF8, neg->cookie);
        neg->state = 5;
        neg->completedCallback(neg->result, neg->socket, &neg->remoteaddr, neg->userdata);
        func_02199FB4(neg->cookie);
    } else {
        func_0217D254(7, (char *)3, 8, g_021A5B30, neg->cookie);
        func_02199394((NATNegotiator *)neg);
        neg->state = 7;
        neg->retryTime = func_0217F264() + 500;
        neg->retryCount = 0;
        neg->maxRetryCount = 4;
        neg->completedCallback(neg->result, neg->socket, &neg->remoteaddr, neg->userdata);
    }
}
