/*
 * function: SetReceiveBufferSize
 * address:  0x0217EF00
 * packet:   pkt_ov009_0217EF00
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SetReceiveBufferSize (gsplatformsocket)
 *
 * symbols:
 *   setsockopt       0x0217ecf8 arm
 */

extern int setsockopt(int s, int level, int optname, void * optval, int optlen);

int SetReceiveBufferSize(int sock, int size)
{
    int rcode;

    rcode = setsockopt(sock, 0xffff, 0x1002, &size, 4);
    return (rcode != -1);
}
