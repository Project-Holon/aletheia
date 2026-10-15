/*
 * function: WIFIBATTLEMATCH_VIEW_DeletePokeActor
 * address: 0x021E73B8
 * packet: pkt_ov177_021E73B8
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
#include "../include/Obj00133.h"
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleasePalette(u32 i);
void WIFIBATTLEMATCH_VIEW_DeletePokeActor(char *p)
{
    CLACT_DeleteActor(((struct Obj00133 *)p)->f188);
    CLACT_ReleaseCharacter((u32)(((struct Obj00133 *)p)->f1EC));
    CLACT_ReleaseCellAnim((u32)(((struct Obj00133 *)p)->f1F0));
    CLACT_ReleasePalette((u32)(((struct Obj00133 *)p)->f1E8));
}
