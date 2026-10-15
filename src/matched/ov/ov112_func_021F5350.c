/*
 * function: MUSICAL_MCSS_GetRenderPos
 * address:  0x021F5350
 * packet:   pkt_021F5350
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MUSICAL_MCSS_GetFieldA  0x021F6234  thumb  ov112
 */
#include "../include/Obj22536.h"

void MUSICAL_MCSS_GetFieldA(char *p, int *q);

void MUSICAL_MCSS_GetRenderPos(int *p, int *q)
{
    MUSICAL_MCSS_GetFieldA(*(char * *)&((struct Obj22536 *)p)->f8, q);
}
