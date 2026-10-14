/*
 * function: WORLDTRADE_DEPOSIT_CreateActors
 * address: 0x021F7878
 * packet: pkt_ov135_021F7878
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * CLACT_CreateActor returns the object consumed by the subsequent calls and stores.
 * Matched ov135 neighbours prove its pointer request in the fifth slot.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_StopActorAnim 0x0204B974 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj00778.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 x,y,z; u8 a,b; } Pos;
extern void MI_CpuFill8(void *,u32,u32);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Actor;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_StopActorAnim(struct Actor *a);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void WORLDTRADE_DEPOSIT_CreateActors(u8 *p)
{
    Pos pos;
    MI_CpuFill8(&pos,0,8);
    pos.x=0xA0;
    pos.y=0x20;
    ((struct Obj00778 *)p)->fBF8=CLACT_CreateActor(((struct Obj00778 *)p)->fBC0,(unsigned int)((struct Obj00778 *)p)->fBE8,(unsigned int)((struct Obj00778 *)p)->fBC8,(unsigned int)((struct Obj00778 *)p)->fBF0,&pos,0,0x48);
    CLACT_SetActorAnimSeq(((struct Obj00778 *)p)->fBF8,12);
    CLACT_SetActorAutoAnim(((struct Obj00778 *)p)->fBF8,1);
    CLACT_StopActorAnim(((struct Obj00778 *)p)->fBF8);
    CLACT_SetActorDrawEnable(((struct Obj00778 *)p)->fBF8,0);
    pos.x=0xE4;
    pos.y=0x75;
    ((struct Obj00778 *)p)->fD2C=CLACT_CreateActor(((struct Obj00778 *)p)->fBC0,(unsigned int)((struct Obj00778 *)p)->fBC4,(unsigned int)((struct Obj00778 *)p)->fBC8,(unsigned int)((struct Obj00778 *)p)->fBCC,&pos,0,0x48);
    CLACT_SetActorAnimSeq(((struct Obj00778 *)p)->fD2C,0x26);
    CLACT_SetActorDrawEnable(((struct Obj00778 *)p)->fD2C,0);
    pos.x=0x8C;
    ((struct Obj00778 *)p)->fD30=CLACT_CreateActor(((struct Obj00778 *)p)->fBC0,(unsigned int)((struct Obj00778 *)p)->fBC4,(unsigned int)((struct Obj00778 *)p)->fBC8,(unsigned int)((struct Obj00778 *)p)->fBCC,&pos,0,0x48);
    CLACT_SetActorAnimSeq(((struct Obj00778 *)p)->fD30,0x27);
    CLACT_SetActorDrawEnable(((struct Obj00778 *)p)->fD30,0);
}
