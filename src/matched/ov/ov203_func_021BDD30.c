/*
 * function: DEMO3D_UpdateContext
 * address:  0x021BDD30
 * packet:   pkt_021BDD30
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj25308.h"

void DEMO3D_UpdateContext(char *a)
{
    void **p = *(void ** *)&((struct Obj25308 *)a)->fC;

    if (p)
        ((void (*)(void *))p[1])(a);
}
