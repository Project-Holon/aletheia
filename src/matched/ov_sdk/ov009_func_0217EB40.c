/*
 * function: closesocketsure
 * address:  0x0217EB40
 * packet:   pkt_ov009_0217EB40
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      closesocketsure (gsplatformsocket)
 *
 * symbols:
 *   SOC_Close        0x0215f644 arm
 *   SOCL_IsReleased  0x0215e7c8 arm
 *   CheckRcode       0x0217eb00 arm
 */

extern int SOC_Close(int s);
extern int SOCL_IsReleased(int s);
extern int CheckRcode(int rcode, int errCode);

int closesocketsure(int sock, int *notInCloseSocket)
{
    int rcode;

    rcode = SOC_Close(sock);
    if (rcode == 0) {
        *notInCloseSocket = (*notInCloseSocket == 0) ? 1 : 0;
        return *notInCloseSocket;
    }
    if (SOCL_IsReleased(sock) == 0)
        return 0;
    CheckRcode(rcode, -1);
    *notInCloseSocket = 1;
    return 1;
}
