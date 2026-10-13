/*
 * function: func_021FBDD0
 * address: 0x021FBDD0
 * packet: pkt_ov135_021FBDD0
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
 *   func_021FA394 0x021FA394 thumb ov135
 */
#include "../include/Obj01746.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int on);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern int func_021FA394(void *p);
int func_021FBDD0(u8 *p)
{
    int r;
    r = func_021FA394(p);
    switch (r) {
    case -2:
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01746 *)p)->f8, 1);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj01746 *)p)->f8), CLACT_GetActorAnimSeq((struct Obj *)(((struct Obj01746 *)p)->f8)) + 9);
        ((struct Obj01746 *)p)->f48 = 3;
        ((struct Obj01746 *)p)->f4C = 35;
        ((struct Obj01746 *)p)->f41 = -2;
        break;
    case -1: break;
    default:
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01746 *)p)->f8, 1);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj01746 *)p)->f8), CLACT_GetActorAnimSeq((struct Obj *)(((struct Obj01746 *)p)->f8)) + 9);
        ((struct Obj01746 *)p)->f48 = 3;
        ((struct Obj01746 *)p)->f4C = 35;
        ((struct Obj01746 *)p)->f41 = *(u32 *)(*(u8 * *)&((struct Obj01746 *)p)->f30 + (r + ((struct Obj01746 *)p)->f56 * 4) * 8 + 4);
        break;
    }
    return -1;
}
