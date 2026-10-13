/*
 * function: BTL_SERVER_FLOW_GetActivePosPerSide
 * address:  0x021C8180
 * packet:   pkt_021C8180
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetActivePosPerSide  0x021B8670  thumb  ov093
 */
#include "../include/Obj18337.h"

unsigned int BTL_MAIN_GetActivePosPerSide(unsigned int **p);

int BTL_SERVER_FLOW_GetActivePosPerSide(int *p)
{
    return BTL_MAIN_GetActivePosPerSide((unsigned int **)(((struct Obj18337 *)p)->f4));
}
