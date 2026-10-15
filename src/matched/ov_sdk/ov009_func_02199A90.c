/*
 * function: SendPingPacket
 * address:  0x02199A90
 * packet:   pkt_ov009_02199A90
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SendPingPacket (libdwcgsnatneg.TWL.HYB.a(natneg.o))
 *
 * symbols:
 *   SOC_InetNtoA   0x0215FA9C  arm  ov009
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   SendPacket     0x021992A8  arm  ov009
 *   current_time   0x0217F264  arm  ov009
 *   gNatNegMagic     0x021A5A7C  data
 *   gNatNegSendPingFmt     0x021A5C60  data
 */

#include "../include/G_Magic6.h"

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
    u32 ipaddr;
    u16 port;
    u8 gotyourdata;
    u8 finished;
    u8 rest[0x38];
} NatNegPacket;

typedef struct NATNegotiator
{
    int gameSock;
    int cookie;
    int clientindex;
    char pad0[0xC];
    int negotiateSock;
    int state;
    char pad1[0x10];
    int retryCount;
    int maxRetryCount;
    u32 retryTime;
    u32 guessedIP;
    u16 guessedPort;
    u8 gotRemoteData;
    u8 sendGotRemoteData;
} NATNegotiator;

#define NN_SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | (((x) << 24) & 0xFF000000))
#define NN_SWAP16(x) ((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00))

extern char *SOC_InetNtoA();
extern void gsDebugFormat();
extern void SendPacket();
extern u32 current_time(void);
extern struct Magic6 gNatNegMagic;
extern char gNatNegSendPingFmt[];

void SendPingPacket(NATNegotiator *neg)
{
    NatNegPacket p;

    {
        u8 *m = (u8 *)&gNatNegMagic;
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
    p.ipaddr = neg->guessedIP;
    p.port = NN_SWAP16(neg->guessedPort);
    p.gotyourdata = neg->gotRemoteData;
    p.finished = (neg->gotRemoteData && neg->sendGotRemoteData) ? 1 : 0;
    gsDebugFormat(7, 0, 8, gNatNegSendPingFmt, neg->cookie, SOC_InetNtoA(neg->guessedIP), neg->guessedPort, neg->gotRemoteData);
    SendPacket(neg->gameSock == -1 ? neg->negotiateSock : neg->gameSock, neg->guessedIP, neg->guessedPort, &p, 0x14);
    neg->retryTime = current_time() + 700;
    neg->maxRetryCount = 7;
}
