/*
 * function: EL_SCOREBOARD_IsFinishRequested
 * address:  0x02187D24
 * packet:   pkt_ov020_02187D24
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj19483.h"

typedef unsigned int u32;

u32 EL_SCOREBOARD_IsFinishRequested(char *p)
{
    return ((struct Obj19483 *)p)->f10;
}
