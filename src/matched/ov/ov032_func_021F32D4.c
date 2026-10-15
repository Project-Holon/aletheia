/*
 * function: BEACON_VIEW_DeletePanelActors
 * address: 0x021F32D4
 * packet: pkt_ov032_021F32D4
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
#include "../include/Obj13069.h"
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned);
extern void CLACT_DeleteActor(struct Obj *);
void BEACON_VIEW_DeletePanelActors(char *p)
{
    int i;
    char *q;
    for (i = 0; i < 6; i++) {
        q = p + i * 4;
        CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj13069 *)q)->f2BC, 0);
        CLACT_DeleteActor(*(struct Obj * *)&((struct Obj13069 *)q)->f2BC);
    }
}
