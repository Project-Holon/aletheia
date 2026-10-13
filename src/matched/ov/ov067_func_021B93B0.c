/*
 * function: FRAME_LIST_GetCursor
 * address:  0x021B93B0
 * packet:   pkt_021B93B0
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *
 * Unlabelled leaf in ov067, printed as a .word run; signed halfword getter.
 * Blocker target of ov210's func_021BF728 (pkt_021BF728), reached across the
 * ov210/ov067 overlay pair.
 */
#include "../include/Obj20629.h"

int FRAME_LIST_GetCursor(char *p)
{
    return ((struct Obj20629 *)p)->f5C;
}
