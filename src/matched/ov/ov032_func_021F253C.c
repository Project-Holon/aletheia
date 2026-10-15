/*
 * unit:     yes
 * function: BEACON_VIEW_RequestTransition, BEACON_VIEW_ClearEndRequest
 * address:  0x021F253C
 * packet:   pkt_021F253C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj20459.h"
#include "../include/Obj20460.h"

void BEACON_VIEW_RequestTransition(char *p, int v)
{
    ((struct Obj20459 *)p)->f70 = v;
}

void BEACON_VIEW_ClearEndRequest(char *p)
{
    ((struct Obj20460 *)p)->f70 = 0;
}
