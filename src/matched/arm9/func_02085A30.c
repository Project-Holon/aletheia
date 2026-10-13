/*
 * function: OS_GetThreadPriority
 * address:  0x02085A30
 * packet:   pkt_02085A30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj01024.h"

void *OS_GetThreadPriority(char *p)
{
    return ((struct Obj01024 *)p)->f70;
}
