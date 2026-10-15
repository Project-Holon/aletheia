/*
 * function: BSUBWAY_RECORD_LIST_PlaceCursorActor
 * address: 0x021B9FC8
 * packet: pkt_ov069_021B9FC8
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding follow.
 * symbols:
 *   CURSOR_MOVE_GetEntry 0x0202616C thumb
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
#include "../include/Obj09876.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Point { u16 x, y; } Point;
extern void *CURSOR_MOVE_GetEntry(void **obj, unsigned int idx);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void BSUBWAY_RECORD_LIST_PlaceCursorActor(char *p, int i)
{
    Point pt;
    u8 *v;
    v = CURSOR_MOVE_GetEntry(((struct Obj09876 *)p)->f14C, i);
    pt.x = v[0];
    pt.y = v[1];
    CLACT_AddActorSurfacePos(((struct Obj09876 *)p)->f124, (const struct Vec2 *)(&pt), 0);
}
