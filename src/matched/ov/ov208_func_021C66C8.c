/*
 * function: func_021C66C8
 * address: 0x021C66C8
 * packet: pkt_ov208_021C66C8
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
#include "../include/Obj03368.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
void func_021C66C8(void *unused,u8 *p)
{
    u8 i;
    for(i=0;i<4;i++)CLACT_DeleteActor(*(struct Obj **)(p+i*0x28+0x618));
    for(i=0;i<4;i++)CLACT_DeleteActor(*(struct Obj **)(p+i*4+0x5e4));
    CLACT_ReleasePalette(((struct Obj03368 *)p)->f5C4);
    CLACT_ReleaseCharacter(((struct Obj03368 *)p)->f5C0);
    CLACT_ReleaseCellAnim(((struct Obj03368 *)p)->f5C8);
    CLACT_ReleasePalette(((struct Obj03368 *)p)->f5D0);
    CLACT_ReleaseCharacter(((struct Obj03368 *)p)->f5CC);
    CLACT_ReleaseCellAnim(((struct Obj03368 *)p)->f5D4);
    CLACT_ReleasePalette(((struct Obj03368 *)p)->f5DC);
    CLACT_ReleaseCharacter(((struct Obj03368 *)p)->f5D8);
    CLACT_ReleaseCellAnim(((struct Obj03368 *)p)->f5E0);
}
