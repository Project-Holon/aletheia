/*
 * function: NHTTP_RAP_GetConnection
 * address: 0x021B973C
 * packet: pkt_ov114_021B973C
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: the following labelled function is NHTTP_RAP_StartConnection.
 */
#include "../include/Obj22570.h"
int NHTTP_RAP_GetConnection(char *p)
{
    if (p) return ((struct Obj22570 *)p)->fC;
    return 0;
}
