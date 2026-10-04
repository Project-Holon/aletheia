/*
 * unit:     no
 * function: func_02036738
 * address:  0x02036738
 * packet:   pkt_020366C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj05732.h"

void func_02036738(char *q, int v)
{
    *(char *)*(char * *)&((struct Obj05732 *)q)->f0 = (char)v;
    *(char * *)&((struct Obj05732 *)q)->f0 = *(char * *)&((struct Obj05732 *)q)->f0 + 1;
    ((struct Obj05732 *)q)->f4 = ((struct Obj05732 *)q)->f4 - 1;
}

