/*
 * function: func_021FB674
 * address: 0x021FB674
 * packet: pkt_ov135_021FB674
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_021FA514 0x021FA514 thumb ov135
 */
#include "../include/Obj00195.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int on);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern int func_021FA514(void *p, u8 *flags);
int func_021FB674(u8 *p)
{
    int r;
    r = func_021FA514(p, p + 0x60);
    switch ((u32)r) {
    case -2:
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00195 *)p)->f8, 1);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00195 *)p)->f8), CLACT_GetActorAnimSeq((struct Obj *)(((struct Obj00195 *)p)->f8)) + 9);
        ((struct Obj00195 *)p)->f48 = 3;
        ((struct Obj00195 *)p)->f4C = 20;
        ((struct Obj00195 *)p)->f38 = -1;
        break;
    case 10:
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00195 *)p)->f8, 1);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00195 *)p)->f8), CLACT_GetActorAnimSeq((struct Obj *)(((struct Obj00195 *)p)->f8)) + 9);
        ((struct Obj00195 *)p)->f48 = 3;
        ((struct Obj00195 *)p)->f4C = 20;
        ((struct Obj00195 *)p)->f38 = -2;
        break;
    case -1: break;
    default:
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00195 *)p)->f8, 1);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00195 *)p)->f8), 19);
        ((struct Obj00195 *)p)->f38 = r;
        ((struct Obj00195 *)p)->f48 = 20;
        break;
    }
    return -1;
}
