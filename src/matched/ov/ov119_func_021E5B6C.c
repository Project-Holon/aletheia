/*
 * function: POKETRADE_2D_PlaceTouchbarActors
 * address: 0x021E5B6C
 * packet: pkt_ov119_021E5B6C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: first y ternary is b == 0 ? 8 : 12 to retain branch polarity.
 * symbols:
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
#include "../include/Obj08073.h"
typedef unsigned short u16;
typedef struct { u16 x, y; } Pos;
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void POKETRADE_2D_PlaceTouchbarActors(int p, int b, int c)
{
    Pos pos;
    if (c) {
        pos.x = 96; pos.y = 12;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj08073 *)p)->fF10), (const struct Vec2 *)(&pos), 1);
        pos.x = 160; pos.y = 12;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj08073 *)p)->fF14), (const struct Vec2 *)(&pos), 1);
    } else {
        pos.x = 96; pos.y = b == 0 ? 8 : 12;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj08073 *)p)->fF10), (const struct Vec2 *)(&pos), 1);
        pos.x = 160; pos.y = b ? 8 : 12;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj08073 *)p)->fF14), (const struct Vec2 *)(&pos), 1);
    }
}
