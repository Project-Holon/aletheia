/*
 * unit:     yes
 * function: TOUCHBAR_SetButtonActorPriority, func_021B6A1C
 * address:  0x021B6A10
 * packet:   pkt_ov067_021B6A10
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two ARM9 tail calls on the pointer loaded from offset 0.
 *
 * symbols:
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 */
#include "../include/Obj20614.h"
#include "../include/Obj20615.h"

typedef unsigned int   u32;
struct Node;
void TOUCHBAR_SetButtonActorPriority(void *p, unsigned int v)
{
    void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
    CLACT_SetActorDrawPriority(((struct Obj20614 *)p)->f0, v);
}

void func_021B6A1C(void *p, unsigned int v)
{
    void CLACT_SetActorBgPriority(void *, unsigned int);
    CLACT_SetActorBgPriority(((struct Obj20615 *)p)->f0, v);
}
