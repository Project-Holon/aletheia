/*
 * function: func_021C21C4
 * address: 0x021C21C4
 * packet: pkt_ov217_021C21C4
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: two zero padding bytes at 0x021C224E, not a follower.
 * ABI: B8C4's own source omits the visible original r1=0; retain it.
 *      Palette is selected only for the original modes 0..3; original
 *      default branch retains entry r5 without initializing it.
 * symbols:
 *   func_0204B404 0x0204B404 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAnimLoopCount 0x0204B9C4 arm
 *   func_0204B92C 0x0204B92C arm
 *   CLACT_SetActorAutoAnimSpeed 0x0204B954 arm
 *   CLACT_StartActorAnim 0x0204B95C arm
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../include/Obj06719.h"
#include "../include/Obj06720.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Vec2 { short x,y; };
struct Obj;
struct Actor;
extern void func_0204B404(struct Obj *,const struct Vec2 *,u32);
extern void CLACT_SetActorAnimSeq(struct Obj *,u16);
extern void CLACT_SetActorAnimFrame(struct Obj *,u32);
extern void CLACT_SetActorAnimLoopCount(struct Actor *,u32);
extern void func_0204B92C(struct Obj *,u32);
extern void CLACT_SetActorAutoAnimSpeed(struct Actor *,u32);
extern void CLACT_StartActorAnim(struct Actor *);
extern void func_0204B3DC(struct Obj *,u32);
void func_021C21C4(u8 *p,int index)
{
    u8 *record=p+0x28+index*24;
    struct Obj *obj=*(struct Obj * *)&((struct Obj06720 *)record)->f14;
    struct Vec2 point;
    u16 palette;
    point.x=record[0xe];
    point.y=record[0xf];
    ((struct Obj06720 *)record)->f0=1;
    switch (((struct Obj06720 *)record)->f10) {
    case 0: palette=((struct Obj06719 *)p)->f16; break;
    case 1: palette=((struct Obj06719 *)p)->f18; break;
    case 2: palette=((struct Obj06719 *)p)->f1A; break;
    case 3: palette=((struct Obj06719 *)p)->f1C; break;
    }
    func_0204B404(obj,&point,((struct Obj06719 *)p)->f14);
    CLACT_SetActorAnimSeq(obj,palette);
    CLACT_SetActorAnimFrame(obj,0);
    CLACT_SetActorAnimLoopCount((struct Actor *)obj,1);
    func_0204B92C(obj,1);
    CLACT_SetActorAutoAnimSpeed((struct Actor *)obj,0x12000);
    CLACT_StartActorAnim((struct Actor *)obj);
    func_0204B3DC(obj,1);
}
