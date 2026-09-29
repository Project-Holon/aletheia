/*
 * function: func_0219AA08
 * address:  0x0219AA08
 * packet:   pkt_ov009_0219AA08
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ProcessInitPacket (libdwcgsnatneg.TWL.HYB.a(natneg.o))
 *
 * symbols:
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   current_time   0x0217F264  arm  ov009
 *   SendPacket     0x021992A8  arm  ov009
 *   g_021A6470     0x021A6470  data
 *   g_021A648C     0x021A648C  data
 *   g_021A6498     0x021A6498  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct SOCSockAddrIn
{
    u8 len;
    u8 family;
    u16 port;
    u32 addr;
} SOCSockAddrIn;

typedef struct NatNegPacket
{
    u8 magic[6];
    u8 version;
    u8 packettype;
    int cookie;
    u8 clientindex;
    u8 rest[0x3F];
} NatNegPacket;

typedef struct NATNegotiator
{
    int gameSock;
    int cookie;
    int clientindex;
    void (*progressCallback)(int state, void *userdata);
    int pad0;
    void *userdata;
    int negotiateSock;
    int state;
    int initAckRecv[4];
    int pad1[2];
    u32 retryTime;
} NATNegotiator;

#define NN_SWAP16(x) ((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00))

extern void gsDebugFormat();
extern u32 current_time(void);
extern void SendPacket();
extern char g_021A6470[];
extern char g_021A648C[];
extern char g_021A6498[];

void func_0219AA08(NATNegotiator *neg, NatNegPacket *p, SOCSockAddrIn *fromaddr)
{
    switch (p->packettype)
    {
    case 1:
        if (p->clientindex > 3)
            return;
        gsDebugFormat(7, 0, 8, g_021A6470, p->clientindex);
        neg->initAckRecv[p->clientindex] = 1;
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
