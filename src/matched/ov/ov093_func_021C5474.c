/*
 * function: BTL_SERVER_FLOW_ClearPendingCounter
 * address:  0x021C5474
 * packet:   pkt_021C5474
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent 12, compiled 10, trailing padding)
 */
#include "../include/Obj21097.h"

void *BTL_SERVER_FLOW_ClearPendingCounter(char *p)
{
    ((struct Obj21097 *)p)->f220 = 0;
    return p;
}
