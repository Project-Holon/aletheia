/*
 * function: NNS_G3dTexGetRequiredSize
 * address:  0x02069FD0
 * packet:   pkt_020694D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj16534.h"

int NNS_G3dTexGetRequiredSize(int p)
{
    return p ? (((struct Obj16534 *)p)->fC << 3) : 0;
}
