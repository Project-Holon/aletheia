/*
 * function: func_021C2D88
 * address: 0x021C2D88
 * packet: pkt_ov208_021C2D88
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
#include "../include/Obj05541.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
void func_021C2D88(void *unused, u8 *p, void *a2)
{
    u8 i;
    for (i = 0; i < 7; i++)
        CLACT_DeleteActor(*(struct Obj **)(p + i * 4 + 0x9c));
    CLACT_ReleasePalette(((struct Obj05541 *)p)->f88);
    CLACT_ReleaseCharacter(((struct Obj05541 *)p)->f84);
    CLACT_ReleaseCellAnim(((struct Obj05541 *)p)->f8C);
    CLACT_ReleasePalette(((struct Obj05541 *)p)->f94);
    CLACT_ReleaseCharacter(((struct Obj05541 *)p)->f90);
    CLACT_ReleaseCellAnim(((struct Obj05541 *)p)->f98);
}
