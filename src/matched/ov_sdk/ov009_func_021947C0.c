/*
 * function: ServerOpFloat
 * address:  0x021947C0
 * packet:   pkt_ov009_021947C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ServerOpFloat (gstats.o)
 *
 * symbols:
 *   func_021937D0 0x021937D0  arm
 *   gGstatsConn   0x021ADFE0  data
 */

#include "../include/G_StatsConn.h"

extern double *func_021937D0(void *set, char *name, int type, void *initialvalue);
extern struct StatsConn gGstatsConn;

double ServerOpFloat(int *game, char *name, double *(*func)(void *, char *, void *), double value)
{
    double *ret;

    if (game == 0)
        game = (int *)((int *)&gGstatsConn)[3];
    if (game == 0)
        ret = &value;
    else {
        ret = func((void *)game[3], name, &value);
        if (ret == 0)
            ret = func_021937D0((void *)game[3], name, 1, &value);
    }
    return *ret;
}
