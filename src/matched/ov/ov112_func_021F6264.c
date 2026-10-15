/*
 * function: MUSICAL_MCSS_SetFieldC
 * address:  0x021F6264
 * packet:   pkt_021F6264
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj22545.h"

void MUSICAL_MCSS_SetFieldC(char *p, unsigned short v)
{
    ((struct Obj22545 *)p)->fFC = v;
}
