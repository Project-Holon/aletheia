/*
 * function: NNS_G3dTexSetTexKey
 * address:  0x02069FF8
 * packet:   pkt_020694D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj01198.h"

void NNS_G3dTexSetTexKey(char *p, int a, int b)
{
    if (a) *(int *)&((struct Obj01198 *)p)->f8 = a;
    if (b) *(int *)&((struct Obj01198 *)p)->f18 = b;
}
