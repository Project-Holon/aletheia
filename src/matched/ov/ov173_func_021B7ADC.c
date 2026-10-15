/*
 * function: POKE_SUMMARY_ACTOR_PositionMonActor
 * address:  0x021B7ADC
 * packet:   pkt_021B7ADC
 * region:   ov173
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 */
#include "../include/Obj05451.h"
typedef unsigned short u16;
typedef unsigned int u32;

struct Obj;
struct Vec2;
void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);

void POKE_SUMMARY_ACTOR_PositionMonActor(unsigned char *p, u32 idx, int unused)
{
    u16 local[2];

    if (idx < 4) {
        local[0] = 0x82;
        local[1] = idx * 0x18 + 0x54;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj05451 *)p)->f10C), (const struct Vec2 *)local, 1);
        CLACT_SetActorAnimFrame((struct Obj *)(((struct Obj05451 *)p)->f10C), 0);
    } else if (idx < 6) {
        local[0] = (idx - 4) * 0x28;
        local[1] = 0xa8;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj05451 *)p)->f10C), (const struct Vec2 *)local, 1);
        CLACT_SetActorAnimFrame((struct Obj *)(((struct Obj05451 *)p)->f10C), 1);
    } else {
        local[0] = 0xc0;
        local[1] = 0xa0;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj05451 *)p)->f10C), (const struct Vec2 *)local, 1);
        CLACT_SetActorAnimFrame((struct Obj *)(((struct Obj05451 *)p)->f10C), 2);
    }
}
