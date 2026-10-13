/*
 * function: VS_MULTI_LIST_MoveActorX
 * address: 0x021F72DC
 * packet: pkt_ov097_021F72DC
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
struct Actor;
struct PtS { short x, y; };
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void VS_MULTI_LIST_MoveActorX(unsigned p, unsigned i, int dx)
{
    struct PtS pt;
    unsigned base = p + 0x54;
    CLACT_GetActorSurfacePos(*(struct Actor **)(base + i * 4), &pt, 0);
    pt.x = pt.x + dx;
    CLACT_AddActorSurfacePos((struct Obj *)(*(struct Actor **)(base + i * 4)), (const struct Vec2 *)(&pt), 0);
}
