/*
 * function: func_02194724
 * address:  0x02194724
 * packet:   pkt_ov009_02194724
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GetPlayerIndex (gstats.o)
 *
 * symbols:
 *   func_02184208 0x02184208  arm
 *   g_021ADFE0   0x021ADFE0  data
 */

#include "../include/G_StatsConn.h"

extern void *func_02184208(void *a, int n);
extern struct StatsConn g_021ADFE0;

int func_02194724(int *game, int pnum)
{
    if (game == 0)
        game = (int *)((int *)&g_021ADFE0)[3];
    if (game == 0)
        return pnum;
    return *(int *)func_02184208((void *)game[7], pnum);
}
