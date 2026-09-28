/*
 * function: IsPrivateIP
 * address:  0x0217F038
 * packet:   pkt_ov009_0217F038
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      IsPrivateIP (gsplatformsocket)
 *
 * symbols:
 *   (none)
 */

struct SOCInAddr {
    unsigned int addr;
};

int IsPrivateIP(struct SOCInAddr * addr)
{
    unsigned int ip;
    int b1;
    int b2;

    ip = addr->addr;
    ip = ((ip >> 24) & 0xff) | ((ip >> 8) & 0xff00) | ((ip << 8) & 0xff0000)
       | ((ip << 24) & 0xff000000);
    b2 = (ip >> 24) & 0xff;
    b1 = (ip >> 16) & 0xff;
    if (b2 == 10)
        return 1;
    if (b2 == 172 && b1 >= 16 && b1 <= 31)
        return 1;
    if (b2 == 192 && b1 == 168)
        return 1;
    return 0;
}
