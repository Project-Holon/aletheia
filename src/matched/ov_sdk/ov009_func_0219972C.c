/*
 * function: func_0219972C
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
 *   func_021992FC  0x021992FC  arm  ov009
 *   func_02094798  0x02094798  arm
 *   func_0209477C  0x0209477C  arm
 *   func_0215FA9C  0x0215FA9C  arm  ov009
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_021992A8  0x021992A8  arm  ov009
 *   func_02199360  0x02199360  arm  ov009
 *   func_0217F264  0x0217F264  arm  ov009
 *   g_021A5A7C     0x021A5A7C  data
 *   g_021ACEFC     0x021ACEFC  data
 *   g_021AE6C4     0x021AE6C4  data
 *   g_021A5B8C     0x021A5B8C  data
 *   g_021AE698     0x021AE698  data
 *   g_021A5BAC     0x021A5BAC  data
 *   g_021AE6C0     0x021AE6C0  data
 *   g_021A5BE8     0x021A5BE8  data
 *   g_021AE6BC     0x021AE6BC  data
 *   g_021A5C24     0x021A5C24  data
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

extern unsigned int func_021992FC(void);
extern char *func_02094798(char *dst, const char *src);
extern unsigned long func_0209477C(const char *s);
extern char *func_0215FA9C(unsigned int in);
extern void func_0217D254(int theCat, int theType, unsigned char theLevel, const char *theTokenStr, ...);
extern void func_021992A8(int sock, unsigned int toaddr, unsigned short toport, void *data, int len);
extern unsigned short func_02199360(int sock);
extern unsigned int func_0217F264(void);

extern struct Magic6 g_021A5A7C;
extern char g_021ACEFC[];
extern unsigned int g_021AE6C4;
extern unsigned int g_021AE6C0;
extern unsigned int g_021AE6BC;
extern NegotiateAnchor g_021AE698;
extern char g_021A5B8C[];
extern char g_021A5BAC[];
extern char g_021A5BE8[];
extern char g_021A5C24[];

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
    p->cookie = NN_HTONL((unsigned int)neg->cookie);
    p->clientindex = neg->clientIndex;
    p->usegameport = (neg->gameSock == -1) ? 0 : 1;
    localip = NN_HTONL(func_021992FC());
    buffer[15] = (unsigned char)(localip >> 24);
    buffer[16] = (unsigned char)(localip >> 16);
    buffer[17] = (unsigned char)(localip >> 8);
    buffer[18] = (unsigned char)localip;
    buffer[19] = 0;
    buffer[20] = 0;
    func_02094798(buffer + 21, g_021ACEFC);
    packetlen = func_0209477C(g_021ACEFC) + 22;

    if (p->usegameport && !neg->initAckRecv[0]) {
        p->porttype = 0;
        func_0217D254(7, 0, 8, g_021A5B8C, func_0215FA9C(g_021AE6C4), 27901);
        func_021992A8(neg->gameSock, g_021AE698.matchup1ip, 27901, p, packetlen);
    }

    if (!neg->initAckRecv[1]) {
        p->porttype = 1;
        func_0217D254(7, 0, 8, g_021A5BAC, neg->cookie, func_0215FA9C(g_021AE6C4), 27901);
        func_021992A8(neg->negotiateSock, g_021AE698.matchup1ip, 27901, p, packetlen);
    }

    localport = NN_HTONS(func_02199360(p->usegameport ? neg->gameSock : neg->negotiateSock));
    buffer[19] = (unsigned char)(localport >> 8);
    buffer[20] = (unsigned char)localport;

    if (!neg->initAckRecv[2]) {
        p->porttype = 2;
        func_0217D254(7, 0, 8, g_021A5BE8, neg->cookie, func_0215FA9C(g_021AE6C0), 27901);
        func_021992A8(neg->negotiateSock, g_021AE698.matchup2ip, 27901, p, packetlen);
    }

    if (!neg->initAckRecv[3]) {
        p->porttype = 3;
        func_0217D254(7, 0, 8, g_021A5C24, neg->cookie, func_0215FA9C(g_021AE6BC), 27901);
        func_021992A8(neg->negotiateSock, g_021AE698.matchup3ip, 27901, p, packetlen);
    }

    neg->state = 2;
    neg->retryTime = func_0217F264() + 500;
    neg->maxRetryCount = 10;
}
