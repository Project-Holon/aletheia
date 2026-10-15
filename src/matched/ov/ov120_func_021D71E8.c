/*
 * function: GTSNEGO_MSG_MoveListActor
 * address: 0x021D71E8
 * packet: pkt_ov120_021D71E8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { s16 x, y; } Vec;
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void GTSNEGO_MSG_MoveListActor(u8 *p, int index, int delta)
{
    Vec pos;
    if (*(void **)((u32)p + 0x14c + (u32)index * 4) != 0) {
        CLACT_GetActorSurfacePos(*(void **)((u32)p + 0x14c + (u32)index * 4), (struct PtS *)&pos, 1);
        pos.y += (s16)delta;
        CLACT_AddActorSurfacePos(*(void **)((u32)p + 0x14c + (u32)index * 4), (const struct Vec2 *)(&pos), 1);
    }
}
