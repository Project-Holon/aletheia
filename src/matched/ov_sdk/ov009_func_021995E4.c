/*
 * function: SendPreinitPacket
 * address:  0x021995E4
 * packet:   pkt_ov009_021995E4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SendPreinitPacket (libdwcgsnatneg.TWL.HYB.a(natneg.o))
 *
 * symbols:
 *   GetClientUniqueID  0x021990A0  arm  ov009
 *   SOC_InetNtoA       0x0215FA9C  arm  ov009
 *   gsDebugFormat      0x0217D254  arm  ov009
 *   SendPacket         0x021992A8  arm  ov009
 *   current_time       0x0217F264  arm  ov009
 *   gNatNegMagic         0x021A5A7C  data
 *   gNatNegServer1IP         0x021AE6C4  data
 *   gNatNegPreinitFmt         0x021A5B70  data
 *   gNatnegGlobals         0x021AE698  data
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
    u8 clientindex;
    u8 pad0[3];
    int clientUniqueID;
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
    char pad1[0x14];
    int maxRetryCount;
    u32 retryTime;
} NATNegotiator;

typedef struct NegotiateAnchor
{
    char pad[0x2C];
    u32 matchup1ip;
} NegotiateAnchor;

#define NN_SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | (((x) << 24) & 0xFF000000))

extern int GetClientUniqueID();
extern char *SOC_InetNtoA();
extern void gsDebugFormat();
extern void SendPacket();
extern u32 current_time(void);
extern struct Magic6 gNatNegMagic;
extern u32 gNatNegServer1IP;
extern char gNatNegPreinitFmt[];
extern NegotiateAnchor gNatnegGlobals;

void SendPreinitPacket(NATNegotiator *neg)
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
    p.packettype = 15;
    p.cookie = NN_SWAP32((u32)neg->cookie);
    p.clientindex = (u8)neg->clientindex;
    p.clientUniqueID = GetClientUniqueID();
    gsDebugFormat(7, 0, 8, gNatNegPreinitFmt, SOC_InetNtoA(gNatNegServer1IP), 27901);
    SendPacket(neg->negotiateSock, gNatnegGlobals.matchup1ip, 27901, &p, 0x12);
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
