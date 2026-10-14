/*
 * function: WORLDTRADE_INPUT_StateSubCategoryInputAlt
 * address: 0x021FB964
 * packet: pkt_ov135_021FB964
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   WORLDTRADE_INPUT_UpdateButtonRow 0x021F9CDC thumb ov135
 */
#include "../include/Obj00194.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int on);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern int WORLDTRADE_INPUT_UpdateButtonRow(void *p, u8 *flags);
int WORLDTRADE_INPUT_StateSubCategoryInputAlt(u8 *p)
{
    int r;
    r = WORLDTRADE_INPUT_UpdateButtonRow(p, p + 0x60);
    switch ((u32)r) {
    case 0: case 1: case 2: case 3: case 4:
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00194 *)p)->f8, 1);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00194 *)p)->f8), CLACT_GetActorAnimSeq((struct Obj *)(((struct Obj00194 *)p)->f8)) + 9);
        ((struct Obj00194 *)p)->f48 = 24;
        ((struct Obj00194 *)p)->f3A = r;
        break;
    case -2:
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00194 *)p)->f8, 1);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00194 *)p)->f8), CLACT_GetActorAnimSeq((struct Obj *)(((struct Obj00194 *)p)->f8)) + 9);
        ((struct Obj00194 *)p)->f48 = 24;
        ((struct Obj00194 *)p)->f3A = -1;
        break;
    }
    return -1;
}
