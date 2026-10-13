/*
 * function: EL_SCOREBOARD_GetMode
 * address:  0x02187D20
 * packet:   pkt_02187D20
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj19482.h"

typedef unsigned int u32;

u32 EL_SCOREBOARD_GetMode(char *p)
{
    return ((struct Obj19482 *)p)->fC;
}
