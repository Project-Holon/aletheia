/*
 * unit:     no
 * function: CLACT_GetActorDrawPriority
 * address:  0x0204B838
 * packet:   pkt_0204B764
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj16082.h"

int CLACT_GetActorDrawPriority(int a0){ return (((unsigned int)((((struct Obj16082 *)((char *)(a0)))->f60 << 0x18)) >> 0x18) & 0xff); }
