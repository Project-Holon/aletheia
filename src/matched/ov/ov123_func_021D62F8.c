/*
 * function: func_021D62F8
 * address: 0x021D62F8
 * packet: pkt_ov123_021D62F8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj03266.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Point { s16 x, y; u16 f4; u8 f6, f7; };
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, u32, u32, u32, const void *, u16, u16);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void func_021D62F8(u8 *p, int x, int y)
{
    struct Point pt;
    if (((struct Obj03266 *)p)->fAC == 0) {
        pt.x = x; pt.y = y; pt.f4 = 0; pt.f6 = 0; pt.f7 = 1;
        ((struct Obj03266 *)p)->fAC = CLACT_CreateActor((void *)((struct Obj03266 *)p)->fC, (u32)((struct Obj03266 *)p)->f3C, ((struct Obj03266 *)p)->f24, ((struct Obj03266 *)p)->f58, &pt, 1, ((struct Obj03266 *)p)->f43C4);
        CLACT_SetActorAutoAnim(((struct Obj03266 *)p)->fAC, 1);
        CLACT_SetActorDrawEnable(((struct Obj03266 *)p)->fAC, 1);
    }
}
