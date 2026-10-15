/*
 * function: RESEARCH_GRAPH_LayoutActors
 * address: 0x021BF3D8
 * packet: pkt_ov217_021BF3D8
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C3AC8 0x021C3AC8 data a4
 *   RESEARCH_GRAPH_GetMarkerActor 0x021BFA08 thumb ov217
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 */
#include "../include/Obj00021.h"
typedef unsigned char u8;
struct Row { u8 x,y,w,h; int fields[8]; };
struct Vec2 { short x,y; };
struct Obj;
extern const struct Row d_021C3AC8[];
extern unsigned RESEARCH_GRAPH_GetMarkerActor(void *,unsigned);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned);
extern void CLACT_AddActorSurfacePos(struct Obj *,const struct Vec2 *,unsigned);
extern void CLACT_SetActorAutoAnim(struct Obj *,unsigned);
void RESEARCH_GRAPH_LayoutActors(char *p)
{
    const struct Row *row;
    struct Obj *a,*b;
    struct Vec2 pos;
    row=&d_021C3AC8[((struct Obj00021 *)p)->f34];
    a=(struct Obj *)RESEARCH_GRAPH_GetMarkerActor(p,0);
    b=(struct Obj *)RESEARCH_GRAPH_GetMarkerActor(p,1);
    if (((struct Obj00021 *)p)->f3D0==1 || ((struct Obj00021 *)p)->f34==2 || ((struct Obj00021 *)p)->f34==4) {
        CLACT_SetActorDrawEnable(a,0);
        CLACT_SetActorDrawEnable(b,0);
        return;
    }
    pos.x=row->fields[0]+row->fields[4];
    pos.y=row->fields[1]+row->fields[5];
    CLACT_AddActorSurfacePos(a,&pos,0);
    pos.x=row->fields[0]+row->fields[6];
    pos.y=row->fields[1]+row->fields[7];
    CLACT_AddActorSurfacePos(b,&pos,0);
    CLACT_SetActorDrawEnable(a,1);
    CLACT_SetActorDrawEnable(b,1);
    CLACT_SetActorAutoAnim(a,1);
    CLACT_SetActorAutoAnim(b,1);
}
