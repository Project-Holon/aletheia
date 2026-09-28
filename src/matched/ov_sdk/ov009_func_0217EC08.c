/*
 * function: connect
 * address:  0x0217EC08
 * packet:   pkt_ov009_0217EC08
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      connect (gsplatformsocket)
 *
 * symbols:
 *   SOC_Connect      0x0215f480 arm
 *   CheckRcode       0x0217eb00 arm
 */

struct SOCSockAddr {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned char addr[4];
} __attribute__((packed));

extern int SOC_Connect(int s, void * sockAddr);
extern int CheckRcode(int rcode, int errCode);

int connect(int sock, const struct SOCSockAddr * addr, int len)
{
    struct SOCSockAddr remoteAddr;
    int rcode;

    remoteAddr = *addr;
    remoteAddr.len = len;
    rcode = SOC_Connect(sock, &remoteAddr);
    return CheckRcode(rcode, -1);
}
