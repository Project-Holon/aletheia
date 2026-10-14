/*
 * function: WORLDTRADE_INPUT_StateSubCategorySelectedAlt
 * address: 0x021FB9E4
 * packet: pkt_ov135_021FB9E4
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
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   WORLDTRADE_INPUT_MenuFinish 0x021F9660 thumb ov135
 *   BGWINFRM_SetFrameDataArc  0x0202CAE4  thumb  arm9
 *   BGWINFRM_StartMove  0x0202CD64  thumb  arm9
 */
#include "../include/Obj00098.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
struct Actor;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int on);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void WORLDTRADE_INPUT_MenuFinish(void *p, u32 mode);
extern void BGWINFRM_StartMove(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern void BGWINFRM_SetFrameDataArc(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
int WORLDTRADE_INPUT_StateSubCategorySelectedAlt(u8 *p)
{
    if (CLACT_IsActorAnimActive(((struct Obj00098 *)p)->f8) != 0) return -1;
    CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)&((struct Obj00098 *)p)->f8, 0);
    WORLDTRADE_INPUT_MenuFinish(p, 5);
    if (((struct Obj00098 *)p)->f3A < 0) {
        ((struct Obj00098 *)p)->f48 = 21;
    } else {
            BGWINFRM_StartMove(((struct Obj00098 *)p)->f18, 0, -4, 0, 3);
            if (((struct Obj00098 *)p)->f14 != 0) CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00098 *)p)->f14, 0);
            CLACT_SetActorAnimSeq((struct Obj *)(*(u32 *)&((struct Obj00098 *)p)->f8), 7);
            ((struct Obj00098 *)p)->f48 = 2;
            BGWINFRM_SetFrameDataArc(((struct Obj00098 *)p)->f18, 0, 0x60, 0x18, 1);
            ((struct Obj00098 *)p)->f4C = 26;
    }
    return -1;
}
