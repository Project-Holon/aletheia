/*
 * function: func_0219A52C
 * address:  0x0219A52C
 * packet:   pkt_ov009_0219A52C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SendConnectAck (libdwcgsnatneg.TWL.HYB.a(natneg.o))
 *
 * symbols:
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   SendPacket     0x021992A8  arm  ov009
 *   g_021A5A7C     0x021A5A7C  data
 *   g_021A61E8     0x021A61E8  data
 *
 * Builds a NATNEG connect-ack packet (6-byte magic block copy, version 4,
 * packettype 6, byte-swapped cookie and porttype) and sends it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_0219A52C.c \
 *       --func func_0219A52C --addr 0x0219A52C --region ov009 --arm --cc 1.1p1 --lang c99
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
    u8 porttype;
    u8 pad[0x3E];
} NatNegPacket;

typedef struct NATNegotiator
{
    char pad0[4];
    int cookie;
    int porttype;
    char pad1[0xC];
    int socket;
} NATNegotiator;

typedef struct SOCSockAddrIn
{
    u8 len;
    u8 family;
    u16 port;
    u32 addr;
} SOCSockAddrIn;

#define NN_SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | (((x) << 24) & 0xFF000000))
#define NN_SWAP16(x) ((u16)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))

extern void gsDebugFormat();
extern void SendPacket();
extern struct Magic6 g_021A5A7C;
extern char g_021A61E8[];

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
    p.porttype = neg->porttype;
    gsDebugFormat(7, 0, 8, g_021A61E8, neg->cookie);
    SendPacket(neg->socket, toaddr->addr, NN_SWAP16(toaddr->port), &p, 0x15);
}
