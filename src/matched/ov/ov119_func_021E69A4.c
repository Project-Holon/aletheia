/*
 * function: POKETRADE_2D_DeletePickedIconActor
 * address: 0x021E69A4
 * packet: pkt_ov119_021E69A4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
#include "../include/Obj00001.h"
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void POKETRADE_2D_DeletePickedIconActor(char *p)
{
    if (((struct Obj00001 *)p)->fFD4) {
        CLACT_DeleteActor((struct Obj *)(((struct Obj00001 *)p)->fFD4));
        ((struct Obj00001 *)p)->fFD4 = 0;
    }
}
