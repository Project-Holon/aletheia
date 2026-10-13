/*
 * function: BUTTON_MAN_GetResourceType
 * address:  0x02051B04
 * packet:   pkt_02051B04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * ARM leaf, seeded 2026-09-27 from the ov195 call site 0x02208954
 * (func_0220887C). Returns the u16 at +8 of its argument.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj16194.h"

typedef unsigned short u16;

u16 BUTTON_MAN_GetResourceType(void *res)
{
    return ((struct Obj16194 *)res)->f8;
}
