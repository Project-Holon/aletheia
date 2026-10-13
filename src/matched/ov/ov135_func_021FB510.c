/*
 * function: func_021FB510
 * address: 0x021FB510
 * packet: pkt_ov135_021FB510
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021F9FF0 0x021F9FF0 thumb ov135
 */
#include "../include/Obj02490.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_021F9FF0(void *p);
extern void func_020061E4(u32 se);
int func_021FB510(u8 *p)
{
    int r;
    r = func_021F9FF0(p);
    switch (r) {
    case -2:
        func_020061E4(0x551);
        func_0204B3DC((struct Obj *)((struct Obj02490 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj02490 *)p)->f8), CLACT_GetActorAnimSeq((struct Obj *)(((struct Obj02490 *)p)->f8)) + 9);
        ((struct Obj02490 *)p)->f48 = 16;
        ((struct Obj02490 *)p)->f3C = -1;
        break;
    case -1: break;
    default:
        func_0204B3DC((struct Obj *)((struct Obj02490 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj02490 *)p)->f8), CLACT_GetActorAnimSeq((struct Obj *)(((struct Obj02490 *)p)->f8)) + 9);
        ((struct Obj02490 *)p)->f48 = 3;
        ((struct Obj02490 *)p)->f4C = 17;
        ((struct Obj02490 *)p)->f3C = r;
        break;
    }
    return -1;
}
