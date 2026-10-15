/*
 * function: CTVT_COMM_SetRequestedMode
 * address: 0x021B80DC
 * packet: pkt_ov172_021B80DC
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj24076.h"
typedef unsigned char u8;
typedef unsigned int u32;
void CTVT_COMM_SetRequestedMode(int unused, char *p, u32 v)
{
    ((struct Obj24076 *)p)->f178 = v;
}
