/*
 * function: func_021D634C
 * address: 0x021D634C
 * packet: pkt_ov123_021D634C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: indexed p+0x74 array base and non-const table retain the original scheduling.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   d_021DAACC 0x021DAACC data a4
 */
#include "../include/Obj02836.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Point { s16 x,y; u16 f4; u8 f6,f7; };
struct Entry { int x,y,n; };
extern struct Entry d_021DAACC[];
struct Actor;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern struct Obj *CLACT_CreateActor(void *, u32, u32, u32, const void *, u16, u16);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);
void func_021D634C(u8 *p, unsigned int i)
{
    struct Point pt;
    if (*(void **)(p + i*4 + 0x74)) CLACT_DeleteActor(*(void **)(p+i*4+0x74));
    pt.x = d_021DAACC[i].x; pt.y = d_021DAACC[i].y;
    pt.f4 = i; pt.f6 = d_021DAACC[i].n; pt.f7 = 1;
    ((void **)(p + 0x74))[i] = CLACT_CreateActor((void *)((struct Obj02836 *)p)->fC, (u32)((struct Obj02836 *)p)->f38, ((struct Obj02836 *)p)->f20, ((struct Obj02836 *)p)->f54, &pt, 0, ((struct Obj02836 *)p)->f43C4);
    CLACT_SetActorAnimFrame(((void **)(p+0x74))[i],0);
    CLACT_SetActorAutoAnim(((void **)(p+0x74))[i],1);
    CLACT_SetActorDrawEnable(((void **)(p+0x74))[i],1);
    CLACT_SetActorAffineMode(((void **)(p+0x74))[i],2);
}
