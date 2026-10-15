/*
 * function: BEACON_VIEW_TaskStateTasks
 * address: 0x021F2608
 * packet: pkt_ov032_021F2608
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_Main 0x020310C4 arm
 */
#include "../include/Obj09800.h"
struct Tcbl;
extern void TCBL_Main(struct Tcbl *);
int BEACON_VIEW_TaskStateTasks(char *p, int *unused)
{
    TCBL_Main(*(struct Tcbl * *)&((struct Obj09800 *)p)->fA0);
    if (((struct Obj09800 *)p)->fA8 == 0)
        return 1;
    return 0;
}
