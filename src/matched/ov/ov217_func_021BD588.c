/*
 * function: RESEARCH_LIST_UpdateCenterActor
 * address:  0x021BD588
 * packet:   pkt_ov217_021BD588
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RESEARCH_LIST_GetActor  0x021BC720  thumb  ov217
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef struct { unsigned short x, y; } Pos;
typedef unsigned int   u32;
extern u32 RESEARCH_LIST_GetActor(void *p, u32 i);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *a, unsigned int b);

void RESEARCH_LIST_UpdateCenterActor(void *p)
{
    int obj = RESEARCH_LIST_GetActor(p, 1);
    Pos pos;
    pos.x = 0x80;
    pos.y = 0x60;
    CLACT_AddActorSurfacePos((struct Obj *)obj, (const struct Vec2 *)(&pos), 0);
    CLACT_SetActorDrawEnable((struct Obj *)obj, 1);
}
