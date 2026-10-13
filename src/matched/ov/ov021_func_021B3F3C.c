/*
 * function: SCRCMD_PROC_FLD_FreeShopCells
 * address:  0x021B3F3C
 * packet:   pkt_ov021_021B3F3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 */
#include "../include/Obj02711.h"

typedef unsigned int   u32;
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void ARC_TOOL_DeleteHandle(void *a);
struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);

void SCRCMD_PROC_FLD_FreeShopCells(char *w)
{
    CLACT_ReleaseCellAnim((u32)(((struct Obj02711 *)w)->f1F4));
    CLACT_ReleaseCellAnim((u32)(((struct Obj02711 *)w)->f1E8));
    CLACT_ReleaseCellAnim((u32)(((struct Obj02711 *)w)->f1DC));
    CLACT_ReleaseCharacter((u32)(((struct Obj02711 *)w)->f1F0));
    CLACT_ReleaseCharacter((u32)(((struct Obj02711 *)w)->f1E4));
    CLACT_ReleaseCharacter((u32)(((struct Obj02711 *)w)->f1D8));
    CLACT_ReleasePalette((u32)(((struct Obj02711 *)w)->f1EC));
    CLACT_ReleasePalette((u32)(((struct Obj02711 *)w)->f1D4));
    ARC_TOOL_DeleteHandle(((struct Obj02711 *)w)->f1F8);
    CLACT_DeleteUnit(((struct Obj02711 *)w)->f1BC);
}
