/*
 * function: accept
 * address:  0x0217ED0C
 * packet:   pkt_ov009_0217ED0C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      accept (gsplatformsocket)
 *
 * symbols:
 *   SOC_Accept       0x0215f714 arm
 *   CheckRcode       0x0217eb00 arm
 */

struct SOCSockAddr {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned char addr[4];
};

extern int SOC_Accept(int s, void * sockAddr);
extern int CheckRcode(int rcode, int errCode);

int accept(int sock, struct SOCSockAddr * addr, int * len)
{
    int rcode;

    addr->len = (unsigned char)*len;
    rcode = SOC_Accept(sock, addr);
    *len = addr->len;
    return CheckRcode(rcode, -1);
}
