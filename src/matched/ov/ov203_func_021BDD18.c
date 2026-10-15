/*
 * function: DEMO3D_DeleteContext
 * address:  0x021BDD18
 * packet:   pkt_021BDD18
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj25307.h"

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void DEMO3D_DeleteContext(char *a)
{
    void **p = *(void ** *)&((struct Obj25307 *)a)->fC;

    if (p)
        ((void (*)(void *))p[2])(a);
    func_020307B0(a);
}
