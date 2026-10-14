/*
 * function: WORLDTRADE_INPUT_StateThreeOptionInput
 * address: 0x021FBCF4
 * packet: pkt_ov135_021FBCF4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: two zero bytes of alignment padding after the return.
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   WORLDTRADE_INPUT_UpdateThreeOptionMenu 0x021FA15C thumb ov135
 */
#include "../include/Obj02202.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int on);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern int WORLDTRADE_INPUT_UpdateThreeOptionMenu(void *p);
int WORLDTRADE_INPUT_StateThreeOptionInput(u8 *p)
{
    int r;
    r = WORLDTRADE_INPUT_UpdateThreeOptionMenu(p);
    switch (r) {
    case -2:
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj02202 *)p)->f8, 1);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj02202 *)p)->f8), CLACT_GetActorAnimSeq((struct Obj *)(((struct Obj02202 *)p)->f8)) + 9);
        ((struct Obj02202 *)p)->f48 = 3;
        ((struct Obj02202 *)p)->f4C = 32;
        ((struct Obj02202 *)p)->f40 = -2;
        break;
    case -1: break;
    default:
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj02202 *)p)->f8, 1);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj02202 *)p)->f8), CLACT_GetActorAnimSeq((struct Obj *)(((struct Obj02202 *)p)->f8)) + 9);
        ((struct Obj02202 *)p)->f48 = 3;
        ((struct Obj02202 *)p)->f4C = 32;
        ((struct Obj02202 *)p)->f40 = r;
        break;
    }
    return -1;
}
