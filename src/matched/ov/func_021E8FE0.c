/*
 * function: BOX2_SEQ_SetState
 * address:  0x021E8FE0
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *
 * Store v at +0x28, return 13.
 */
#include "../include/Obj18471.h"


int BOX2_SEQ_SetState(char *p, int v)
{
    ((struct Obj18471 *)p)->f28 = v;
    return 0xd;
}

