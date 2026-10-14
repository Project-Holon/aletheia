/*
 * function: DENDOU_VIEW_StepCursor
 * address: 0x021DD558
 * packet: pkt_ov171_021DD558
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: signed byte step avoids an extra truncation before the addition.
 */
#include "../include/Obj03310.h"
typedef signed char s8;
typedef unsigned short u16;
int DENDOU_VIEW_StepCursor(char *p, s8 step)
{
    int old;
    old = ((struct Obj03310 *)p)->fC5C;
    ((struct Obj03310 *)p)->fC5C += step;
    if (((struct Obj03310 *)p)->fC5C < 0)
        ((struct Obj03310 *)p)->fC5C = *(u16 *)(p + ((struct Obj03310 *)p)->fC5E * 0xbc + 0xc4) - 1;
    else if (((struct Obj03310 *)p)->fC5C >= *(u16 *)(p + ((struct Obj03310 *)p)->fC5E * 0xbc + 0xc4))
        ((struct Obj03310 *)p)->fC5C = 0;
    if (((struct Obj03310 *)p)->fC5C != old)
        return 1;
    return 0;
}
