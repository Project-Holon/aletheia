/*
 * function: WORLDTRADE_INPUT_StateCategoryInput
 * address: 0x021FAE2C
 * packet: pkt_ov135_021FAE2C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_INPUT_UpdateCategoryGrid 0x021F9A88 thumb ov135
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 */
#include "../include/Obj00246.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 WORLDTRADE_INPUT_UpdateCategoryGrid(void *, void *);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
int WORLDTRADE_INPUT_StateCategoryInput(u8 *p)
{
    u32 sel = WORLDTRADE_INPUT_UpdateCategoryGrid(p, p + 96);
    if (sel != -2) {
        if (sel <= 8) {
            CLACT_SetActorDrawEnable(((struct Obj00246 *)p)->f8, 1);
            CLACT_SetActorAnimSeq(((struct Obj00246 *)p)->f8, 19);
            ((struct Obj00246 *)p)->f48 = 8;
            ((struct Obj00246 *)p)->f38 = sel;
        }
    } else {
        CLACT_SetActorDrawEnable(((struct Obj00246 *)p)->f8, 1);
        CLACT_SetActorAnimSeq(((struct Obj00246 *)p)->f8, CLACT_GetActorAnimSeq(((struct Obj00246 *)p)->f8) + 9);
        ((struct Obj00246 *)p)->f48 = 3;
        ((struct Obj00246 *)p)->f4C = 8;
        ((struct Obj00246 *)p)->f38 = -1;
    }
    return -1;
}
