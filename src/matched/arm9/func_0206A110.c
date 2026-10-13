/*
 * function: NNS_G3dPlttGetRequiredSize
 * address:  0x0206A110
 * packet:   pkt_020694D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj16538.h"

int NNS_G3dPlttGetRequiredSize(int p)
{
    return p ? (((struct Obj16538 *)p)->f30 << 3) : 0;
}
