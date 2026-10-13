/*
 * function: PLEASURE_BOAT_Update
 * address:  0x021C868C
 * packet:   pkt_ov021_021C868C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PLEASURE_BOAT_GetTimeEvent  0x021C87E0  thumb  ov021
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 */
#include "../include/Obj07575.h"

extern int PLEASURE_BOAT_GetTimeEvent(char *p);
struct Desc;
extern struct Desc *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3);

int PLEASURE_BOAT_Update(int a, char *b)
{
    int r4;
    int flag;
    int v;

    if (b == 0) {
        return 0;
    }
    if (((struct Obj07575 *)b)->f1B4 != 0) {
        return 0;
    }
    ((struct Obj07575 *)b)->f4 = ((struct Obj07575 *)b)->f4 + 1;
    v = PLEASURE_BOAT_GetTimeEvent(b);
    switch (v) {
    case 1:
        ((struct Obj07575 *)b)->f0 = 1;
        flag = 0;
        break;
    case 2:
        r4 = (int)SCRIPT_SYS_CreateScriptEventSimple(a, 1, 0, 0x8015);
        flag = 1;
        break;
    default:
        flag = 0;
        break;
    }
    if (flag == 0) {
        r4 = 0;
    }
    return r4;
}
