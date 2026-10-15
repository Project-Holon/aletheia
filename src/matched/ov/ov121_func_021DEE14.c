/*
 * function: MYSTERY_NET_SetNdState
 * address: 0x021DEE14
 * packet: pkt_ov121_021DEE14
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021DFC00 0x021DFC00 data a4
 */
#include "../include/Obj08104.h"
extern int d_021DFC00[];
void MYSTERY_NET_SetNdState(char *p, int *state, int value)
{
    d_021DFC00[1] = 0;
    d_021DFC00[3] = 0;
    ((struct Obj08104 *)p)->f708 = value;
    ((struct Obj08104 *)p)->f72C = 0;
    *state = 100;
}
