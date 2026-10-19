/*
 * function: MUSICAL_MCSS_SetMCAnimScale
 * address:  0x021F624C
 * packet:   pkt_021F624C
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj10309.h"

void MUSICAL_MCSS_SetMCAnimScale(char *p, int *q)
{
    ((struct Obj10309 *)p)->fD4 = q[0];
    ((struct Obj10309 *)p)->fD8 = q[1];
    ((struct Obj10309 *)p)->fDC = q[2];
}
