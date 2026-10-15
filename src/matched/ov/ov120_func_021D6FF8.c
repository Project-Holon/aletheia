/*
 * function: GTSNEGO_MSG_SetScrollState
 * address: 0x021D6FF8
 * packet: pkt_ov120_021D6FF8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:

 */
#include "../include/Obj06440.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

void GTSNEGO_MSG_SetScrollState(u8 *p, int state)
{
    ((struct Obj06440 *)p)->f108 = state;
    if (state == 2) ((struct Obj06440 *)p)->f10C = ((struct Obj06440 *)p)->f104 + 48;
    else if (state == 1) ((struct Obj06440 *)p)->f10C = ((struct Obj06440 *)p)->f104 - 48;
}
