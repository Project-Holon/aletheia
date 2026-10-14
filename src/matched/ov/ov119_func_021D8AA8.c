/*
 * function: POKETRADE_PROC_IsHostSide
 * address:  0x021D8AA8
 * packet:   pkt_ov119_021D8AA8
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Dense 9-way switch on *(u32 *)(p + 0x118C): returns 0 for the even/pair
 * cases {0,4,6,7,8}, 1 for {1,2,3,5} and for anything above 8.
 * Shape lever: the result must be a named local initialised to the
 * fall-through value, with only the non-default cases empty and the
 * default setting it; spelling each case as its own `return` makes the
 * compiler emit one return block per arm and no shared exit.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22702.h"

int POKETRADE_PROC_IsHostSide(void *p)
{
    unsigned int x = ((struct Obj22702 *)p)->f118C;
    int r = 0;

    switch (x) {
    case 0:
    case 4:
    case 6:
    case 7:
    case 8:
        break;
    default:
        r = 1;
    }
    return r;
}
