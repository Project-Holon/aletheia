/*
 * function: GetTeamIndex
 * address:  0x021946F4
 * packet:   pkt_ov009_021946F4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GetTeamIndex (gstats.o)
 *
 * symbols:
 *   func_02184208 0x02184208  arm
 *   gGstatsConn   0x021ADFE0  data
 */

#include "../include/G_StatsConn.h"

extern void *func_02184208(void *a, int n);
extern struct StatsConn gGstatsConn;

int GetTeamIndex(int *game, int tnum)
{
    if (game == 0)
        game = (int *)((int *)&gGstatsConn)[3];
    if (game == 0)
        return tnum;
    return *(int *)func_02184208((void *)game[8], tnum);
}
