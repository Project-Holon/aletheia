/*
 * function: INTRO_CMD_DeleteActors
 * address: 0x021BED6C
 * packet: pkt_ov204_021BED6C
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
#include "../include/Obj08383.h"
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleasePalette(unsigned);
extern void CLACT_ReleaseCellAnim(unsigned);
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
int INTRO_CMD_DeleteActors(char *p)
{
    unsigned i;
    for (i = 0; i < 3; i++) {
        char *q = p + i * 4;
        CLACT_ReleaseCharacter(((struct Obj08383 *)q)->f10B4);
        CLACT_ReleasePalette(((struct Obj08383 *)q)->f10C0);
        CLACT_ReleaseCellAnim(((struct Obj08383 *)q)->f10CC);
        CLACT_DeleteActor(((struct Obj08383 *)q)->f10A8);
    }
    return 1;
}
