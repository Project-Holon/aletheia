/*
 * function: GTSNEGO_MSG_SetListActorPos
 * address: 0x021D7190
 * packet: pkt_ov120_021D7190
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { s16 x, y; } Vec;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void GTSNEGO_MSG_SetListActorPos(u8 *p, int index, int x, int y)
{
    Vec pos;
    if (index < 6) {
        pos.x = x;
        pos.y = y;
        CLACT_AddActorSurfacePos(*(void **)((u32)p + 0x14c + (u32)index * 4), (const struct Vec2 *)(&pos), 1);
        CLACT_SetActorDrawEnable(*(void **)((u32)p + 0x14c + (u32)index * 4), 1);
    }
}
