/*
 * unit:     no
 * function: G3D_SYSTEM_GetTexDataAddr
 * address:  0x020473D8
 * packet:   pkt_02047260
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_GetResourceTex  0x02047250  arm
 */
#include "../include/Obj16033.h"

int G3D_SYSTEM_GetTexDataAddr(int a0){ int t0 = G3D_SYSTEM_GetResourceTex(); return (t0 + ((struct Obj16033 *)((char *)(t0)))->f14); }
