/*
 * function: BTLV_CORE_BuildMessageToBuffer
 * address:  0x021EA5F0
 * packet:   pkt_ov093_021EA5F0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_BuildMessage  0x021EA55C  thumb  ov093
 */
#include "../include/Obj21563.h"
struct H;

extern void BTLV_CORE_BuildMessage(struct H *p, int a);

void BTLV_CORE_BuildMessageToBuffer(char *p, struct H *h)
{
    BTLV_CORE_BuildMessage(h, ((struct Obj21563 *)p)->fAC);
}
