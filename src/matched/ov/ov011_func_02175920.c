/*
 * function: func_02175920
 * address:  0x02175920
 * packet:   pkt_02175920
 * region:   ov011
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets the byte field at +0x19A of the object to 1.
 */
#include "../include/Obj12430.h"

void func_02175920(void *p)
{
    *(char *)&((struct Obj12430 *)p)->f19A = 1;
}
