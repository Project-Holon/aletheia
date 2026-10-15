/*
 * function: BR_UTIL_GetListMenuHitId
 * address: 0x021FCDA8
 * packet: pkt_ov186_021FCDA8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: S27 parent clearance; ov183 callers DFFB0 and E024C sole blocker.
 */
#include "../include/Obj24838.h"
int BR_UTIL_GetListMenuHitId(char *p)
{
    return ((struct Obj24838 *)p)->f48;
}
