/*
 * function: CloseStatsConnection
 * address:  0x02193D00
 * packet:   pkt_ov009_02193D00
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CloseStatsConnection (gstats.o)
 *
 * symbols:
 *   shutdown 0x0217EB9C  arm
 *   closesocket 0x0217EB2C  arm
 *   ClosePendingCallbacks 0x02194614  arm
 *   gsifree 0x0217EAE0  arm
 *   gGstatsSocket   0x021A57C8  data
 *   gGstatsConn   0x021ADFE0  data
 */

#include "../include/G_StatsSocket.h"
#include "../include/G_StatsConn.h"

extern int shutdown(int sock, int how);
extern int closesocket(int sock);
extern void ClosePendingCallbacks(void);
extern void gsifree(void *ptr);
extern struct StatsSocket gGstatsSocket;
extern struct StatsConn gGstatsConn;

void CloseStatsConnection(void)
{
    if (((int *)&gGstatsSocket)[1] != -1) {
        shutdown(((int *)&gGstatsSocket)[1], 2);
        closesocket(((int *)&gGstatsSocket)[1]);
    }
    ((int *)&gGstatsSocket)[1] = -1;
    ClosePendingCallbacks();
    if (((int *)&gGstatsConn)[10] != 0) {
        gsifree((void *)((int *)&gGstatsConn)[10]);
        ((int *)&gGstatsConn)[10] = 0;
        ((int *)&gGstatsConn)[6] = 0;
        ((int *)&gGstatsConn)[2] = 0;
    }
}
