/*
 * function: func_021FAD24
 * address: 0x021FAD24
 * packet: pkt_ov135_021FAD24
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment padding at 0x021FAD82.
 * symbols:
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BGWINFRM_StartMove 0x0202CD64 thumb
 */
#include "../include/Obj03297.h"
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
struct WinMgr;
struct Actor;
struct Obj;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void BGWINFRM_StartMove(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
int func_021FAD24(u8 *p)
{
    if (CLACT_IsActorAnimActive(((struct Obj03297 *)p)->f8)) return -1;
    CLACT_SetActorDrawEnable(((struct Obj03297 *)p)->f8, 0);
    CLACT_SetActorDrawEnable(((struct Obj03297 *)p)->fC, 0);
    CLACT_SetActorDrawEnable(((struct Obj03297 *)p)->f10, 0);
    if (((struct Obj03297 *)p)->f54 == 3 && ((struct Obj03297 *)p)->f4C == 28)
        BGWINFRM_StartMove(((struct Obj03297 *)p)->f18, 0, 6, 0, 6);
    else
        BGWINFRM_StartMove(((struct Obj03297 *)p)->f18, 0, 4, 0, 4);
    ((struct Obj03297 *)p)->f48 = 4;
    return -1;
}
