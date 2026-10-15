/*
 * function: GTSNEGO_MSG_ClearScrollState
 * address: 0x021D7020
 * packet: pkt_ov120_021D7020
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:

 */
#include "../include/Obj22843.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

void GTSNEGO_MSG_ClearScrollState(u8 *p)
{
    ((struct Obj22843 *)p)->f108 = 0;
}
