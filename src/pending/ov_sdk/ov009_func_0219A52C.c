/*
 * function: func_0219A52C
 * address:  0x0219A52C
 * packet:   pkt_ov009_0219A52C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (107 bytes differ: ordering and register allocation of the 6-byte NNMagicData copy)
 *
 * sdk:      SendConnectAck (natneg.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_021992A8  0x021992A8  arm  ov009
 *   g_021A5A7C  0x021A5A7C  data
 *   g_021A61E8  0x021A61E8  data
 */

typedef struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
} SOCSockAddrIn;

typedef struct {
    unsigned char b[6];
} NNMagic;

typedef struct _NatNegPacket {
    NNMagic magic;
    unsigned char version;
    unsigned char packettype;
    unsigned int cookie;
    unsigned char clientindex;
    unsigned char porttype;
    unsigned char pad[0x3E];
} NatNegPacket;

typedef struct _NATNegotiator {
    unsigned char pad0[4];
    unsigned int cookie;
    unsigned int porttype;
    unsigned char padC[0xC];
    int socket;
} NATNegotiator;

#define SWAP16(x) ((unsigned short)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))
#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))

extern NNMagic g_021A5A7C;
extern char g_021A61E8[];
extern void func_0217D254(int cat, int type, int level, const char *fmt, ...);
extern void func_021992A8(int sock, unsigned int toaddr, unsigned short toport, void *data, int len);

void func_0219A52C(NATNegotiator *neg, SOCSockAddrIn *toaddr)
{
    NatNegPacket p;

    *(NNMagic *)&p = g_021A5A7C;
    p.packettype = 6;
    p.version = 4;
    p.cookie = SWAP32(neg->cookie);
    p.porttype = neg->porttype;
    func_0217D254(7, 0, 8, g_021A61E8, neg->cookie);
    func_021992A8(neg->socket, toaddr->addr, SWAP16(toaddr->port), &p, 0x15);
}
