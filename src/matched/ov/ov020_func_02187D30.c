/*
 * function: EL_SCOREBOARD_IsStateDone
 * address:  0x02187D30
 * packet:   pkt_ov020_02187D30
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj01207.h"

typedef unsigned int u32;

int EL_SCOREBOARD_IsStateDone(char *p)
{
    if (*(u32 *)&((struct Obj01207 *)p)->f1C < ((struct Obj01207 *)p)->f18)
        return 1;
    return 0;
}
