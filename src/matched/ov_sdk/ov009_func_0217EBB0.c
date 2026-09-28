/*
 * function: bind
 * address:  0x0217EBB0
 * packet:   pkt_ov009_0217EBB0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      bind (gsplatformsocket)
 *
 * symbols:
 *   SOC_Bind         0x0215f454 arm
 *   CheckRcode       0x0217eb00 arm
 */

struct SOCSockAddr {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned char addr[4];
} __attribute__((packed));

extern int SOC_Bind(int s, void * sockAddr);
extern int CheckRcode(int rcode, int errCode);

int bind(int sock, const struct SOCSockAddr * addr, int len)
{
    struct SOCSockAddr localAddr;
    int rcode;

    if (addr->port == 0)
        return 0;

    localAddr = *addr;
    localAddr.len = len;
    rcode = SOC_Bind(sock, &localAddr);
    return CheckRcode(rcode, -1);
}
