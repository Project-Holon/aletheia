/*
 * function: COMM_TVT_SYS_GetReturnedFromChild
 * address: 0x021BE02C
 * packet: pkt_ov172_021BE02C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj24115.h"
typedef unsigned int u32;
u32 COMM_TVT_SYS_GetReturnedFromChild(void *p)
{
    return ((struct Obj24115 *)p)->f10;
}
