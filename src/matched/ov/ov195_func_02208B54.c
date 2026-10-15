/*
 * function: SHINKA_DEMO_EFFECT_RemoveUnit
 * address:  0x02208B54
 * packet:   pkt_02208B54
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   SHINKA_DEMO_EFFECT_FreeNode 0x02208714 thumb
 */
#include "../include/Obj05518.h"

typedef unsigned int   u32;
struct Ctx;
extern void G3D_UTIL_RemoveUnit(struct Ctx *c, u32 i);
extern void SHINKA_DEMO_EFFECT_FreeNode(void *p);

void SHINKA_DEMO_EFFECT_RemoveUnit(char *a)
{
    G3D_UTIL_RemoveUnit((struct Ctx *)(*(int *)&((struct Obj05518 *)a)->f14), ((struct Obj05518 *)a)->f18);
    SHINKA_DEMO_EFFECT_FreeNode((void *)(((struct Obj05518 *)a)->f20));
    ((struct Obj05518 *)a)->f1C = 0;
}