/*
 * function: func_021D8F0C
 * address: 0x021D8F0C
 * packet: pkt_ov131_021D8F0C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj05393.h"

void func_021D8F0C(void *unused, unsigned char *p, int delta)
{
    int max = (p[0x10] - 6) * 24;
    unsigned int old;
    if (max < 0) max = 0;
    if (delta > 24) delta = 24;
    if (delta < -24) delta = -24;
    old = ((struct Obj05393 *)p)->f14;
    if ((short)old + delta < 0) ((struct Obj05393 *)p)->f14 = 0;
    else if (old + delta > (unsigned int)max) ((struct Obj05393 *)p)->f14 = max;
    else ((struct Obj05393 *)p)->f14 = old + delta;
    if (delta != 0) ((struct Obj05393 *)p)->fC = 1;
}
