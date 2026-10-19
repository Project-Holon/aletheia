/*
 * function: OS_SetThreadDestructor
 * address:  0x02085B94
 * packet:   pkt_02085B94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj16692.h"

void OS_SetThreadDestructor(char *p, int v)
{
    ((struct Obj16692 *)p)->fB4 = v;
}
