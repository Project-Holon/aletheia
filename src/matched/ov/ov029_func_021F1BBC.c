/*
 * function: C_GEAR_DeleteSplashActors
 * address: 0x021F1BBC
 * packet: pkt_ov029_021F1BBC
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
#include "../include/Obj20395.h"
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
void C_GEAR_DeleteSplashActors(char *p)
{
    int i;
    if (((struct Obj20395 *)p)->f170 != 0) {
        for (i = 0; i < 18; i++) {
            CLACT_DeleteActor((struct Obj *)(*(int *)(p + i * 4 + 0x170)));
            *(int *)(p + i * 4 + 0x170) = 0;
        }
    }
}
