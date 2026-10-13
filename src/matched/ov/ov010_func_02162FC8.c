/*
 * function: EVENTDATA_SYSTEM_IsPosEventRailHit
 * address:  0x02162FC8
 * packet:   pkt_ov010_02162FC8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj05891.h"

typedef unsigned short u16;
typedef short s16;

int EVENTDATA_SYSTEM_IsPosEventRailHit(char *p, u16 *v)
{
    u16 *q;

    if (((struct Obj05891 *)p)->f8 == 0) {
        return 0;
    }
    q = (u16 *)(p + 10);
    if (((struct Obj05891 *)p)->fA == v[0] && q[1] <= v[3] && q[1] + q[3] > v[3]
        && ((s16 *)q)[2] <= ((s16 *)v)[2] && ((s16 *)q)[2] + q[4] > ((s16 *)v)[2]) {
        return 1;
    }
    return 0;
}
