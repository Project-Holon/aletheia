/*
 * function: func_0220B000
 * address: 0x0220B000
 * packet: pkt_ov196_0220B000
 * region: ov196
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {u16 x,y;} Pos;
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_0220B000(int *p, u8 *q)
{
    Pos pos;
    u8 h=q[3]/2;
    u8 w=q[2]/2;
    pos.x=q[0]-w;pos.y=q[1]-h;CLACT_AddActorSurfacePos((struct Obj *)p[0],(const struct Vec2 *)(&pos),1);
    pos.x=q[0]-w;pos.y=q[1]+h;CLACT_AddActorSurfacePos((struct Obj *)p[1],(const struct Vec2 *)(&pos),1);
    pos.x=q[0]+w;pos.y=q[1]-h;CLACT_AddActorSurfacePos((struct Obj *)p[2],(const struct Vec2 *)(&pos),1);
    pos.x=q[0]+w;pos.y=q[1]+h;CLACT_AddActorSurfacePos((struct Obj *)p[3],(const struct Vec2 *)(&pos),1);
}
