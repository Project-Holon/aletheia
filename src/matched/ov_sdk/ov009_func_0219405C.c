/*
 * function: FindRequest
 * address:  0x0219405C
 * packet:   pkt_ov009_0219405C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FindRequest (gstats.o)
 *
 * symbols:
 *   func_02184200 0x02184200  arm
 *   func_02184208 0x02184208  arm
 *   gGstatsConn   0x021ADFE0  data
 */

#include "../include/G_StatsConn.h"

extern int func_02184200(const int *p);
extern int *func_02184208(void *array, int n);
extern struct StatsConn gGstatsConn;

int FindRequest(int reqtype, int localid, int profileid)
{
    int *req;
    int i;

    if (((int *)&gGstatsConn)[5] == 0)
        return -1;
    for (i = 0; i < func_02184200((void *)((int *)&gGstatsConn)[5]); i++) {
        req = func_02184208((void *)((int *)&gGstatsConn)[5], i);
        if (req[0] == reqtype && req[1] == localid && req[2] == profileid)
            return i;
    }
    return -1;
}
