/*
 * function: Wf2dmapFriend_ShowEntryActor
 * address: 0x021C87B0
 * packet: pkt_ov128_021C87B0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021C8808, 021C8814 read WINOUT; 021C8828 reads DISPCNT.
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   gWf2dmapEntrySlotPos 0x021CA6C8 data a2
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj00179.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct Point {s16 x,y;} Point;
typedef struct Entry {s16 x,y; s16 rest[3];} Entry;
extern const Entry gWf2dmapEntrySlotPos[];
struct Actor;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
static inline void Outside(int wnd,int effect)
{
    u32 tmp=(*(volatile u16 *)0x0400004A & ~0x3F) | wnd;
    if(effect) tmp |= 0x20;
    *(volatile u16 *)0x0400004A=(u16)tmp;
}
void Wf2dmapFriend_ShowEntryActor(u8 *p, u8 *a1)
{
    Point pos;
    CLACT_SetActorDrawEnable(((struct Obj00179 *)p)->f1A0,1);
    CLACT_SetActorAnimSeq(((struct Obj00179 *)p)->f1A0,1);
    CLACT_RestartActorAnim(((struct Obj00179 *)p)->f1A0);
    *(int *)&((struct Obj00179 *)p)->f1A8=0;
    CLACT_SetActorAutoAnim(((struct Obj00179 *)p)->f1A0,1);
    pos.x=gWf2dmapEntrySlotPos[*(s16 *)(p + 4)].x * 8;
    pos.y=gWf2dmapEntrySlotPos[*(s16 *)(p + 4)].y * 8 - 4;
    CLACT_AddActorSurfacePos(((struct Obj00179 *)p)->f1A0,(const struct Vec2 *)(&pos),0);
    *(volatile u16 *)0x0400004A=(u16)((*(volatile u16 *)0x0400004A & ~0x3F00) | 0x700);
    Outside(31,1);
    *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000 & ~0xe000) | 0x8000;
    GFL_USE_PlaySeDefaultVolume(0x668);
}
