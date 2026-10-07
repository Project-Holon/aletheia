/*
 * file:     unit_02193FF4_p03.c
 * unit:     yes
 * function: func_021946F4, func_02194724
 * address:  0x021946F4
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
 *   func_02184208 0x02184208  arm
 *   g_021ADFE0   0x021ADFE0  data
 */
#include "../../matched/include/G_StatsConn.h"

extern void *func_02184208(void *a, int n);
int func_021946F4(int *game, int tnum);
int func_02194724(int *game, int pnum);
extern struct StatsConn g_021ADFE0;


/*
 * sdk:      GetTeamIndex (gstats.o)
 */
int func_021946F4(int *game, int tnum)
{
    if (game == 0)
        game = (int *)((int *)&g_021ADFE0)[3];
    if (game == 0)
        return tnum;
    return *(int *)func_02184208((void *)game[8], tnum);
}


/*
 * sdk:      GetPlayerIndex (gstats.o)
 */
int func_02194724(int *game, int pnum)
{
    if (game == 0)
        game = (int *)((int *)&g_021ADFE0)[3];
    if (game == 0)
        return pnum;
    return *(int *)func_02184208((void *)game[7], pnum);
}
