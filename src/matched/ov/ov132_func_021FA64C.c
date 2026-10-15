/*
 * function: STA_ACT_BUTTON_Delete
 * address: 0x021FA64C
 * packet: pkt_ov132_021FA64C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware control read at 021FA652 and store 021FA658.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj01550.h"
typedef unsigned short u16;
struct Bank;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern u32 func_020307B0(void *p);
void STA_ACT_BUTTON_Delete(char *p)
{
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    if (((struct Obj01550 *)p)->f48 != 255) CLACT_DeleteActor(((struct Obj01550 *)p)->f4C);
    if (((struct Obj01550 *)p)->f4A != 255) CLACT_DeleteActor(((struct Obj01550 *)p)->f50);
    CLACT_DeleteActor(((struct Obj01550 *)p)->f5C);
    CLACT_ReleasePalette((u32)(((struct Obj01550 *)p)->f1C));
    CLACT_ReleaseCharacter((u32)(((struct Obj01550 *)p)->f28));
    CLACT_ReleaseCellAnim((u32)(((struct Obj01550 *)p)->f34));
    CLACT_ReleasePalette((u32)(((struct Obj01550 *)p)->f20));
    CLACT_ReleaseCharacter((u32)(((struct Obj01550 *)p)->f2C));
    CLACT_ReleaseCellAnim((u32)(((struct Obj01550 *)p)->f38));
    CLACT_ReleasePalette((u32)(((struct Obj01550 *)p)->f24));
    CLACT_ReleaseCharacter((u32)(((struct Obj01550 *)p)->f30));
    CLACT_ReleaseCellAnim((u32)(((struct Obj01550 *)p)->f3C));
    CLACT_DeleteUnit(((struct Obj01550 *)p)->f18);
    func_020307B0(p);
}
