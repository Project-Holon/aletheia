/*
 * function: NNS_G3dTex4x4GetRequiredSize
 * address:  0x02069FE4
 * packet:   pkt_020694D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj16535.h"

int NNS_G3dTex4x4GetRequiredSize(int p)
{
    return p ? (((struct Obj16535 *)p)->f1C << 3) : 0;
}
