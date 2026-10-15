/*
 * function: MUSICAL_MCSS_NoOp7
 * address:  0x021F621C
 * packet:   pkt_021F621C
 * region:   ov112
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj13833.h"

void MUSICAL_MCSS_NoOp7(void *p)
{
    unsigned int v = ((struct Obj13833 *)p)->f8;
    ((struct Obj13833 *)p)->f8 = (v & ~1u) | 1u;
}
