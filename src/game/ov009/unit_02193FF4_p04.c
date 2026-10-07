/*
 * file:     unit_02193FF4_p04.c
 * unit:     yes
 * function: func_021947C0, func_02194834
 * address:  0x021947C0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021937D0 0x021937D0  arm
 *   g_021ADFE0   0x021ADFE0  data
 */
#include "../../matched/include/G_StatsConn.h"

extern double *func_021937D0(void *set, char *name, int type, void *initialvalue);
double func_021947C0(int *game, char *name, double *(*func)(void *, char *, void *), double value);
void *func_02194834(int *game, char *name, void *(*func)(void *, char *, void *), void *value);
extern struct StatsConn g_021ADFE0;


/*
 * sdk:      ServerOpFloat (gstats.o)
 */
double func_021947C0(int *game, char *name, double *(*func)(void *, char *, void *), double value)
{
    double *ret;

    if (game == 0)
        game = (int *)((int *)&g_021ADFE0)[3];
    if (game == 0)
        ret = &value;
    else {
        ret = func((void *)game[3], name, &value);
        if (ret == 0)
            ret = func_021937D0((void *)game[3], name, 1, &value);
    }
    return *ret;
}


/*
 * sdk:      ServerOpString (gstats.o)
 */
void *func_02194834(int *game, char *name, void *(*func)(void *, char *, void *), void *value)
{
    void *ret;

    if (game == 0)
        game = (int *)((int *)&g_021ADFE0)[3];
    if (game == 0)
        return value;
    ret = func((void *)game[3], name, value);
    if (ret != 0)
        return ret;
    return func_021937D0((void *)game[3], name, 2, value);
}
