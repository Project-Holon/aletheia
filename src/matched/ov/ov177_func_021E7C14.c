/*
 * function: WIFIBATTLEMATCH_VIEW_DeleteRecordActor
 * address: 0x021E7C14
 * packet: pkt_ov177_021E7C14
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   CLACT_DeleteActor  0x0204B3B4  arm  arm9
 */
#include "../include/Obj08288.h"
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleaseCellAnim(unsigned);
extern void CLACT_ReleasePalette(unsigned);
void WIFIBATTLEMATCH_VIEW_DeleteRecordActor(char *p)
{
    CLACT_DeleteActor(((struct Obj08288 *)p)->f64);
    CLACT_ReleaseCharacter(((struct Obj08288 *)p)->f82);
    CLACT_ReleaseCellAnim(((struct Obj08288 *)p)->f84);
    CLACT_ReleasePalette(((struct Obj08288 *)p)->f80);
}
