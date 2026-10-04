/*
 * function: func_02162F0C
 * address:  0x02162F0C
 * packet:   pkt_ov010_02162F0C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj01639.h"

typedef unsigned short u16;
typedef short s16;

int func_02162F0C(char *p, int *v)
{
    u16 *q;
    int x, y, z;

    if (((struct Obj01639 *)p)->f8 == 1) {
        return 0;
    }
    q = (u16 *)(p + 10);
    x = (v[0] >> 4) / 0x1000;
    z = (v[2] >> 4) / 0x1000;
    y = v[1] >> 12;
    if (((struct Obj01639 *)p)->fA <= x && ((struct Obj01639 *)p)->fA + q[2] > x
        && q[1] <= z && q[1] + q[3] > z
        && ((s16 *)q)[4] - 2 <= y && ((s16 *)q)[4] + 2 > y) {
        return 1;
    }
    return 0;
}
