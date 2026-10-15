/*
 * function: SendInitPackets
 * address:  0x0219972C
 * packet:   pkt_ov009_0219972C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SendInitPackets (libdwcgsnatneg.TWL.HYB.a natneg.o)
 *
 * symbols:
 *   GetLocalIP  0x021992FC  arm  ov009
 *   strcpy  0x02094798  arm
 *   strlen  0x0209477C  arm
 *   func_0215FA9C  0x0215FA9C  arm  ov009
 *   func_0217D254  0x0217D254  arm  ov009
 *   SendPacket  0x021992A8  arm  ov009
 *   GetLocalPort  0x02199360  arm  ov009
 *   current_time  0x0217F264  arm  ov009
 *   gNatNegMagic     0x021A5A7C  data
 *   gGsAvailabilityGameName     0x021ACEFC  data
 *   gNatNegServer1IP     0x021AE6C4  data
 *   gNatNegInitGpFmt     0x021A5B8C  data
 *   gNatnegGlobals     0x021AE698  data
 *   gNatNegInitNn1Fmt     0x021A5BAC  data
 *   gNatNegServer2IP     0x021AE6C0  data
 *   gNatNegInitNn2Fmt     0x021A5BE8  data
 *   gNatNegServer3IP     0x021AE6BC  data
 *   gNatNegInitNn3Fmt     0x021A5C24  data
 *
 * localip, localport and gamename are written through buffer, not p: the
 * object addresses them from sp (buffer + 0x0F, + 0x13, + 0x15) while every
 * other field goes through p in r6, and it stores localip and localport one
 * byte at a time, most significant byte first.  The swap macros evaluate
 * their argument once per term, so GetLocalIP runs four times and
 * GetLocalPort twice, as in the object.
 */

#include "../arm9_sdk/libc/string.h"
#include "../include/G_Magic6.h"

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
    unsigned char porttype;                          /* 0x0C */
    unsigned char clientindex;                       /* 0x0D */
    unsigned char usegameport;                       /* 0x0E */
    unsigned char localip[4];                        /* 0x0F */
    unsigned char localport[2];                      /* 0x13 */
    char gamename[64];                               /* 0x15 */
} NatNegPacket;

/* matchup3ip, matchup2ip and matchup1ip sit 0x24, 0x28 and 0x2C bytes past
 * negotiateList; the object reaches them through that one anchor word. */
typedef struct NegotiateAnchor {
    char pad[0x24];
    unsigned int matchup3ip;
    unsigned int matchup2ip;
    unsigned int matchup1ip;
} NegotiateAnchor;

#define NN_HTONL(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | (((x) << 24) & 0xFF000000))
#define NN_HTONS(x) ((unsigned short)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))

extern unsigned int GetLocalIP(void);
extern char *strcpy(char *dst, const char *src);
extern unsigned long strlen(const char *s);
extern char *func_0215FA9C(unsigned int in);
extern void func_0217D254(int theCat, int theType, unsigned char theLevel, const char *theTokenStr, ...);
extern void SendPacket(int sock, unsigned int toaddr, unsigned short toport, void *data, int len);
extern unsigned short GetLocalPort(int sock);
extern unsigned int current_time(void);

extern struct Magic6 gNatNegMagic;
extern char gGsAvailabilityGameName[];
extern unsigned int gNatNegServer1IP;
extern unsigned int gNatNegServer2IP;
extern unsigned int gNatNegServer3IP;
extern NegotiateAnchor gNatnegGlobals;
extern char gNatNegInitGpFmt[];
extern char gNatNegInitNn1Fmt[];
extern char gNatNegInitNn2Fmt[];
extern char gNatNegInitNn3Fmt[];

void SendInitPackets(NATNegotiator *neg)
{
    char buffer[85];
    NatNegPacket *p;
    unsigned int localip;
    unsigned short localport;
    int packetlen;

    p = (NatNegPacket *)buffer;
    memcpy(p->magic, ((unsigned char *)&gNatNegMagic), 6);
    p->version = 4;
    p->packettype = 0;
    p->cookie = NN_HTONL((unsigned int)neg->cookie);
    p->clientindex = neg->clientIndex;
    p->usegameport = (neg->gameSock == -1) ? 0 : 1;
    localip = NN_HTONL(GetLocalIP());
    buffer[15] = (unsigned char)(localip >> 24);
    buffer[16] = (unsigned char)(localip >> 16);
    buffer[17] = (unsigned char)(localip >> 8);
    buffer[18] = (unsigned char)localip;
    buffer[19] = 0;
    buffer[20] = 0;
    strcpy(buffer + 21, gGsAvailabilityGameName);
    packetlen = strlen(gGsAvailabilityGameName) + 22;

    if (p->usegameport && !neg->initAckRecv[0]) {
        p->porttype = 0;
        func_0217D254(7, 0, 8, gNatNegInitGpFmt, func_0215FA9C(gNatNegServer1IP), 27901);
        SendPacket(neg->gameSock, gNatnegGlobals.matchup1ip, 27901, p, packetlen);
    }

    if (!neg->initAckRecv[1]) {
        p->porttype = 1;
        func_0217D254(7, 0, 8, gNatNegInitNn1Fmt, neg->cookie, func_0215FA9C(gNatNegServer1IP), 27901);
        SendPacket(neg->negotiateSock, gNatnegGlobals.matchup1ip, 27901, p, packetlen);
    }

    localport = NN_HTONS(GetLocalPort(p->usegameport ? neg->gameSock : neg->negotiateSock));
    buffer[19] = (unsigned char)(localport >> 8);
    buffer[20] = (unsigned char)localport;

    if (!neg->initAckRecv[2]) {
        p->porttype = 2;
        func_0217D254(7, 0, 8, gNatNegInitNn2Fmt, neg->cookie, func_0215FA9C(gNatNegServer2IP), 27901);
        SendPacket(neg->negotiateSock, gNatnegGlobals.matchup2ip, 27901, p, packetlen);
    }

    if (!neg->initAckRecv[3]) {
        p->porttype = 3;
        func_0217D254(7, 0, 8, gNatNegInitNn3Fmt, neg->cookie, func_0215FA9C(gNatNegServer3IP), 27901);
        SendPacket(neg->negotiateSock, gNatnegGlobals.matchup3ip, 27901, p, packetlen);
    }

    neg->state = 2;
    neg->retryTime = current_time() + 500;
    neg->maxRetryCount = 10;
}
