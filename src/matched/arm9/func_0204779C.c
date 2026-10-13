/*
 * unit:     no
 * function: G3D_SYSTEM_GetObjectAnimeCount
 * address:  0x0204779C
 * packet:   pkt_02047260
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj16046.h"

int G3D_SYSTEM_GetObjectAnimeCount(int *p){ return ((struct Obj16046 *)p)->fC; }
