/*
 * function: SendReportPacket
 * address:  0x02199394
 * packet:   pkt_ov009_02199394
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SendReportPacket (libdwcgsnatneg.TWL.HYB.a(natneg.o))
 *
 * symbols:
 *   strlen         0x0209477C  arm
 *   memcpy         0x02092344  arm
 *   SOC_InetNtoA   0x0215FA9C  arm  ov009
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   SendPacket     0x021992A8  arm  ov009
 *   gNatNegMagic     0x021A5A7C  data
 *   gGsAvailabilityGameName     0x021ACEFC  data
 *   gNatSocks     0x021A5A70  data
 *   gNatnegGlobals     0x021AE698  data
 *   gNatNegServer1IP     0x021AE6C4  data
 *   gNatNegSendReportFmt     0x021A5AB4  data
 */

#include "../include/G_Magic6.h"
#include "../include/G_NatSocks.h"

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

typedef struct NATNegotiator
{
    int gameSock;
    int cookie;
    int clientindex;
    char pad0[0xC];
    int negotiateSock;
    int state;
    char pad1[0x24];
    int result;
} NATNegotiator;

typedef struct NegotiateAnchor
{
    char pad0[8];
    int natMappingScheme;
    char pad1[0x20];
    u32 matchup1ip;
} NegotiateAnchor;

typedef struct NatSocks NatSocks;

#define NN_SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | (((x) << 24) & 0xFF000000))

extern int strlen();
extern void *memcpy();
extern char *SOC_InetNtoA();
extern void gsDebugFormat();
extern void SendPacket();
extern struct Magic6 gNatNegMagic;
extern char gGsAvailabilityGameName[];
extern struct NatSocks gNatSocks;
extern NegotiateAnchor gNatnegGlobals;
extern u32 gNatNegServer1IP;
extern char gNatNegSendReportFmt[];

void SendReportPacket(NATNegotiator *neg)
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
    p.packettype = 13;
    p.cookie = NN_SWAP32((u32)neg->cookie);
    p.clientindex = (u8)neg->clientindex;
    p.negResult = neg->result == 0 ? 1 : 0;
    p.natType = gNatSocks.natType;
    p.mappingScheme = gNatnegGlobals.natMappingScheme;
    if (strlen(gGsAvailabilityGameName))
        memcpy(p.gamename, gGsAvailabilityGameName, 0x32);
    gsDebugFormat(7, 0, 8, gNatNegSendReportFmt, neg->cookie, SOC_InetNtoA(gNatNegServer1IP), 27901, p.negResult);
    SendPacket(neg->negotiateSock, gNatnegGlobals.matchup1ip, 27901, &p, 0x49);
}
