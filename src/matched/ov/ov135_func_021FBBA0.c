/*
 * function: func_021FBBA0
 * address: 0x021FBBA0
 * packet: pkt_ov135_021FBBA0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021FA85C 0x021FA85C thumb ov135
 *   BGWINFRM_SetFrameDataArc  0x0202CAE4  thumb  arm9
 */
#include "../include/Obj02201.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct WinMgr;
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int on);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_021FA85C(void *p);
extern void BGWINFRM_SetFrameDataArc(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
int func_021FBBA0(u8 *p)
{
    int r;
    r = func_021FA85C(p);
    switch (r) {
    case -2:
        func_0204B3DC((struct Obj *)((struct Obj02201 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj02201 *)p)->f8), CLACT_GetActorAnimSeq((struct Obj *)(((struct Obj02201 *)p)->f8)) + 9);
        BGWINFRM_SetFrameDataArc(((struct Obj02201 *)p)->f18, 0, 0x60, 0x18, 1);
        ((struct Obj02201 *)p)->f48 = 5;
        ((struct Obj02201 *)p)->f4C = 28;
        break;
    case -1: break;
    default:
        func_0204B3DC((struct Obj *)((struct Obj02201 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj02201 *)p)->f8), CLACT_GetActorAnimSeq((struct Obj *)(((struct Obj02201 *)p)->f8)) + 9);
        ((struct Obj02201 *)p)->f48 = 3;
        ((struct Obj02201 *)p)->f4C = 29;
        ((struct Obj02201 *)p)->f3E = r;
        break;
    }
    return -1;
}
