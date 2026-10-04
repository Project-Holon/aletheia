/*
 * unit:     no
 * function: func_020607E8
 * address:  0x020607E8
 * packet:   pkt_02060764
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj00512.h"

void *func_020607E8(int *p, int v)
{
    int *q = (int *)p[0];
    ((struct Obj00512 *)q)->f0 = (unsigned short)v;
    ((struct Obj00512 *)q)->f2 = 0;
    ((struct Obj00512 *)q)->f4 = (int)((char *)p[1] - ((char *)q + 0x10));
    ((struct Obj00512 *)q)->f8 = 0;
    *(int *)&((struct Obj00512 *)q)->fC = 0;
    return q;
}

