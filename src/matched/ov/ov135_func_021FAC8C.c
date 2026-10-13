/*
 * function: func_021FAC8C
 * address: 0x021FAC8C
 * packet: pkt_ov135_021FAC8C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: explicit if/else calls preserve the flag argument's scheduling.
 * symbols:
 *   BGWINFRM_IsMoving 0x0202CE40 thumb
 *   func_020355C4 0x020355C4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_021F4FF4 0x021F4FF4 thumb ov135
 */
#include "../include/Obj01745.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct WinMgr;
extern u32 BGWINFRM_IsMoving(struct WinMgr *mgr, u32 idx);
extern u8 func_020355C4(void);
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void func_021F4FF4(u32, u32, u32);
int func_021FAC8C(u8 *p)
{
    if (!BGWINFRM_IsMoving(*(struct WinMgr * *)&((struct Obj01745 *)p)->f18, 0)) {
        if (func_020355C4() == 1)
            func_0204B3DC(((struct Obj01745 *)p)->f8, 0);
        else
            func_0204B3DC(((struct Obj01745 *)p)->f8, 1);
        if (((struct Obj01745 *)p)->f54 == 2) {
            func_0204B92C(((struct Obj01745 *)p)->fC, 0);
            func_0204B92C(((struct Obj01745 *)p)->f10, 0);
            CLACT_SetActorAnimSeq(((struct Obj01745 *)p)->fC, 38);
            CLACT_SetActorAnimSeq(((struct Obj01745 *)p)->f10, 39);
            func_021F4FF4(*(u32 *)&((struct Obj01745 *)p)->fC, 228, 120);
            func_021F4FF4(*(u32 *)&((struct Obj01745 *)p)->f10, 154, 120);
            func_0204B3DC(((struct Obj01745 *)p)->fC, 1);
            func_0204B3DC(((struct Obj01745 *)p)->f10, 1);
        }
        ((struct Obj01745 *)p)->f48 = ((struct Obj01745 *)p)->f4C;
    }
    return -1;
}
