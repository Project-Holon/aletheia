/*
 * function: BOX2_SEQ_DeleteAllActors
 * address:  0x021EBF50
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_DeleteActorSlot  0x021EBF34  thumb  ov170
 *   CLACT_DeleteUnit  0x0204B1CC  arm  arm9
 *
 * Release all 0x60 slots of the 0x9E70 pool, then release the pool
 *   head itself.
 */
#include "../include/Obj07238.h"


struct S;
extern void BOX2_SEQ_DeleteActorSlot(struct S *p, int i);
struct Bank;
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
void BOX2_SEQ_DeleteAllActors(char *p)
{
    unsigned i;
    for (i = 0; i < 0x60; i++)
        BOX2_SEQ_DeleteActorSlot((struct S *)p, i);
    CLACT_DeleteUnit((struct Bank *)(((struct Obj07238 *)p)->f9E70));
}
