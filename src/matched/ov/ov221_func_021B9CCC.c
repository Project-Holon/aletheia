/*
 * function: func_021B9CCC
 * address:  0x021B9CCC
 * packet:   pkt_021B9CCC
 * region:   ov221
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 */
#include "../include/Obj02557.h"

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);

void func_021B9CCC(char *p)
{
    CLACT_DeleteActor(((struct Obj02557 *)p)->f54);
    CLACT_ReleaseCellAnim((u32)(((struct Obj02557 *)p)->f50));
    CLACT_ReleaseCharacter((u32)(((struct Obj02557 *)p)->f48));
    CLACT_ReleasePalette((u32)(((struct Obj02557 *)p)->f4C));
}
