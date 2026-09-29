/*
 * function: func_021992A8
 * address:  0x021992A8
 * packet:   pkt_ov009_021992A8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SendPacket (natneg.o)
 *
 * symbols:
 *   func_0217ECA4  0x0217ECA4  arm  ov009
 */

typedef struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
} SOCSockAddrIn;

#define SWAP16(x) ((unsigned short)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))

extern int func_0217ECA4(int sock, void *buf, int len, int flags, SOCSockAddrIn *addr, int tolen);

void func_021992A8(int sock, unsigned int toaddr, unsigned short toport, void *data, int len)
{
    SOCSockAddrIn saddr;

    saddr.family = 2;
    saddr.port = SWAP16(toport);
    saddr.addr = toaddr;
    func_0217ECA4(sock, data, len, 0, &saddr, 8);
}
