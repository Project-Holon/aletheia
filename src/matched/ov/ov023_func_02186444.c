/*
 * function: OEKAKI_SetNextScene
 * address:  0x02186444
 * packet:   pkt_02186444
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj20366.h"

typedef unsigned int u32;

void OEKAKI_SetNextScene(char *p, u32 v)
{
    ((struct Obj20366 *)p)->f19C = v;
}
