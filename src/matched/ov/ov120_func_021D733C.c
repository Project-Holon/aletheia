/*
 * function: GTSNEGO_MSG_SetIconY
 * address: 0x021D733C
 * packet: pkt_ov120_021D733C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   GTSNEGO_MSG_GetListRowY 0x021D72C8 thumb ov120
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
#include "../include/Obj10399.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { s16 x, y; } Vec;
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern int GTSNEGO_MSG_GetListRowY(u8 *, int, int);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void GTSNEGO_MSG_SetIconY(u8 *p, int index, int count)
{
    Vec pos;
    if (((struct Obj10399 *)p)->f140 != 0) {
        CLACT_GetActorSurfacePos(((struct Obj10399 *)p)->f140, (struct PtS *)&pos, 1);
        pos.y = GTSNEGO_MSG_GetListRowY(p, index, count) + 26;
        CLACT_AddActorSurfacePos(((struct Obj10399 *)p)->f140, (const struct Vec2 *)(&pos), 1);
    }
}
