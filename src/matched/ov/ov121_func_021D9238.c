/*
 * function: MYSTERY_StepScroll
 * address:  0x021D9238
 * packet:   pkt_021D9238
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10411.h"

typedef unsigned int u32;

void MYSTERY_StepScroll(char *p)
{
    if (((struct Obj10411 *)p)->f4 != 0 && ((struct Obj10411 *)p)->f0 != 0) {
        void (*fp)(char *) = *(void (**)(char *))(p + 0x11c);
        if (fp != 0)
            fp(p);
    }
}
