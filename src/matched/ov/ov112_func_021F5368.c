/*
 * function: MUSICAL_MCSS_SetRenderFrame
 * address:  0x021F5368
 * packet:   pkt_021F5368
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MUSICAL_MCSS_SetMCAnimFrame  0x021F6264  thumb  ov112
 */
#include "../include/Obj22538.h"

void MUSICAL_MCSS_SetMCAnimFrame(char *p, unsigned short v);

void MUSICAL_MCSS_SetRenderFrame(int *p, unsigned short v)
{
    MUSICAL_MCSS_SetMCAnimFrame(*(char * *)&((struct Obj22538 *)p)->f8, v);
}
