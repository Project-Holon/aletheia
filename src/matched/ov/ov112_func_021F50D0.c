/*
 * function: MUSICAL_MCSS_GetStateA
 * address:  0x021F50D0
 * packet:   pkt_021F50D0
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj22532.h"

int MUSICAL_MCSS_GetStateA(const unsigned char *p)
{
    if (*(const unsigned short *)&((struct Obj22532 *)p)->f6 & 0x80)
        return 1;
    return 0;
}
