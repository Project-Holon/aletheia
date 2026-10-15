/*
 * function: SHINKA_DEMO_EFFECT_Draw
 * address:  0x02208804
 * packet:   pkt_02208804
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SHINKA_DEMO_EFFECT_DrawNodes 0x02208A78 thumb
 *   SHINKA_DEMO_EFFECT_DrawParticle 0x02208A24 thumb
 */
#include "../include/Obj08350.h"

struct Anim;
extern void SHINKA_DEMO_EFFECT_DrawNodes(struct Anim *p);
extern void SHINKA_DEMO_EFFECT_DrawParticle(int);

void SHINKA_DEMO_EFFECT_Draw(char *a)
{
    SHINKA_DEMO_EFFECT_DrawNodes((struct Anim *)a);
    SHINKA_DEMO_EFFECT_DrawParticle(((struct Obj08350 *)a)->f10);
}
