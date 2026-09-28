/*
 * function: CanReceiveOnSocket
 * address:  0x0217EF50
 * packet:   pkt_ov009_0217EF50
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CanReceiveOnSocket (gsplatformsocket)
 *
 * symbols:
 *   GSISocketSelect  0x0217ed64 arm
 */

extern int GSISocketSelect(int theSocket, int * theReadFlag, int * theWriteFlag, int * theExceptFlag);

int CanReceiveOnSocket(int sock)
{
    int aReadFlag = 0;

    if (GSISocketSelect(sock, &aReadFlag, 0, 0) == 1)
        return aReadFlag;
    return 0;
}
