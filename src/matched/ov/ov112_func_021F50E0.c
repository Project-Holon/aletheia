/*
 * function: MUSICAL_MCSS_GetStateB
 * address:  0x021F50E0
 * packet:   pkt_021F50E0
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj22533.h"

int MUSICAL_MCSS_GetStateB(const unsigned char *p)
{
    if (*(const unsigned short *)&((struct Obj22533 *)p)->f6 & 0x200)
        return 1;
    return 0;
}
