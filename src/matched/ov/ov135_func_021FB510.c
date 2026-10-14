/*
 * function: WORLDTRADE_INPUT_StateSpeciesListInput
 * address: 0x021FB510
 * packet: pkt_ov135_021FB510
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   WORLDTRADE_INPUT_UpdatePagedList4 0x021F9FF0 thumb ov135
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj02490.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern int WORLDTRADE_INPUT_UpdatePagedList4(void *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
int WORLDTRADE_INPUT_StateSpeciesListInput(u8 *p)
{
    int r;
    r = WORLDTRADE_INPUT_UpdatePagedList4(p);
    switch (r) {
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj02490 *)p)->f8, 1);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj02490 *)p)->f8), CLACT_GetActorAnimSeq((struct Obj *)(((struct Obj02490 *)p)->f8)) + 9);
        ((struct Obj02490 *)p)->f48 = 16;
        ((struct Obj02490 *)p)->f3C = -1;
        break;
    case -1: break;
    default:
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj02490 *)p)->f8, 1);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj02490 *)p)->f8), CLACT_GetActorAnimSeq((struct Obj *)(((struct Obj02490 *)p)->f8)) + 9);
        ((struct Obj02490 *)p)->f48 = 3;
        ((struct Obj02490 *)p)->f4C = 17;
        ((struct Obj02490 *)p)->f3C = r;
        break;
    }
    return -1;
}
