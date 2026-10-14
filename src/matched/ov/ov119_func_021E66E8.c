/*
 * function: POKETRADE_2D_DeleteFloatingIconActor
 * address: 0x021E66E8
 * packet: pkt_ov119_021E66E8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
#include "../include/Obj10383.h"
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void POKETRADE_2D_DeleteFloatingIconActor(void *p)
{
    if (((struct Obj10383 *)p)->fF20) {
        CLACT_DeleteActor((struct Obj *)(((struct Obj10383 *)p)->fF20));
        ((struct Obj10383 *)p)->fF20 = 0;
    }
}
