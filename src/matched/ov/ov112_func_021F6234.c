/*
 * function: MUSICAL_MCSS_GetFieldA
 * address:  0x021F6234
 * packet:   pkt_021F6234
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj10307.h"

void MUSICAL_MCSS_GetFieldA(char *p, int *q)
{
    ((struct Obj10307 *)p)->fC8 = q[0];
    ((struct Obj10307 *)p)->fCC = q[1];
    ((struct Obj10307 *)p)->fD0 = q[2];
}
