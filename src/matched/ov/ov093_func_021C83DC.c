/*
 * function: BTL_SERVER_FLOW_SetCurTurnStateFlag
 * address:  0x021C83DC
 * packet:   pkt_021C83DC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj21120.h"

void BTL_SERVER_FLOW_SetCurTurnStateFlag(char *p, int x)
{
    *(char *)(((struct Obj21120 *)p)->f4A8 + 4) = x;
}
