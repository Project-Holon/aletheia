/*
 * function: SHINKA_DEMO_EFFECT_Trigger
 * address:  0x02208814
 * packet:   pkt_02208814
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SHINKA_DEMO_EFFECT_SetParticleTimer 0x02208A38 thumb
 */
#include "../include/Obj10830.h"

typedef unsigned int   u32;
extern void SHINKA_DEMO_EFFECT_SetParticleTimer(char *p, u32 v);

void SHINKA_DEMO_EFFECT_Trigger(char *a)
{
    SHINKA_DEMO_EFFECT_SetParticleTimer((char *)(((struct Obj10830 *)a)->f10), 0x1e);
    if (((struct Obj10830 *)a)->f8 == 1)
        ((struct Obj10830 *)a)->f8 = 2;
}