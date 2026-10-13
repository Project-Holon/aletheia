/*
 * function: FRAME_LIST_GetPrinter
 * address: 0x021B9394
 * packet: pkt_ov067_021B9394
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: four-byte getter; next leaf 021B9398 belongs to S27, not this file.
 */
#include "../include/Obj20627.h"
unsigned FRAME_LIST_GetPrinter(char *p)
{
    return ((struct Obj20627 *)p)->f34;
}
