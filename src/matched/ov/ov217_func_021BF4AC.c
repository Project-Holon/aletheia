/*
 * function: RESEARCH_GRAPH_LayoutMarkerActor
 * address: 0x021BF4AC
 * packet: pkt_ov217_021BF4AC
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: bind table=d_021C3850 before the guards to retain its r7 base.
 * F910 preserves caller's visibly loaded r1; C11DC/C11FC index parameters are u8 from original truncations.
 * symbols:
 *   d_021C3850 0x021C3850 data a2
 *   RESEARCH_GRAPH_GetEntryIdBySave 0x021BF910 thumb ov217
 *   RESEARCH_GRAPH_GetLeftCircle 0x021BF76C thumb ov217
 *   CircleGraph_GetPercentByKey 0x021C11DC thumb ov217
 *   CircleGraph_GetLabelPositionByKey 0x021C11FC thumb ov217
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorAnimLoopCount 0x0204B9C4 arm
 */
#include "../include/Obj00021.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
struct Obj; struct Actor;
struct Vec2 { short x,y; };
extern const u16 d_021C3850[];
typedef unsigned int   u32;
extern u32 RESEARCH_GRAPH_GetEntryIdBySave(u8 *p);
extern u8 *RESEARCH_GRAPH_GetLeftCircle(void *p);
extern u8 CircleGraph_GetPercentByKey(u8 *p, u8 key);
extern void CircleGraph_GetLabelPositionByKey(u8 *h, u8 key, s32 *px, s32 *py);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned);
extern void CLACT_AddActorSurfacePos(struct Obj *,const struct Vec2 *,unsigned);
extern void CLACT_SetActorAutoAnim(struct Obj *,unsigned);
extern void CLACT_SetActorAnimLoopCount(struct Actor *,unsigned);
void RESEARCH_GRAPH_LayoutMarkerActor(char *p)
{
    struct Obj *obj;
    unsigned index;
    s32 x,y;
    struct Vec2 pos;
    const u16 *table;
    obj=*(struct Obj * *)&((struct Obj00021 *)p)->f3A0;
    table=d_021C3850;
    if (((struct Obj00021 *)p)->f3C8==0) { CLACT_SetActorDrawEnable(obj,0); return; }
    if (((struct Obj00021 *)p)->f34!=2) { CLACT_SetActorDrawEnable(obj,0); return; }
    index=RESEARCH_GRAPH_GetEntryIdBySave((u8 *)p);
    if (CircleGraph_GetPercentByKey(RESEARCH_GRAPH_GetLeftCircle(p),index)==0) { CLACT_SetActorDrawEnable(obj,0); return; }
    if (index==0) { CLACT_SetActorDrawEnable(obj,0); return; }
    CircleGraph_GetLabelPositionByKey(RESEARCH_GRAPH_GetLeftCircle(p),index,&x,&y);

    pos.x=x;
    pos.y=y;
    CLACT_AddActorSurfacePos(obj,&pos,table[12]);
    CLACT_SetActorDrawEnable(obj,1);
    CLACT_SetActorAutoAnim(obj,1);
    CLACT_SetActorAnimLoopCount((struct Actor *)obj,2);
}
