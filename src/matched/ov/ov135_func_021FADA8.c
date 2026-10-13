/*
 * function: func_021FADA8
 * address: 0x021FADA8
 * packet: pkt_ov135_021FADA8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BGWINFRM_StartMove 0x0202CD64 thumb
 */
#include "../include/Obj05414.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
struct WinMgr;
struct Actor;
struct Obj;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void BGWINFRM_StartMove(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
int func_021FADA8(u8 *p)
{
    if (CLACT_IsActorAnimActive(((struct Obj05414 *)p)->f8)) return -1;
    CLACT_SetActorDrawEnable(((struct Obj05414 *)p)->f8, 0);
    CLACT_SetActorDrawEnable(((struct Obj05414 *)p)->fC, 0);
    CLACT_SetActorDrawEnable(((struct Obj05414 *)p)->f10, 0);
    BGWINFRM_StartMove(((struct Obj05414 *)p)->f18, 0, 4, 0, 4);
    ((struct Obj05414 *)p)->f48 = 2;
    return -1;
}
