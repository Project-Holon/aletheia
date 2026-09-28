/*
 * function: recvfrom
 * address:  0x0217EC60
 * packet:   pkt_ov009_0217EC60
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      recvfrom (gsplatformsocket)
 *
 * symbols:
 *   SOC_RecvFrom     0x0215f500 arm
 *   CheckRcode       0x0217eb00 arm
 */

struct SOCSockAddr {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned char addr[4];
};

extern int SOC_RecvFrom(int s, void * buf, int len, int flags, void * sockFrom);
extern int CheckRcode(int rcode, int errCode);

int recvfrom(int sock, char * buf, int len, int flags, struct SOCSockAddr * addr, int * fromlen)
{
    int rcode;

    addr->len = (unsigned char)*fromlen;
    rcode = SOC_RecvFrom(sock, buf, len, flags, addr);
    *fromlen = addr->len;
    return CheckRcode(rcode, -1);
}
