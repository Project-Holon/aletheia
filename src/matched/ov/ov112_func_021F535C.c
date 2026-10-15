/*
 * function: MUSICAL_MCSS_GetRenderRot
 * address:  0x021F535C
 * packet:   pkt_021F535C
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MUSICAL_MCSS_GetFieldB  0x021F624C  thumb  ov112
 */
#include "../include/Obj22537.h"

void MUSICAL_MCSS_GetFieldB(char *p, int *q);

void MUSICAL_MCSS_GetRenderRot(int *p, int *q)
{
    MUSICAL_MCSS_GetFieldB(*(char * *)&((struct Obj22537 *)p)->f8, q);
}
