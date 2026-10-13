/*
 * function: CLACT_GetActorBgPriority
 * address:  0x0204B864
 * packet:   pkt_0204B84C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 */
#include "../include/Obj16083.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

u32 CLACT_GetActorBgPriority(u8 *a0)
{
    return (u8)((((struct Obj16083 *)a0)->f60 << 14) >> 30);
}
