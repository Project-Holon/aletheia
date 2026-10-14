/*
 * function: COMM_TVT_SYS_SetHalfRes
 * address: 0x021BE0A0
 * packet: pkt_ov172_021BE0A0
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj24126.h"
typedef unsigned short u16;
typedef unsigned int u32;
void COMM_TVT_SYS_SetHalfRes(void *p, u32 v)
{
    ((struct Obj24126 *)p)->f1C = v;
}
