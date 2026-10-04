/*
 * function: func_021DD51C
 * address: 0x021DD51C
 * packet: pkt_ov171_021DD51C
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: signed byte step avoids an extra truncation before the addition.
 */
#include "../include/Obj00347.h"
typedef signed char s8;
typedef unsigned char u8;
int func_021DD51C(char *p, s8 step)
{
    int old;
    old = ((struct Obj00347 *)p)->fC5E;
    ((struct Obj00347 *)p)->fC5E += step;
    if (((struct Obj00347 *)p)->fC5E < 0)
        ((struct Obj00347 *)p)->fC5E = ((struct Obj00347 *)p)->fC5F - 1;
    else if (((struct Obj00347 *)p)->fC5E >= ((struct Obj00347 *)p)->fC5F)
        ((struct Obj00347 *)p)->fC5E = 0;
    if (((struct Obj00347 *)p)->fC5E != old)
        return 1;
    return 0;
}
