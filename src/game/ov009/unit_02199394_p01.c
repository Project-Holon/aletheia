/*
 * file:     unit_02199394_p01.c
 * unit:     yes
 * function: func_02199A90, func_02199BE4
 * address:  0x02199A90
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
 *   SOC_InetNtoA   0x0215FA9C  arm  ov009
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   SendPacket     0x021992A8  arm  ov009
 *   current_time   0x0217F264  arm  ov009
 *   g_021A5A7C     0x021A5A7C  data
 *   g_021A5C60     0x021A5C60  data
 *   NatifyThink        0x02198E74  arm  ov009
 *   DetermineNatType   0x02198E80  arm  ov009
 *   closesocket        0x0217EB2C  arm  ov009
 *   g_021AE698         0x021AE698  data
 *   g_021AE6C8         0x021AE6C8  data
 *   g_021A5A70         0x021A5A70  data
 */
#include "../../matched/include/G_Magic6.h"
#include "../../matched/include/G_NatSocks.h"

#define NN_SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | (((x) << 24) & 0xFF000000))
#define NN_SWAP16(x) ((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00))
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

typedef struct NAT
{
    char pad0[0x8C];
    int natType;
    int mappingScheme;
    char pad1[0x44];
} NAT;

typedef struct NatifyState
{
    int negotiateList;
    int pad;
    int natMappingScheme;
    void (*natifyCallback)(int success, NAT nat);
    u32 natifyStartTime;
} NatifyState;

typedef struct NatSocks NatSocks;

extern char *SOC_InetNtoA();
extern void gsDebugFormat();
extern void SendPacket();
extern u32 current_time(void);
extern int NatifyThink();
extern int DetermineNatType();
extern int closesocket();
void func_02199A90(NATNegotiator *neg);
int func_02199BE4(int sock);
extern struct Magic6 g_021A5A7C;
extern char g_021A5C60[];
extern NatifyState g_021AE698;
extern NAT g_021AE6C8;
extern struct NatSocks g_021A5A70;


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
    p.ipaddr = neg->guessedIP;
    p.port = NN_SWAP16(neg->guessedPort);
    p.gotyourdata = neg->gotRemoteData;
    p.finished = (neg->gotRemoteData && neg->sendGotRemoteData) ? 1 : 0;
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
