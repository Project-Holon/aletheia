/*
 * function: C_GEAR_DeleteFadeFx
 * address:  0x021F2E5C
 * packet:   pkt_021F2E5C
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_DeleteFadeFx 0x021F2E5C thumb
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
#include "../include/Obj20399.h"

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void C_GEAR_DeleteFadeFx(char *p)
{
    CLACT_DeleteActor((struct Obj *)(((struct Obj20399 *)p)->f8));
}
