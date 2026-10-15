/*
 * function: MYSTERY_UTIL_DispatchTask
 * address:  0x021DA898
 * packet:   pkt_021DA898
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13955.h"

typedef unsigned int u32;

void MYSTERY_UTIL_DispatchTask(char *p)
{
    if (((struct Obj13955 *)p)->f4 == 0)
        (*(void (**)(char *, char *, u32))p)(p, p + 8, ((struct Obj13955 *)p)->fC);
}
