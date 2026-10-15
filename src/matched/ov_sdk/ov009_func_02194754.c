/*
 * function: ServerOpInt
 * address:  0x02194754
 * packet:   pkt_ov009_02194754
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ServerOpInt (gstats.o)
 *
 * symbols:
 *   func_021937D0 0x021937D0  arm
 *   gGstatsConn   0x021ADFE0  data
 */

#include "../include/G_StatsConn.h"

extern int *func_021937D0(void *set, char *name, int type, void *initialvalue);
extern struct StatsConn gGstatsConn;

int ServerOpInt(int *game, char *name, int *(*func)(void *, char *, void *), int value)
{
    int *ret;

    if (game == 0)
        game = (int *)((int *)&gGstatsConn)[3];
    if (game == 0)
        ret = &value;
    else {
        ret = func((void *)game[3], name, &value);
        if (ret == 0)
            ret = func_021937D0((void *)game[3], name, 0, &value);
    }
    return *ret;
}
