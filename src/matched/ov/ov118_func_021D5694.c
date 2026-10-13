/*
 * function: func_021D5694
 * address:  0x021D5694
 * packet:   pkt_ov118_021D5694
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *
 * Teardown of the three sub-buffers at +0x8a8/+0x88c/+0x8bc (their base
 * 0x8a8 is the single pool word) plus the +0xb0 pointer hung off the +0xc
 * record; every slot clears to zero. Non-SDK deps are the matched ov118
 * func_021D5694 callers' targets; this is the first callee of func_021D6C78.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01724.h"
#include "../include/Obj22670.h"
#include "../include/Obj22671.h"
#include "../include/Obj22672.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);

void func_021D5694(void *p)
{
    u8 *b = p;

    if (((struct Obj22670 *)((u8 *)((struct Obj01724 *)b)->fC))->fB0 != 0)
        CLACT_DeleteActor(((struct Obj22671 *)((u8 *)((struct Obj01724 *)b)->fC))->fB0);
    if (((struct Obj01724 *)b)->f8A8 != 0) {
        CLACT_ReleaseCharacter((u32)(((struct Obj01724 *)b)->f8A8));
        CLACT_ReleasePalette((u32)(((struct Obj01724 *)b)->f88C));
        CLACT_ReleaseCellAnim((u32)(((struct Obj01724 *)b)->f8BC));
    }
    ((struct Obj01724 *)b)->f8A8 = 0;
    ((struct Obj01724 *)b)->f88C = 0;
    ((struct Obj01724 *)b)->f8BC = 0;
    ((struct Obj22672 *)((u8 *)((struct Obj01724 *)b)->fC))->fB0 = 0;
}
