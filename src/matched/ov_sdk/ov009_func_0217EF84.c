/*
 * function: CanSendOnSocket
 * address:  0x0217EF84
 * packet:   pkt_ov009_0217EF84
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CanSendOnSocket (gsplatformsocket)
 *
 * symbols:
 *   GSISocketSelect  0x0217ed64 arm
 */

extern int GSISocketSelect(int theSocket, int * theReadFlag, int * theWriteFlag, int * theExceptFlag);

int CanSendOnSocket(int sock)
{
    int aWriteFlag = 0;

    if (GSISocketSelect(sock, 0, &aWriteFlag, 0) == 1)
        return aWriteFlag;
    return 0;
}
