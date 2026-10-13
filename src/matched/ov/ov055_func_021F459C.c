/*
 * function: CROWD_ClearChatterSlot
 * address:  0x021F459C
 * packet:   pkt_ov055_021F459C
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clear the two halfwords at 0x6 and 0x0.
 */
#include "../include/Obj05138.h"

void CROWD_ClearChatterSlot(void *p)
{
    ((struct Obj05138 *)p)->f6 = 0;
    ((struct Obj05138 *)p)->f0 = 0;
}
