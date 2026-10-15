/*
 * function: RESEARCH_LIST_UpdateEntryActor
 * address: 0x021BC014
 * packet: pkt_ov217_021BC014
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: BF28/BF3C forward entry r0/r1 to BF04/BF1C; preserve both, with observed u8 argument truncation.
 * symbols:
 *   RESEARCH_LIST_FindSaveIndex 0x021BBC50 thumb ov217
 *   RESEARCH_LIST_GetActor 0x021BC720 thumb ov217
 *   RESEARCH_LIST_GetEntryScreenX 0x021BBF28 thumb ov217
 *   RESEARCH_LIST_GetEntryScreenY 0x021BBF3C thumb ov217
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
struct Obj;
struct Vec2 { s16 x,y; };
extern u8 RESEARCH_LIST_FindSaveIndex(u8 *p);
extern u32 RESEARCH_LIST_GetActor(void *p,u32 index);
extern int RESEARCH_LIST_GetEntryScreenX(unsigned char *p, unsigned int slot);
extern int RESEARCH_LIST_GetEntryScreenY(u8 *p,u8 index);
extern void CLACT_SetActorDrawEnable(struct Obj *p,u32 value);
extern void CLACT_AddActorSurfacePos(struct Obj *p,const struct Vec2 *delta,u32 which);
extern void CLACT_SetActorAutoAnim(struct Obj *p,u32 value);
void RESEARCH_LIST_UpdateEntryActor(u8 *p)
{
    struct Vec2 point;
    u32 index;
    struct Obj *obj;
    index=RESEARCH_LIST_FindSaveIndex(p);
    obj=(struct Obj *)RESEARCH_LIST_GetActor(p,2);
    if(index==255) {
        CLACT_SetActorDrawEnable(obj,0);
        return;
    }
    point.x=RESEARCH_LIST_GetEntryScreenX(p,(u8)index);
    point.y=RESEARCH_LIST_GetEntryScreenY(p,index)+10;
    CLACT_AddActorSurfacePos(obj,&point,0);
    CLACT_SetActorAutoAnim(obj,1);
    CLACT_SetActorDrawEnable(obj,1);
}
