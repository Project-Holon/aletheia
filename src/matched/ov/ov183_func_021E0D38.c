/*
 * function: func_021E0D38
 * address: 0x021E0D38
 * packet: pkt_ov183_021E0D38
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021E0D8E alignment padding.
 * symbols:
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 */
#include "../include/Obj02895.h"
typedef unsigned char u8;
typedef short s16;
struct Coordinates { u8 pad[0x298]; u8 rect[32][4]; };
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, unsigned int which);
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
void func_021E0D38(struct Coordinates *p, int index)
{
    int width = p->rect[index + 12][1] - p->rect[index + 12][0];
    int height = p->rect[index + 12][3] - p->rect[index + 12][2];
    s16 pos[2];
    pos[0] = height / 2 + p->rect[index + 12][2];
    pos[1] = width / 2 + p->rect[index + 12][0];
    CLACT_AddActorSurfacePos(((struct Obj02895 *)p)->f1B0, (const struct Vec2 *)pos, 1);
    CLACT_SetActorAnimFrame(((struct Obj02895 *)p)->f1B0, 0);
}
