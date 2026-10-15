/*
 * function: SHINKA_DEMO_EFFECT_Destroy
 * address:  0x02208770
 * packet:   pkt_02208770
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SHINKA_DEMO_EFFECT_RemoveUnit 0x02208B54 thumb
 *   SHINKA_DEMO_EFFECT_DeleteUnit 0x02208A6C thumb
 *   SHINKA_DEMO_EFFECT_DeleteParticle 0x02208994 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj05518.h"

extern void SHINKA_DEMO_EFFECT_RemoveUnit(char *a);
extern void SHINKA_DEMO_EFFECT_DeleteUnit(char *p);
extern void SHINKA_DEMO_EFFECT_DeleteParticle(char *a);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void SHINKA_DEMO_EFFECT_Destroy(char *a)
{
    SHINKA_DEMO_EFFECT_RemoveUnit(a);
    SHINKA_DEMO_EFFECT_DeleteUnit(a);
    SHINKA_DEMO_EFFECT_DeleteParticle((char *)(((struct Obj05518 *)a)->f10));
    func_020307B0(a);
}