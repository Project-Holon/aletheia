/*
 * function: EVENTDATA_SYSTEM_IsPosEventGridHitIgnoreHeight
 * address:  0x02162F74
 * packet:   pkt_ov010_02162F74
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj04156.h"

typedef unsigned short u16;

int EVENTDATA_SYSTEM_IsPosEventGridHitIgnoreHeight(char *p, int *v)
{
    u16 *q;
    int x, z;

    if (((struct Obj04156 *)p)->f8 == 1) {
        return 0;
    }
    q = (u16 *)(p + 10);
    x = (v[0] >> 4) / 0x1000;
    z = (v[2] >> 4) / 0x1000;
    if (((struct Obj04156 *)p)->fA <= x && ((struct Obj04156 *)p)->fA + q[2] > x
        && q[1] <= z && q[1] + q[3] > z) {
        return 1;
    }
    return 0;
}
