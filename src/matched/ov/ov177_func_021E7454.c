/*
 * function: WIFIBATTLEMATCH_VIEW_DeleteActorFromTable
 * address:  0x021E7454
 * packet:   pkt_021E7454
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 */
#include "../include/Obj24448.h"

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void WIFIBATTLEMATCH_VIEW_DeleteActorFromTable(int *p)
{
    CLACT_DeleteActor((struct Obj *)(((struct Obj24448 *)p)->f18C));
}
