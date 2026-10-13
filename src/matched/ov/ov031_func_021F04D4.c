/*
 * function: UNION_SUBDISP_DeleteActorRes
 * address: 0x021F04D4
 * packet: pkt_ov031_021F04D4
 * region: ov031
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
#include "../include/Obj09792.h"
typedef unsigned int u32;
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleaseCellAnim(u32);
void UNION_SUBDISP_DeleteActorRes(char *p)
{
    CLACT_ReleasePalette(((struct Obj09792 *)p)->fC);
    CLACT_ReleaseCharacter(((struct Obj09792 *)p)->f8);
    CLACT_ReleaseCellAnim(((struct Obj09792 *)p)->f10);
}
