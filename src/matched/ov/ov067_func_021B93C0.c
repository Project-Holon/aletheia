/*
 * function: FRAME_LIST_CanScrollDown
 * address:  0x021B93C0
 * packet:   pkt_021B93C0
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Unlabelled leaf in ov067, printed as a .word run: true when the signed
 * halfword at +0x62 is below the unsigned halfword at +0x64.  Blocker target
 * of ov210's func_021BF728 (pkt_021BF728), across the ov210/ov067 pair.
 */
#include "../include/Obj13136.h"

typedef unsigned short u16;

int FRAME_LIST_CanScrollDown(char *p)
{
    return ((struct Obj13136 *)p)->f62 < ((struct Obj13136 *)p)->f64;
}
