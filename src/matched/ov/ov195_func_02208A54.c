/*
 * function: SHINKA_DEMO_EFFECT_InitUnit
 * address:  0x02208A54
 * packet:   pkt_02208A54
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_UTIL_Create 0x02047CFC arm
 */
#include "../include/Obj00687.h"

extern int G3D_UTIL_Create(int, int, int);

void SHINKA_DEMO_EFFECT_InitUnit(char *a)
{
    *(int *)&((struct Obj00687 *)a)->f14 = G3D_UTIL_Create(4, 1, ((struct Obj00687 *)a)->f0);
    ((struct Obj00687 *)a)->f1C = 0;
}