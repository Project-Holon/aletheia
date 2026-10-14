/*
 * function: DENDOU_VIEW_MoveActor
 * address: 0x021DE0C0
 * packet: pkt_ov171_021DE0C0
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
typedef struct Vec2 {s16 x,y;} Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *,const struct Vec2 *,u32);
void DENDOU_VIEW_MoveActor(u8 *p, int i, int x, int y)
{
    Vec2 pos;
    pos.x=x; pos.y=y;
    CLACT_AddActorSurfacePos(*(struct Obj **)((u32)p+i*4+0xb74), &pos,0);
}
