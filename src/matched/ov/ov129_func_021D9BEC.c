/*
 * function: WF2DMAP_SCENE_CreateCursorActors
 * address: 0x021D9BEC
 * packet: pkt_ov129_021D9BEC
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two bytes of zero alignment padding.
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   WF2DMAP_SCENE_MoveCursor 0x021D9E60 thumb ov129
 *   WF2DMAP_SCENE_SetCursorPos 0x021D9E98 thumb ov129
 *   WF2DMAP_SCENE_SetCursorVisible 0x021D9E48 thumb ov129
 */
#include "../include/Obj00501.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u16 x,y,frame; u8 speed,flag; } Params;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
typedef unsigned int   u32;
struct Actor;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void WF2DMAP_SCENE_MoveCursor(u8 *p, int n);
extern void WF2DMAP_SCENE_SetCursorPos(char *,int);
extern void WF2DMAP_SCENE_SetCursorVisible(char *,int,int);
void WF2DMAP_SCENE_CreateCursorActors(char *p)
{
    Params s;
    int h=((struct Obj00501 *)p)->f25C;
    s.x=0; s.y=0; s.frame=0; s.speed=0; s.flag=0;
    ((struct Obj00501 *)p)->f194=(int)CLACT_CreateActor((void *)h,((struct Obj00501 *)p)->f274,((struct Obj00501 *)p)->f268,((struct Obj00501 *)p)->f28C,&s,0,50);
    ((struct Obj00501 *)p)->f1B0=(int)CLACT_CreateActor((void *)h,((struct Obj00501 *)p)->f274,((struct Obj00501 *)p)->f268,((struct Obj00501 *)p)->f28C,&s,0,50);
    ((struct Obj00501 *)p)->f1CC=(int)CLACT_CreateActor((void *)h,((struct Obj00501 *)p)->f274,((struct Obj00501 *)p)->f268,((struct Obj00501 *)p)->f28C,&s,0,50);
    WF2DMAP_SCENE_MoveCursor((u8 *)p,0);
    CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00501 *)p)->f194),0);
    CLACT_SetActorAutoAnim((struct Obj *)((struct Obj00501 *)p)->f194,1);
    ((struct Obj00501 *)p)->f1B8=0; ((struct Obj00501 *)p)->f1BA=0;
    ((struct Obj00501 *)p)->f1A4=1;
    WF2DMAP_SCENE_SetCursorPos(p,0);
    CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00501 *)p)->f1B0),((struct Obj00501 *)p)->f1A4);
    CLACT_SetActorAutoAnim((struct Obj *)((struct Obj00501 *)p)->f1B0,1);
    CLACT_SetActorObjMode((struct Actor *)(((struct Obj00501 *)p)->f1B0),1);
    ((struct Obj00501 *)p)->f1D4=0; ((struct Obj00501 *)p)->f1D6=0;
    ((struct Obj00501 *)p)->f1C0=1;
    WF2DMAP_SCENE_SetCursorPos(p,0);
    CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00501 *)p)->f1CC),((struct Obj00501 *)p)->f1C0);
    CLACT_SetActorObjMode((struct Actor *)(((struct Obj00501 *)p)->f1CC),1);
    CLACT_SetActorAutoAnim((struct Obj *)((struct Obj00501 *)p)->f1CC,1);
    WF2DMAP_SCENE_SetCursorVisible(p,1,0);
    WF2DMAP_SCENE_SetCursorVisible(p,2,0);
}
