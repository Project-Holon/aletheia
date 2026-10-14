/*
 * function: COMM_TVT_SYS_SetReturnedFromChild
 * address: 0x021BE030
 * packet: pkt_ov172_021BE030
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj24116.h"
typedef unsigned int u32;
void COMM_TVT_SYS_SetReturnedFromChild(void *p, u32 v)
{
    ((struct Obj24116 *)p)->f10 = v;
}
