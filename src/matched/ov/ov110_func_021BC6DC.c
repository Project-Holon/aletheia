/*
 * function: PMSIV_EDIT_GetSlotCount
 * address:  0x021BC6DC
 * packet:   pkt_ov110_021BC6DC
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * ov110 copy of the getter (`40 6c 70 47` = ldr r0,[r0,#0x44]; bx lr).
 * Note the ov217 entry at the same address is a different function
 * (u8 at +0x30), so a region-qualified entry is required here.
 */
#include "../include/Obj22375.h"

unsigned int PMSIV_EDIT_GetSlotCount(void *p)
{
    return ((struct Obj22375 *)p)->f44;
}
