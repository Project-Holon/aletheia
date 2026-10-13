/*
 * function: C_GEAR_DeleteBarActors
 * address: 0x021F1DB0
 * packet: pkt_ov029_021F1DB0
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
#include "../include/Obj02111.h"
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
void C_GEAR_DeleteBarActors(char *p)
{
    if (((struct Obj02111 *)p)->f164 != 0) {
        CLACT_DeleteActor((struct Obj *)(((struct Obj02111 *)p)->f164));
        ((struct Obj02111 *)p)->f164 = 0;
    }
    if (((struct Obj02111 *)p)->f168 != 0)
        CLACT_DeleteActor((struct Obj *)(((struct Obj02111 *)p)->f168));
    if (((struct Obj02111 *)p)->f16C != 0) {
        CLACT_DeleteActor((struct Obj *)(((struct Obj02111 *)p)->f16C));
        ((struct Obj02111 *)p)->f16C = 0;
    }
}
